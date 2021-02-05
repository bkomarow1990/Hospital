#include "Lib.h"
#include "Doctor.h"
#include "WorkWithDB.h"


int main() {
	
	mainFucntion();
	const char* dir = "Doctors.db";
	sqlite3* DB; 
	WorkWithDB::createDB(dir);
	WorkWithDB::createTable(dir);
	try
	{
		Doctor d1("Ivan", "Bar3ebuh", "Albertovi3ch", 22,"Glpefl3p");
		WorkWithDB::insertDoctorData(dir, d1);
		d1.print();
		
	}
	catch (const MyException& e)
	{
		cerr << e.what();
	}
	catch (...) {
		cerr << "Error..." << endl;
	}
	return 0;
}


