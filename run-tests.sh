#/usr/bin/bash

gcc -Wall -Wextra -std=c11 -c parser.c -o ./lib/parser.o
gcc -Wall -Wextra -std=c11 -c ./tests/parser_test.c -o ./lib/parser_test.o
gcc ./lib/parser.o ./lib/parser_test.o
./a.out
