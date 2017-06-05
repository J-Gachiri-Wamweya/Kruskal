#include "DisjointSets.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;




int main(int argc, char *argv[]) {
  int n;
  
  n = atoi(argv[1]);
  DisjointSets D(n);
   for (int i=0; i < n; i++){
    D.AddSet (i);
  }
   for (int j=1; j < n; j++){
    D.MergeSets (0,j);
    }
   D.printStats();
  return 0;
  
  
	
}

