// Laboratorium5.cpp:
//				Создать динамическую структуру, которая представляет собой хеш таблицу, 
//				значения которой могут принимать структуру Студент с параметрами для имени фамилии курса группы и номера зачетной книжки.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include "time.h"
#include "durak.h"

using namespace std;

struct Student
{
	string firstName;
	string lastName;
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
	string firstName;
	cin >> firstName;
	cout << "Введите имя: ";
	string lastName;
	cin >> lastName;
	cout << "Введите группу: ";
	int group;
	cin >> group;
	cout << "Введите курс: ";
	int course;
	cin >> course;
	cout << "Введите номер зачетной книжки: ";
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
	cout << "Фамилия: " << person.firstName << '\t' << "Имя: " << person.lastName << '\t' << "курс: " << person.course << '\t' << "группа: " << person.group << '\t' << "ЗачКнижка: " << person.recordBook << endl;
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

	enum comands { EXIT, PRINT, ADD, DELETE };
	cout << "Команды:\n"
		<< "\t 1. Печать списка\n"
		<< "\t 2. Добавить новый элемент\n"
		<< "\t 3. Удалить элемент\n"
		<< "\t 0. Выход\n";
	comands operation = (comands)input();
	while (operation)
	{
		switch (operation)
		{
		case PRINT: {
			printTable(*&hash);
			break;
		}
		case ADD: {
			Student person = createPerson();
			addElement(*&hash[getHashKey(person)], person);
			break;
		}
		case EXIT: {
			return 0;
		}
		}
		cout << "Команды:\n"
			<< "\t 1. Печать списка\n"
			<< "\t 2. Добавить новый элемент\n"
			<< "\t 3. Удалить элемент\n"
			<< "\t 0. Выход\n";
		operation = (comands)input();

	}
	system("pause");
    return 0;
}

