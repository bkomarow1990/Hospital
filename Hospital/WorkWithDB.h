#pragma once
#include "Lib.h"
#include "Doctor.h"
#include "sqlite3.h"
class WorkWithDB
{
public:
	const int &createTable()
	{
		sqlite3* DB;
		string sql = "CREATE TABLE IF NOT EXISTS "+DBNAME+" ("
			"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
			"NAME		VARCHAR NOT NULL, "
			"LNAME		VARCHAR NOT NULL, "
			"FATHERNAME		VARCHAR NOT NULL, "
			"AGE		INT NOT NULL, "
			"VOCATION		VARCHAR NOT NULL );";
		try {
			int exit = 0;
			exit = sqlite3_open(dir, &DB);
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
	const int& insertDataDoctorRandom() {
		int age = rand() % 19 + 18;
		string vocations[5]{
			"Hirurg",
			"Lor",
			"Dermatolog",
			"Urolog",
			"Terapewt"
		};
		string names[10]{
			"Ivan",
			"Oleg",
			"Bogdan",
			"Illia",
			"Vadym",
			"Andrii",
			"Boris",
			"Anatoliy",
			"Dzherik",
			"Vova"
		};
		string surnames[10]{
		"Kovalchuk",
		"Ivanov",
		"Olekseeiv",
		"Kravchenko",
		"Striletskiy",
		"Borisov",
		"Kuznets",
		"Polyanow",
		"Albertow",
		"Marmishka"
		};
		string fathernames[10]{
		"Olegovich",
		"Ivanovich",
		"Petrovich",
		"Serhiovich",
		"Igororvich",
		"Antonovich",
		"Vitalitovich",
		"Maksimovich",
		"Borisovich",
		"Anatoliyovich"
		};
		string name = names[rand() % 10];
		string sname = surnames[rand() % 10];
		string fname = fathernames[rand() % 10];
		string vocation = vocations[rand() % 5];
		Doctor doctor(name, sname, fname, age, vocation);
		system("cls");
		//doctor.print();
		sqlite3* DB;
		string sql = "INSERT INTO " + DBNAME + " (NAME, LNAME, FATHERNAME, AGE, VOCATION) VALUES('" + doctor.getName() + "', '" + doctor.getLastName() + "', '" + doctor.getFatherName() + "', " + to_string(doctor.getAge()) + ", '" + doctor.getVocation() + "');";
		try {
			int exit = 0;
			exit = sqlite3_open(dir, &DB);
			char* messageError;
			exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			//system("pause");
			system("cls");
			if (exit != SQLITE_OK)
			{
				cerr << "Error insert data" << endl;
				sqlite3_free(messageError);
			}
			else {
				//cout << "Data Inserted" << endl;
				sqlite3_close(DB);
			}
		} // end of try{}
		catch (const exception& e) {
			cerr << e.what();
		} // end of catch{}
	
		return 0;
	}
	const int &insertDataPerson( const Doctor& doctor) {
		sqlite3* DB;
		string sql = "INSERT INTO "+DBNAME+" (NAME, LNAME, FATHERNAME, AGE, VOCATION) VALUES('" + doctor.getName() + "', '" + doctor.getLastName() + "', '" + doctor.getFatherName() + "', " + to_string(doctor.getAge()) + ", '" + doctor.getVocation() + "');";
		//cout << sql << endl;
		//string sql = "INSERT INTO DOCTORS (NAME, LNAME, FATHERNAME, AGE, VOCATION) VALUES('Valeriy', 'Zhmih', 'Albertovich', 22, 'Gai');";
		try {
			int exit = 0;
			exit = sqlite3_open(dir, &DB);
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
	const int &createDB()
	{
		sqlite3* DB;
		int exit = 0;
		exit = sqlite3_open(dir, &DB);
		sqlite3_close(DB);
		return 0;
	}
	const int &selectData()
	{
		setlocale(LC_CTYPE, "ukr");
		sqlite3* DB;
		int exit = sqlite3_open(dir, &DB);
		string sql = "SELECT * FROM "+DBNAME+" ;";
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}
	const int& deleteData()
	{
		setlocale(LC_CTYPE, "ukr");
		sqlite3* db;
		int exit = sqlite3_open(dir, &db);
		char* zErrMsg = 0;
		int rc;
		sqlite3_stmt* res;
		const char* data = "Callback function called";

		/* Create merged SQL statement */
		string sql = "DELETE FROM "+DBNAME+" WHERE id > 0";
		rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
		sqlite3_close(db);
		return 0;
	}
	const int& selectDataWithRange(const int& from, const int& to)
	{
		setlocale(LC_CTYPE, "ukr");
		sqlite3* DB;
		int exit = sqlite3_open(dir, &DB);
		string sql = "SELECT * FROM DOCTORS WHERE id BETWEEN " + to_string(from) + " AND " + to_string(to)+" ;";
		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}

	const int& selectDataWithFields(const int& row, const string& data)
	{
		setlocale(LC_CTYPE, "ukr");
		sqlite3* DB;
		int exit = sqlite3_open(dir, &DB);
		string sql = "SELECT * FROM DOCTORS WHERE ";
		if (row==1)
		{
			sql += "NAME = '" +data+"'"+";";
		}
		else if (row == 2)
		{
			sql += "SURNAME = '" + data + "'" + ";";
		}
		else if (row == 3)
		{
			sql += "FATHERNAME = '" + data + "'" + ";";
		}
		else if (row == 4)
		{
			sql += "VOCATION = '" + data + "'" + ";";
		}
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

	const int& selectDataWithFields(const int& row, const int& data)
	{
		setlocale(LC_CTYPE, "ukr");
		sqlite3* DB;
		int exit = sqlite3_open(dir, &DB);
		string sql = "SELECT * FROM DOCTORS WHERE AGE = " + to_string(data) + " ";

		sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
		return 0;
	}
	typedef vector<vector<string> > table_type;
	static int vectorCallback(void* NotUsed, int argc, char** argv, char** azColName)
	{
		table_type* table = static_cast<table_type*>(NotUsed);
		vector<string> row;
		for (int i = 0; i < argc; i++)
			row.push_back(argv[i] ? argv[i] : "(NULL)");
		table->push_back(row);
		return 0;
	}
	const int& selectDataWithToVector(const int& from, const int& to, vector<vector<string>> & matrix)
	{
		setlocale(LC_CTYPE, "ukr");
		sqlite3* DB;
		int exit = sqlite3_open(dir, &DB);
		string sql = "SELECT * FROM DOCTORS WHERE id BETWEEN " + to_string(from) + " AND " + to_string(to) + " ;";
		sqlite3_exec(DB, sql.c_str(), vectorCallback, &matrix, NULL);
		return 0;
	}

	WorkWithDB(const char * dirs,const string& DBNAME)
	{
		//const int len = strlen(dir)+1;
		//char* tmp = new char[len + 1];
		//strcpy_s(tmp, len,dir);
		//tmp[len] = '\0'; // I'm paranoid, maybe someone has changed something in dir :-)
		//delete[] dir;
		//this->dir = tmp;
		int size = strlen(dirs)+1;
		this->dir = new char[size] {};

		strcpy_s(dir,size,dirs);
		if (DBNAME.empty())
		{
			return;
		}
		this->DBNAME = DBNAME;
	}
	~WorkWithDB() {
		if (dir!=nullptr)
		{
			delete[] dir;
			dir = nullptr;
		}
		
	}
private: 
	char* dir;
	string DBNAME;
};

