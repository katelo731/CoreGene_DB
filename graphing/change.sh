# take level4 as an example

join finalresult_ID graph_node2comm_level4 > dataset_level4
cat dataset_level4 | awk {'print $2 "\t" $3'} > dataset_level4_v1
sed -i 's/|/\t/g' dataset_level4_v1

# input file :
#
# 0    Cop|100      (finalresult_ID)  
# 0    2335         (graph_node2comm_level4)
#
# output file :
#
# Cop     100     2335
#
