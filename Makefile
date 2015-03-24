CXX = g++
LDFLAGS = -L/Users/anna/fp/jsoncpp/build/debug/lib-ljsoncpp
INC = -I/Users/anna/fp/jsoncpp/include

main: main.cpp
	$(CXX) -o main $(LDFLAGS) $(INC) main.cpp
