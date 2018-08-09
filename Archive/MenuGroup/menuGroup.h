#include "menu.h"
#include <vector>
#include <tuple>
struct MenuData{
	std::string prompt;
	std::vector<std::string> choices;
	std::vector<int> links;
};

class MenuGroup{
public:
	MenuGroup(int height, int width, int x, int y, const char* filename);
	~MenuGroup();
	std::vector<std::tuple<int,int>> Run(int start = 0);
protected:
	std::vector<MenuData> mMenuData;
	int mHeight, mWidth, mY, mX;
};
