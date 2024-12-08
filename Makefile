testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h
	mkdir -p bin
	g++ -o testHashTable testHashTable.cpp
	

clean:
	rm -rf *.o *.gch bin


