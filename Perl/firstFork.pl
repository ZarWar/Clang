my $pid = fork();
unless ( defined $pid ) {
    print "Nevozmojno sozdat process!\n";
} else {
    if ($pid != 0) {
        print "V roditelskom procese. PID potomka: $pid\n";
    } else {
        print "V procese potomke\n";
        exit;
    }
}