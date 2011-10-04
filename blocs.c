#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int fitxer;

int bmount(const char *camino){
	fitxer = open(camino, O_RDWR | O_CREAT, 0666 );
	
	if (fitxer < 0) printf("Error muntant el sistema de fitxers! \n");
	return fitxer;
}

int bumount(){

	if (fitxer < 0) 
		printf("Fitxer no existent! \n");
	else 
		fitxer = close(fitxer);

	if (fitxer < 0) printf("Error desmuntant el sistema de fitxers! \n");

	return fitxer;
}


