#!/usr/bin/env perl

=pod
  Дебаг для Си.
  Запускается командой:
  ./strDebugRem.pl --file=test.c
  
  Дебаг удаляет все строки, созданные прогой strDebug.pl: printf("str 45\n");
=cut

use strict;
use warnings;
use Getopt::Long;

my $data;
my $remove;
my $lines=0;
my @arr;
my $fd;

GetOptions(
  "add=s" => \$data,
  "rem=s" => \$remove,
) or die("Error in command line arguments\n");



if($data){

  die("file not included\n") unless $data;

  open $fd, '<', $data or die("error while openning '$data'\n");
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

} elsif ($remove){

  die("file not included\n") unless $remove;

  open $fd, '<', $remove or die("error while openning '$remove'\n");
  while(<$fd>) {
    $lines++;
    if ($_ =~ s/^([\s\t]*)str;[\s\t]*$//) {
      $_ = ($1 ? $1 : '') . qq{};
    } elsif ($_ =~ s/^([\s\t]*)printf\("str\s\d{1,}(.+)\n?//) {
      $_ = ($1 ? $1 : '') . "" ;
    }
    push(@arr, $_);
  }
  close $fd;

  open $fd, '>', $remove or die("error while writing '$remove'\n");
  for(@arr) {
    print $fd $_;
  }
  close $fd;

}