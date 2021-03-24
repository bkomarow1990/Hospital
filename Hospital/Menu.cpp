#include "Menu.h"

void showMenuCols(vector<string> arr) {
	int max = arr[0].length() + 4;
	for (auto& i : arr)
	{
		if (i.length() > max)
		{
			max = i.length() + 4;
		}
	}
	for (size_t i = 0; i < arr.size(); i++)
	{

		cout << endl;
		for (size_t j = 0; j < max; j++)
		{
			cout << "-";
		}
		cout << endl;
		arr[i].insert(0, "|");

		int t_size = arr[i].size();
		for (int j = 0; j < max - t_size - 2; j++)
		{
			arr[i] += " ";
		}

		arr[i] += " |";
		cout << arr[i];
		if (i == arr.size() - 1)
		{
			cout << endl;
			for (size_t j = 0; j < max; j++)
			{
				cout << "-";
			}
			cout << endl;
		}
	}
}

void showDoctorMenu()
{
	vector <string> columns{
	"1. Show doctors     ",
	"2. Add new doctor   ",
	"3. Delete doctor db  ",
	"0. Exit"
	};
	showMenuCols(columns);
}

void callMenu(WorkWithDB& doctors_db) {
	int answer=0;
	int pod_answer = 0;
	{
		vector<string> list{
			"1. Doctor menu",
			"2. Patient menu",
			"0. Exit",
		};
		showMenuCols(list);
	}

	/*cout << "--------------------- " << endl;
	cout << setw(1) << '|';
	cout <<" 1. Doctor menu " << '|' << endl;
	cout << "--------------------- " << endl;
	cout << setw(1) << '|';
	cout << " 2. Patient menu "  << '|' << endl;
	cout << "--------------------- " << endl;
	cout << setw(1) << '|';
	cout <<"     0. Exit     |" << endl;
	cout << "--------------------- "  << endl;*/
	cinTry(answer);
	switch (answer)
	{
	case 1:
		system("cls");
		showDoctorMenu();
		cinTry(pod_answer);
		//cin >> pod_answer;
		//cinTry(pod_answer);
		switch (pod_answer)
		{
		case 1:
			system("cls");
			{
				vector<string> columns{
					"1. Show with range",
					"2. Show range with sorting",
					"3. Show doctors with field",
					"0. Exit"
				};
				showMenuCols(columns);
			}
			cinTry(pod_answer);
			cout << "Enter field ... " << endl;
			switch (pod_answer)
			{
			case 1:
				system("cls");

				{
					cout << "=================================" << endl;
					cout << "Enter from range select data..." << endl;
					int from, to;
					cin >> from;
					cout << "Enter to range select data..." << endl;
					cin >> to;
					cout << "=================================" << endl;
					if (from > to)
					{
						int temp = to;
						to = from;
						from = temp;
					}
					doctors_db.selectDataWithRange(from, to);
					system("pause");
					system("cls");
					callMenu(doctors_db);
				}
				break;
			case 2:
			{
				cout << "=================================" << endl;
				cout << "Enter from range select data..." << endl;

				int from, to;
				cin >> from;
				cout << "Enter to range select data..." << endl;
				cin >> to;
				if (from > to)
				{
					int temp=to;
					to = from;
					from = temp;
				}
				cout << "=================================" << endl;
				{
					vector<vector<string>> matrix;
					vector<Doctor> doctors_for_sort;
				doctors_db.selectDataWithToVector(from, to, matrix);
				{
					system("cls");
					vector<string> columns{
						"1. Sort by name",
						"2. Sort by surname",
						"3. Sort by fathername",
						"4. Sort by age",
						"0. Exit"
					};
					showMenuCols(columns);
					cinTry(pod_answer); // sort by
					switch (pod_answer)
					{
					case 1:
					{
						system("cls");
						{
							vector<string> columns{
							"1. Sort by Decrease",
							"2. Sort by Descending",
							"0. Exit"
							};
							showMenuCols(columns);
							cinTry(pod_answer);
							switch (pod_answer)
							{
							case 1:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorByName(doctors_for_sort,0);
								break;
							case 2:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorByName(doctors_for_sort, 1);
								system("cls");
								break;
							default:
								system("cls");
								callMenu(doctors_db);
								break;
							}
						}
						break;
					}
					case 2:
					{
						system("cls");
						{
							vector<string> columns{
							"1. Sort by Decrease",
							"2. Sort by Descending",
							"0. Exit"
							};
							showMenuCols(columns);
							cinTry(pod_answer);
							switch (pod_answer)
							{
							case 1:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorBySurname(doctors_for_sort, 0);
								break;
							case 2:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorBySurname(doctors_for_sort, 1);
								system("cls");
								break;
							default:
								system("cls");
								callMenu(doctors_db);
								break;
							}
						}
						break;
					}
					case 3:
					{
						system("cls");
						{
							vector<string> columns{
							"1. Sort by Decrease",
							"2. Sort by Descending",
							"0. Exit"
							};
							showMenuCols(columns);
							cinTry(pod_answer);
							switch (pod_answer)
							{
							case 1:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorByFathername(doctors_for_sort, 0);
								break;
							case 2:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorByFathername(doctors_for_sort, 1);
								system("cls");
								break;
							default:
								system("cls");
								callMenu(doctors_db);
								break;
							}
						}
						break;
					}
					case 4:
					{
						system("cls");
						{
							vector<string> columns{
							"1. Sort by Decrease",
							"2. Sort by Descending",
							"0. Exit"
							};
							showMenuCols(columns);
							cinTry(pod_answer);
							switch (pod_answer)
							{
							case 1:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorByAge(doctors_for_sort, 0);
								break;
							case 2:
								vectorToDoctor(matrix, doctors_for_sort);
								sortVectorByAge(doctors_for_sort, 1);
								system("cls");
								break;
							default:
								system("cls");
								callMenu(doctors_db);
								break;
							}
						}
						break;
					}
					default: // sort_type
					{
						system("cls");
						system("pause");
						callMenu(doctors_db);
						break;
					}
					}
					// end of switch  sort
				}
				cout << "======================================" << endl;
				for (auto& i : doctors_for_sort)
				{
					i.print();
					cout << endl;
				}
				/*for (size_t i = 0; i < matrix.size(); i++)
				{
					cout << "------------------------------" << endl;
					for (size_t j = 0; j < matrix[i].size(); j++)
					{
						switch (j)
						{
						case 0:
							cout << "ID : ";
							break;
						case 1:
							cout << "Name : ";
							break;
						case 2:
							cout << "Surname : ";
							break;
						case 3:
							cout << "Fathername : ";
							break;
						case 4:
							cout << "Age : ";
							break;
						case 5:
							cout << "Vocation : ";
							break;
						default:
							break;
						}
						cout << matrix[i][j] <<endl;
					}
					cout << "------------------------------" << endl;
				}*/
				cout << "======================================" << endl;
				}
				system("pause");
				system("cls");
				callMenu(doctors_db);
			}
			case 3:
			{
				
				system("cls");
					vector<string> columns{
						"1. Find with name",
						"2. Find with surname",
						"3. Find with fathername",
						"4. Find with age",
						"0. Exit"
					};
					showMenuCols(columns);
				}
				cinTry(pod_answer);
				switch (pod_answer)
				{
				case 1:
				{
					string name;
					cout << "Enter name..." << endl;
					cinTry(name);
					doctors_db.selectDataWithFields(1, name);
					system("pause");
					system("cls");
					callMenu(doctors_db);
					break;
				}
					break;
				case 2:
				{
					string surname;
					cout << "Enter surname..." << endl;
					cinTry(surname);
					doctors_db.selectDataWithFields(2, surname);
					system("pause");
					system("cls");
					callMenu(doctors_db);
				}
				break;
				case 3:
				{
					string fathername;
					cout << "Enter fathername..." << endl;
					cinTry(fathername);
					doctors_db.selectDataWithFields(3, fathername);
					system("pause");
					system("cls");
					callMenu(doctors_db);
				}
				break;
				case 4:
				{
					string age;
					cout << "Enter age..." << endl;
					cinTry(age);
					doctors_db.selectDataWithFields(4, stoi(age));
					system("pause");
					system("cls");
					callMenu(doctors_db);
				}
				break;
				default:
					system("cls");
					callMenu(doctors_db);
					break;
				}
				system("pause");
				break;
			default:
				break;
			}
			//WorkWithDB::selectData(dir);
			
			system("cls");
			break;
		case 2:
		{
			// Add doctor
			string n, sn, fn, v;
			int age;
			system("cls");
			cout << "================================================" << endl;
			Doctor doctor;
			cout << "\tEnter doctor name: " << endl;
			cinTry(n);
			doctor.setName(n);
			cout << "\tEnter doctor surname: " << endl;
			cinTry(sn);
			doctor.setLastName(sn);
			cout << "\tEnter doctor fathername: " << endl;
			cinTry(fn);
			doctor.setFatherName(fn);
			cout << "\tEnter doctor age: " << endl;
			cinTry(age);
			doctor.setAge(age);
			cout << "\tEnter vocation: " << endl;
			cinTry(v);
			doctor.setVocation(v);
			system("cls");
			doctor.print();
			doctors_db.insertDataPerson(doctor);
			cout << "================================================" << endl;
		}
		system("pause");
		system("cls");
		callMenu(doctors_db);
		break;
		case 3:
		{
			string ans;
			system("cls");
			cout<<"====================================================="<<endl;
			cout << "Do you really want to clear Doctor db? y/n" << endl;
			cinTry(ans);
			cout << "=====================================================" << endl;
			if (ans=="y" || ans== "yes" || ans == "1" || ans == "Y")
			{
				doctors_db.deleteData();
				
			}
			else {
				system("pause");
				system("cls");
				callMenu(doctors_db);
			}
			system("cls");
			callMenu(doctors_db);
		}
		default:
			system("pause");
			system("cls");
			
			callMenu(doctors_db);

			break;
		}
		break;
	case 2:
	break;
	case 3:
		cout << " Function temp" << endl;
		system("pause");
		callMenu(doctors_db);
		break;
	default:
		system("pause");
		break;
		

	}
}


