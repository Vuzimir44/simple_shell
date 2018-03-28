#include "holberton.h"
unsigned int find_command_length(char *s)
{
	unsigned int commands, i, flag;

	flag = 0;
	commands = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			flag = 1;

		if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
		{
			++commands;
			flag = 0;
		}
		++i;
	}
	return (commands);
}
char **array_from_strtok(char *str)
{
	char **token_holder;
	char *token;
	unsigned int length;
	int i;

	str[_strlen(str) - 1] = '\0';
	length = find_command_length(str);
	if (length == 0)
		return (NULL);

	token_holder = malloc((sizeof(char *)) * (length + 1));
	if (token_holder == NULL)
		return (NULL);
	i = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		token_holder[i] = malloc(_strlen(token) + 1);
		if (token_holder[i] == NULL)
		{
			free_all_double_ptr(token_holder);
			return (NULL);
		}
		_strncpy(token_holder[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		++i;
	}
	token_holder[i] = NULL;
	return (token_holder);
}
