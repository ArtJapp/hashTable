// Laboratorium5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Student
{
	char firstName[50];
	char lastName[50];
	int course;
	int group;
	int recordBook;
};
struct HashTable
{
	int key;
	Student Person;
	HashTable * next;
};

Student createPerson()
{
	cout << "\n������� ������� ��� ������ ���� ����� �������� ������:";
	char firstName[50];
	char lastName[50];
	int group;
	int course;
	int recordBook;
}

int main()
{
    return 0;
}

