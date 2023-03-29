#!/usr/bin/env perl

use strict;
use warnings;
use Getopt::Long;

my $fileName;
my $lines=0;
my @arr;

GetOptions(
  "file=s"   => \$fileName,
) or die("Error in command line arguments\n");

die("file not included\n") unless $fileName;

open my $fd, '<', $fileName or die("error while openning '$fileName'\n");
while(<$fd>) {
  $lines++;
  if ($_ =~ s/^([\s\t\w\(\"]*)str\s\w{1,}.+//) {
    $_ .= ($1 ? $1 : '') . qq{str $lines\n};
  }
  push(@arr, $_);
}
close $fd;

open $fd, '>', $fileName or die("error while writing '$fileName'\n");
for(@arr) {
  print $fd $_;
}
close $fd;