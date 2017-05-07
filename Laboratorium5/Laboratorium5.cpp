// Laboratorium5.cpp:
//				������� ������������ ���������, ������� ������������ ����� ��� �������, 
//				�������� ������� ����� ��������� ��������� ������� � ����������� ��� ����� ������� ����� ������ � ������ �������� ������.

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Student
{
	char * firstName;
	char * lastName;
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
	cout << "\n������� �������: ";
	char firstName[50];
	cin >> firstName;
	cout << "\n������� ���: ";
	char lastName[50];
	cin >> lastName;
	cout << "\n������� ������: ";
	int group;
	cin >> group;
	cout << "\n������� ����: ";
	int course;
	cin >> course;
	cout << "\n������� ����� �������� ������: ";
	int recordBook;
	cin >> recordBook;

	Student tempPerson;
	tempPerson.firstName = firstName;
	tempPerson.lastName = lastName;
	tempPerson.group = group;
	tempPerson.course = course;
	tempPerson.recordBook = recordBook;

	return tempPerson;
}

int getHashKey(int recordBook)
{
	return recordBook % 10;
}

void printStudent(Student person)
{
	cout << person.firstName << '\t' << person.lastName << '\t' << "����: " <<person.course << '\t' << "������: " << person.group << "���������: " << person.recordBook << endl;
}

void printList(HashTable *& hash)
{
	if (hash != NULL)
	{
		while (hash != NULL)
		{
			printStudent(hash->Person);
			cout << endl;
			printList(hash->next);
		}
	}
	else
	{
		cout << "is empty";
	}
}

void printTable(HashTable ** hash)
{
	for (int i = 0; i < 10; i++)
	{
		cout << " \n������ " << i << " �������� � ����:\n";
		printList(*&hash[i]);
	}
}

int main()
{
    return 0;
}

