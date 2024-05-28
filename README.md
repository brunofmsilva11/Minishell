# minishell

**minishell** is a project developed at 42, an innovative programming school. The goal of this project is to create a simple shell, similar to bash, that can execute commands, handle errors, and manage processes. This project teaches fundamental concepts of operating systems, process control, and user interfaces in C.

## Project Objectives

- **Command Execution**: Implement a shell that can execute common commands found in Unix-like operating systems.
- **Process Control**: Manage multiple processes and handle their states.
- **Error Handling**: Implement robust error handling to manage incorrect inputs and command failures.
- **Built-in Commands**: Support a set of built-in commands such as `cd`, `echo`, `exit`, etc.
- **Signal Handling**: Properly handle signals such as `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`.
- **Environment Variables**: Manage and manipulate environment variables.
- **I/O Redirection and Pipes**: Implement input/output redirection and support for pipelines.

## Features

- **Prompt Display**: Display a prompt and wait for user input.
- **Command Parsing**: Parse user input to separate commands and arguments.
- **Built-in Commands**: Implement built-in commands like `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv`.
- **Execution of External Commands**: Execute external system commands by forking processes.
- **Redirection**: Handle input and output redirections (`>`, `>>`, `<`).
- **Pipes**: Support for piping between commands (`|`).
- **Signal Handling**: Manage terminal signals (`SIGINT`, `SIGQUIT`, etc.).
- **Error Handling**: Display appropriate error messages for invalid commands or arguments.

## How to use
