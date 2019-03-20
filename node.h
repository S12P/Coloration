#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node {
public:
  node();
  int get_degree();
  int get_color();
  int get_number_node();

private:
  int number_node;
  int color;
  vector<node> neighbour;
  int degree;
};















#endif
