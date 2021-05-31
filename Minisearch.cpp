#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;
int j = 0;
bool checkfile[3] = { 0 }, found = false;
fstream files[3];
ofstream files2[3];
const string filesNames[3] = { "file1.txt", "file2.txt", "file3.txt" }, filesNames2[3] = { "1.txt", "2.txt", "3.txt" };
string test1 = "0", test2 = "0", stringTest[1000], stringTest2[1000], test;
int op;
void ASCII(string& test1, string& test2)
{
	cout << "Type your word: ";
	cin >> test1;
	test2 = test1;
	if (test1[0] >= 'A' && test1[0] <= 'Z')
		test2[0] += 32;
	else if (test1[0] >= 'a' && test1[0] <= 'z')
		test2[0] -= 32;
}
void find(string& test1, string& test2)
{
	for (int i = 0; i < 3; i++)
	{
		files[i].open(filesNames[i]);
		while (!files[i].eof())
		{
			files[i] >> stringTest[j];
			if (stringTest[j] == test1 || stringTest[j] == test2)
			{
				found = true;
				checkfile[i] = true;
				j = 0;
				break;
			}
			j++;
		}
		files[i].close();
	}
}
bool show()
{
	if (found)
	{
		cout << "Your word was found in those files :\n";
		for (int i = 0; i < 3; i++)
		{
			if (checkfile[i] == true)
				cout << filesNames[i] << endl;

		}
		return true;
	}
	return false;
}
void deleted()
{
	for (int i = 0; i < 3; i++)
	{
		j = 0;
		files[i].open(filesNames[i]);
		while (!files[i].eof())
		{
			files[i] >> test;
			if (test == test1 || test == test2)
				continue;
			stringTest2[j] = test;
			j++;
		}
		j = 0;
		files2[i].open(filesNames2[i]);
		while (stringTest2[j] != "\0")
		{
			files2[i] << stringTest2[j] << endl;
			j++;
		}
		j = 0;
		files[i].close();
		files2[i].close();
		if (i == 0)
		{
			remove("file1.txt");
			rename("1.txt", "file1.txt");
		}
		if (i == 1)
		{
			remove("file2.txt");
			rename("2.txt", "file2.txt");
		}
		if (i == 2)
		{
			remove("file3.txt");
			rename("3.txt", "file3.txt");
		}
	}
}
void manipulations()
{
	cout << "Choose the operation you want to do on the word\n" << "1: delete\n2: update\n3: append\n4: try again\n 5: exit\n";
	cin >> op;
	if (op == 1)
		deleted();
}

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		stringTest[i] = "\0";
		stringTest2[i] = "\0";
	}
	ASCII(test1, test2);
	find(test1, test2);
	if (show())
	{
		manipulations();
	}
}
/*
* 1- want to try struct for name of files and thier object
* 2- making string with  pass it before initialize it is wrong !!
* 3-
*
*
*
*
*/