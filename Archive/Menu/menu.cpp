#include "menu.h"
#include <cstring>

Menu::Menu(int height, int width, int y, int x, char** choices, int numChoices){
	mChoices = choices;
	mNumChoices = numChoices;
	mCurChoice = 0;
	mWindow  = newwin(height, width, y, x);
	box(mWindow, 0, 0);
	Render();
}

Menu::~Menu(){
	delwin(mWindow);
}

int Menu::Run(){
	int input = 0;
	while(input != ' '){
		input = getch();
		switch(input){
		    case KEY_UP:
				if(mCurChoice == 0)
				    mCurChoice = mNumChoices - 1;
				else
				    mCurChoice--;
			break;
			
			case KEY_DOWN:
				if(mCurChoice == mNumChoices - 1)
					mCurChoice = 0;
				else
					mCurChoice++;
			break;
		}
		Render();
	}
	werase(mWindow);
	wrefresh(mWindow);
	return mCurChoice;
}

void Menu::Render(){
	int width, height;
	getmaxyx(mWindow, height, width);
	for(int i = 0; i < mNumChoices; i++){
		int len = strlen(mChoices[i]);
		int x = width / 2 - len / 2;        
		if(i == mCurChoice){
			wattron(mWindow, A_STANDOUT);
			mvwaddstr(mWindow, i+1, x, mChoices[i]);
			wattroff(mWindow, A_STANDOUT);
		}        
		else
			mvwaddstr(mWindow, i+1, x, mChoices[i]);
	} 
	wrefresh(mWindow);
}
