#include "shell.h"


/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *last;
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (!new_node || !str)
	{
		return (NULL);
	}

	new_node->next = str;

	new_node->ptr = '\0';
	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		last = *head;

		while (last->ptr)
		{

			last = last->ptr;
		}

		last->ptr = new_node;
	}

	return (*head);
}


/**
 * path_fill - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_t *path_fill(char *path)
{
	list_t *head = '\0';
	char *value;
	char *cmd_path = _strdup(path);

	value = strtok(cmd_path, ":");
	while (value)
	{
		head = add_node_end(&head, value);
		value = strtok(NULL, ":");
	}

	return (head);
}
/**
 * _which - finds the pathname of a filename
 * @file_name: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *file_name, list_t *head)
{
	struct stat buf;
	char *str;

	list_t *last = head;

	while (last)
	{

		str = concat_all(last->next, "/", file_name);
		if (stat(str, &buf) == 0)
		{
			return (str);
		}
		free(str);
		last = last->ptr;
	}

	return (NULL);
}
/**
 * free_list - frees a list_t
 *@head: pointer to our linked list
 */
void free_list(list_t *head)
{
	list_t *storage;

	while (head)
	{
		storage = head->ptr;
		free(head->next);
		free(head);
		head = storage;
	}

}
