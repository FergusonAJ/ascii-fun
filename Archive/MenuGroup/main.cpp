#include <ncurses.h>
#include <iostream>
#include <sstream>
#include "menuGroup.h"


int main(int argc, char** argv){
	WINDOW* window = initscr();
	if(window == NULL){
		std::cerr << "Error: Unable to initialize window!";
		return 0;
	}
	int width, height;
	getmaxyx(window, height, width);

	cbreak();
	noecho();
	keypad(window, 1);
	curs_set(0);
    wrefresh(window);	

	if(argc > 1){
		MenuGroup mg(height, width, 0, 0, argv[1]);
		std::vector<std::tuple<int,int>> result = mg.Run();
		for(int i = 0; i < result.size(); i++){
			std::ostringstream oss;
			oss << "Menu: " << std::get<0>(result[i]) << " -> Value: " << std::get<1>(result[i]);
			mvwaddstr(window, i, 0, oss.str().c_str());
		}
	}
    else{
	    printw("Pass, as a command line argument, the file you would like to parse!");
    }

	//int choice = menu.Run();
	//waddstr(window, "You chose: ");
	//waddstr(window, choices[choice]);
	//waddstr(window, "!");
	wrefresh(window);
	
	
	getch();
	endwin();
	return 0;
}
