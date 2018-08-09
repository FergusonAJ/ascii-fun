#include <ncurses.h>
#include <iostream>
#include "menu.h"

int main(int argc, char** argv){
	WINDOW* window = initscr();
	if(window == NULL){
		std::cerr << "Unable to initialize error!";
		return 0;
	}
	int width, height;
	getmaxyx(window, height, width);

	cbreak();
	noecho();
	keypad(window, 1);
	curs_set(0);
	
	printw("Hello World!");
	refresh();

	char* choices[4] = {
		(char*)"Continue", 
		(char*)"New Game", 
		(char*)"Options", 
		(char*)"Exit"};	
	Menu menu(height, width, 0, 0, choices, 4);
	int choice = menu.Run();
	waddstr(window, "You chose: ");
	waddstr(window, choices[choice]);
	waddstr(window, "!");
	wrefresh(window);
	
	
	getch();
	endwin();
	return 0;
}
