#!/bin/sh

# delete paralog (need to modify the file name in cpp)
g++ Delete_paralog.cpp -o delete_paralog.out
./delete_paralog.out

# change format
cat resultDBm8.out | awk {'print $1 "\t" $2 "\t" $11'} > IDevalue

# sort
sort -k 3 -g IDevalue > evaluesort

# replace +00 with -309 (the less # of evalue(>0) is 2.225074e-308)
# replace - with \t
sed -i 's/+00/-309/g' evaluesort
sed -i 's/-/\t/g' evaluesort

# change format 
cat evaluesort | awk {'print $1 "\t" $2 "\t" $4'} > IDevalue

# delete the bounding connection (store the pair with less evalue)
g++ permu.cpp -o permu.out
./permu.out

sort -k 1 -k 3n IDevalue_permu.out > permu_sort
cat permu_sort | awk {'print $3 "\t" $1 "\t" $2'} > permu_sort1
uniq -f 1 permu_sort1 > IDevalue_unique
cat IDevalue_unique | awk {'print $2 "\t" $3 "\t" $1'} > permu_sort2

# sort by evalue
sort -k 3rn permu_sort2 > finalresult




