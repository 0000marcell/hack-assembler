#/usr/bin/bash

gcc -Wall -Wextra -c parser.c -o ./lib/parser.o
gcc -Wall -Wextra -c ./tests/parser_test.c -o ./lib/parser_test.o
gcc -Wall -Wextra ./lib/parser.o ./lib/parser_test.o
./a.out
