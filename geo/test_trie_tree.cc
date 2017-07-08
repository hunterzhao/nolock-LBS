#include <assert.h>
#include <stdio.h>
#include "trie_tree.h"

using namespace geo;
int main()
{
   TrieTree tree;
   assert(tree.insert("wx4g") == true);
   assert(tree.insert("wx4h") == true);
   assert(tree.search("wx4g") == true);
   assert(tree.findNumOfCode("wx") == 2);
   assert(tree.findNumOfCode("x") == -1);
   printf("%d\n", tree.findNumOfCode("wx4g88888888"));   
}
