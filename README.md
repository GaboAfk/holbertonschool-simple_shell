# Simple Shell - Holy$hell

This project is a Junior version of a Shell o user interface for Unix-like operating systems

### Style
We use "Betty" coding style.
***
### Functions
* _getenv
Search path in environ.
* get_dir
Search a valid directory for @function.
* array_in_free
Free an array.
* buff_cleaner
Clears the buffer in case of spaces, tabs or new lines only.
* children_maker
Creates a child procces of the program
* spc_cmd
Checks if input promt is exit or print env
***
##### Basic Command Examples List
* pwd
* ls
* sh
* exit
* cat
* env
* grep
* clear
***
### Instructions for use
##### Compile the program
To complie the program, we must use the next code: 

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


##### Run the HolyShell !!
In order to run the program, we must execute the next code: 

```
./hsh
```
##### Execute a valid command

```
ls -l
```

 In the case of executed command is valid. Print in stdout all directories using a long listing format

##### Clarified example
```
#holy$hell ls -l
total 76
-rw-r--r-- 1 root root  2057 Apr 24 21:34 1.0.holyshell.c
-rw-r--r-- 1 root root   245 Apr 24 21:34 AUTHORS
-rw-r--r-- 1 root root    20 Apr 24 21:34 README.md
drwxr-xr-x 2 root root  4096 Apr 24 21:34 advanced_tasks
-rwxr-xr-x 1 root root   846 Apr 24 21:34 bettyplz_autocompJoaquin2.1
-rw-r--r-- 1 root root  1905 Apr 24 21:34 freedoom.1.0.c
-rwxr-xr-x 1 root root   401 Apr 24 21:34 gitpushFiles_All
-rwxr-xr-x 1 root root 17336 Apr 24 21:35 hsh
drwxr-xr-x 2 root root  4096 Apr 24 21:34 hack
drwxr-xr-x 2 root root  4096 Apr 24 21:34 mini_shell_joaqunin
-rw-r--r-- 1 root root  1726 Apr 24 21:34 patheneitor.1.0.c
drwxr-xr-x 2 root root  4096 Apr 24 21:34 pre-shell_gabo
-rwxr-xr-x 1 root root    92 Apr 24 21:34 scripter
drwxr-xr-x 2 root root  4096 Apr 24 21:34 versions
-rw-r--r-- 1 root root   775 Apr 24 21:34 zzz.h
```
##### Execute a invalid command
```
#holy$hell lsls
```
 In the case of executed command is invalid. Print a error message with the name of our program and the invalid command.

 ##### Clarified example
```
#holy$hell lsls
./hsh: 1: lsls: not found
```
##### Exit the program

 To exit the program just enter the exit command.

```
#holy$hell exit
```

### Flowchart of the shell
<img src="https://iili.io/JUBr5xa.png">

## Authors
Gabriel Morffe, Joaquin Aguilar

