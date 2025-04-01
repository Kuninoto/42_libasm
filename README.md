# libasm (42Porto - 42Cursus)  

## Description  

A few string manipulation functions and libc system call wrappers written in x86_64 Assembly with the Intel syntax

### Grade: 100/100  

### Installing and running the project  
1- Install dependencies  
  
	sudo apt install -y nasm
2- Clone this repository  
	
	git clone https://github.com/Kuninoto/42_libasm
3- Navigate to `libasm/`, assemble and wipe the artifact files  
	
	cd 42_libasm/libasm && make && make clean
4- Compile your program with your new `libasm`

	Example (with C): cc -Wall -Wextra -Werror main.c libasm.a

#### Makefile available targets  
`make` or `make all` - Makes `libasm.a`  
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes `libasm.a` and all the resulting object files  
`make re` - Deletes everything (object files and `libasm.a`) and rebuilds `libasm.a`  

#### Adding new functions to this library:
  - Add their prototypes to `libasm.h`  
  - Add their source files to `libasm/`  
  - Add their source file names to the `GENERAL` variable inside the Makefile  
  - Rebuild the library with `make re`  

##### To keep track of what's inside your resulting `libasm.a` run `ar -t libasm.a` 

## Useful links
[You Can Learn Assembly in 10 Minutes (it’s easy)](https://www.youtube.com/watch?v=jPDiaZS-2ok)  
[How do I know what registers function parameters will be mapped on?](https://stackoverflow.com/questions/28728742/how-do-i-know-what-registers-function-parameters-will-be-mapped-on)  
[syscalls(2) man page](https://linux.die.net/man/2/syscalls)  
[Linux System Call Table for x86_64](http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)  
[x64 ASM Cheat Sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)  
[NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)  
[How does push and pop work in assembly](https://stackoverflow.com/questions/26026174/how-does-push-and-pop-work-in-assembly)  
[CPU Registers x86](https://wiki.osdev.org/CPU_Registers_x86)  
[Godbolt](https://godbolt.org/)  

---
Made by Nuno Carvalho (Kuninoto) | nnuno-ca@student.42porto.com  
<div id="badge"> <a href="https://www.linkedin.com/in/nuno-carvalho-218822247"/> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>&nbsp;
