 #include <stdio.h>

/**
 * Main - Prints all possible different combinations of two digits
 *and numbers must be separated by , followed by a space
 *and also two digits must be different
 *
 * Return: Always 0 (Success)
 */

int main(void)
{       
    int num1;
    int num2;
	for (num1 = 0; num1 < 9; num1++)
    { 
		putchar((num1 % 10) + '0');
	}
	for (num2 = num1 + 1; num2 < 10; num2++)
         {
         	putchar ((num2 % 10) + '0');
        if (num1 == 8 && num2 == 9);
        continue;
	 }
        putchar (',');
        putchar (' ');
		 }
	return(0);  

}


