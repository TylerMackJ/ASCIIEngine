SRCS := ${shell find ./src -name *.c*}

all : bin/
	g++ -O2 ${SRCS} -o bin/engine

bin/ : 
	mkdir bin

gdb : bin/
	g++ -Wall -g ${SRCS} -o bin/engine

clean :
	rm -r ./bin