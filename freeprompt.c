#include "shell.h"

/**
 * free_prompt - frees the array of pointer prompt
 * @prompt: array of pointer
 */
void free_prompt(char **prompt)
{
	int index;

	for (index = 0; prompt[index]; index++)
		free(prompt[index]);
	free(prompt);
}
