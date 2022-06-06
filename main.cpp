#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol124;

/*
You may serialize the following tree:
    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
*/

tuple<Node *>
testFixture1()
{
  auto root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(5);
  return make_tuple(root);
}

void test1()
{
  auto f = testFixture1();
  Codec sol;

  auto s = sol.serialize(get<0>(f));

  auto root = sol.deserialize(s);

  cout << "Expect to see 5: " << root->right->right->val << endl;
  
}

void call(istringstream &in)
{
  string val;
  in >> val;
  cout << val;
}

void testistringStream()
{
  auto in = istringstream();
  call(in);
}

main()
{
  test1();
  // testistringStream();
  return 0;
}