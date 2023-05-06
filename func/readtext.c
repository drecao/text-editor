char * readtext(char *name,int *numb){
	char *s;
	FILE *f;
	int i=0;
	int num;
	f=fopen(name,"r+");
	for(;fgetc(f)!=EOF;){
		i++;
	}
	num=i;
	fclose(f);
	f=fopen(name,"r+");
	s=(char *)malloc(sizeof(char)*(num+1));
	for(i=0;i<num;i++){
		s[i]=fgetc(f);
	}
	s[i]='\0';
	fclose(f);
	*numb=num;
	return s;
}
