#include "shell.h"

/**
 * _strcat - conactenate strings
 * @dest: where it's concactenated.
 * @src: string to be concactenated
 *
 * Return: Pointer to concactenated string.
 */
char *_strcat(char *dest, const char *src)
{
	const char *stemp;
	char *dtemp;

	stemp =  src;
	dtemp = dest;

	while (*dtemp != '\0')
		dtemp++;

	while (*stemp != '\0')
		*dtemp++ = *stemp++;

	*dtemp = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @str1: ...
 * @str2: ...
 *
 * Return: byte difference with
 * respect to str1.
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}

/**
 * _strlen - Returns the length of a string.
 * @str: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (len);

	while (str[len])
		len++;

	return (len);
}

/**
 * _strcpy - Copies string content from
 * source to destination
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	if (!dest || !src)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - allcoates memory and duplicate
 * the content of the string
 * @str: string to be duplicated
 *
 * Return: pointer to duplicate string
 */

char *_strdup(const char *str)
{
	int i, len;
	char *new;

	if (!str)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;

	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);

	for (i = 0; i < len; i++)
		new[i] = str[i];

	new[len] = str[len];
	return (new);
}
