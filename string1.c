#include "shell.h"
#include <unistd.h>

/**
 * _strcpy - copies a string
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{

	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{

		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{

	int length = 0;
	char *rest;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	rest = malloc(sizeof(char) * (length + 1));
	if (!rest)
		return (NULL);
	for (length++; length--;)
		rest[length] = *--str;
	return (rest);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: none
 */
void _puts(char *str)
{

	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{

		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c  to stdout
 * @c: the character to be printed
 *
 * Return: on success 1.
 * on error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{

	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{

		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1); 

}