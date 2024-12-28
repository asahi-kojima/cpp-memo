#! /bin/zsh

rm *.a *.o

g++ -std=c++11 -c util.cpp

ar rc libtest.a util.o

g++ -std=c++11 main.cpp libtest.a -o main.out

#こっちも動く
#ar rc libtest.a util.o
#g++ -std=c++11 main.cpp -L. -ltest -o main.out

./main.out