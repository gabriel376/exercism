package Accumulate;
use strict;
use warnings;
use Exporter qw<import>;
our @EXPORT_OK = qw<accumulate>;

sub accumulate {
  my ($list, $sub) = @_;
  my @accumulated;

  for (@$list) {
    push(@accumulated, &$sub($_));
  }

  return \@accumulated;
}

1;
