from random import randint

fichier = open("../test/graphe.txt", "w")
esp = " "
rl = "\n"
nb_node = randint(2, 15)
nb_vertex = randint(1, nb_node * (nb_node - 1) /2 )
l_vertex = []
fichier.write(str(nb_node) + esp + str(nb_vertex) + rl)
while len(l_vertex) < nb_vertex:
    n1, n2 = randint(1, nb_node), randint(1, nb_node)
    if (n1, n2) not in l_vertex and n1 != n2:
        l_vertex.append((n1, n2))

for k in range(len(l_vertex)):
    n1, n2 = l_vertex[k]
    fichier.write(str(n1) + esp + str(n2) + rl)
fichier.close()
