#include "menu.h"
#include <cstring>

Menu::Menu(int height, int width, int y, int x, std::string prompt, std::vector<std::string> choices){
	mChoices = choices;
	mNumChoices = choices.size();
	mCurChoice = 0;
	mWindow  = newwin(height, width, y, x);
	mPrompt = prompt;
	box(mWindow, 0, 0);
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
	int len = mPrompt.length();
	int x = width / 2 - len / 2;
	int y = 1;
	if(len != 0){
		mvwaddstr(mWindow, y, x, mPrompt.c_str());
		y += 2;
	}
	for(int i = 0; i < mNumChoices; i++){
		len = mChoices[i].length();
		x = width / 2 - len / 2;        
		if(i == mCurChoice){
			wattron(mWindow, A_STANDOUT);
			mvwaddstr(mWindow, i+y, x, mChoices[i].c_str());
			wattroff(mWindow, A_STANDOUT);
		}        
		else
			mvwaddstr(mWindow, i+y, x, mChoices[i].c_str());
	} 
	wrefresh(mWindow);
}
