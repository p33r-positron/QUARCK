#include <stdio.h>
#include "quarck.h"

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		fputs("Utilisation: quacklire <fichier>\r\n", stderr);
		return 1;
	}

	FILE* in = NULL;
	in = fopen(argv[1], "r");

	if(!in)
	{
		fputs("Erreur pendant l'ouverture du fichier.\r\n", stderr);
		return 1;
	}

	char c;
	for(;;)
	{
		c = fgetc(in);
		if(c == EOF)
			break;

		put2qckar(c);
	}

	return 0;
}