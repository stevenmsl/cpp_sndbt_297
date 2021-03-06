
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <string>

using namespace std;
namespace sol124
{

  class Solution
  {
  private:
  public:
  };

  class Codec
  {
  private:
    void _serialize(Node *root, ostringstream &out);
    Node *_deserialize(istringstream &in);

  public:
    string serialize(Node *root);
    Node *deserialize(string data);
  };

}
#endif