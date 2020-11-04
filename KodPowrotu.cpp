#include <iostream>

using namespace std;


/*
	argc - ostatni indeks tablicy argv (nigdy nie jest ujemny)
	argv - tablica wskaznikow do ciagow, ktore pokazuja parametry programu
	envp - tablica wskaznikow do zmiennych srodowiskowych


		puts("argumenty programu");
	for (int k = 0; k < argc; k++)
	{
		puts(argv[k]);
	}

	puts("zmienne œrodowiskowe");

	while (*envp != NULL)
	{
		puts(*envp++);
	}

*/

bool isSilent(char argv[])
{
	if ((string)argv == "/s" || (string)argv == "/S")
	{
		return true;
	}
	return false;
}


int main(int argc, char* argv[])
{
	bool silent = false;

	for (int i = 0; i < argc; i++)
	{
		if (isSilent(argv[i]))
		{
			silent = true;
		}
	}

	if (argc == 1)
	{
		cout << 11;
		return 11;
	}
	else if (argc == 2 && silent)
	{
		return 11;
	}
	else if (argc == 2 && !silent)
	{
		//na pewno wyswietlam

		if (!isdigit(*argv[argc - 1]))
		{
			cout <<12;
			return 12;
		}
		else
		{
			cout << argv[argc - 1];
			return (int)argv[argc - 1];
		}
	}
	else if (argc > 2)
	{
		if (!silent)
		{
			cout << 13;
		}

		return 13;
	}

}