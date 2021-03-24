#pragma once
#include "Lib.h"
#include "WorkWithDB.h"
template <typename T>
void cinTry(T& data);
template<typename T>
inline void cinTry(T& data)
{
    if (!(cin >> data))
    {
        throw InvalidArgumentChoise("Invalid entry, returned to main menu");
    }
}

void showDoctorMenu();
void callMenu(WorkWithDB& doctors_db);
template <typename T>
void bubbleSortVectorMatrix(vector<vector<string>>& matrix, const int& row);
void showMainMenu(WorkWithDB& doctors_db);
void vectorToDoctor(const vector<vector<string>>& string_v, vector<Doctor>& doctors);
void sortVectorByName(vector<Doctor> &doctors, const bool& type);
void sortVectorBySurname(vector<Doctor> &doctors, const bool& type);
void sortVectorByFathername(vector<Doctor> &doctors, const bool& type);
void sortVectorByAge(vector<Doctor> &doctors, const bool& type);
template<typename T>
inline void bubbleSortVectorMatrix(vector<vector<string>>& matrix, const int& row)
{
	vector<vector<string>> tmp = matrix;

	int i, j;
	T temp;
	for (i = 0; i < matrix.size() - 1; i++)
	{
		for (j = 0; j < matrix.size() - i - 1; j++)
		{
			if (matrix[j][row] > matrix[j + 1][row])
			{
				temp = matrix[j + 1][row];
				matrix[j + 1][row] = matrix[j][row];
				matrix[j][row] = temp;
				for (size_t b = 0; b < matrix.size()-i-1; b++)
				{
					if (b==row)
					{
						tmp[j][row] = matrix[j][b-1];
					}
					tmp[j][b] = matrix[j][b];
				}
			}
		}

	}
	matrix = tmp;
}

