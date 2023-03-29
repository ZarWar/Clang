sub a {
    $i = 0;
    return sub {++$i};
};
$a = a;
print $a->() . "\n";
print $a->() . "\n"



__END__
sub a {
    $i = 0;
    return sub {
        return ++$i;
    };
};