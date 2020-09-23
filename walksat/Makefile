all: walksat_main.o optimized_WALKSAT.o
	g++ -o walkSAT walksat_main.o optimized_WALKSAT.o

walksat_main.o: walksat_main.cpp optimized_WALKSAT.h
	g++ -c walksat_main.cpp

optimized_WALKSAT.o: optimized_WALKSAT.cpp optimized_WALKSAT.h
	g++ -c optimized_WALKSAT.cpp

clean:
	rm -f *.o walkSAT