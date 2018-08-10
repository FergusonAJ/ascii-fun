#include <ncurses.h>
#include <vector>
#include <string>

class Menu{
public:
	Menu(int height, int width, int y, int x, std::string prompt, std::vector<std::string> choices);
	~Menu();
	void Render();
	int Run();
protected:
	std::vector<std::string> mChoices;
	int mNumChoices;
	std::string mPrompt;
	WINDOW * mWindow;
	int mCurChoice;
};
