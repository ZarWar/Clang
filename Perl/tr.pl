use strict;
use warnings;
use Data::Dumper;
use Getopt::Long;


my ($k, $r);
GetOptions ("k=i" => \$k,
            "r" => \$r)
or die("Error in command line arguments\n");

# my @arr = qw/aaa ccc bbb ddd eee/;

my @arr = <>;
@arr = sort { $a cmp $b } @arr;

if ($r) {
    for (my $i = 0; $i<@arr/2; $i++) {
        my $t  =  $arr[@arr -1 -$i];
        $arr[@arr -1 -$i]=$arr[$i];
        $arr[$i] = $t;
    }
}



if ($k) {
    my @sort;
    for (@arr) {
        my @splitted = split ' ', $_;
        my $cup = $splitted[ $k -1 ];
        push @sort, $cup;
    }
    @sort = sort { $a cmp $b } @sort;
    print "@sort\n";
}



print  Dumper \@arr,\$r;


# print "$k $r\n";