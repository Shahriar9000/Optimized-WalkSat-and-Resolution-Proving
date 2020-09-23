all: rsp_main.o resolution_proving.o
	g++ -o resolution rsp_main.o resolution_proving.o

rsp_main.o: rsp_main.cpp resolution_proving.h
	g++ -c rsp_main.cpp

resolution_proving.o: resolution_proving.cpp resolution_proving.h
	g++ -c resolution_proving.cpp

clean:
	rm -f *.o resolution