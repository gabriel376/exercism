package Accumulate;
use strict;
use warnings;
use Exporter qw<import>;
our @EXPORT_OK = qw<accumulate>;

sub accumulate {
  my ($list, $sub) = @_;
  my @accumulated;

  push @accumulated, $sub->($_) for @$list;

  return \@accumulated;
}

1;
