int test_text(char *name){
	FILE *f;
	f=fopen(name,"r+");
	if(f == NULL){
		f=fopen(name,"w+");
		fclose(f);
		return 0;
	}
	else{
		fclose(f);
		return 1;
	}
}
