use Getopt::Long;
#require
 'Array_Utils.pm';
my $device="";
my @output="";
my $shouldIPrint=0;
my @stuffToPrint="";
my @previousStuffToPrint="";
GetOptions ("s=s" => \$device);
if($device){
$device="-s ".$device;
}
print "Rooting the device...\n";
#`adb $device root`;
print "Waiting for adb to reboot...";
`adb $device wait-for-device`;
print " Done.\n";
sleep(1);
@output = `adb $device wait-for-device shell dumpsys SurfaceFlinger`;
80-NP925-1 C
Confidential and Proprietary – Qualcomm Technologies, Inc.
MAY CONTAIN U.S. AND INTERNATIONAL EXPORT CONTROLLED INFORMATION
25
Android Display Debug Guide
 UI Corruption and Flicker
foreach (@output){
if(/^Hardware Composer state/){
$shouldIPrint=1;
}elsif(/^Overlay State/){
$shouldIPrint=0;
}
if($shouldIPrint){
#print $_;
push(@previousStuffToPrint, $_);
}
}
my $shouldIPrint=0;
while (1){
@output = `adb $device wait-for-device shell dumpsys
SurfaceFlinger`;
foreach (@output){
if(/^Hardware Composer state/){
$shouldIPrint=1;
#}elsif(/^Pipes/){
}elsif(/^================/){
#push(@stuffToPrint, $_);
$shouldIPrint=0;
}
if($shouldIPrint){
#print $_;
push(@stuffToPrint, $_);
}
#if(/Pipes used=/){
#
 push(@stuffToPrint, $_);
#}
}
#
 if (array_diff(@previousStuffToPrint, @stuffToPrint)){
system $^O eq 'MSWin32' ? 'cls' : 'clear';
print @stuffToPrint;
#
 @previousStuffToPrint = @stuffToPrint;
@stuffToPrint="";
sleep undef, undef, undef, 0.1;
#
 }
}
