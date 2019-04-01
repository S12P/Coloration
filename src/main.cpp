#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

string File = "../test/test.txt";


int search_max_degree(int nb_node, int tab[]){
        int max = 0;
        int indice_max = 0;
        for (int i = 0; i < nb_node; i++) {
                if (max < tab[i]) {
                        max = tab[i];
                        indice_max = i;
                }
        }
        return(indice_max);
}


int main(){
        int nb_node = 0;
        int nb_vertex = 0;
        ifstream fichier(File, ios::in);
        fichier >> nb_node >> nb_vertex;


        int color_t = nb_node;
        int a, b, i, j;
        int mat[nb_node][nb_node];
        int mat_o[nb_node][nb_node];
        vector<vector<int> > v(nb_node);
        int color[nb_node];
        int degree[nb_node];
        bool e = false;
        int p = 0;


        for (i = 0; i < nb_node; i++) {
                color[i] = 0;
                for (j = 0; j < nb_node; j++) {
                        mat[i][j] = 0;
                        mat_o[i][j] = 0;
                }
        }
        for (i = 0; i < nb_vertex; i++) {
                fichier >> a >> b;
                a--;
                b--;
                mat[a][b] = 1;
                mat[b][a] = 1;
                mat_o[a][b] = 1;
                mat_o[b][a] = 1;
        }
        fichier.close();


        int somme, n;

        while ( !e) {


                for (int i = 0; i < nb_node; i++) {
                        somme = 0;
                        for (int j = 0; j < nb_node; j++) {
                                somme += mat[i][j];

                        }

                        degree[i] = somme;
                }
                int n = search_max_degree(nb_node, degree); // indice du noeud au degre max


                color_t = nb_node;
                sort(v[n].begin(), v[n].end());
                for (i = v[n].size() - 1; i >= 0 ; i--) {
                        if (v[n][i] == color_t) {
                          color_t--;
                        }
                }

                color[n] = color_t;
                for (i = 0; i < nb_node; i++) {
                        if (mat_o[n][i] == 1) {
                                v[i].push_back(color_t);
                        }
                }
                e = true;
                for (i = 0; i < nb_node; i++) {
                        if (mat[n][i] == 1) {
                                mat[n][i] = 0;
                                mat[i][n] = 0;
                        }
                }
                for (int i = 0; i < nb_node && e; i++) {
                        for (int j = 0; j < nb_node; j++) {
                                if (mat[i][j] != 0) {
                                        e = false;
                                }
                        }
                }

        }

        ofstream fichier_out(File, ios::app);
        for (i = 0; i < nb_node; i++){
          fichier_out << i + 1 << " " << color[i] << endl;
        }
        fichier_out.close();
        system("python3 graphe.py");
        return 0;
}
