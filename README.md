Simple Shell Projecti
Simple Shell 0.1
This is a simple UNIX command line interpreter, also known as a shell, developed as part of the Simple Shell 0.1 project. The shell provides a basic command-line interface for users to interact with the operating system. It supports the execution of simple commands and displays a prompt for user input.

Usage
To run the Simple Shell, execute the following command:
$ simple_shell
Features
Command Execution: The shell waits for the user to type a command and executes it.
Prompt: After executing a command, the shell displays a prompt indicating that it is ready for the next command.
Simple Command Lines: The shell supports command lines that consist of only one word. No arguments are passed to programs.
Error Handling: If an executable program cannot be found, the shell prints an error message and displays the prompt again.
End of File Handling: The shell handles the "end of file" condition (Ctrl+D) gracefully and exits the program.
Basic Functionality: The shell focuses on providing a minimalistic command-line interface and does not include advanced features such as semicolons, pipes, redirections, or special characters like ", ', `, , *, &, #.
PATH and Built-ins: The shell does not rely on the PATH environment variable to locate executables and does not implement any built-in commands.
Cursor Movement: The shell does not provide cursor movement capabilities.
Command Arguments: The shell does not support commands with arguments.
Contributing
Contributions to the Simple Shell project are welcome. If you find any issues or have suggestions for improvements, please submit a pull request or open an issue on the project's GitHub repository.

License
The Simple Shell is open-source software released under the MIT License. You are free to use, modify, and distribute this software. See the LICENSE file for more details.

Authors
This Simple Shell project was developed by [Ismail] and [Chapa]. You can find the list of contributors in the project's GitHub repository.
