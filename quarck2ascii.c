#include <stdio.h>
#include <stdlib.h>
#include "quarck.c"

int main(int argc, char** argv)
{
	if(argc != 2 && argc != 3)
	{
		fputs("Utilisation: quarck2ascii <fichierQUARCK> [fichierASCII]\r\n", stderr);
		return 1;
	}

	FILE *in = NULL, *out = NULL;
	in = fopen(argv[1], "r");
	if(!in)
	{
		fputs("Erreur pendant l'ouverture du fichier QUARCK.\r\n", stderr);
		return 1;
	}
	char* outfile_name;
	if(argc == 3)
		out = fopen(argv[2], "w");
	else
	{
		outfile_name = (char*) malloc(sizeof(argv[2]) + 7);
		sprintf(outfile_name, "%s.quarck", argv[2]);
		out = fopen(outfile_name, "w");
		free(outfile_name);
	}
	if(!out)
	{
		fputs("Erreur pendant l'ouverture du fichier ASCII.\r\n", stderr);
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