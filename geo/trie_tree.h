#ifndef TRIE_TREE_H_
#define TRIE_TREE_H_

#include <vector>
#include <string>

namespace geo 
{

struct Node
{
   char val;
   int  num;
   std::vector<Node*> children;
   Node(char v) : val(v), num(0) 
   {
      for (int i = 0; i < 32; i++)
         children.push_back(nullptr);
   }
};


class TrieTree
{
public:
   TrieTree();
   ~TrieTree();
   bool insert(std::string code);
   bool search(std::string code);
   int  findNumOfCode(std::string code);
   
private:
   Node* root_;


};
}
#endif
