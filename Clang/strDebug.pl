#!/usr/bin/env perl

=pod
  Дебаг для Си.
  Запускается командой:
  ./strDebug.pl --file=test.c
  
  Пишешь на пустой строке:
  str;
  и дебаг меняет его на:
  printf("str 8\n");
  где "8" - номер строки.
  Если переместить такого вида printf() на другую строку,
  то номер печатаемой строки поменяется на актуальный.
  После номера строки позволительно печатать любые символы,
  например комментарий:
  printf("str 14: объясняю, как работает дебаг\n");
  printf("str 15всё ещё объясняю, как работает дебаг\n");
  Дебаг создавался, чтобы видеть, в какие условия программа
  проваливается, а в какие - нет.
=cut

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
  if ($_ =~ s/^([\s\t]*)str;[\s\t]*$//) {
    $_ .= ($1 ? $1 : '') . qq{printf("str $lines\\n");\n};
  } elsif ($_ =~ s/^([\s\t]*)printf\("str\s\d{1,}(.+)\n?//) {
    $_ .= ($1 ? $1 : '') . qq{printf("str $lines} . $2 . "\n";
  }
  push(@arr, $_);
}
close $fd;

open $fd, '>', $data or die("error while writing '$data'\n");
for(@arr) {
  print $fd $_;
}
close $fd;