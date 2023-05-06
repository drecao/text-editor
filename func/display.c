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
