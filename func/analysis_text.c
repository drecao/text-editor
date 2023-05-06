void analysis_text(char *text,int *ana_stru){
	int ana_stru_numb=0;
	int i=0;
	int text_num=0;
	char c;
	c=*(text+text_num);
	for(; ana_stru_numb<LINES_EXP;){
		if(c=='\n'){
			*(ana_stru+ana_stru_numb)=i;
			ana_stru_numb=ana_stru_numb+1;
			i=0;
			text_num=text_num+1;
			c=*(text+text_num);
		}
		else if(i==(COLS-1)){
			*(ana_stru+ana_stru_numb)=i+1;
			ana_stru_numb=ana_stru_numb+1;
			i=0;
			text_num=text_num+1;
			c=*(text+text_num);
		}
		else if(c=='\0'){
			if(*(text+text_num-1)=='\n'){
			*(ana_stru+ana_stru_numb)=-1;
			ana_stru_numb=ana_stru_numb+1;
			for(;ana_stru_numb<LINES_EXP;){
				*(ana_stru+ana_stru_numb)=-1;
				ana_stru_numb=ana_stru_numb+1;
			}
			}
			else{
				*(ana_stru+ana_stru_numb)=i;
				ana_stru_numb=ana_stru_numb+1;
				for(;ana_stru_numb<LINES_EXP;){
					*(ana_stru+ana_stru_numb)=-1;
					ana_stru_numb=ana_stru_numb+1;
				}
			}
		}
		else {
		i=i+1;
		text_num=text_num+1;
		c=*(text+text_num);
		}
	}
}
