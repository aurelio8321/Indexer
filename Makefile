driver.out: driver.o Indexer.o Word.o
	g++ -Wall -std=c++11 -o driver.out driver.o Indexer.o Word.o

driver.o: driver.cpp Indexer.h Word.h
	g++ -Wall -std=c++11 -c driver.cpp

Indexer.o: Indexer.cpp Indexer.h BinarySearchTree.h Word.h
	g++ -Wall -std=c++11 -c Indexer.cpp

Word.o: Word.cpp Word.h
	g++ -Wall -std=c++11 -c Word.cpp

clean:
	rm *.o
	rm *driver.out
	rm filterResults.txt
	rm indexResults.txt

run:
	./driver.out $(FILTER) $(DATA)