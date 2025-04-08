matrix.exe: main.cpp
	g++ -o matrix.exe main.cpp

clean:
	rm -f matrix.exe

run:
	./matrix.exe