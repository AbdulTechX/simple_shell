#include "shell.h"

/**
 * clear_input - initializes input_t struct
 * @input: struct address
 */
void clear_input(input_t *input)
{
	input->arg = NULL;
	input->argv = NULL;
	input->path_name = NULL;
	input->argc = 0;
}

/**
 * set_input - initializes input_t struct
 * @input: struct address
 * @arv: argument vector
 */
void set_input(input_t *input, char **arv)
{
	int i = 0;

	input->fname = arv[0];
	if (input->arg)
	{
		input->argv = strtow(input->arg, " \t");
		if (!input->argv)
		{
			input->argv = malloc(sizeof(char *) * 2);
			if (input->argv)
			{
				input->argv[0] = _strdup(input->arg);
				input->argv[1] = NULL;
			}
		}
		for (i = 0; input->argv && input->argv[i]; i++)
			;
		input->argc = i;

		replace_alias(input);
		replace_vars(input);
	}
}

/**
 * free_input - frees input_t struct fields
 * @input: struct address
 * @all: true if freeing all fields
 */
void free_input(input_t *input, int all)
{
	ffree(input->argv);
	input->argv = NULL;
	input->path_name = NULL;
	if (all)
	{
		if (!input->cmd_buf)
			free(input->arg);
		if (input->env)
			free_list(&(input->env));
		if (input->hist)
			free_list(&(input->hist));
		if (input->alias)
			free_list(&(input->alias));
		ffree(input->environ);
			input->environ = NULL;
		b_free((void **)input->cmd_buf);
		if (input->readfd > 2)
			close(input->readfd);
		_putchar(BUF_FLUSH);
	}
}
