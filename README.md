# holbertonschool-simple_shell

## Shell description
- In this project we replicated a simple version of the command line interpreter.

## Topics

* [How to run](#how_to_run)
* [Functions](#functions)
* [Files](#functions)
* [Examples](#examples)
* [Credit](#credit_to)

## How to run
1. Download the repository using the `git clone` command with the following link: `git@github.com:jrjuanj01/holbertonschool-simple_shell.git`

2. Use the following command to run the program: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

3. To enter the simple shell program you will need to run: `./hsh`

After that you can run any simple command that does not require any advanced features like pipelines, redirections or semicolons.

## Functios
- Displays a prompt and waits for the user to type a command.
- Supports basic commands such as: ls, mv, touch, rm, etc...
- Prints error messages if command is not found.
- Handles command lines with arguments.

## Files

<table class="tg">
  <col width="45%">
  <col width="65%">
  <tr>
    <td>shell.c</td>
    <td>
      This is the main file where the core loop is located at.
    </td>
  </tr>
  <tr>
    <td>shell.h</td>
    <td>
      <p>
        Header file containing all prototypes with all the libraries used on the project.
      </p>
    </td>
  </tr>
  <tr>
    <td>shell_functions.c</td>
    <td>
      File containing all helper functions for the simple shell to run.
    </td>
  </tr>
</table>

# Examples of different commands to run

    username@prompt:~$ ./hsh
    $ ls
    header.h hsh main.c README.md
    $ ls -l
    -re-r--r-- 1 user user 1568 Apr 24 11:13 header.h
    -rwxr-xr-x 1 user user 16512 Apr 22 16:21 hsh
    -rw-r--r-- 1 user user 1851 Apr 24 10:16 main.c
    -rw-r--r-- 1 user user 1534 Apr 24 10:55 README.md
    $ pwd
    /home/holbertonschool-simple-shell/
    $ touch dog
    $ ls
    dog header.h hsh main.c README.md
    $ mv dog cat
    $ ls
    cat header.h hsh main.c README.md
    $ rm cat
    $ ls
    header.h hsh main.c README.md
    $ exit
    username@prompt:~$

## Credit to
[Juan J. Mendez Torres Jr](https://github.com/jrjuanj01)

[Jose Oquendo](https://github.com/AlphaShrodinger)

[Jezer A. Gonzalez Gonzalez](https://github.com/JezerGonzalez)
