#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[], char** envp)
{
	string line = "";
	string col = "";
	string row[4];
	while (getline(cin, line))	//biore kazda kolumne
	{
		stringstream data;
		data << line;			//pole w kolumnie
		for (int i = 0; i < 4; i++)
		{
			getline(data, col, '\t');
			row[i] = col;		//dopisuje kolumne do tablicy
		}
		for (int i = 1; i < argc; i++) // dla kazego parametru oprocz pocz¹tkowego
		{
			if (*argv[i] == '1')
			{
				cout << row[0] << '\t';
			}
			else if (*argv[i] == '2')
			{
				cout << row[1] << '\t';
			}
			else if (*argv[i] == '3')
			{
				cout << row[2] << '\t';
			}
			else if (*argv[i] == '4')
			{
				cout << row[3] << '\t';
			}
		}
		cout << endl;
	}
}