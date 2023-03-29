use strict;
use warnings;
use Getopt::Long;

my $data;
my $lines=0;
my @arr;

GetOptions(
  "file=s"   => \$data,
) or die("Error in command line arguments\n");

die("file not included\n") unless $data;

open my $fd, '<', $data or die("error while openning '$data'\n");
while(<$fd>) {
  $lines++;
  $_ =~ s/^([\s\t]+)str;[\s\t]*$/$1 \bprintf("str $lines\\n");\n/;
  push(@arr, $_);
}
close $fd;

open $fd, '>', $data or die("error while writing '$data'\n");
for(@arr) {
  print $fd $_;
}
close $fd;