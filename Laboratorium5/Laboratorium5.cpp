// Laboratorium5.cpp:
//				Создать динамическую структуру, которая представляет собой хеш таблицу, 
//				значения которой могут принимать структуру Студент с параметрами для имени фамилии курса группы и номера зачетной книжки.

#include "stdafx.h"
#include <iostream>
#include <cstring>
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

int getHashKey(Student Person)
{
	return Person.recordBook % 10;
}

void printStudent(Student person)
{
	cout << person.firstName << '\t' << person.lastName << '\t' << "курс: " <<person.course << '\t' << "группа: " << person.group << "ЗачКнижка: " << person.recordBook << endl;
}

void printList(HashTable *& hash)
{
	if (hash != NULL)
	{
			cout << endl;
			cout << '\t';
			printStudent(hash->Person);

			if (hash->next != NULL)
				printList(hash->next);
	}
	else
	{
		cout << " пустоту";
	}
}

void printTable(HashTable ** hash)
{
	for (int i = 0; i < 10; i++)
	{
		cout << " \nСтрока " << i << " содержит в себе: ";
		printList(*&hash[i]);
	}
	cout << endl;
}

HashTable * search(HashTable *& hash, int recordBook)
{
	if (hash == NULL)
	{
		return NULL;
	}
	if (hash->Person.recordBook == recordBook)
	{
		return hash;
	}
	else
	{
		search(hash->next, recordBook);
	}
}

void addElement(HashTable *& hash, Student Person)
{
	if (hash == NULL)
	{
		hash = new HashTable;
		hash->key = getHashKey(Person);
		hash->Person = Person;
		hash->next = NULL;
	}
	else
	{
		addElement(hash->next, Person);
	}
}

int main()
{
	setlocale(0, "RUSSIAN");
	HashTable ** hash = new HashTable*[10];
	for (int i = 0; i < 10; i++)
	{
		hash[i] = NULL;
	}
	printTable(hash);
	Student st = createPerson();
	addElement(*&hash[getHashKey(st)], st);
	st = createPerson();
	addElement(*&hash[getHashKey(st)], st);
	printTable(hash);
	system("pause");
    return 0;
}

