# Simple Unix Command Line Interpreter #
![simpleshell](https://i.imgur.com/Db0vO3g.png)

# Overview #
The program codes contained in this repository are used to implement a simple command line interpreter (aka simple shell).  

# Background #
0. Who designed and implemented the original Unix operating system?  
Kenneth Lane Thompson designed and implemented the original UNIX operating system at Bell Labs.  

1. Who wrote the first version of the Unix shell?  
Thompson also wrote the first version of the Unix shell.  The first version was called the Thompson shell, **sh**.  It was modeled after the Multics shell, also invented at Bell Labs.  

2. Who invented the B programming language (the direct predecessor to the C programming language)?  
Additionally, Thompson invented the B programming language for Unix shell.  Later, Dennis Ritchie rewrote B programming language into a higher-leverl language known today as C.  

3. Who is Ken Thompson?  
Thompson pioneered computer science while at Bell Labs in the 1960s.  It's where he invented the original Unix operating system and then, B programming language to partner with.  Interestingly, the first program written in the first version of Unix was a chess game program.  Thompson worked collaboratively with Ritchie to further develop the Unix operating system.  

4. How does a shell work?  
Shell is a command-line interpreter that provides user interface for Unix operating systems.  Users interacts with the shell using a terminal emulator or serial hardware connections.  The shell takes user commands and passes them to the underlying operating system to execute.  In the shell, there are configuration files containing commands.  These files set the variables used to find executables, control shell behavior, etc.  

5. What is a **pid** and a **ppid**?  
Every program loaded and started in the operating system is a process.  Every process has a unique id (aka **pid**) attached to it.  The **pid** is used by functions and system calls to interact and manipulate other processes.  Every **pid** has a parent id (aka **ppid** that started it all which is shown in the diagram below.  In order to retrieve the pid or ppid for a current process, use command **getpid** and **getppid** respectively.  

![5. What are PID and PPID?](https://i.imgur.com/hpsCKIP.png)

6. How to manipulate the environment of the current process?  
The environment is an array of strings pointed to by global variable, **environ** defined in the unistd header file.  These strings are formatted as such: var=value, where var is the variable name and value is the value.  Essentially, these strings are environment variables used to provide user information to programs such as name of logged-in user or user's login directory.  Additionally, these variables could have been imported from a parent process.  A full list if these avariables could be displayed with the **env** or **printenv** command.  Additionally, the user could use **getenv** to search and obtain a specific environment variable.  

7. What is the difference between a function and a system call?  
A function is used in a program to make a request to perform a specific task.  A system call is a request to the kernal to access a resource.  

8. How to create processes?  
The system call, **fork** could be used to create a new process that's a duplicate of the parent process called a child process.  Both the child process and parent process will continue to run but with different stacks, datas and heaps.  If the return value of **fork** is 0, then it's the child process.  If the return value is 1, then it's the parent process.  

9. What are the three prototypes of main?  
The main function is the entry point to any program and it's when the operating system passes control to it.  The following are three prototypes of a main function that differs in their parameters.  
```C
int main(void);
int main(int argc, char **argv);
int main(int argc, char **argv, char **env);
```

10. How does the shell use the **PATH** to find the programs?  
**PATH** is an environment variable that produces a colon delimited list of directories when the command **echo $PATH** is executed (see example below).  Executable files for running applications and commands are stored in different paths.  For example, the executable file for the **ls -l** command is stored in /bin which stores user utilities related to directory navigation and file management.  The **-l** is an optional flag to additionally list file types, permissions, hard links, owner, group, size, last-modified date and filename.  If a user wants to use an executable file and it's stored in **PATH**, then, the user only needs to type the file name on the command line to find it.  If it's not in **PATH**, then the user needs to type the absolute path.  

![echo$PATH](https://i.imgur.com/hK9iAqH.png)

    The **stat** system call gets the status of a file.  If successful, it returns a zero but if fail, it returns -1.  For example, an user could run the following main function to obtain the status of the **ls** command file.  
```C
int main(int argc, char **argv)
{
	int i;
	struct stat status;

	for (i = 1; 1 < argc; i++)
	{
		if (stat(argv[i], &status) == 0)
		{
			printf(%s is a file\n", argv[i]);
		}
	}
	return (0);
}
```
![stat](https://i.imgur.com/HPE5nuP.png)

11. How to execute another program with the **execve** system call?  
**execve** is a system call that executes another program with the current process' memory.  Essentially, it replaces the current process, therefore, upon success, it returns nothing.  But upon fail, it returns -1.  

12. How to suspend the execution of a process until one of its children terminates?  
**wait** is a system call that suspends execution of a process until its children terminates.  It allows the operating system to release the resources associated with the children.  If **wait** isn't called, then the children will be in a zombie state that still fills a space in the kernel.  Upon success, it returns the pid of the terminated child and upon fail, it returns -1.  

13. What is **EOF** / “end-of-file”?  
**EOF** is a macro in the standard input/output header file in C programming.  It's used to mark the end of a file or the last byte of data was read.  Its return value is -1 to indicate that it reached the end of the input stream.  In Unix, the keyboard command for **EOF** is Ctrl+D and in Windows, it's Ctrl+Z.  

    The **getline** function reads an entire line from stream and stores it in a buffer.  In turn, the buffer address is stored in a pointer.  If successful, it returns the number of characters read including the new line but not the null byte.  If fail due to an error or **EOF** was reached, then it returns -1.  

    Similarly, the **strtok** function reads a string and delimits it.  Once delimited, the string is broken up into "tokens" with a null byte at the end of each.  If successful, it returns a pointer to the next token, but if fail, it returns NULL.  

# Specifications #
0. **README**, **man**, **AUTHORS**  
    1. Contains a **README**.  
	2. Contains a **man** page for simple shell.  
	3. Contains an **AUTHORS** file at the root of your repository, listing all individuals having contributed content to the repository.  

1. Betty would be proud  
    1. Program code that's in compliance with Betty programming language style.  

2. Test suite  
    1. Contribute to a test repository.  

3. Simple shell 0.1  
    1. Program code for simple shell implementation.  
	2. Simple shell displays a prompt and wait for user to type a command.  The command line always ends with a new line.  
	3. The prompt will display again after a command was executed.  
	4. The command lines are simple (no semicolons, no pipes, no redirections, etc.).  
	5. The command lines are made only of one word (no arguments).  
	6. Prints an error message and display the prompt again if an executable isn't found.  
	7. Handle errors.  
	8. Handle **EOF**.  

4. Handle command lines with arguments.  

5. Handle the **PATH**.  

6. Implement the **exit** built-in, that exits the shell.  

7. Implement the **env** built-in, that prints the current environment.  

# Example #


# Resources #
0. man pages:  
man sh  
man ls  
man env  
man printenv  
man stat  
man 2 execve  
man 2 getpid  
man 2 getline  
man 2 fork  
man 2 wait  
man 2 execve  
man 3 getenv  
man 3 strtok  
man 5 environ  

1. Unix shell  
<https://en.wikipedia.org/wiki/Unix_shell>

2. Thompson shell  
<https://en.wikipedia.org/wiki/Thompson_shell>

3. Ken Thompson  
<https://en.wikipedia.org/wiki/Ken_Thompson>

4. Why are system calls expensive in operating systems?  
<https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems>

5. What are PID and PPID?  
<https://delightlylinux.wordpress.com/2012/06/25/what-is-pid-and-ppid/>

6. What is the Difference Between System Call and Function Call  
<https://pediaa.com/what-is-the-difference-between-system-call-and-function-call/>

7. fork() in C  
<https://www.geeksforgeeks.org/fork-system-call/>

8. CS360 Lecture notes -- Introduction to System Calls (I/O System Calls)  
<https://web.eecs.utk.edu/~mbeck/classes/cs560/360/notes/Syscall-Intro/lecture.html>

9. What is EOF in C?  
<https://www.quora.com/What-is-EOF-in-C>

10. What does $PATH mean?  
<https://askubuntu.com/questions/551990/what-does-path-mean>

11. What Exactly is Your Shell PATH?  
<https://medium.com/@jalendport/what-exactly-is-your-shell-path-2f076f02deb4>

12. Shell and Environment Variables  
<https://www.cs.odu.edu/~zeil/cs252/latest/Public/envvariables/index.html>

13. ls  
<https://en.wikipedia.org/wiki/Ls>

14. Input/Output on Streams  
<http://kirste.userpage.fu-berlin.de/chemnet/use/info/libc/libc_7.html>

# Authors #
Jeremy Bedolla <1106@holbetonschool.com>  
Jennifer Tang <1039@holbertonschool.com>  

