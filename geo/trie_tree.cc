#include <trie_tree.h>


namespace geo 
{
std::string base = "0123456789bcdefghjkmnpqrstuvwxyz";

int findIndex(char c)
{
   if (c >= '0' && c <= '9') return c - '0';
   if (c >= 'b' && c <= 'h') return c - 'b' + 10;
   if (c >= 'j' && c <= 'k') return c - 'j' + 17;
   if (c >= 'm' && c <= 'n') return c - 'm' + 19;
   if (c >= 'p' && c <= 'z') return c - 'p' + 21;
   return -1;
}

TrieTree::TrieTree() : root_(new Node(' '))
{
}

TrieTree::~TrieTree() 
{
  //delete all
}

bool TrieTree::insert(std::string code)
{
  Node* parent = root_;
  for (int i = 0; i < code.size(); i++)
  {
      Node*& current = parent->children[findIndex(code[i])];
      if (current == nullptr)
      {
         current = new Node(code[i]); 
      }
      current->num++;
      parent = current;
  }
  return true;
}

bool TrieTree::search(std::string code)
{
  Node* parent = root_;
  for (int i = 0; i < code.size(); i++)
  {
      Node* current = parent->children[findIndex(code[i])];
      if (current == nullptr) return false;
      parent = current;
  }
  return true;
}

int TrieTree::findNumOfCode(std::string code)
{
  Node* parent = root_;
  for (int i = 0; i< code.size(); i++)
  {
     Node* current = parent->children[findIndex(code[i])];
     if (current == nullptr) return -1;
     parent = current;
  }
  
  return parent->num;
}
}

