# Graph coloring

Graph coloring with the ant algorithm. You can use the algorithm with a random graph or a user-created file


<img src="https://raw.githubusercontent.com/S12P/graph_coloring/master/res/Figure_1.png" title="Exemple" />


Files
-----
    README.md
    
    src/main.cpp                                     Algorithm of graph coloring
    src/generateur_graphe.py                         Create a random graph
    src/graphe.py                                    Drawing colored graphs
    
Building on OS X with random graph
----------------
    
    $ clang++ main.cpp
    
    
Building on Linux with random graph
-----------------
    
    $ g++ main.cpp
    
Building on OS X with random graph
----------------
    
    $ clang++ main.cpp name_of_file
    
    
Building on Linux with random graph
-----------------
    
    $ g++ main.cpp name_of_file

File structure that describes the graph
-----------------
number_of_node  number_of_edges
at each line two nodes that are connected by an edge
