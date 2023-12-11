#!/usr/bin/env perl

use strict;
# use warnings;
use Getopt::Long;
use Date::Parse;

my $fileName;
my $pattern;
my $lines=0;
my $prevDate;
my @arr;

GetOptions(
  "file=s"   => \$fileName,
  "pattern=s"   => \$pattern,
) or die("Error in command line arguments\n");
die("file not included\n") unless $fileName;
die ("pattern not included\n") unless $pattern;

open my $fd, '<', $fileName or die("error while openning '$fileName'\n");
while(<$fd>) {
    # if ($_ =~ $pattern) {
    if ($_ =~ /^(\d{4}-\d{2}-\d{2}).(\d{2}:\d{2}:\d{2})/ && $_ =~ $pattern) {

        my $currDate = $1 . 'T' . $2;

        if (!$prevDate) {
            $prevDate = $currDate;
        } else {
            my $dateDiff = str2time($currDate) - str2time($prevDate);

            my $dateDiffss = $dateDiff % 60;
            my $dateDiffmm = $dateDiff / 60 % 60;
            my $dateDiffhh = $dateDiff / 3600 % 24;
            my $dateDiffdd = $dateDiff / 86400 % 86400;

            printf "\t=== next log appear in %d dd, %d hh, %d mm, %d ss ===\n\n", $dateDiffdd, $dateDiffhh, $dateDiffmm, $dateDiffss;
            
            $prevDate = $currDate;
        }

        print "$_";
    }
}
close $fd;

=BEGIN

^(\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2})

1995-01-24T09:08:17.1823213

2023-07-25 00:08:50,444 INFO AntaresVision.Tracking.Data.ItemDetail IP:[192.168.1.152] Host:[STATION-LABEL-2] - Deleting items details if empty END
    + 4 часа 20 минут
2023-07-25 00:13:10,444 INFO AntaresVision.Tracking.Data.ItemDetail IP:[192.168.1.152] Host:[STATION-LABEL-2] - Deleting items details if empty END
    + 1 часа 10 минут
2023-07-25 00:14:20,444 INFO AntaresVision.Tracking.Data.ItemDetail IP:[192.168.1.152] Host:[STATION-LABEL-2] - Deleting items details if empty END

=END