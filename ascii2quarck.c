#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc != 2 && argc != 3)
	{
		fputs("Utilisation: ascii2quarck <fichierASCII> [fichierQUARCK]\r\n", stderr);
		return 1;
	}

	FILE *in = NULL, *out = NULL;
	in = fopen(argv[1], "r");
	if(!in)
	{
		fputs("Erreur pendant l'ouverture du fichier ASCII.\r\n", stderr);
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
		fputs("Erreur pendant l'ouverture du fichier QUARCK.\r\n", stderr);
		return 1;
	}

	fseek(in, 0, SEEK_END);
	unsigned int file_size = ftell(in);
	char* whole_file = (char*) malloc(file_size+1);
	if(!whole_file)
	{
		fputs("Erreur RAM.\r\n", stderr);
	}
	fseek(in, 0, SEEK_SET);
	fread(whole_file, sizeof(char), file_size, in);
	

	char c, tmp;
	for(unsigned int i = 0 ; i < file_size ; i++)
	{
		c = whole_file[i];
		if(c == EOF)
			break;

		if(c >= 'A' && c <= 'M')
			fputc(0b11110000 | (c - 64), out);
		else if(c >= 'N' && c <= 'Z')
		{
			fputc(0b11101111, out);
			fputc((c - 77) << 4, out);
		}
		else if(c >= 'a' && c <= 'm')
		{
			fputc((c - 96) << 4, out);
		}
		else if(c >= 'n' && c <= 'z')
			fputc(0b11100000 | (c - 96), out);
		else if(c == ' ')
			fputc(0, out);
		else if(c == '\n')
			fputc(0b11101110, out);
		else if(!c)
			fputc(0, out);
		//Otherwise it is a non-QUARCK char
	}

	return 0;
}