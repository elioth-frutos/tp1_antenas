CC = gcc
CFLAGS = -g -Wall -Wextra
OBJS = main.o compute_functions.o print_functions.o
OBJS_PATH = bin/main.o bin/compute_functions.o bin/print_functions.o
EXE_NAME = main

all = main

main: ${OBJS}
	${CC} ${CFLAGS} ${OBJS_PATH} -o ${EXE_NAME}

main.o: src/main.c
	${CC} ${CFLAGS} -c src/main.c 
	mv main.o ./bin

compute_functions.o: src/compute_functions/compute_functions.c
	${CC} ${CFLAGS} -c src/compute_functions/compute_functions.c
	mv compute_functions.o ./bin

print_functions.o: src/print_functions/print_functions.c
	${CC} ${CFLAGS} -c src/print_functions/print_functions.c
	mv print_functions.o ./bin

clean:
	rm ./bin/*.o main
