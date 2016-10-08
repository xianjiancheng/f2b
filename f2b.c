#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){

	FILE *fin, *fout;
	char c;

	if(argc !=2){
		printf("Usage: %s filein \n", argv[0]);
		exit(0);
	}
	
	if((fin = fopen(argv[1],"r"))==NULL){
		perror("fopen filein");
		exit(0);
	}
	
	char *name = argv[1];	
	char *out = strcat(name , ".old");
	fout = fopen(out,"w");

	while ((c=getc(fin))!= EOF)
		putc(c,fout);

	fclose(fin);
	fclose(fout);
	return 0;

}
