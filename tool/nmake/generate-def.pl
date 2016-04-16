#!/usr/bin/perl -W

use warnings;
use strict;
use File::Find;

my @function_names = ();
sub extract_functions {
  open( FILE, $_ ) or die "can't open $_";
  local $/ = undef;
  my $lines = <FILE>;
  
  my @matches = $lines =~ /(.*)\n\(.*\);$/mg; 
  close( FILE );
  
  foreach my $match (@matches){
    push( @function_names, $match )  }
}

sub process_headers {
  my $filename = $_;  
  
  if( $filename =~ /.*.h/ ){
    extract_functions( $filename );
  }
}
open( DEF, ">./woodpile.def" ) or die "can't open woodpile.def";find( \&process_headers, "../../include/woodpile" );
print DEF "LIBRARY    woodpile\n\nEXPORTS\n";

my $i = 1;
foreach my $function_name (@function_names){
  print DEF "  $function_name @" . $i . "\n";
  $i++;
}close( DEF );