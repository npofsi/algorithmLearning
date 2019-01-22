#!/bin/sh
name=hello
g++ $name.cpp -o $name.out -lm 
clear
./$name.out << $name.in
sleep 1
./build.sh