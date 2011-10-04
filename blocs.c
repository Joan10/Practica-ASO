#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define MIDA_BLOC 1024

int fitxer;

int bmount(const char *camino){
	fitxer = open(camino, O_RDWR | O_CREAT, 0666 );
	
	if (fitxer < 0) printf("Error muntant el sistema de fitxers!\n");
	return fitxer;
}

int bumount(){

	if (fitxer < 0) 
		printf("Fitxer no existent!\n");
	else 
		fitxer = close(fitxer);

	if (fitxer < 0) printf("Error desmuntant el sistema de fitxers!\n");

	return fitxer;
}

int bwrite(unsigned int bloque, const void *buf){

	if (lseek(fitxer, bloque*MIDA_BLOC, SEEK_SET) < 0) {
		printf("Error indexant el bloc!\n"); 
		return -1;
	}

	if (write(fitxer, buf, MIDA_BLOC) < 0){
		printf("Error escrivint al fitxer\n");
		return -1;
	}

	return fitxer;


}

int bread(unsigned int bloque, void *buf){

	if (lseek(fitxer, bloque*MIDA_BLOC, SEEK_SET) < 0) {
		printf("Error indexant el bloc!\n"); 
		return -1;
	}
	
	if (read(fitxer, buf, MIDA_BLOC) < 0){
		printf("Error llegint el fitxer\n");
		return -1;
	}

	return fitxer;

}

