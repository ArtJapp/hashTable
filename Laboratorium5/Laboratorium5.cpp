// Laboratorium5.cpp:
//				Создать динамическую структуру, которая представляет собой хеш таблицу, 
//				значения которой могут принимать структуру Студент с параметрами для имени фамилии курса группы и номера зачетной книжки.

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
	cout << "\nВведите фамилию: ";
	char firstName[50];
	cin >> firstName;
	cout << "\nВведите имя: ";
	char lastName[50];
	cin >> lastName;
	cout << "\nВведите группу: ";
	int group;
	cin >> group;
	cout << "\nВведите курс: ";
	int course;
	cin >> course;
	cout << "\nВведите номер зачетной книжки: ";
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
	cout << person.firstName << '\t' << person.lastName << '\t' << "курс: " <<person.course << '\t' << "группа: " << person.group << "ЗачКнижка: " << person.recordBook << endl;
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
		cout << " \nСтрока " << i << " содержит в себе:\n";
		printList(*&hash[i]);
	}
}

int main()
{
    return 0;
}

