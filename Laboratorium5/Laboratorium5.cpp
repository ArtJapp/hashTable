// Laboratorium5.cpp:
//				������� ������������ ���������, ������� ������������ ����� ��� �������, 
//				�������� ������� ����� ��������� ��������� ������� � ����������� ��� ����� ������� ����� ������ � ������ �������� ������.

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

int getHashKey(Student Person)
{
	return Person.recordBook % 10;
}

void printStudent(Student person)
{
	cout << person.firstName << '\t' << person.lastName << '\t' << "����: " <<person.course << '\t' << "������: " << person.group << "���������: " << person.recordBook << endl;
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
		cout << " �������";
	}
}

void printTable(HashTable ** hash)
{
	for (int i = 0; i < 10; i++)
	{
		cout << " \n������ " << i << " �������� � ����: ";
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

