# Build-Z-Shell — Project Status and Roadmap

This document summarizes what has been implemented so far, the current functionality of the shell, and what is planned next. The summary is based on the codebase and comments in `main.c` as requested.

## Overview
Build-Z-Shell is a custom Unix-like shell written in C. It provides an interactive prompt, parses user input into tokens, and dispatches built-in commands. The long-term objectives include executing external commands, robust environment and PATH management, and improved error handling.

## What’s Implemented So Far

- Interactive shell loop (`shell_loop()` in `main.c`)
  - Displays the prompt `[torres_shell]>` and reads input with `getline()`.
  - Handles Ctrl+D (EOF) to exit the loop gracefully.
- Input parsing (`parse_input()` in `input_parser.c`)
  - Tokenizes input by whitespace (`' '`, `\n`, `\t`, `\r`, `\a`).
  - Allocates tokens dynamically and ensures they are properly null-terminated.
  - `free_tokens()` releases allocated memory for tokens after each command.
- Built-in command dispatch (`shell_builts()` in `main.c`)
  - Recognizes and routes to built-in functions.
  - Current built-ins:
    - `cd` (basic): changes directory when provided a path, e.g., `cd /some/path`.
    - `pwd`: prints the current working directory.
    - `echo`: supports `-n` to omit the trailing newline and expands environment variables (e.g., `echo $PATH`).
    - `env`: prints environment variables.
    - `which`: identifies built-in commands; groundwork in place for PATH searching.
    - `exit` / `quit`: exits the shell.
- Helper utilities (`helpers.c`)
  - `my_strlen`, `my_strcmp`, `my_strncmp`, `my_getenv`, `my_strdup`, `my_strcopy`.
  - `my_getenv` is used to access environment variables (e.g., for `echo $VAR`).
- Build system (`Makefile`)
  - `make` builds the shell into the `torres_shell` executable.
  - Targets: `all`, `clean`, `fclean`, `re`.

## How It Works (High Level)

1. `main()` calls `shell_loop(env)`.
2. `shell_loop()` shows the prompt and reads a line using `getline()`.
3. The line is tokenized by `parse_input()` into an array of strings (`args`).
4. `shell_builts(args, env, initial_directory)` dispatches the command:
   - If it matches a built-in (e.g., `cd`, `pwd`, `echo`, `env`, `which`, `exit`), that function is executed.
   - Otherwise, it currently prints an "Unknown Command" message.
5. Memory from tokenization is freed each iteration.

## Roadmap / Planned Features (from comments in `main.c` and code)

- Execute external commands
  - Fork/exec to run programs found in the system `PATH`.
  - Properly search `PATH` directories to locate executables (`which` to leverage the same logic).
- Environment variable management
  - Implement `setenv` and `unsetenv` built-ins.
  - Support exporting/updating environment variables for child processes.
- PATH management
  - Parse and manipulate `PATH` within the shell session where appropriate.
- Enhanced `cd`
  - Support `cd -` (previous directory), `cd ~` (home directory), `cd ..`, and `cd` with no args (home).
  - Improve error messages for non-existent paths or permission issues.
- Error handling
  - Consistent error reporting and exit codes across built-ins and external command execution.
- Usability improvements
  - More informative prompts, better formatting for `env`, and additional built-ins as needed.

## Build and Run

Prerequisites: `gcc` and `make` on a Unix-like system.

- Build:
  - `make`
- Run:
  - `./torres_shell`
- Try commands:
  - `pwd`
  - `echo hello` / `echo -n hello` / `echo $PATH`
  - `env`
  - `cd /tmp` (example)
  - `which echo`
  - `exit` or `quit`

## Repository Map (key files)

- `main.c` — Shell loop and built-in dispatch via `shell_builts()`.
- `input_parser.c` — Tokenizer (`parse_input`) and memory cleanup (`free_tokens`).
- `CommandParser.c` — Built-in implementations: `cd`, `pwd`, `echo`, `env`, `which` (stubs for `setenv`/`unsetenv`).
- `helpers.c` — String/env helper functions.
- `torres_shell.h` — Declarations and `#define MAX_INPUT`.
- `Makefile` — Build targets.


