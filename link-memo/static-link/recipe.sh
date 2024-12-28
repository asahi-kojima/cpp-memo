#! /bin/zsh


g++ -std=c++11 -c util.cpp

ar rc libtest.a util.o

g++ -std=c++11 main.cpp libtest.a -o main

./main.out