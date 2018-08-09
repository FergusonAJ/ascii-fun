#include <ncurses.h>

class Menu{
public:
	Menu(int height, int width, int y, int x, char** choices, int numChoices);
	~Menu();
	void Render();
	int Run();
protected:
	char** mChoices;
	int mNumChoices;
	WINDOW * mWindow;
	int mCurChoice;
};
