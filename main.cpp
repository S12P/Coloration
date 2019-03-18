#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

string File = "test.txt";

int main(){
  int nb_node = 0;
  int nb_vertex = 0;
  ifstream fichier(File, ios::in);
  fichier >> nb_node >> nb_vertex;
  int a, b, i, j;
  int mat[nb_node][nb_node];
  for (i = 0; i < nb_node; i++){
    for (j = 0; j < nb_node; j++){
      mat[i][j] = 0;
    }
  }
  for (i = 0; i < nb_vertex; i++){
    fichier >> a >> b;
    a--;
    b--;
    mat[a][b] = 1;
    mat[b][a] = 1;
  }
  fichier.close();
  for (i = 0; i < nb_node; i++){
    for (j = 0; j < nb_node; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  

}
