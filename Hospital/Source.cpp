#include "Lib.h"
#include "Doctor.h"
#include "WorkWithDB.h"
#include "Menu.h"
#include <windows.h>
#include <ctime>
int main() {
	srand(unsigned(NULL));
	
	try
	{
		WorkWithDB doctors_db("Doctors.db", "DOCTORS");
		mainFucntion();
		//doctors_db.createDB();
		//doctors_db.createTable();
		system("cls");
		showMainMenu(doctors_db);
		
	}
	catch (const MyException& e)
	{
		cerr << e.what() << endl;;
	}
	catch (...) {
		cerr << "Error..." << endl;
		system("pause");
	}
	return 0;
}


