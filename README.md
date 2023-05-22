# 0x16. C - Simple Shell

This project is a Unix Command interpreter created as a Milstone Project for the low-level programming and algorithm track at ALX SOFTWARE ENGINERING.

## Description

Simple_shell is simple Unix command language interprter that reads command from either a file or standard and excutes them. base on thompson Shell.

### Compilation

To invoke simple_shell , compile all .c in the repository and run the resulting excutable.

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

hsh can be invoke both interactively and non-interactively. 

  $ echo "echo 'hello'" | ./hsh
   'hello'
  $
if s is invoked with standard input connected to a terminal (determined by isatty(#)), an interative shell is opened.

  $./hsh
  $
Alternatively, if command line arguments are supplied upon invocation, simple_shell treats the first argument as a file from which to read commands. The supplied file should contain one command per line. Shellby runs each of the commands contained in the file in order before exiting.

Example:

   $ cat test
   echo 'hello'
   $ ./hsh test
   'hello'
   $
#### Essential Functionalities of the Simple Shell:

    Displays a prompt "#simple_shell$ " and waits for user input.
    Runs all commands of type "executable program" (ls and /bin/ls).
    Runs the following build_in commands: exit, env, setenv and unsetenv.
    Handles commands with arguments.
    Handles the PATH global variable.
    Handles The EOF (End Of File) condition.
    Handles the Ctrl + C signal -> It doesn't exit the shell

##### Files description

> AUTHORS -> List of contributors to this repository
> Shell.h -> Header file
> Shell.c -> Main function

    sig_handler -> handles the Ctrl + C signal
    _EOF -> handles the End Of File condition

> string.c

    _putchar -> prints a character
    _puts -> prints a string
    _strlen -> gives the length of a string
    _strdup -> copies a string in a newly allocated memory
    concat_all -> concatenates 3 strings in a newly allocated memory

> execute -> executes a command using execve
> realloc -> reallocates a memory block
> freearv -> frees a 2 dimensional array

> buildin.c
> exitt -> handles the exit buildin command
> _atoi -> converts a string into an integer
> env -> prints the current environment
> setenv -> Initialize a new global variable, or modify an existing one
> unsetenv -> remove a global variable
> checkbuild.c
 checkbuild -> checks if a command is a build-in command

> linkpath.c

    _getenv -> returns the value of a global variable
    add_node_end -> adds a node in a singly linked list
    linkpath -> creates a singly linked list for PATH directories
    _which -> finds the pathname of a command
    free_list -> frees the linked list of PATH value
###### List of allowed functions and system calls for this project

>    access (man 2 access)
>   chdir (man 2 chdir)
>    close (man 2 close)
>   closedir (man 3 closedir)
>   execve (man 2 execve)
>   exit (man 3 exit)
>   _exit (man 2 _exit)
>   fflush (man 3 fflush)
>   fork (man 2 fork)
>    free (man 3 free)
>   getcwd (man 3 getcwd)
>   getline (man 3 getline)
>   isatty (man 3 isatty)
>   kill (man 2 kill)
>   malloc (man 3 malloc)
>   open (man 2 open)
>   opendir (man 3 opendir)
>   perror (man 3 perror)
>   read (man 2 read)
>   readdir (man 3 readdir)
>   signal (man 2 signal)
>   stat (__xstat) (man 2 stat)
>   lstat (__lxstat) (man 2 lstat)
>   fstat (__fxstat) (man 2 fstat)
>   strtok (man 3 strtok)
>   wait (man 2 wait)
>   waitpid (man 2 waitpid)
>   wait3 (man 2 wait3)
>   wait4 (man 2 wait4)
>   write (man 2 write)

######  USAGE
  You can try our shell by following these steps:

  Step 1: Clone our repository using this command, (you need to have git installed on your machine first)

          git clone https://github.com/MatriMariem/simple_shell

    Step 2: Change directory to simple_shell:

cd simple_shell

    Step 3: Compile the C files in this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

    Step 4: Run the shell

          ./hsh

Exiting the shell When you want to exit the shell, you can use one of the following methods:

    1: Type the command "exit"

exit..

###### Author

