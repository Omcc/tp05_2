gcc -c weekTwoBinary.c -o weekTwoBinary.o
gcc -c weekTwomain.c -o weekTwomain.o
gcc weekTwomain.c weekTwoBinary.o -o main -lm