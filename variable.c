#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @input: the parameter struct
 * @store: the char buffer
 * @ptr: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(input_t *input, char *store, size_t *ptr)
{
	size_t j = *ptr;

	if (store[j] == '|' && store[j + 1] == '|')
	{
		store[j] = 0;
		j++;
		input->cmd_buf_type = CMD_OR;
	}
	else if (store[j] == '&' && store[j + 1] == '&')
	{
		store[j] = 0;
		j++;
		input->cmd_buf_type = CMD_AND;
	}
	else if (store[j] == ';') /* found end of this command */
	{
		store[j] = 0; /* replace semicolon with null */
		input->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @input: the parameter struct
 * @store: the char buffer
 * @ptr: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(input_t *input, char *store, size_t *ptr, size_t i,
		size_t len)
{
	size_t j = *ptr;

	if (input->cmd_buf_type == CMD_AND)
	{
		if (input->status)
		{
			store[i] = 0;
			j = len;
		}
	}
	if (input->cmd_buf_type == CMD_OR)
	{
		if (!input->status)
		{
			store[i] = 0;
			j = len;
		}
	}

	*ptr = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @input: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(input_t *input)
{
	int i;
	list_t *node;
	char *ptr;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(input->alias, input->argv[0], '=');
		if (!node)
			return (0);
		free(input->argv[0]);
		ptr = _strchr(node->s, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		input->argv[0] = ptr;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @input: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(input_t *input)
{
	int i = 0;
	list_t *node;

	for (i = 0; input->argv[i]; i++)
	{
		if (input->argv[i][0] != '$' || !input->argv[i][1])
			continue;

		if (!_strcmp(input->argv[i], "$?"))
		{
			replace_string(&(input->argv[i]),
					_strdup(convert_number(input->status, 10, 0)));
			continue;
		}
		if (!_strcmp(input->argv[i], "$$"))
		{
			replace_string(&(input->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(input->env, &input->argv[i][1], '=');
		if (node)
		{
			replace_string(&(input->argv[i]),
					_strdup(_strchr(node->s, '=') + 1));
			continue;
		}
		replace_string(&input->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
