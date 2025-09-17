# Custom-Shell
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

 ## New Features
 - External command execution: run many common Unix commands found on your system `PATH`.
 - Improved error messages for invalid commands or missing executables.
 - Quality-of-life improvements to built-ins like `echo`, `pwd`, and `cd`.

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

 ## Torres Shell Commands
 Below is a non-exhaustive list of commands you can run in Torres Shell. Availability depends on what is installed on your system.

 1. Basic file and directory commands
 - `ls` → list files in the current directory.
 - `pwd` → print working directory (built-in available too).
 - `cd <dir>` → change directory (built-in available too).
 - `mkdir test` → create a directory.
 - `rmdir test` → remove a directory.
 - `touch file.txt` → create an empty file.
 - `rm file.txt` → remove a file.

 2. Viewing and editing files
 - `cat file.txt` → print file contents.
 - `less file.txt` or `more file.txt` → view file contents page by page.
 - `head file.txt` → first 10 lines.
 - `tail file.txt` → last 10 lines.

 3. System commands
 - `whoami` → print the current user.
 - `date` → print current date/time.
 - `uptime` → system uptime.
 - `env` → print environment variables (built-in version available too).
 - `echo "hello world"` → print text (built-in available too).

 4. Network commands
 - `ping -c 1 google.com` → send one ping packet.
 - `curl http://example.com` → fetch a web page (if installed).
 - `wget http://example.com` → download a file.

 5. Other utilities
 - `grep pattern file.txt` → search in files.
 - `sort file.txt` → sort file contents.
 - `wc file.txt` → count lines, words, and characters.
 - `uname -a` → system information.

 6. Testing invalid or non-existent commands
 - `foobar` → should print command not found in your shell.
 - `./nonexistent` → tests running a relative path that doesn’t exist.
