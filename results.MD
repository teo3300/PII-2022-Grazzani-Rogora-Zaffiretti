# Risultati test

Tests executed on FPGA **xc7k160tfbv484-2**


|Nome|Descrizione|Tipo (Syn o Impl)|Vitis Directives|LUT|FF|Target Clock(ns)|Max  Target Clock reachable (ns)|
|----|-----------|:---------------:|----------------|:-:|:-:|:-------------:|:------------------------------:|
|Reference|Test from ascon-hardware repo(VHDL post implementation)| impl| x | 1459 | 666 | 10 | fixed to 10|
|Standard Version|debloat of unusefull ports(our baseline)|syn|x|9213|3654|15 |15|
|||impl|x|4590|3438|10 |8.5|
|Standard Version|Permutations.h directives |syn|INLINE recoursive on P6, P8, P12 |42969|5229|10 |3|
|||impl|"""|11361|4984|10 |7.5|
|Standard Version|ROUND.h directives |syn|PIPELINE on ROR function |11492|3420|13 |13|
|||impl|""" |3701|3147|10 |8.4|
|Pipelined permutations|Permutations are pipelined so P8->P6 and P12->P8 |syn|x |9213|3654|3420|15 |15|
|||impl|x |4590|3438|10 |8.5|

