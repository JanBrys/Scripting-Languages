#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool isSilent(char argv[])
{
	if ((string)argv == "/s" || (string)argv == "/S")
	{
		return true;
	}
	return false;
}


int main(int argc, char* argv[], char** envp)
{
	bool silent = false;

	/*
		puts("zmienne œrodowiskowe");
	
	while (*envp != NULL)
	{
		puts(*envp++);
	}
	*/
	if (argc > 1)
	{
		for (int i = 0; i < argc; i++)
		{
			if (isSilent(argv[i]))
			{
				silent = true;
			}
		}
		//cout << envp[0];

		//pobieram wszystkie parametry z argv i wstawiam do vectora
		vector <string> parameters;

		//wpisuje do wektora wszystkie parametry oprocz trybu cichego i lokacji pliku
		for (int i = 0; i < argc; i++)
		{
			if (argv[i] != "/S" && argv[i] != "/s" && argv[i] != argv[0])
			{
				parameters.push_back((argv[i]));
			}
		}
		vector<string> env;
		vector<char> details;
		string param = "";
		string value = "";

		int foo = 0;

		while (*envp != NULL)
		{
			env.push_back(*envp++);
		}
		for (int i = 0; i < env.size(); i++)
		{
			for (int j = 0; j < env[i].size(); j++)
			{
				if (env[i][j] != '=' && foo<j)
				{
					param += env[i][j];
					
				}
				else if(j<foo)
				{
					value += env[i][j];
				}
				else if(env[i][j]=='=')
				{
					foo = j;
				}
			}
			for (int a = 0; a < parameters.size(); a++)
			{
				if (parameters[a] == param)
				{
					cout << param << endl;
					cout << "=" << endl;
					cout << value;
				}
			}
			param = "";
			value = "";
			foo = 0;
		}
	}
	
}