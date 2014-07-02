
CFLAGS = -c -Wall -g
LFLAGS = -g -o assign7

assign7: assign7.o binarytree.o
	g++ assign7.o binarytree.o $(LFLAGS)

assign7.o: assign7.cpp binarytree.h
	g++ $(CFLAGS) assign7.cpp

binarytree.o: binarytree.cpp binarytree.h
	g++ $(CFLAGS) binarytree.cpp

clean:
	rm -f assign7 *.o *~ *#
