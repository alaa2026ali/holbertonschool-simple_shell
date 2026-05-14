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
We followed a simple logic to make this shell run correctly:

1. **Wait for Input:** The shell stays active and shows the `($)` prompt, waiting for you to type something.
2. **Reading & Splitting:** Once you hit Enter, the shell reads your line and breaks it into separate words (tokens) so it can understand the command and its arguments.
3. **Creating a Process:** Because we don't want the main shell to close after one command, we use `fork` to create a "child process" that handles the execution.
4. **Running the Command:** The child process uses `execve` to look for the command and run it.
5. **Cleaning Up:** After the command finishes, the shell cleans up any allocated memory to prevent leaks and goes back to step 1.

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
