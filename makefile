COMPILER = g++
CLEAR_SCREEN = clear
REMOVE=rm

start: compile link run
compile:
	${COMPILER} -I "./include" -c ./src/main.cpp -o ./lib/main.o
	${COMPILER} -I "./include" -c ./src/image.cpp -o ./lib/image.o
link: compile
	${COMPILER} -o ./bin/program ./lib/*
run: compile link
	${CLEAR_SCREEN}
	./bin/program
remove:
	${REMOVE} ./lib/** ./bin/**