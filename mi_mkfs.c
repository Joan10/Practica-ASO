#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "blocs.h"
#define MIDA_BLOC 1024

int main(int argc, char **argv){

	char *NomFitxer = argv[1];
	
	int NumBlocs = atoi(argv[2]);

	bmount(NomFitxer);
	
	unsigned char buffer[MIDA_BLOC];
	unsigned char buffer2[MIDA_BLOC];

	memset(buffer,0,MIDA_BLOC);
	buffer[5] = 'r';
	int i;
	for (i=0; i<NumBlocs; i++) {
		bwrite(i,buffer);
	}

	bread(10, buffer2);
	printf("%c \n ", buffer2[5]);
	printf("%c \n ", buffer[5]);
	umount();


}
