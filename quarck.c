#include "quarck.h"
#include <stdio.h>

const char quarck_table[14] = {0, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
char quarck_var_isExt_, quarck_var_isMaj_;
int quarck_var_err_ = 0;

int putqckar(char qckar)
{
	return fputqckar(qckar, stdout);
}

int put2qckar(char double_qckar)
{
	return fput2qckar(double_qckar, stdout);
}

int putsqck(char* qckar_str)
{
	while(*qckar_str)
		quarck_var_err_ |= put2qckar(*qckar_str++);
	return quarck_var_err_;
}

int fputqckar(char qckar, FILE* stream)
{
	if(qckar == 14)
		quarck_var_isExt_ = 13;
	else if(qckar == 15)
		quarck_var_isMaj_ = 32;
	else if(!qckar)
		quarck_var_isExt_ = (quarck_var_isMaj_ = 0);
	else
	{
		qckar = quarck_table[qckar];
		qckar += quarck_var_isExt_;
		qckar -= quarck_var_isMaj_;
		quarck_var_isExt_ = (quarck_var_isMaj_ = 0);
		return fputc(qckar, stream);
	}

	return 0;
}

int fput2qckar(char double_qckar, FILE* stream)
{
	if(double_qckar == 0)
		return fputc(' ', stream);
	return fputqckar((double_qckar & 0xF0) >> 4, stream) | fputqckar(double_qckar & 0x0F, stream);
}

int fputsqck(char* qckar_str, FILE* stream)
{
	while(*qckar_str)
		quarck_var_err_ |= put2qckar(*qckar_str++);
	return quarck_var_err_;
}