/* FIXME: Implement! */
#include <stdio.h>

char smallest_character(char str[], char c){
	int size;
	for(size=0; str[size]!=127; size++)
		if(str[size] > c)
			return str[size];
	return str[0];
}

int main()
{
	char in[] = {'c', 'f', 'j', 'p', 'v'};
	
	printf("%c\n", smallest_character(in, 'c'));

	return 0;
}
