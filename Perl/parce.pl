use strict;
use warnings;

my $string = '1 2 3 4 5 6 7 8 9';
my @arr = split(/ /, $string);
print"@arr\n";

my @desc = splice(@arr, 4, scalar @arr);
print"@desc\n";

my $desc = join(':', @desc);
print"$desc\n";
