# Simple Shell Project

## Description
Simple Shell is a UNIX command line interpreter written in **C**. It provides a basic interface between the user and the kernel to execute commands, emulating the behavior of `sh`.

This project is part of the **ALX / Holberton School** curriculum for the Low-level programming track.

---

## Features
- **Prompt:** Displays a command prompt `($) `.
- **Execution:** Executes commands using `execve`.
- **Processes:** Creates child processes using `fork`.
- **Termination:** Waits for process termination using `wait`.
- **PATH Handling:** Handles the `PATH` environment variable to find executables.
- **Signal Handling:** Handles `Ctrl+D` (EOF) to exit gracefully.
- **Built-ins:** Supports `exit` and `env` commands.

---

## Requirements
- **OS:** Ubuntu 20.04 LTS.
- **Compiler:** `gcc` with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- **Coding Style:** All files must follow the **Betty style**.
- **Memory:** No memory leaks (Checked with `valgrind`).
- **Organization:** Maximum 5 functions per file.
															
---

## Learning Objectives
At the end of this project, we are expected to be able to explain:
* How a shell works and its basic architecture.
* How to create and manage processes using fork, wait, and execve.
* The difference between a function and a system call.
* How to handle signals and the EOF (Ctrl+D) condition.
* How to implement and use the PATH variable to locate executables.								
---

## Compilation
To compile the shell, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

### Interactive Mode
```bash
\$ ./hsh
(\$) /bin/ls
hsh main.c shell.c
(\$) exit
\$
```

### Non-Interactive Mode
```bash
\$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
\$
```

---
## Logic Flow
graph TD
    A[Start Shell] --> B[Display Prompt $]
    B --> C[Read Command Line]
    C --> D[Parse Input into Tokens]
    D --> E{Is Built-in?}
    E -- Yes --> F[Execute Built-in]
    E -- No --> G[Fork Process]
    G --> H[Child: Execve Command]
    H --> I[Parent: Wait for Child]
    I --> B
---

## File Description

| File | Description |
| --- | --- |
| `main.h` | Header file with prototypes and libraries. |
| `shell.c` | The main loop (REPL) of the shell. |
| `functions.c` | Helper functions for string parsing and execution. |
| `man_1_simple_shell` | Custom manual page. |
| `AUTHORS` | List of contributors. |

---

## Authors
- **Alaa AlDwasari** (GitHub: https://github.com/alaa2026ali)
- **Alqhtani Hadeel**(GitHub: https://github.com/ixhadeel)
