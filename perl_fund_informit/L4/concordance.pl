#!/usr/bin/perl
use strict;
use warnings;

my $speech = <<'END_OF_TEXT';
Let freedom ring from Stone Mountain of Georgia. Let freedom ring from Lookout Mountain of Tennessee.
Let freedom ring from every hill and molehill of Mississippi. From every mountainside, let freedom ring.
And when this happens, when we allow freedom ring, when we let it ring from every village and every hamlet, from every state and
every city, we will be able to speed up that day when all of God's children, black men and white men, Jews and Gentiles, Protestants
and Catholics, will be able to join hands and sing in the words of the old Negro spiritual:
Free at last! Free at last! Thank God Almighty, we are free at last!
END_OF_TEXT

my %word_count;

for my $word ( split ' ', $speech )
{
  $word_count{$word}++;                    # $word_count{$word} = $word_count{$word} + 1;
}

for my $word (sort { $word_count{$b} <=> $word_count{$a} } keys %word_count)
{
  if ( $word_count{$word} <= 3)
  {
    last;
  }
  print "$word: $word_count{$word}\n";
}
