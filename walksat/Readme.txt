HOW TO RUN WALKSAT
-------------------

$ make all
$ ./SAT (filename)


Example:
---------

NEW (2023 MinGW):
g++ -Wall -g -O2 -c optimized_WALKSAT.cpp
g++ -Wall -g -O2 -c walksat_main.cpp
g++ -o SAT walksat_main.o optimized_WALKSAT.o -static-libgcc

OLD:

9000s@LAPTOP-GVVCJ91D MINGW64 ~/Documents/CMPT310/A5_project
$ mingw32-make all
g++ -c walksat_main.cpp
g++ -o SAT walksat_main.o optimized_WALKSAT.o

9000s@LAPTOP-GVVCJ91D MINGW64 ~/Documents/CMPT310/A5_project
$ ./SAT.exe 4_queens.txt
4_queens.txt
Faster Implementation of WalkSAT Solver using C++
Problem trying to solve: 4_queens.txt
Walk-SAT took 0 seconds to run.
1 0
2 1
3 0
4 0
5 0
6 0
7 0
8 1
9 1
10 0
11 0
12 0
13 0
14 0
15 1
16 0
Therefore solution = X1:2, X2:8, X3:9, X4:15,
