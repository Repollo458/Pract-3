testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o testTableEntry testTableEntry.cpp

clean:
	rm -rf *.o *.gch bin


