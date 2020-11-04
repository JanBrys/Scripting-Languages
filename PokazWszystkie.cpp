#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[], char** envp)
{
	puts("argumenty programu");
	for (int k = 0; k < argc; k++)
	{
		puts(argv[k]);
	}

	cout << endl;

	puts("zmienne œrodowiskowe");

	while (*envp != NULL)
	{
		puts(*envp++);
	}
}
