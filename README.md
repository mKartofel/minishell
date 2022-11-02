# minishell
Minishell is a two person project at 42. The goal is to create to create a bash-like shell from scratch.

![Minishell Demo](https://user-images.githubusercontent.com/92207326/199325562-99e55cc2-61be-46d7-ab5d-df5fa266666e.gif)

## How to run it

First you have to compile the project :
```
make
```
You can then run the program :
```
./minishell
```
A prompt will appear in the terminal, you can type in commands as you would with Bash. For example :
```
echo "Hello there !"
```

## Features
* Bash-like builtins (echo, cd, pwd, export, unset, env, exit)
* Environment variables handling
* Redirections (<, >, <<, >>)
* Pipes |
* Launch executables when given a relative/absolute path
* Also search for executables in the PATH
* Parameter expansion, quotes handling
* Signal handling (ctrl-c, ctrl-d, ctrl-\)
* Commands history


