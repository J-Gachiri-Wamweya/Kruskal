disjoint: DisjointSets.cpp DisjointSets.hpp driver.cc
	g++ -Wall -g -c DisjointSets.cpp -o DisjointSets.o 
	g++ -Wall -g driver.cc DisjointSets.o -o disjoint

clean: 
	rm -f disjoint
	rm -f DisjointSets.o 
	rm -fr disjoint.dSYM/* 
	rmdir disjoint.dSYM
 
