void run_time(int *p_y, int *p_x, char *text,int *ana_stru){
	commond(p_y,p_x,ana_stru);
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
