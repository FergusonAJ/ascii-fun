#include "menuGroup.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

MenuGroup::MenuGroup(int height, int width, int x, int y, const char* filename){
	mWidth = width;
	mHeight = height;
	mX = x;
	mY = y;
	std::ifstream fp;
	fp.open(filename);
	if(!fp){
		std::cerr << "Cannot open file: " << filename << "!" << std::endl;
		return;
	}
	std::string s;
	std::string curPrompt;
	std::vector<std::string> curChoices;
	std::vector<int> curLinks;
	while(std::getline(fp, s)){
		if(s[0] == '#')
			continue;
		else if(s.empty()){
			MenuData md = {};
			md.prompt = curPrompt.substr(0, std::string::npos);
			md.choices.swap(curChoices);
			md.links.swap(curLinks);
			mMenuData.push_back(md);
			curPrompt.clear();
			curChoices.clear();
			curLinks.clear();
		}
		else{
			if(curPrompt.empty()){
				std::cout << "Prompt: ";
				curPrompt = s.substr(0,std::string::npos);
				std::cout << curPrompt;
			}
			else if(curChoices.size() == curLinks.size()){
				curChoices.push_back(s.substr(0, std::string::npos));
				std::cout << "Choice: " << curChoices[curChoices.size() - 1];
			}
			else{
				std::cout << "Link: ";
				curLinks.push_back(atoi(s.c_str()));
			}

		}

		std::cout << s << std::endl;
		for(int i = 0; i < curChoices.size(); i++){
			std::cout << i << " " << curChoices[i] << std::endl;
		}
	}
	fp.close();
	if(!curPrompt.empty()){
		MenuData md = {};
		md.prompt = curPrompt.substr(0, std::string::npos);
		md.choices.swap(curChoices);
		md.links.swap(curLinks);
		mMenuData.push_back(md);
	}

}

MenuGroup::~MenuGroup(){
}

std::vector<std::tuple<int,int>> MenuGroup::Run(int start){
	std::vector<std::tuple<int,int>> result;
	while(start >= 0 && start < mMenuData.size()){
		Menu menu(mHeight, mWidth, mX, mY, mMenuData[start].prompt, mMenuData[start].choices);
		menu.Render();
		int res = menu.Run();
		result.push_back(std::make_tuple(start, res));
		start = mMenuData[start].links[res];
	}
	return result;
	
}


