/* FIXME: Implement! */
#include <stdio.h>

char smallest_character(char str[], char c, int index){
	if(str[index]!=127){
		if(str[index] > c)
			return str[index];
		else
			return smallest_character(str, c, (index+1));
	}
	return str[0];
}

int main()
{
	char in[] = {'c', 'f', 'j', 'p', 'v'};
	
	printf("%c\n", smallest_character(in, 'z', 0));

	return 0;
}
