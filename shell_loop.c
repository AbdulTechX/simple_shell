nclude "shell.h"

/**
 *  * hsh - main shell loop
 *   * @input: the parameter & return info struct
 *    * @arv: the argument vector from main()
 *     *
 *      * Return: 0 on success, 1 on error, or error code
 *       */
int hsh(input_t *input, char **arv)
{
		ssize_t r = 0;
			int builtin_ret = 0;

				while (r != -1 && builtin_ret != -2)
						{
									clear_input(input);
											if (interactive(input))
															_puts("simple_shell$ ");
													_error_putchar(BUF_FLUSH);
															r = get_input(input);
																	if (r != -1)
																				{
																								set_input(input, arv);
																											builtin_ret = find_builtin(input);
																														if (builtin_ret == -1)
																																			find_cmd(input);
																																}
																			else if (interactive(input))
																							_putchar('\n');
																					free_input(input, 0);
																						}
					write_history(input);
						free_input(input, 1);
							if (!interactive(input) && input->status)
										exit(input->status);
								if (builtin_ret == -2)
										{
													if (input->err_num == -1)
																	exit(input->status);
															exit(input->err_num);
																}
									return (builtin_ret);
}

/**
 *  * find_builtin - finds a builtin command
 *   * @input: the parameter & return info struct
 *    *
 *     * Return: -1 if builtin not found,
 *      * 	0 if builtin executed successfully,
 *       * 	1 if builtin found but not successful,
 *        * 	2 if builtin signals exit()
 *         */
int find_builtin(input_t *input)
{
		int i, built_in_ret = -1;
			builtin_T builtintbl[] = {
						{"exit", shell_exit},
								{"env", shell_env},
										{"help", shell_help},
												{"history", shell_history},
														{"setenv", shell_setenv},
																{"unsetenv", shell_unsetenv},
																		{"cd", shell_cd},
																				{"alias", shell_alias},
																						{NULL, NULL}
							};

				for (i = 0; builtintbl[i].value; i++)
							if (_strcmp(input->argv[0], builtintbl[i].value) == 0)
										{
														input->line_count++;
																	built_in_ret = builtintbl[i].func(input);
																				break;
																						}
					return (built_in_ret);
}

/**
 *  * find_cmd - finds a command in PATH
 *   * @input: the parameter & return info struct
 *    *
 *     * Return: void
 *      */
 void find_cmd(input_t *input)
{
		char *path_name = NULL;
			int i, k;

				input->path_name = input->argv[0];
					if (input->linecount_flag == 1)
							{
										input->line_count++;
												input->linecount_flag = 0;
													}
						for (i = 0, k = 0; input->arg[i]; i++)
									if (!is_delim(input->arg[i], " \t\n"))
													k++;
							if (!k)
										return;

								path_name = find_path(input, _getenv(input, "PATH="), input->argv[0]);
									if (path_name)
											{
														input->path_name = path_name;
																fork_cmd(input);
																	}
										else
												{
															if ((interactive(input) || _getenv(input, "PATH=")
																							|| input->argv[0][0] == '/') && is_cmd(input, input->argv[0]))
																			fork_cmd(input);
																	else if (*(input->arg) != '\n')
																				{
																								input->status = 127;
																											print_error(input, "not found\n");
																													}
																		}
}

/**
 *  * fork_cmd - forks a an exec thread to run cmd
 *   * @input: the parameter & return info struct
 *    *
 *     * Return: void
 *      */
void fork_cmd(input_t *input)
{
		pid_t child_pid;

			child_pid = fork();
				if (child_pid == -1)
						{
									/* TODO: PUT ERROR FUNCTION */
									perror("Error:");
											return;
												}
					if (child_pid == 0)
							{
										if (execve(input->path_name, input->argv, get_location(input)) == -1)
													{
																	free_input(input, 1);
																				if (errno == EACCES)
																									exit(126);
																							exit(1);
																									}
												/* TODO: PUT ERROR FUNCTION */
											}
						else
								{
											wait(&(input->status));
													if (WIFEXITED(input->status))
																{
																				input->status = WEXITSTATUS(input->status);
																							if (input->status == 126)
																												print_error(input, "Permission denied\n");
																									}
														}
}
