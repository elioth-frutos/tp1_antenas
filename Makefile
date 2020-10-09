
CC = gcc
CFLAGS = -c -g
OBJS = build/main.o build/compute_functions.o build/print_functions.o
OBJS2 = main.o compute_functions.o print_functions.o
EXE_NAME = main

BUILD_PATH = build

all = main

main: ${OBJS2}
	${CC} ${OBJS} -o ${EXE_NAME}

main.o: src/main.c
	${CC} src/main.c ${CFLAGS}
	mv main.o ./build

compute_functions.o: src/compute_functions/compute_functions.c
	${CC} src/compute_functions/compute_functions.c ${CFLAGS}
	mv compute_functions.o ./build

print_functions.o: src/print_functions/print_functions.c
	${CC} src/print_functions/print_functions.c ${CFLAGS}
	mv print_functions.o ./build

clean:
	rm ./build/*.o main
