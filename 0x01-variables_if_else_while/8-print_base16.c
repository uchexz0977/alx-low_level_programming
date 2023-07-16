#include <stdio.h>

/**
 * Main - Prints numbers between 0 and 9
 * and letters between a to f 
 *
 * Return: Always 0 (Success)
 */

int main(){
	int num;
	char alphabet;
	for(num=0; num<=9; num++)
	{
		putchar((num%10) + '0');
	}
	for(alphabet='a'; alphabet<='f'; alphabet++)
	{
		putchar(alphabet);
	}
	putchar('\n');

	return(0);
}
