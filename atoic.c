 #include "shell.h"

/**
 * * _atoi - converts a string into an integer
 * *@str: pointer to a string
 * *Return: the integer
 * */
int _atoi(char *str)
{
	int index, num, 
	    sign = 1;

	index = 0;
	num = 0;
	while (!((str[index] >= '0') && (str[index] <= '9')) && (str[index] != '\0'))
	{
		if (str[index] == '-')
		{
			sign = sign * (-1);
		}
		index++;
	}
	while ((str[index] >= '0') && (str[index] <= '9'))
	{
		num = (num * 10) + (sign * (str[index] - '0'));
		index++;
	}
	return (num);
}
