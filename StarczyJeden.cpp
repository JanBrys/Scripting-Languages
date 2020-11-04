#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isInVector(string word, vector<string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == word)
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[], char** envp)
{
	string line = "";
	string col = "";
	float sum = 0;
	vector<string> vec;
	bool is_in_row = false;
	while (getline(cin, line))	//biore kazda kolumne
	{
		vec.clear();
		is_in_row = false;
		stringstream data;
		data << line;			//pole w kolumnie
		while (getline(data, col, '\t'))
		{
			vec.push_back(col);
		}
		for (int i = 1; i < argc; i++) // dla kazego parametru oprocz pocz¹tkowego
		{
			if (isInVector(argv[i], vec))
			{
				is_in_row = true;
			}
		}
		if (is_in_row)
		{
			cout << line << endl;
		}

	}
}