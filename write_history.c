#include "shell.h"

/**
 * history_file - gets the history file
 * @input: parameter struct
 *
 * Return: allocated string containg history file
 */

char *history_file(input_t *input)
{
	char *store, *file;

	file = _getenv(input, "HOME=");
	if (!file)
		return (NULL);
	store = malloc(sizeof(char) * (_strlen(file) + _strlen(HIST_FILE) + 2));
	if (!store)
		return (NULL);
	store[0] = 0;
	_strcpy(store, file);
	_strcat(store, "/");
	_strcat(store, HIST_FILE);
	return (store);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @input: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(input_t *input)
{
	ssize_t fd;
	char *file_name = history_file(input);
	list_t *node = NULL;

	if (!file_name)
		return (-1);

	fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file_name);
	if (fd == -1)
		return (-1);
	for (node = input->hist; node; node = node->next)
	{
		_putsfd(node->s, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from file
 * @input: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(input_t *input)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *store = NULL, *file_name = history_file(input);

	if (!file_name)
		return (0);

	fd = open(file_name, O_RDONLY);
	free(file_name);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	store = malloc(sizeof(char) * (fsize + 1));
	if (!store)
		return (0);
	rdlen = read(fd, store, fsize);
	store[fsize] = 0;
	if (rdlen <= 0)
		return (free(store), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (store[i] == '\n')
		{
			store[i] = 0;
			history_list(input, store + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		history_list(input, store + last, linecount++);
	free(store);
	input->histcount = linecount;
	while (input->histcount-- >= HIST_MAX)
		delete_node_at_index(&(input->hist), 0);
	renumber_history(input);
	return (input->histcount);
}

/**
 * history_list - adds entry to a history linked list
 * @input: Structure containing potential arguments. Used to maintain
 * @store: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int history_list(input_t *input, char *store, int linecount)
{
	list_t *node = NULL;

	if (input->hist)
		node = input->hist;
	add_node_end(&node, store, linecount);

	if (!input->hist)
		input->hist = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @input: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(input_t *input)
{
	list_t *node = input->hist;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (input->histcount = i);
}
