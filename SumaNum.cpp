#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isStringADigit(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (!isdigit(word[i]) && word[i] != '.')
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[], char** envp)
{
	string line = "";
	string col = "";
	float sum = 0;
	while (getline(cin, line))	//biore kazda kolumne
	{
		stringstream data;
		data << line;			//pole w kolumnie
		while(getline(data, col, '\t'))
		{
			if (isStringADigit(col) && col.length()!=10)
			{
				sum += stof(col);
			}
		}
	}
	cout << "Suma: " << sum;
}