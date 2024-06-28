# ID: 326662574
# MAIL: noamlevin11@gmail.com

CXX = clang++
CXXFLAGS = -std=c++14 -Wsign-conversion -g
CATANOBJ = Catan.o Player.o Board.o Game.o Place.o Card.o
#TESTOBJ = Test.o TestCounter.o $(filter-out main.o, $(CATANOBJ))
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

all: Catan

#Catan: $(CATANOBJ)
#	$(CXX) $(CXXFLAGS) $(CATANOBJ) -o Catan

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

Catan: $(CATANOBJ)
	$(CXX) $(CXXFLAGS) $(CATANOBJ) -o Catan

valgrind: Catan
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Catan 2>&1 | { egrep "lost| at " || true; }
#	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o Catan

.PHONY: all clean