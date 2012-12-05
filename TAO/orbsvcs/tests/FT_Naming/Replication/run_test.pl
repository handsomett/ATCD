eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

# This is a Perl script that runs a Naming Service test.  It starts
# all the servers and clients as necessary.

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;
use Cwd;

$startdir = getcwd();

$quiet = 0;

# check for -q flag
if ($ARGV[0] eq '-q') {
    $quiet = 1;
}

my $test = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";

# Variables for command-line arguments to client and server
# executables.
$hostname = $test->HostName ();

$ns_orb_port1 = 10001 + $test->RandomPort ();
$ns_orb_port2 = 10002 + $test->RandomPort ();
$ns_endpoint1 = "iiop://$hostname:$ns_orb_port1";
$ns_endpoint2 = "iiop://$hostname:$ns_orb_port2";

$iorfile1 = "ns1.ior";
$iorfile2 = "ns2.ior";
$primary_iorfile = "ns_primary.ior";
$naming_persistence_dir = "NameService";

## Allow the user to determine where the persistent file will be located
## just in case the current directory is not suitable for locking.
## We can't change the name of the persistent file because that is not
## sufficient to work around locking problems for Tru64 when the current
## directory is NFS mounted from a system that does not properly support
## locking.
foreach my $possible ($ENV{TMPDIR}, $ENV{TEMP}, $ENV{TMP}) {
    if (defined $possible && -d $possible) {
      if (chdir($possible)) {
        last;
      }
    }
}

my $test_iorfile1 = $test->LocalFile ($iorfile1);
my $test_iorfile2 = $test->LocalFile ($iorfile2);
my $test_primary_iorfile = $test->LocalFile ($primary_iorfile);

$status = 0;



print "INFO: Running the test in ", getcwd(), "\n";

# Make sure that the directory to use to hold the naming contexts exists
# and is cleaned out
if ( ! -d "$naming_persistence_dir" ) {
    mkdir ($naming_persistence_dir, 0777);
    }
else {
    chdir $naming_persistence_dir;
    opendir(THISDIR, ".");
    @allfiles = grep(!/^\.\.?$/, readdir(THISDIR));
    closedir(THISDIR);
    foreach $tmp (@allfiles){
        $test->DeleteFile ($tmp);
    }
    chdir "..";
}

# Run two Naming Servers and one client.  Client uses iors
# in files to find the individual copies of the Naming Servers.

my $args = "-ORBEndPoint $ns_endpoint1 -o $iorfile1 -m 0 -r $naming_persistence_dir --primary";
my $prog = "$startdir/../../../Naming_Service/tao_ft_naming";

print STDERR "Starting Primary: $prog $args\n";

$NS1 = $test->CreateProcess ("$prog", "$args");

$test->DeleteFile ($iorfile1);

$NS1->Spawn ();

if ($test->WaitForFileTimed ($iorfile1,
                             $test->ProcessStartWaitInterval()) == -1) {
    print STDERR "ERROR: cannot find file <$test_iorfile1>\n";
    $NS1->Kill (); $NS1->TimedWait (1);
    exit 1;
}

$args = "-ORBEndPoint $ns_endpoint2 -o $iorfile2 -m 0 -r $naming_persistence_dir --backup";

$prog = "$startdir/../../../Naming_Service/tao_ft_naming";

print STDERR "Starting Backup: $prog $args\n";

$NS2 = $test->CreateProcess ("$prog", "$args");

$test->DeleteFile ($iorfile2);

$NS2->Spawn ();

if ($test->WaitForFileTimed ($iorfile2,
                             $test->ProcessStartWaitInterval()) == -1) {
    print STDERR "ERROR: cannot find file <$test_iorfile2>\n";
    $NS2->Kill (); $NS2->TimedWait (1);
    exit 1;
}

$args = "-p file://$iorfile1 -q file://$iorfile2";
$prog = "$startdir/client";

print STDERR "Starting Client: $prog $args\n";

$CL = $test->CreateProcess ("$prog", "$args");

$client = $CL->SpawnWaitKill ($test->ProcessStartWaitInterval());

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

$NS1->Kill ();
$NS2->Kill ();

$test->DeleteFile ($iorfile1);
$test->DeleteFile ($iorfile2);

exit $status;
