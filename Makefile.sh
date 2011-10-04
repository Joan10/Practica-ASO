gcc -c mi_mkfs.c
gcc -c blocs.c

gcc -o bin/blocs mi_mkfs.o blocs.o
