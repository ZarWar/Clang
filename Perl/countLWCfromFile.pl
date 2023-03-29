use warnings;

my ($linesTotal, $wordsTotal, $charsTotal)=(0, 0, 0);
my $fileCount=0;

for my $filename(@ARGV)
{
  unless(open $fd, '<', $filename)
  {
    warn "$0: Невозможно открыть файл «$filename»: $!\n";
    next;
  }

  my ($lines, $words, $chars)=(1, 0, 0);

  $fileCount++;

  my $flag=0;
  my $c;

  while(read $fd, $c, 1)
  {
    $chars++;

    $lines++ if $c eq "\n";

    if($c=~m/\s/)
    {
      $words++ if $flag;
      $flag=0;
    }
    else
    {
      $flag=1;
    }
  }

  $linesTotal+=$lines;
  $wordsTotal+=$words;
  $charsTotal+=$chars;

  print "\nFilename: $filename\nLines:    $lines\nWords:    $words\nChars:    $chars\n";
  close $fd;
}

print "\nВсего\tL's: $linesTotal\tW's: $wordsTotal\tC's: $charsTotal\n" if $fileCount>1;