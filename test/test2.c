#include <stdio.h>

long unsigned int fsize(FILE *f);
void mv_file(FILE *f,long unsigned int number,long unsigned int last,char insert);

int main(int argc, char *argv[]){
	FILE *f;
	char *name=argv[1];
	long unsigned int last;
	long unsigned int number;
	char insert;
	printf("input number:\n");
	scanf("%lu",&number);
	printf("input char:\n");
	insert=getchar();
	f=fopen(name,"r+");
	last=fsize(f);
	mv_file(f,number,last,insert);
	fclose(f);
	return 0;
}

long unsigned int fsize(FILE *f){
	char a;
	long unsigned int num=0;
	a=getc(f);
	for(;a!=EOF;){
		num++;
		a=getc(f);
	}
	return num;
}

void mv_file(FILE *f,long unsigned int number,long unsigned int last,char insert){
	char a;
	fpos_t location=last-1;
	fpos_t *p_lo=&location;
	for(;location>=number;){
		fsetpos(f,p_lo);
		a=getc(f);
		fprintf(f,"%c",a);
		location --;
	}
	location=number;
	fsetpos(f,p_lo);
	fprintf(f,"%c",insert);
}
