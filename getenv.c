#include "shell.h"

/**
 * get_location - returns the string array copy of our environ
 * @input: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_location(input_t *input)
{
	if (!input->environ || input->env_changed)
	{
		input->environ = list_to_strings(input->env);
		input->env_changed = 0;
	}

	return (input->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @input: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(input_t *input, char *var)
{
	list_t *node = input->env;
	size_t i = 0;
	char *ptr;

	if (!node || !var)
		return (0);

	while (node)
	{
		ptr = starts_with(node->s, var);
		if (ptr && *ptr == '=')
		{
			input->env_changed = delete_node_at_index(&(input->env), i);
			i = 0;
			node = input->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (input->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @input: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @num: the string env var value
 *  Return: Always 0
 */
int _setenv(input_t *input, char *var, char *num)
{
	char *store = NULL;
	list_t *node;
	char *ptr;

	if (!var || !num)
		return (0);

	store = malloc(_strlen(var) + _strlen(num) + 2);
	if (!store)
		return (1);
	_strcpy(store, var);
	_strcat(store, "=");
	_strcat(store, num);
	node = input->env;
	while (node)
	{
		ptr = starts_with(node->s, var);
		if (ptr && *ptr == '=')
		{
			free(node->s);
			node->s = store;
			input->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(input->env), store, 0);
	free(store);
	input->env_changed = 1;
	return (0);
}
