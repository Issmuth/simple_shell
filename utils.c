#include "shell.h"

/**
 * reverse - reverses string
 * @str: string
 * @len: string length
 */

void reverse(char *str, int len)
{
	int start = 0, end = len - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * _itoa - converts integer to string
 * @n: number to convert
 *
 * Return: pointer to converted string
 */

char *_itoa(int n)
{
	int is_negative = 0, count = 0, temp;
	int i = 0, digit, size;
	char *str;

	if (n < 0)
	{
		is_negative++;
		n *= -1;
	}
	
	temp = n;
	if (n != 0)
	{
		while (temp != 0)
		{
			count++;
			temp /= 10;
		}
	} else
		count = 1;

	size = count + is_negative + 1;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);

	while (n != 0)
	{
		digit = n % 10;
		str[i++] = (char)(digit + '0');
		n /= 10;
	}

	if (is_negative)
		str[i++] = '-';

	str[i] = '\0';

	reverse(str, i);
	return (str);
}

/**
 * _atoi - convert string to integer
 * @str: string to be converted
 *
 * Return: converted number
 */

int _atoi(char *str)
{
	int i, is_negative = 1;
	int flag = 0, value;
	size_t result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			is_negative *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			flag = 1;
		} else if (flag == 1)
			flag = 2;
	}
	if (is_negative == -1)
	{
		value = -result;
	} else
		value = result;

	return (value);
}

