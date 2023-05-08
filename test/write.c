#include <stdio.h>

long unsigned int fsize(char *name);
void mv_file(FILE *f,long unsigned int number,long unsigned int last,char insert);

int main(int argc, char *argv[]){
	FILE *f;
	char *name=argv[1];
	long unsigned int last;
	long unsigned int number;
	char insert;
	f=fopen(name,"r+");
	for(;;){
	printf("input number and char:\n");
	scanf("%lu %c",&number,&insert);
	if(insert=='Q'){
		break;
	}
	last=fsize(name);
	mv_file(f,number,last,insert);
	printf("last:%lu\nnumber:%lu",last,number);
	}
	fclose(f);
	return 0;
}

long unsigned int fsize(char *name){
	FILE *f;
	int a;
	long unsigned int num=0;
	f=fopen(name,"r+");
	a=getc(f);
	printf("fsize\n");
	for(;a!=EOF;){
		num++;
		a=getc(f);
	}
	fclose(f);
	return num;
}

void mv_file(FILE *f,long unsigned int number,long unsigned int last,char insert){
	char a;
	fpos_t location=last-1;
	fpos_t *p_lo=&location;
	printf("mv_file\n");
	for(;location>=number;){
		printf("location:%lu\n",location);
		fsetpos(f,p_lo);
		a=getc(f);
		location++;
		fsetpos(f,p_lo);
		fputc(a,f);
		location=location-2;
	}
	location=number;
	fsetpos(f,p_lo);
	fprintf(f,"%c",insert);
}
