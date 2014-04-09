#!/usr/bin/perl

@a = (1);
for ($i = 1; $i<=100; $i++) {
  $a[$i] = $a[$i-1] * $i;
}
$t = <>;
while ($t--) {
  $n = <>;
  printf("%s\n", $a[$n]);
}
