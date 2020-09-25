# Optimized-WalkSat-and-Resolution-Proving
Project: Fast Implementations of WalkSAT and Resolution Proving
Environment:
  OS: Windows 10, 64-bit, 8GB RAM
  Processor: intel core i5 , CPU at 1.80 GHz
  Used MinGW to simulate terminal like environment on Windows, as I do not have access to Linux machine.
Program Structure
  • Generate_random_KCNF.py
      o Generates a random CNF clause and outputs in miniSAT input format.
  • walksat folder:
      o contains program for faster implementation of WALKSAT in C++
  ▪ use “$make all” command to compile the code when inside the folder.
  ▪ Use “$./walkSAT (filename)” to run, filename can be generated using generate_random_KCNF.py file.
  • Resolution folder:
      o Resolution Proving implemented in C++
  ▪ use “$make all” command to compile the code when inside the folder.
  ▪ Use “$./resolution (filename)” to run, filename can be generated using generate_random_KCNF.py file.
Note: Results can be reproduced typing above commands in respective folder.

Implement an efficient version of both WalkSAT, and a propositional theorem prover based on resolution. They should both use the minisat input format. Using the same set of test examples, compare the performance of your two algorithms against the Python version of WalkSAT (in the textbook code in logic.py) and minisat. Use randomly generated k-CNF sentences as input (these are described in the textbook in the first full paragraph of page 264).

The markers will be looking for the following:

Implementation of WalkSAT using an efficient programming language, such as C++ (Python is probably not efficient enough).
Implementation of a propositional theorem prover based on resolution using an efficient programming language, such as C++ (Python is probably not efficient enough).
Speedy solving times: not only should you use an efficient programming language, but you should use efficient data structures and algorithms, plus anything else you can think of to make this run efficiently.
Randomly generated k-CNF expressions. 
Note that this part of your project could probably be done in Python, as efficiency is not as important as it is for the main solvers.
A written report of at least one page that explains your programs, the techniques they use, the results of your comparisons, etc. This should include graphs and tables of relevant data.
