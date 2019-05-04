// IPR2_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <iostream>
#include <string>

#define PRIME_SIZE 29

using namespace std;

class Line
{
public:
	Line *next;
	string value;

	Line()
	{
		this->next = NULL;
	}

	Line(string value)
	{
		this->value = value;
		this->next = NULL;
	}

	~Line()
	{
		//cout << "Delete " << this->value << endl;
		if (this->next != NULL)
		{
			delete this->next;
		}
	}
};

class HashTable // РҐРµС€-С‚Р°Р±Р»РёС†Р°, РїСЂРµРґСЃС‚Р°РІР»РµРЅРЅР°СЏ РІ РІРёРґРµ РјР°СЃСЃРёРІР° СЌР»РµРјРµРЅС‚РѕРІ (РєРѕС‚РѕСЂС‹Рµ РІ СЃРІРѕСЋ РѕС‡РµСЂРµРґСЊ РїСЂРµРґСЃС‚Р°РІР»СЏСЋС‚ СЃРїРёСЃРѕРє).
{
	Line *table[PRIME_SIZE];

	static int hash(string str)
	{
		int asciisum = 0;
		for (int i = 0; i < str.length(); i++)
		{
			asciisum += str[i];
		}
		return asciisum % PRIME_SIZE;
	}

public:

	HashTable()
	{
		for (int i = 0; i < PRIME_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	~HashTable()
	{
		//cout << "Delete table\n";
		for (int i = 0; i < PRIME_SIZE; i++)
		{
			delete table[i];
		}
	}

	void push(string value)
	{
		int hashNumber = hash(value);
		Line *pers = new Line(value);
		Line *place = table[hashNumber];
		if (place == NULL)
		{
			table[hashNumber] = pers;
			return;
		}

		while (place->next != NULL)
		{
			place = place->next;
		}
		place->next = pers;
	}

	Line* find(string value)
	{
		int hashNumber = hash(value);
		Line *result = table[hashNumber];
		if (!result)
		{
			cout << "Element not found" << endl;
			return NULL;
		}
		while (result->value != value)
		{
			if (!result->next)
			{
				cout << "Element not found" << endl;
				break;
			}
			result = result->next;
		}
		return result;
	}
};

int main()
{
	HashTable newTable;
	newTable.push("Anaconda");
	newTable.push("Rabbit");
	newTable.push("Squirrel");
	newTable.push("Bison");
	newTable.push("Fox" );

	Line * search = newTable.find("Bison");
	if (search)
	{
		cout << search->value << endl;
	}

	return 0;
}


