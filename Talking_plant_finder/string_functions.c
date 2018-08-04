#include "string_functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>	/* exit() */
char* concat(const char *s1, const char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1);//+1 for the null-terminator
													   //in real code you would check for errors in malloc here
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}


char* integer_to_string(int x)
{
	char* buffer = malloc(sizeof(char) * sizeof(int) * 4 + 1);
	if (buffer)
	{
		sprintf(buffer, "%d", x);
	}
	return buffer; // caller is expected to invoke free() on this buffer to release memory	
}


