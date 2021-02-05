#pragma once
#include "Lib.h"
#include "Doctor.h"
class WorkWithDB
{
public:
	static int createTable(const char* s)
	{
		sqlite3* DB;
		string sql = "CREATE TABLE IF NOT EXISTS DOCTORS("
			"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
			"NAME		VARCHAR NOT NULL, "
			"LNAME		VARCHAR NOT NULL, "
			"FATHERNAME		VARCHAR NOT NULL, "
			"AGE		INT NOT NULL, "
			"VOCATION		VARCHAR NOT NULL );";
		try {
			int exit = 0;
			exit = sqlite3_open(s, &DB);
			char* messageError;
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (exit != SQLITE_OK)
			{
				cerr << "Error create table";
				sqlite3_free(messageError);
			}
			else {
				cout << "Table created" << endl;
				sqlite3_close(DB);
			}
		} // end of try{}
		catch (const exception& e) {
			cerr << e.what();
		} // end of catch{}
		return 0;
	}
	static int insertDoctorData(const char* s, const Doctor& doctor) {
		sqlite3* DB;
		string sql = "INSERT INTO DOCTORS (NAME, LNAME, FATHERNAME, AGE, VOCATION) VALUES('" + doctor.getName() + "', '" + doctor.getLastName() + "', '" + doctor.getFatherName() + "', " + to_string(doctor.getAge()) + ", '" + doctor.getVocation() + "');";
		cout << sql << endl;
		//string sql = "INSERT INTO DOCTORS (NAME, LNAME, FATHERNAME, AGE, VOCATION) VALUES('Valeriy', 'Zhmih', 'Albertovich', 22, 'Gai');";
		try {
			int exit = 0;
			exit = sqlite3_open(s, &DB);
			char* messageError;
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (exit != SQLITE_OK)
			{
				cerr << "Error insert data" << endl;
				sqlite3_free(messageError);
			}
			else {
				cout << "Data Inserted" << endl;
				sqlite3_close(DB);
			}
		} // end of try{}
		catch (const exception& e) {
			cerr << e.what();
		} // end of catch{}
		return 0;
	}
	static int createDB(const char* s)
	{
		sqlite3* DB;
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		sqlite3_close(DB);
		return 0;
	}
	static int selectData(const char* s)
	{
		sqlite3* DB;
		int exit = sqlite3_open(s, &DB);
		string sql = "SELECT * FROM GRADES;";
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}

	static int callback(void* NotUsed, int argc, char** argv, char** azColName)
	{
		for (int i = 0; i < argc; i++)
		{
			cout << azColName[i] << ": " << argv[i] << endl;
		}
		cout << endl;
		return 0;
	}
};