void showMainMenu(WorkWithDB& doctors_db)
{
	try {
		callMenu(doctors_db);
	}
	catch (const invalid_argument& invalid) {
		cerr << invalid.what() << endl;
		system("cls");
		cout << "=============================================" << endl;
		cerr << "        Error returned to main menu...\a" << endl;
		cout << "             Press any key..." << endl;
		cout << "=============================================" << endl;
		system("pause");
		system("cls");
		callMenu(doctors_db);
	}
	catch (...) {
		system("cls");
		cout << "=============================================" << endl;
		cerr << "        Error, returned to main menu...\a" << endl;
		cout << "             Press any key..." << endl;
		cout << "=============================================" << endl;
		system("pause");
		system("cls");
		callMenu(doctors_db);
		
	}
}

void vectorToDoctor(const vector<vector<string>>& string_v, vector<Doctor>& doctors)
{
	Doctor temp;
	for (size_t i = 0; i < string_v.size(); i++)
	{
		for (size_t j = 1; j < 6; j++)
		{
			if (j==1)
			{
				temp.setName(string_v[i][j]);
			}
			else if (j == 2) {
				temp.setLastName(string_v[i][j]);
			}
			else if (j == 3) {
				temp.setFatherName(string_v[i][j]);
			}
			else if (j == 4) {
				temp.setAge(stoi(string_v[i][j]));
			}
			else if (j == 5) {
				temp.setVocation((string_v[i][j]));
			}
			
		}
		doctors.push_back(temp);
	}
}

