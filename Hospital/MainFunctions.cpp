#include "MainFunctions.h"

void setColor(const int& text, const int& bg)
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));

}


void setGreenColorText()
{
	system("color 0A");
}

void mainFucntion()
{
	setGreenColorText();
}

