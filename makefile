bin/main: build/main.o build/board.o build/block.o
	g++ -o bin/main build/board.o build/main.o

build/board.o: src/board.cpp
	g++ -o build/board.o -c src/board.cpp

build/block.o: src/block.cpp
	g++ -o build/block.o -c src/block.cpp

build/main.o: src/main.cpp src/board.h src/block.h
	g++ -o build/main.o -c src/main.cpp

Clean:
	rm -f build/*.o