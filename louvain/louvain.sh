#!/bin/sh

# make instr
make -f Makefile

# 1. Conversion from a text format (each line contains a triple "src dest w")
./convert -i finalresult_intnode -o graph.bin -w graph.weights

# 2. Computes communities with a specified quality function and displays hierarchical tree:
./louvain graph.bin -l -1 -q id_qual -w graph.weights > graph.tree

# 3. Displays information on the tree structure (number of hierarchical levels and nodes per level):
./hierarchy graph.tree

#    Displays the belonging of nodes to communities for a given level of the tree:
./hierarchy graph.tree -l 0 > graph_node2comm_level0
./hierarchy graph.tree -l 1 > graph_node2comm_level1
./hierarchy graph.tree -l 2 > graph_node2comm_level2
./hierarchy graph.tree -l 3 > graph_node2comm_level3
./hierarchy graph.tree -l 4 > graph_node2comm_level4

# 4. To display the X relational matrix for a given level of the tree:
./matrix graph.tree -l 0 > graph_X_level0
./matrix graph.tree -l 1 > graph_X_level1
./matrix graph.tree -l 2 > graph_X_level2
./matrix graph.tree -l 3 > graph_X_level3
./matrix graph.tree -l 4 > graph_X_level4



