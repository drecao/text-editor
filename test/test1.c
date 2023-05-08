#include <stdio.h>

int main(int argc, char *argv[]){
	char a;
	FILE *f;
	long unsigned int location;
	fpos_t pos;
	fpos_t *p_pos;
	char *name=argv[1];
	f=fopen(name,"r+");
	printf("input:\n");
	a=getchar();
	for(;;){
		a=getchar();
		if(a=='q'){
			break;
		}
		fprintf(f,"%c",a);
		printf("input again:\n");
	}
	fclose(f);
	return 0;
}
