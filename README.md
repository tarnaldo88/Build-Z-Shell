# Build-Z-Shell
 Custom Unix-like shell in C.

 ## Overview
 Build-Z-Shell is an interactive shell that reads a command line, tokenizes it, and dispatches built-in commands. Future iterations will execute external commands and manage environment variables robustly.

 ## Current Functionality
 - Interactive prompt `[torres_shell]>` with input via `getline()` and graceful EOF handling (Ctrl+D).
 - Input tokenization by whitespace via `parse_input()` and memory cleanup with `free_tokens()`.
 - Built-ins wired through `shell_builts()`:
   - `cd` (basic: `cd [path]`)
   - `pwd`
   - `echo` (supports `-n`; expands `$ENV` like `echo $PATH`)
   - `env`
   - `which` (identifies built-ins; groundwork for PATH search)
   - `exit` / `quit`
 - "Unknown Command" message for non-recognized commands.

 ## How It Works
 1. `main()` calls `shell_loop(env)`.
 2. `shell_loop()` shows the prompt and reads a line using `getline()`.
 3. The line is tokenized by `parse_input()` into an array of strings (`args`).
 4. `shell_builts(args, env, initial_directory)` dispatches the command:
    - If it matches a built-in (e.g., `cd`, `pwd`, `echo`, `env`, `which`, `exit`), it is executed.
    - Otherwise, it currently prints an "Unknown Command" message.
 5. Memory from tokenization is freed each iteration.

 ## Quick Start
 - Build: `make`
 - Run: `./torres_shell`

 Try:
 - `pwd`
 - `echo hello` / `echo -n hello` / `echo $PATH`
 - `env`
 - `cd /tmp`
 - `which echo`
 - `exit` or `quit`

 ## Roadmap
 - Execute external commands by searching `PATH` and using fork/exec.
 - Implement `setenv` and `unsetenv` for environment management.
 - PATH handling and prompt/usability improvements.
 - Enhanced `cd`: `cd -`, `cd ~`, `cd ..`, `cd` (home), and better error messages.

 ## More Details
 See full status and roadmap: [README/PROJECT_STATUS.md](README/PROJECT_STATUS.md)
