# Minishell

<img width="1000" alt="Minishell Screen Shot" src="https://github.com/user-attachments/assets/cbf0975c-9ede-4867-b16b-7b8d4047a51d">

Minishell is a simple shell implementation, inspired by bash. This project is part of the 42 school curriculum.

## Table of Contents
1. [Installation](#installation)
2. [Usage](#usage)
3. [Project Structure](#project-structure)
4. [Norminette](#norminette)
5. [Resources](#resources)

## Installation

To compile the project, follow these steps:

1. Clone the repository:
   git clone https://github.com/your-username/42-Minishell.git
   cd 42-Minishell

2. Compile the project using the provided Makefile:
   make

This will generate the `minishell` executable.

## Usage

To run the shell:

./minishell

The shell supports various built-in commands and features, including:

- Command execution
- Pipes (|)
- Redirections (<, >, <<, >>)
- Environment variable expansion
- Signal handling (Ctrl-C, Ctrl-D, Ctrl-\)
- Built-in commands: echo, cd, pwd, export, unset, env, exit

Example usage:

`minishell> echo Hello, World!`

Hello, World!

`minishell> pwd`

/path/to/current/directory

`minishell> ls -l | grep .c`

-rw-r--r--  1 user  group  1234 Jan 1 12:00 file1.c

-rw-r--r--  1 user  group  5678 Jan 2 13:00 file2.c

`minishell> cat < input.txt > output.txt`

`minishell> export MY_VAR=42`

`minishell> echo $MY_VAR`

42

`minishell> exit`

## Project Structure

The project is organized into several directories:

- builtin/: Contains implementations of built-in commands
- common/: Contains common utilities and the main minishell logic
- excute/: Handles command execution and piping
- libft/: Custom library with various utility functions
- parsing/: Handles input parsing and processing
- requirements/: Contains project requirements and documentation

## Norminette

This project follows the Norm, a programming standard used at 42 school. The Norminette tool is used to check compliance with this standard. For more details on the Norm, refer to the norminette.pdf in the requirements/ directory.

## Resources

- Project Subject: Detailed project requirements and specifications can be found in subject.pdf in the requirements/ directory.

Note: The bonus part mentioned in the subject has not been implemented in this version of the project.