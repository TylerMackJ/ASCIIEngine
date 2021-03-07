all : bin/
	g++ src/* -o bin/engine

bin/ : 
	mkdir bin