#include "shell.h"

/**
 * shell_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @input: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int shell_history(input_t *input)
{
	print_list(input->hist);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @input: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(input_t *input, char *s)
{
	char *ptr, c;
	int ret;

	ptr = _strchr(s, '=');
	if (!ptr)
		return (1);
	c = *ptr;
	*ptr = 0;
	ret = delete_node_at_index(&(input->alias),
		get_node_index(input->alias, node_starts_with(input->alias, s, -1)));
	*ptr = c;
	return (ret);
}
/**
 * set_alias - sets alias to string
 * @input: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(input_t *input, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(input, str));

	unset_alias(input, str);
	return (add_node_end(&(input->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *ar = NULL;

	if (node)
	{
		ptr = _strchr(node->s, '=');
		for (ar = node->s; ar <= ptr; ar++)
		_putchar(*ar);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * shell_alias - mimics the alias builtin (man alias)
 * @input: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int shell_alias(input_t *input)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (input->argc == 1)
	{
		node = input->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; input->argv[i]; i++)
	{
		ptr = _strchr(input->argv[i], '=');
		if (ptr)
			set_alias(input, input->argv[i]);
		else
			print_alias(node_starts_with(input->alias, input->argv[i], '='));
	}

	return (0);
}
