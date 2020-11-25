<p align="center">
   <img src="https://www.holbertonschool.com/holberton-logo.png"(https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcTLtL_ToHLEo_BWFxD-yf32Ux3zfsH_NPc8Qw&usqp=CAU)
     alt="Flow chart"
     style="float: left; margin-right: 10px;">
</p>
<p align="center">PROJECT SIMPLE_SHELL</p>

## 🐚 🔥 SIMPLE_SHELL 🔥 🐚

A simple UNIX command interpreter written as part of the low-level programming and algorithm track at Holberton School.

### Installation

#### Requirements
 - Gcc >= 4.8.4
 - Linux

#### Steps to compile and execute.
 - `git clone https://github.com/gdorelo/simple_shell.git`
 - `cd simple_shell`
 - `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
 - `./hsh`

### Sys Functions
Prototypes | Description
----------- | -------------
**loop** | Start the main loop our shell.
**prompt** | Function to print our prompt line.
**save_buffer** | Read the line command.
**split_buffer** | Split line command and convert to *tokens* each argument.
**execute** | Function to execute all arguments in command line.
**find_path** | Searches the enviroment list to find the command's path.
**split_path** | Function that splits the path.
**checkspaces** | Function that check for empty spaces
**_atoi** | Function that convert a chart to string
**_strcat** | Function to concatenates two strings.
**_strcmp** | Function to comparates two strings.
**_strncmp** | Function to comparates two strings.
**_strlen** | Function to know the length of the string.
**_strcpy** | Function to copy a string.
**_putchar** |Function to write a character
**print_number** | Function to print a number
**search_builtin** | Function that searches command from built in options
**builtin_exit** | Builtin Exit Function
**builtin_env** | Builtin print Enviromental variables function
**check_dot_slash** | Function that checks for spaces and slashes
**print_error** | Function that prints errors
**free_memory** | Function that frees memory
**kill_signal** | Function that handle signal

### Flowchart
<p align="center">
   <img src="">
</p>

### Files

This list is our files used to compile our shell

* [shell.h](https://github.com/martinmsaavedra/simple_shell/blob/main/shell.h)
Header of functions where are store the prototypes and libraries.

* [main.c](https://github.com/martinmsaavedra/simple_shell/blob/main/main.c)
Entry point to the shell.

* [loop.c](https://github.com/martinmsaavedra/simple_shell/blob/main/loop.c)
Initializace the main loop of the shell.

* [find_path.c](https://github.com/martinmsaavedra/simple_shell/blob/main/find_path.c)
Function to find a command with or without path.

* [prompt.c](https://github.com/martinmsaavedra/simple_shell/blob/main/prompt.c)
Function to print the prompt.

* [string_functions.c](https://github.com/martinmsaavedra/simple_shell/blob/main/string_functions.c)
Functions to handle strings.

* [save_buffer.c](https://github.com/martinmsaavedra/simple_shell/blob/main/save_buffer.c)
Function that reads and saves the command line.

* [split_buffer.c](https://github.com/martinmsaavedra/simple_shell/blob/main/split_buffer.c)
Functions to split the command line.

* [split_path.c](https://github.com/martinmsaavedra/simple_shell/blob/main/split_path.c)
Function that splits the path.

* [execute_command.c](https://github.com/martinmsaavedra/simple_shell/blob/main/execute_command.c)
Function execute each argument and return a integer to standard out.

* [_atoi.c](https://github.com/martinmsaavedra/simple_shell/blob/main/_atoi.c)
Function to convert a string to a int.

* [builtin_functions.c](https://github.com/martinmsaavedra/simple_shell/blob/main/builtin_functions.c)
Set of Builtin Functions.

* [check_dot_slash.c](https://github.com/martinmsaavedra/simple_shell/blob/main/check_dot_slash.c)
Function to check when command is only a dot or slash.

* [checkspaces.c](https://github.com/martinmsaavedra/simple_shell/blob/main/checkspaces.c)
Function to check for spaces in buffer.

* [errors.c](https://github.com/martinmsaavedra/simple_shell/blob/main/errors.c)
Function to print errors.

* [free_memory.c](https://github.com/martinmsaavedra/simple_shell/blob/main/free_memory.c)
Function to free memory.

* [print_functions.c](https://github.com/martinmsaavedra/simple_shell/blob/main/print_functions.c)
Set of print functions.

* [signal.c](https://github.com/martinmsaavedra/simple_shell/blob/main/signal.c)
Function to handle "Ctrl + c".

#### REQUIREMENTS

* Allowed editors: *vi*, *vim*, *emacs*
* All your files will be compiled on Ubuntu 14.04 LTS.
* Your programs and functions will be compiled with *gcc 4.8.4* using the flags *-Wall -Werror -Wextra* and *-pedantic*
* All your files should end with a new line
* A *README.md* file, at the root of the folder of the project is mandatory
* Your code should use the *Betty* style. It will be checked using *betty-style.pl* and *betty-doc.pl*
* No more than 5 functions per file.
* Your shell should not have any memory leaks.
* All your header files should be include guarded.
* Use system calls only when you need to (why?).

### EXAMPLES
#### Modes

##### Non-interactive
*Command*
```
echo "/bin/ls" | ./hsh
```
*Output*
```
example.c   example.c  example.c        file     man_1_simple_shell  example.c  README.md 
AUTHORS  example.c      example.c  example.c  example.c      readline.c         shell.h 
```
<hr>

##### Interactive

*Command*
```
./hsh
```
Then the prompt appears, so you can type in the command line, and press return

**Ex**
`/bin/ls`

*Output*
```
example.c   example.c  example.c        file     man_1_simple_shell  example.c  README.md 
AUTHORS  example.c      example.c  example.c  example.c      readline.c         shell.h  
```
<p align="center"> AUTHORS </p>
<p align="center">
<h2 align="center">Made by Martin Saavedra y Matias Zappino</h2>
