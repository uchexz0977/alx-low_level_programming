#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member - Dog's name
 * @age: Second member - Dog's age
 * @owner: Third member - Dog's owner
 *
 * Description: This struct defines the basic information of a dog.
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

/**
 * init_dog - Initializes a dog structure
 * @d: Pointer to the dog structure
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - Prints the information of a dog
 * @d: Pointer to the dog structure
 */
void print_dog(struct dog *d);

/**
 * new_dog - Creates a new dog structure
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 * Return: Pointer to the newly created dog structure
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - Frees memory allocated for a dog structure
 * @d: Pointer to the dog structure to be freed
 */
void free_dog(dog_t *d);

/**
 * _strcpy - Copies the string pointed to by src, including the null byte,
 * to the buffer pointed to by dest.
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src);

/**
 * _strlen - Computes the length of a string
 * @s: Input string
 * Return: Length of the string
 */
int _strlen(char *s);

#endif /* DOG_H */

