# ID: 326662574
# MAIL: noamlevin11@gmail.com

CXX = clang++
CXXFLAGS = -std=c++14 -Wsign-conversion -g
CATANOBJ = Catan.o Player.o Board.o Game.o Place.o Card.o
DEMOOBJ = Catan.o Player.o Board.o Demo.o Place.o Card.o
TESTOBJ = Test.o TestCounter.o $(filter-out Game.o, $(CATANOBJ))
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

all: Catan Demo test

TestCounter.o: TestCounter.cpp
	$(CXX) $(CXXFLAGS) -c TestCounter.cpp

Test.o: Test.cpp
	$(CXX) $(CXXFLAGS) -c Test.cpp

Catan.o : Catan.cpp Catan.hpp
	$(CXX) $(CXXFLAGS) -c Catan.cpp

Player.o : Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Board.o : Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Place.o : Place.cpp Place.hpp
	$(CXX) $(CXXFLAGS) -c Place.cpp

Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Card.o : Card.cpp Card.hpp
	$(CXX) $(CXXFLAGS) -c Card.cpp

Demo.o : Demo.cpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Demo : $(DEMOOBJ)
	$(CXX) $(CXXFLAGS) $(DEMOOBJ) -o Demo

Catan: $(CATANOBJ)
	$(CXX) $(CXXFLAGS) $(CATANOBJ) -o Catan

test: $(TESTOBJ)
	$(CXX) $(CXXFLAGS) $(TESTOBJ) -o test

valgrind: Catan
	#valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Catan 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Demo 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o Catan Demo test

.PHONY: all clean