*This project was created as part of the 42 curriculum by chgomez.*

# pipex

## Overview

`pipex` is a C project that recreates the behavior of a Unix shell pipeline.

The program takes an input file, executes two commands connected by a pipe, and redirects the final output to an output file.

It reproduces the following shell behavior:

```bash
< infile cmd1 | cmd2 > outfile
```

Using the program:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

## Description

The goal of `pipex` is to understand how Unix processes communicate through pipes and how command execution works at a low level.

The project uses system calls such as `fork()`, `pipe()`, `dup2()`, `execve()`, `open()`, `close()` and `waitpid()` to create two child processes, redirect file descriptors and execute external commands.

The first child process reads from the input file and sends its output through the pipe.
The second child process reads from the pipe and writes the final result into the output file.

## Example

Shell behavior:

```bash
< infile grep "hello" | wc -l > outfile
```

Equivalent `pipex` usage:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

## Features

* Recreates a basic Unix pipeline.
* Executes two commands using `execve()`.
* Searches command paths through the environment variable `PATH`.
* Redirects input and output using file descriptors.
* Connects processes with `pipe()`.
* Creates child processes with `fork()`.
* Handles command arguments with a custom `ft_split`.
* Includes error handling for files, commands and system calls.
* Builds the executable using a custom `Makefile`.

## Technologies

* C language
* Unix system calls
* File descriptors
* Process creation
* Pipes
* Environment variables
* Makefile
* Compilation with `cc`
* Flags: `-Wall -Wextra -Werror`

## Project Structure

```text
.
├── Makefile
├── en.subject.pdf
├── include/
│   └── pipex.h
└── src/
    ├── main.c
    ├── child1.c
    ├── child2.c
    ├── execute.c
    ├── errors.c
    ├── ft_split.c
    └── utils.c
```

## How to Compile

Compile the project:

```bash
make
```

This generates the executable:

```text
pipex
```

Remove object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Rebuild the project:

```bash
make re
```

## How to Run

General syntax:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

This should behave like:

```bash
< infile grep hello | wc -l > outfile
```

## Testing Example

Create a simple input file:

```bash
echo -e "hello\nworld\nhello 42" > infile
```

Run `pipex`:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Check the result:

```bash
cat outfile
```

Expected output:

```text
2
```

You can compare it with the shell behavior:

```bash
< infile grep hello | wc -l > expected
diff outfile expected
```

If `diff` produces no output, both results are the same.

## Implementation Highlights

* `main.c` validates arguments, creates the pipe and manages child processes.
* `child1.c` handles the first command and redirects the input file to the pipe.
* `child2.c` handles the second command and redirects the pipe output to the output file.
* `execute.c` resolves command paths and executes commands with `execve()`.
* `errors.c` centralizes error handling.
* `utils.c` contains helper functions used across the project.
* `ft_split.c` provides custom string splitting for command parsing.

## What I Learned

* How Unix pipes work internally.
* How to create and manage child processes with `fork()`.
* How to redirect standard input and output with `dup2()`.
* How to execute external programs with `execve()`.
* How to work with environment variables such as `PATH`.
* How file descriptors are inherited by child processes.
* How to close unused file descriptors to avoid leaks or blocked processes.
* How to structure a small Unix system programming project in C.

## Resources

* `man 2 pipe`
* `man 2 fork`
* `man 2 dup2`
* `man 2 execve`
* `man 2 open`
* `man 2 waitpid`
* 42 pipex subject
* Unix process and file descriptor documentation

## Notes

This project follows the constraints and style expected in the 42 curriculum.
The implementation is intentionally written in C and focuses on Unix process management, pipes, command execution and file descriptor redirection.

## Author

Christian Gómez
Junior Software Developer in training at 42 Barcelona
GitHub: [github.com/chgomez04](https://github.com/chgomez04)
