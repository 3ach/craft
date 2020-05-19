CC = g++
THRIFT = thrift

CFLAGS = -Wall 

raft-server: src/*.cpp
	g++ -pipe -std=c++17 -I. -lgflags -lthrift -o raft-server if/gen-cpp/*.cpp src/*.cpp -lpthread

