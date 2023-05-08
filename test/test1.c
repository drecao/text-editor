#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *f;
	char *name=argv[1];
	char a;
	fpos_t pos;
	fpos_t *p_pos=&pos;
	f=fopen(name,"r+");
	a=getchar();
	fgetpos(f,p_pos);
	printf("pos:%lu\n",pos);
	fputc(a,f);
	pos=3;
	fsetpos(f,p_pos);
	fputc(a,f);
	printf("after:%c\n",fgetc(f));
	fputc(a,f);
	fputc('\n',f);
	fclose(f);
	return 0;
}
