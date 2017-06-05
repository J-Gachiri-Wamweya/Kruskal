//DisjointSets.hpp
#ifndef _DISJIONTSETS_HPP
#define _DISJOINTSETS_HPP



// An implementation of a dictionary as a *resizable* hash table with
// chaining.

class DisjointSets {
public:
  DisjointSets(int n);
  ~DisjointSets();
  int FindSet(int u);
  void AddSet(int u);
  void MergeSets(int u, int v);
  void printStats();
  private:
    // You are allowed to change this if you need to, but be sure to
    // keep the structure where you compute key->getUniqId() ONCE
    // when you add a PuzzleState to the hash table, and then
    // store the UniqId string in keyID.  Then, when you do a
    // find, have a helper function that calls getUniqId() once
    // for the PuzzleState being searched for, and does all the
    // comparisons on strings.  This is much more efficient than
    // calling getUniqId() repeatedly.
    struct ChainNode {
      int  Node; // NULL indicates empty bucket.
      int  size; // Avoid recomputation of key's getUniqId()
      ChainNode *set;
      ChainNode *next;
    };
    
    // A pointer to the underlying hash table array, with elements
    // of type (ChainNode *).  We use an explicit pointer, instead of
    // declaring "ChainNode * table[size]" so you can use this code
    // to help you with the ResizeChainHashDict class.
    ChainNode **arraySet;
    int nodes; // size of the hash table array
    //int number; // how many items are currently in hash table

    // The next two variables are just to collect statistics on the
    // number of probes required for each call to find().
    //int *probes_stats; // probe_stats[i] should be how often i probes needed
    //const static int MAX_STATS = 20; // How big to make the array.

    //int hash(string keyID); // The hash function
  };

#endif

