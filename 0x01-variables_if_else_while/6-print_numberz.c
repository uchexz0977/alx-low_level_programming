#include <stdio.h>

/**
 * Main - Prints numbers 0 to 9
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
    int n;
    for (n = 0; n < 10; n++)
    {
        putchar ((n % 10) + '0');
    }
    
    printf ("\n");
    
    return(0);
}

