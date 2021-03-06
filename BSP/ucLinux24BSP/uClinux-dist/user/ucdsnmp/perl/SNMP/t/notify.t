#!./perl

BEGIN {
    unless(grep /blib/, @INC) {
        chdir 't' if -d 't';
        @INC = '../lib' if -d '../lib';
    }
}
use Test;
BEGIN { $n = 7; plan tests => $n }
use SNMP;
use vars qw($agent_port $comm $comm2 $trap_port $agent_host);
require "t/startagent.pl";
$SNMP::debugging = 0;
$SNMP::verbose = 0;

my $res;
my $enterprise = '.1.3.6.1.2.1.1.1.0';
my $agent = $agent_host;
my $generic = 'specific';
my $junk_oid = ".1.3.6.1.2.1.1.1.1.1.1";
my $oid = '.1.3.6.1.2.1.1.1';
my $junk_name = 'fooDescr';
my $junk_host = 'no.host.here';
my $name = "gmarzot\@nortelnetworks.com";

#                         V1 trap testing
######################  1  #############################
# Fire up a trap session.
my $s1 =
    new SNMP::Session (DestHost=>$agent_host,Community=>$comm,RemotePort=>$trap_port);
ok(defined($s1));

##########################  2  ####################################
# test v1 trap
$res = $s1->trap(enterprise => $enterprise, agent=>$agent, generic=>$generic,[[sysContact, 0, "\@baynetworks.com"], [sysLocation, 0, "here"]] );
print("res is $res\n");
#ok(defined($res));
ok($res =~ /^0 but true/);

########################### 3 #############################
# test with wrong trapoid
# No acknowledgement....so I can't detect any failure.
#$res = $s1->trap(trapoid=>'coldStt',[[sysContact, 0, "\@baynetworks.com"], [sysLocation, 0, "here"]] );
#print("res is $res\n");
#ok($res =~ /^0 but true/);
#########################################################

#                      V2 testing
########################## 4 ############################
# Fire up a v2 trap session.
my $s2 =
    new SNMP::Session (Version=>2, DestHost=>$agent_host,Community=>$comm2,RemotePort=>$trap_port);
ok(defined($s2));
#########################  5  ###########################
# test v2 trap
$res = $s2->trap(uptime=>200, trapoid=>'coldStart',[[sysContact, 0, "\@baynetworks.com"], [sysLocation, 0, "here"]] );
#print("res is $res\n");
ok($res =~ /^0 but true/);
##########################  6  ##########################
# no trapoid and uptime given. Should take defaults...
my $ret = $s2->trap([[sysContact, 0, "\@baynetworks.com"], [sysLocation, 0, "here"]] );
#print("res is $ret\n");
ok(defined($ret));

#########################################################

#                     v3 testing
########################  7  ############################
# Fire up a v3 trap session.
my $s3 = new SNMP::Session(Version=>3, DestHost=> $agent_host, RemotePort=>$trap_port);
ok(defined($s3));

########################  8  ###########################
$res = $s3->inform(uptime=>111,trapoid=>'coldStart',[[sysContact, 0, "\@baynetworks.com"], [sysLocation, 0, "RML"]] );
print("res is $res\n");
#ok(defined($res));
ok($res =~ /^0 but true/);

##############################################

    snmptest_cleanup();
