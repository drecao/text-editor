#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

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
