#include <ncurses.h>
#include <iostream>
#include <sstream>
#include "menuGroup.h"


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
	wrefresh(window);

	/*const char* choices[4] = {
		"Continue", 
		"New Game", 
		"Options", 
		"Exit"};
	const char* prompt = "Welcome! What would you like to do!";
	Menu menu(height, width, 0, 0, prompt, choices, 4);*/

	if(argc > 1){
		MenuGroup mg(height, width, 0, 0, argv[1]);
		std::vector<std::tuple<int,int>> result = mg.Run();
		for(int i = 0; i < result.size(); i++){
			std::ostringstream oss;
			oss << "Menu: " << std::get<0>(result[i]) << " -> Value: " << std::get<1>(result[i]);
			mvwaddstr(window, i, 0, oss.str().c_str());
		}
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
