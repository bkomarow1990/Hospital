#pragma once
#include "Lib.h"
void showDoctorMenu() {
	cout << "1. Show all doctors" << endl;
	cout << "2. Add new doctor" << endl;
	cout << "0. Exit" << endl;
}
void showMainMenu() {
	int answer;
	int pod_answer;
	cout << "1. Doctor menu "<<endl;
	cout << "2. Patient menu "<<endl;
	cout << "0. Exit "<<endl;
	cin >> answer;
	switch (answer)
	{
	case 1:
		showDoctorMenu();
		switch (pod_answer)
		{
		case 1:

			break;
		default:
			break;
		}
		break;
	default:
		system("pause");
		exit(0);
	}
}
