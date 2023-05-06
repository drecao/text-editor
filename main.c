#include <curses.h>
#include <stdlib.h>
#include <stdio.h>

//define utrl int LINES_EXP
int LINES_EXP;

//define functions used
void initw();
char * readtext(char *name,int *numb);
int test_text(char *name);
void commond(int *p_y,int *p_x, int *ana_stru);
void display(char *text, char *name);
void run_time(int *p_y,int *p_x, char *text,int *ana_stru);
void move_cur(int dir, int *p_y, int *p_x, int *ana_stru);
void analysis_text(char *text,int *ana_stru);

//main function
int main(int argc, char *argv[]){

	//init the curses windows
	initw();
	LINES_EXP=LINES-2;

	//text analysis struct
	int *ana_stru;
	ana_stru=(int *)malloc(LINES_EXP*sizeof(int));

	//define i,text,num,name
	int i;
	int *n=&i;
	int num;
	char *text;
	char *name=argv[1];
	//define cur location and stream location
	int cur_y=0;
	int cur_x=0;
	int *p_y=&cur_y;
	int *p_x=&cur_x;
	fpos_t location;
	fpos_t *p_location=&location;

	//program_main_course
	test_text(name);
	text=readtext(name,n);
	display(text,name);
	analysis_text(text,ana_stru);
	run_time(p_y,p_x,text,ana_stru);

	//finish_test
	num=i;
	printf("Start here !!!\n");
	printf("%s",text);
	printf("End here !!!\n");
	printf("numbers=%d\n",num);
	printf("ana_stru:");
	for(i=0;i<(LINES_EXP);i++){
			printf("%d ",*(ana_stru+i));
	}
	printf("\nLINES:%d LINES_EXP:%d\n",LINES,LINES_EXP);
	for(i=0;i<=num;i++){
		printf("%d ",*(text+i));
	}
	printf("\n");

	//free the malloc_space
	free(text);
	free(ana_stru);
	return 0;
}


void initw(){
	initscr();
	raw();
	noecho();
	curs_set(1);
}

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


void commond(int *p_y,int *p_x, int *ana_stru){
	int a;
	for(;;){
		a=getchar();
		if(a==':'){
			move((LINES-1),0);
			clrtoeol();
			printw("%c",a);
			refresh();
			a=getchar();
			if(a=='q'){
				printw("%c",a);
				refresh();
				a=getchar();
				if(a=='\r'|a=='\n'){
					endwin();
					break;
				}
				else{
					printw("%c",a);
					refresh();
				}
			}
			else{
				printw("%c",a);
				refresh();
			}
		}
		if(a==27){
			a=getchar();
			if(a==91){
				a=getchar();
				if(a==65){
					move_cur(1,p_y,p_x,ana_stru);
				}
				else if(a==66){
					move_cur(2,p_y,p_x,ana_stru);
				}
				else if(a==68){
					move_cur(3,p_y,p_x,ana_stru);
				}
				else if(a==67){
					move_cur(4,p_y,p_x,ana_stru);
				}
			}
		}
		if(a=='k'){
			move_cur(1,p_y,p_x,ana_stru);
		}
		else if(a=='j'){
			move_cur(2,p_y,p_x,ana_stru);
		}
		else if(a=='h'){
			move_cur(3,p_y,p_x,ana_stru);
		}
		else if(a=='l'){
			move_cur(4,p_y,p_x,ana_stru);
		}

	}
}

void display(char *text, char *name){
	move(0,0);
	printw("%s",text);
	move(LINES_EXP,0);
	clrtoeol();
	move((LINES-1),0);
	clrtoeol();
	move(LINES_EXP,0);
	printw("file name: %s",name);
	move(0,0);
	refresh();
}

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

void run_time(int *p_y, int *p_x, char *text,int *ana_stru){
	commond(p_y,p_x,ana_stru);
}

void move_cur(int dir, int *p_y, int *p_x, int *ana_stru){
	if(dir==1 && (*p_y)!=0){
		*p_y=*p_y-1;
	}
	if(dir==2 && (*p_y)<(LINES_EXP-1)){
		*p_y=*p_y+1;
		if(*(ana_stru+(*p_y))==0){
			*p_x=0;
		}
		else if(*(ana_stru+(*p_y))<(*p_x+1)){
			*p_y=*p_y-1;
		}
	}
	if(dir==3 && (*p_x)!=0){
		*p_x=*p_x-1;
	}
	if(dir==4){
		*p_x=*p_x+1;
		if(*(ana_stru+(*p_y))<=*p_x){
			*p_x=*p_x-1;
		}
	}
	move(*p_y,*p_x);
	refresh();
}

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