void sortVectorByName(vector<Doctor>& doctors, const bool& type)
{
	Doctor temp;
	if (!type)
	{
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getName() > doctors[j + 1].getName())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
	else {
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getName() < doctors[j + 1].getName())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
}

void sortVectorBySurname(vector<Doctor>& doctors, const bool& type)
{
	Doctor temp;
	if (!type)
	{
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getLastName() > doctors[j + 1].getLastName())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
	else {
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getLastName() < doctors[j + 1].getLastName())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
}

void sortVectorByFathername(vector<Doctor>& doctors, const bool& type)
{
	Doctor temp;
	if (!type)
	{
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getFatherName() > doctors[j + 1].getFatherName())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
	else {
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getFatherName() < doctors[j + 1].getFatherName())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
}

void sortVectorByAge(vector<Doctor>& doctors, const bool& type)
{
	Doctor temp;
	if (!type)
	{
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getAge() > doctors[j + 1].getAge())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
	else {
		int i, j;
		for (i = 0; i < doctors.size() - 1; i++) {

			// Last i elements are already in place  
			for (j = 0; j < doctors.size() - i - 1; j++) {
				if (doctors[j].getAge() < doctors[j + 1].getAge())
				{
					temp = doctors[j];
					doctors[j] = doctors[j + 1];
					doctors[j + 1] = temp;
				}
			}

		}
	}
}




