#!/usr/bin/perl -w

use strict;
use Math::Trig;

my $size = shift || 256;

for (my $i = 0; $i < $size; $i ++) {
        my $arg = pi * $i / ($size * 2);
        my $sin = int(-sin($arg) * 0x8000 - 0.5) & 0xffff;
        my $cos = int(-cos($arg) * 0x8000 - 0.5) & 0xffff;
        if (($i % 6) == 0) {
                print "   ";
        }
        print sprintf(" 0x%04x%04x,", $sin, $cos);
        if (($i % 6) == 5) {
                print "\n";
        }
} 
print "\n";
