use strict;
use warnings;

use Class::Struct;
use Data::Dumper;

# my $digit = 100;
# $digit = \$digit;
# my $right;
# my $left;
struct( $s => '$', my $a => '@', h => '%', c => 'My_Other_Class' );
print"$a\n";

# my @arr = (1,2,3);
# my %hash = (
#     my $digit => 0,
#     my $right => \%hash
#     my $left => \%hash,
# );

# my $scalarref;
# $scalarref = \%hash;

# print"@arr\n";
# print Dumper \%hash;
# print Dumper \$scalarref;
# print"$scalarref\n";