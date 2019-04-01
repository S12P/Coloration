import networkx as nx
import matplotlib.pyplot as plt
import os
import sys

file = sys.argv[1]
print(file)

G = nx.Graph()
l_vertex = []
l_node = []
color_ = []
mon_fichier = open(file, "r")
contenu = mon_fichier.read().split()
nb_node = int(contenu[0])
nb_vertex = int(contenu[1])
for i in range(2*(nb_vertex + 1), len(contenu), 2):
    G.add_node(int(contenu[i]))
    color_.append(int(contenu[i+1]))
for i in range(2, 2*(nb_vertex + 1), 2):
    G.add_edge(int(contenu[i]), int(contenu[i+1]))

mon_fichier.close()


nx.draw(G, with_labels=True, node_color = color_)
plt.show()
