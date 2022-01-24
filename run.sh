#/usr/bin/bash

gcc -Wall -Wextra -c ./parser.c -o ./parser.o
gcc -Wall -Wextra -c ./main.c -o ./main.o
gcc -Wall -Wextra ./main.o ./parser.o
./a.out
