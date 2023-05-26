#include "shell.h"


/**
 * shell_env - prints the current environment
 * @input: struct to contain variable array of arguments
 * Return: Always 0
 *
 */
int shell_env(input_t *input)
{
	print_list_str(input->env);
	return (0);

}

/**
 * _getenv - get the environment vairiable.
 * @input: struct contain arguments.
 * @var: environment variable
 *
 * Return: the value
 */
char *_getenv(input_t *input, const char *var)
{
	list_t *node = input->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->s, var);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * shell_setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @input: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int shell_setenv(input_t *input)
{
	if (input->argc != 3)
	{
		_error_puts("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(input, input->argv[1], input->argv[2]))
		return (0);

	return (1);
}

/**
 * shell_unsetenv - Remove an environment variable
 * @input: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int shell_unsetenv(input_t *input)
{
	int i;

	if (input->argc == 1)
	{
		_error_puts("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= input->argc; i++)
		_unsetenv(input, input->argv[i]);

	return (0);
}
/**
 * populate_env_list - populates env linked list
 * @input: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(input_t *input)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	input->env = node;
	return (0);
}
