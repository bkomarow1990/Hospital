#include "MainFunctions.h"
#include "Menu.h"
bool SetWindowSize(size_t width, size_t height)
{
	string request_str = "mode con cols=" + to_string(width) + " lines=" + to_string(height);
	const char* c = request_str.c_str();
	system(c);
	return true;
}
void setColorText(string& colorbg, const string &colortxt)
{
	colorbg += colortxt; 
	colorbg.insert(0, "color ");
	const char* color_ = colorbg.c_str();
	system(color_);
}
void setColor(const int& text, const int& bg)
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));

}
void setUserColor() {
	string choise, choise2;
	cout << "==============================================================" << endl;
	cout << "	      What color of console do you want? " << endl;
	cout << R"(
		 0 = Черный 8 = Серый
		 1 = Синий 9 = Светло-синий
		 2 = Зеленый A = Светло-зеленый
		 3 = Голубой B = Светло-голубой
		 4 = Красный C = Светло-красный
		 5 = Лиловый D = Светло-лиловый
		 6 = Желтый E = Светло-желтый
		 7 = Белый F = Ярко-белый
)" << endl;
	cinTry(choise);
	cout << "	      What color of text do you want? " << endl;
	cinTry(choise2);
	setColorText(choise, choise2);
	cout << "==============================================================" << endl;
	system("pause");
	system("cls");
}
void printProgramName() {
	

	cout << R"(
===============================================================================================================
	    __    __    ______        _______..______    __  .___________.     ___       __      
	   |  |  |  |  /  __  \      /       ||   _  \  |  | |           |    /   \     |  |     
	   |  |__|  | |  |  |  |    |   (----`|  |_)  | |  | `---|  |----`   /  ^  \    |  |     
	   |   __   | |  |  |  |     \   \    |   ___/  |  |     |  |       /  /_\  \   |  |     
	   |  |  |  | |  `--'  | .----)   |   |  |      |  |     |  |      /  _____  \  |  `----.
	   |__|  |__|  \______/  |_______/    | _|      |__|     |__|     /__/     \__\ |_______|
===============================================================================================================
)";
	cout << R"(

   _               ___                   _                    ___          _      _            
 | |__   _  _    | _ )  ___   __ _   __| |  __ _   _ _      / __|  _ _   (_)  __| |  ___   ___
 | '_ \ | || |   | _ \ / _ \ / _` | / _` | / _` | | ' \    | (_ | | ' \  | | / _` | / -_) |_ /
 |_.__/  \_, |   |___/ \___/ \__, | \__,_| \__,_| |_||_|    \___| |_||_| |_| \__,_| \___| /__|
         |__/                |___/                                                            



)";
	system("pause");
}



void mainFucntion()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setUserColor();
	printProgramName();

    //SetWindowSize(20,10);
}

