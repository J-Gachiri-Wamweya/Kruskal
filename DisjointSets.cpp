#ifndef _DISJOINTSETS_CPP
#define _DISJOINTSETS_CPP

//DisjointSets.cpp
#include "DisjointSets.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of the dictionary ADT as a fixed-size hash table with
// chaining

DisjointSets::DisjointSets(int n) {
  nodes = n;
  arraySet = new ChainNode*[nodes](); // Parentheses initialize to all NULL
  for (int i = 0; i < n; i++){
    arraySet[i]= NULL;
  }
  //number = 0;

  // Initialize the array of counters for probe statistics
  //probes_stats = new int[MAX_STATS]();
}
DisjointSets::~DisjointSets() {
  for (int i=0; i< nodes; i++) {
    // Delete the chains from each table entry...
    ChainNode *head = arraySet[i];
    while (head!=NULL) {
      ChainNode *temp = head;
      head = head->next;
      // delete temp->key;  // Each PuzzleState is a key exactly once.
      // Don't delete temp->data here, to avoid double deletions.
      delete temp;
    }
  }
  // Delete the table itself
  delete [] arraySet;
}

void DisjointSets::AddSet(int u) {
  arraySet[u] = new ChainNode();
  arraySet[u]->Node = u;
  arraySet[u]->size = 1;
  arraySet[u]->set = arraySet[u];
  arraySet[u]->next = NULL;
}

int DisjointSets::FindSet(int u) {
  ChainNode *temp = arraySet[u]->set;
  int ret = temp->Node;
  return ret;
}
  
void DisjointSets::printStats() {
   for (int i=0; i< nodes; i++) {
    // Delete the chains from each table entry...
    // ChainNode *temp = 
    std::cout << "Node = " <<arraySet[i]->Node << ", Size = " << arraySet[i]->size << std::endl;
    }
}
void DisjointSets::MergeSets(int u, int v) {
ChainNode *temp = new ChainNode();
 if (arraySet[u]->set->size < arraySet[v]->set->size){
   temp = arraySet[u]->set;
   while(temp->next){
     temp->set = arraySet[v]->set;
     temp = temp->next;
   }
   //temp->set = arraySet[v]->set;
    temp = arraySet[v]->set;
   while(temp->next){
         temp = temp->next;
   }
   temp->next = arraySet[u]->set;
   arraySet[v]->size = arraySet[v]->size + arraySet[u]->size;
 }
 else {
   temp = arraySet[v]->set;
   while(temp->next){
     temp->set = arraySet[u]->set;
     temp = temp->next;
   }
   //temp->set = arraySet[u]->set;
    temp = arraySet[u]->set;
   while(temp->next){
         temp = temp->next;
   }
   temp->next = arraySet[v]->set;
   arraySet[u]->size = arraySet[v]->size + arraySet[u]->size;
 }
 
}
#endif 
/*
int FixedChainHashDict::hash(string keyID) {
  int h=0;
  for (int i= (int)keyID.length()-1; i>=0; i--) {
    h = (keyID[i] + 31*h) % size;
  }
// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Hashing " << keyID << " to " << h << std::endl;
#endif
// End of "DO NOT CHANGE" Block
  return h;
}

bool FixedChainHashDict::find(PuzzleState *key, PuzzleState *&pred) {
  // Returns true iff the key is found.
  // Returns the associated value in pred

  // Be sure not to keep calling getUniqId() over and over again!

  // TODO:  Put your code here!  Remember to update probes_stats, too.
  int probes = 0;  
  
  
  string KEYID = key->getUniqId();
  int p = hash (KEYID)%size;
  
  ChainNode *temppred;
  if (table[p] == NULL){
       probes_stats[probes]++;
      return false;
    }
    
    else {
	
	if (table[p]->keyID == KEYID){
	  pred = table[p]->data;
	  probes_stats[probes]++;
	  
	  return true;
	}
	else {
	  temppred = table[p];
	   probes++;
	  while (temppred->next != NULL){
	   
	    if (temppred->next->keyID == KEYID){
	      pred = temppred->next->data;
	      if (probes < MAX_STATS){
		probes_stats[probes]++;
	      }
	      return true;
	    }
	     probes++;
	    temppred = temppred->next;
	  }
	}
    }
   
    if (probes < MAX_STATS){
      probes_stats[probes]++;
    }
    return false;

}

// You may assume that no duplicate PuzzleState is ever added.
void FixedChainHashDict::add(PuzzleState *key, PuzzleState *pred) {
  string KEYID = key->getUniqId();
  ChainNode *temppred = new ChainNode();
  temppred->data = pred;
  temppred->keyID = KEYID;
  temppred->key=key;
  int p = hash (KEYID)%size;
  if (table[p] == NULL) {
    temppred->next = NULL;
    table[p]= temppred;
    number++;
    return;
  }
  else
    {
      temppred->next = table[p];
      table[p]=temppred;
      number++;
      return ;
      // TODO:  Put your code here!
    }
}

*/
