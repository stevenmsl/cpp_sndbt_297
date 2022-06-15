#include "solution.h"
#include "util.h"

#include <string>
#include <sstream>

using namespace sol124;
using namespace std;

/*takeaways
  - ok was confused when the deseraliztion will
    terminate.
    - the string must be ended with "^ ^ "
      to represent the left and right children
      of the rightmost leaf node
    - we don't rely on when we have consumed
      the entire input stream, which we never
      will as there is an extra space at the
      end of the string

*/
string Codec::serialize(Node *root)
{
  auto out = ostringstream();
  _serialize(root, out);
  return out.str();
}

Node *Codec::deserialize(string data)
{
  auto in = istringstream(data);

  return _deserialize(in);
}

void Codec::_serialize(Node *root, ostringstream &out)
{
  if (root == nullptr)
  {
    /* indicate an empty node
       - the separate needs to be a space char because we
         are using istringstream to parse the tokens
         later when deserializing
    */
    out << "^ ";
    return;
  }
  out << root->val << " ";
  _serialize(root->left, out);
  _serialize(root->right, out);
}
Node *Codec::_deserialize(istringstream &in)
{

  string val;
  in >> val;
  /* a leaf node */
  if (val == "^")
    return nullptr;

  auto root = new Node(stoi(val));

  root->left = _deserialize(in);
  root->right = _deserialize(in);

  return root;
}
