# [IBM Ponder This March 2024 Challenge](https://research.ibm.com/haifa/ponderthis/challenges/March2024.html)

My solution stores a precomputed bitset which is true at positions where the index is a prime number and false otherwise. Values are calculated with a (decently) fast prime sieve. Going up to 2e11 takes up ~20GB space as a binary file.

Ouput for the inital solution in ~30s on a single core:
```
-> Finding a0 for n: 1000
-> Largest sequence so far: 1 at a0: 1
-> Largest sequence so far: 2 at a0: 8
-> Largest sequence so far: 4 at a0: 9
-> Largest sequence so far: 7 at a0: 15
-> Largest sequence so far: 10 at a0: 24
-> Largest sequence so far: 13 at a0: 90
-> Largest sequence so far: 16 at a0: 105
-> Largest sequence so far: 22 at a0: 114
-> Largest sequence so far: 28 at a0: 225
-> Largest sequence so far: 34 at a0: 264
-> Largest sequence so far: 46 at a0: 300
-> Largest sequence so far: 88 at a0: 945
-> Largest sequence so far: 100 at a0: 5349
-> Largest sequence so far: 103 at a0: 7035
-> Largest sequence so far: 124 at a0: 11739
-> Largest sequence so far: 157 at a0: 17280
-> Largest sequence so far: 247 at a0: 35475
-> Largest sequence so far: 274 at a0: 46914
-> Largest sequence so far: 283 at a0: 190365
-> Largest sequence so far: 331 at a0: 351645
-> Largest sequence so far: 430 at a0: 603054
-> Largest sequence so far: 466 at a0: 1209900
-> Largest sequence so far: 478 at a0: 3146220
-> Largest sequence so far: 562 at a0: 3279864
-> Largest sequence so far: 682 at a0: 6407664
-> Largest sequence so far: 892 at a0: 26447649
-> Found a0: 115192665
```

The bonus solution took about 15 mins on a single core.