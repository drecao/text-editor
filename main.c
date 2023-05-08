//include define
#include "define/def.h"

//include functions
#include "func/analysis_text.c"
#include "func/display.c"
#include "func/initw.c"
#include "func/readtext.c"
#include "func/runtime.c"
#include "func/test_text.c"


//main function
int main(int argc, char *argv[]){

	//init the curses windows
	initw();
	LINES_EXP=LINES-2;
	TEXT_LOCATION=0;

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

/*
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
*/
	//free the malloc_space
	free(text);
	free(ana_stru);
	return 0;
}
