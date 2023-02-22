#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to be evaluated
 *
 * Return: the string lenth
 */
int _strlen(char *s)
{

	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicographic comparison of to two stings
 * @s1: first string
 * @s2: second string
 *
 * Return: a negative number if s1 < s2, Positive if s1 > s2, zero if s1 is= s2
 */
int _strcmp(char *s1, char *s2)
{

	while ((*s1)++ && (*s2)++) /* while loop shortened*/
	{

		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - finds a needle sub-string in haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{

	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{

	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
