#!/bin/bash

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#     TESTING ${1}            #"
echo "# # # # # # # # # # # # # # # # # # # #"

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#             COMPILING               #"
echo "# # # # # # # # # # # # # # # # # # # #"
make clean
make ALG=$1

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#           VALGRIND TESTS            #"
echo "# # # # # # # # # # # # # # # # # # # #"
./test.sh ./bin/$1.out

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#           RUNNING TESTS             #"
echo "# # # # # # # # # # # # # # # # # # # #"
for i in {0..10}
do
    time ./bin/$1.out
done
