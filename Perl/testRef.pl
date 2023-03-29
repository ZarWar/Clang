use strict;
use warnings;

my $foo = "boot";
my @arr = (1,2,3);
my $bar = \$foo;
my $var = \@arr;

print("$$bar\n");
print("@$var\n");
print("@arr\n");

say $foo "out";