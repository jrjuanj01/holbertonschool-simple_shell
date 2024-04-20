# holbertonschool-simple_shell

## Shell
- In this project we replicated a simple version of the command line interpreter.

This project was compiled using:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Functios
- Displays a prompt and waits for the user to type a command.
- Supports basic commands such as: ls, mv, touch, rm, etc...
- Prints error messages if command is not found.
- Handles command lines with arguments.

## Files

# Examples of different commands
## Example 1
    username@prompt:~$ ./hsh
    $ ls
    README.md header.h main.c
    $ exit
    username@prompt:~$

## Example 2
    username@prompt:~$ ./hsh
    $ pwd
    /home/holbertonschool-simple-shell/
    $ ^D
    username@prompt:~$

## Credit to
[Juan J. Mendez Torres Jr](https://github.com/jrjuanj01)

[Jose Oquendo](https://github.com/AlphaShrodinger)

[Jezer A. Gonzalez Gonzalez](https://github.com/JezerGonzalez)
