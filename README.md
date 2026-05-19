# Simple Shell

A simple UNIX command line interpreter written in C as part of the Holberton School / ALX low-level programming curriculum.

---

## Description

`hsh` is a custom shell that replicates the basic behavior of the standard UNIX shell.

The shell reads commands from standard input, resolves executable paths using the `PATH` environment variable, and executes commands using system calls such as `fork` and `execve`.

It supports both interactive and non-interactive modes.

---

## Requirements

- **OS**: Ubuntu 20.04 LTS
- **Compiler**: `gcc` compiler
- **Coding Style**: Betty coding style compliant
- **Memory**: No memory leaks (Valgrind verified)

Compilation flags required:
`-Wall -Werror -Wextra -pedantic -std=gnu89`

---

## Allowed Functions & System Calls

The project utilizes the following system calls and library functions:
`access`, `execve`, `exit`, `fork`, `free`, `getline`, `isatty`, `malloc`, `perror`, `stat`, `strtok`, `wait`.

---

## Compilation

Compile the shell using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

### Interactive Mode
```bash
\$ ./hsh
#cisfun\$ /bin/ls
AUTHORS  README.md  execute.c  main.h  path_handler.c  shell.c
#cisfun\$
```

### Non-Interactive Mode
```bash
\$ echo "/bin/ls" | ./hsh
AUTHORS  README.md  execute.c  main.h  path_handler.c  shell.c
\$
```

---

## Features

- Displays a custom shell prompt.
- Reads user input dynamically using `getline`.
- Executes commands independently using `fork` and `execve`.
- Resolves system commands using the `PATH` environment variable.
- Handles custom commands with arguments.
- Waits for child processes to exit using `wait`.
- Supports both interactive and non-interactive execution modes.
- Handles `Ctrl+D` (EOF) safely.

---

## How It Works

1. The shell displays a prompt in interactive mode.
2. The user enters a command line.
3. The input line is read using `getline`.
4. The command line is split into tokens using `strtok`.
5. The shell searches for the executable in the `PATH` directories.
6. A child process is created using `fork`.
7. The resolved command path is executed using `execve`.
8. The parent process waits for the child process to finish.
9. The shell repeats the process until EOF (`Ctrl+D`) or `exit` is called.

---

## Project Files


| File | Description |
| :--- | :--- |
| `shell.c` | Main shell loop, input handling, and built-ins. |
| `execute.c` | Core command execution and process handling logic. |
| `path_handler.c` | Handles command path resolution searching directories in `PATH`. |
| `main.h` | Core header file containing standard libraries and prototypes. |
| `man_1_simple_shell` | Custom UNIX manual page for the `hsh` shell. |
| `AUTHORS` | Machine-readable file listing project contributors. |
| `.gitignore` | Specifies intentionally untracked files to ignore. |

---

## Testing & Examples

```bash
\$ ./hsh
#cisfun\$ /bin/echo Hello
Hello
#cisfun\$
```

---

## Manual Page

To display the integrated manual page locally, run:

```bash
man ./man_1_simple_shell
```

---

## Authors

- Alaa Aldwasari
- Hadeel Alqhtani

---

## Known Bugs

No known bugs.

---

## License

This project is for educational purposes only.
