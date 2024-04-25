# Holbertonschool-simple-shell group project
By: Jose A. Oquendo Vazquez, Jezer Gonzalez & Juan Jose Junior Mendez Torres

Description: During this proyect we are told to create a shell program from scratch as a group task. A shell program is a type of computer program called command-line interpreter that lets the users control the operating system with command-lines. It allows users to communicate efficiently and directly with their operating systems.Shell is one of the simplest ways to set up automation that give the developers and users conditional and loop control structures to repeat commands. For a more detailed explanation, refer to the man page of the proyect with the comman "man ./man_1_simple_shell". The following is a description of the tasks to complete during this proyect and the intructions.

Tasks:

0: README, man AUTHORS

Intructions: Write a README file and a man page for your shell. You should have the authors file at the root ofyour repository, listing all individuals having contributed content to the repository.

Use: Were asked to create both a man page and a README file that can be used to understand better the process we take as well as the result for the shell project.

1: Betty would be proud

Intructions: Write a code that passes the Betty checks.

2: Sinmple shell 0.1

Intructions: Write a UNIX command line interpreter.

Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments

3: Simple shell 0.2

Intructions: Add to the previous shell to handle command lines with arguments.

4: Simple shell 0.3

Intructions: Add to the previous shell to be able to handle the PATH and for fork not be called if the command doesn’t exist

5: Simple shell 0.4

Intructions: Add to the previous shell to be able to Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

6: Simple shell 1.0

Intructions: Add to the previous shell to implement the env built-in, that prints the current environment.

