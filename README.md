# libasm (42Porto - 42Cursus) <img src="https://hackr.io/tutorials/learn-assembly-language/logo/logo-assembly-language?ver=1557983975" title="ASM" alt="ASM Logo" width="55" height="55" align="right" />&nbsp; 

## Grade: 100/100

### Overview
A few string manipulation functions and libc system call wrappers written in Assembly x86_64 with the Intel syntax

### Installing and running the project:
1- Clone this repository
	
	git clone https://github.com/Kuninoto/42_libasm
2- Navigate to _libasm_ and run `make`
	
	cd 42_libasm/libasm && make
3- `make clean` so that you don't keep those object files that you won't need anymore

	make clean
4- Compile your programs with your new _libasm.a_

	Example (C): cc -Wall -Wextra -Werror main.c libasm.a


###  Subject (v5): [libasm en_subject](./extras/en.subject_libasm.pdf)

#### Makefile Available Targets:  
`make` or `make all` - Makes _libasm.a_  
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes _libasm.a_ and all the resulting object files  
`make re` - Deletes everything (object files and _libasm.a_) and rebuilds _libasm.a_
#### Adding new functions to this library:
  - Add their prototypes to _libasm.h_
  - Add their source files to /libasm
  - Add their source file names to the "GENERAL" variable inside the Makefile   
  - Rebuild the library with `make re`
##### To keep track of what's inside your resulting _libasm.a_ run `ar -t libasm.a` 

## Useful links
[You Can Learn Assembly in 10 Minutes (it’s easy)](https://www.youtube.com/watch?v=jPDiaZS-2ok)  
[How do I know what registers function parameters will be mapped on?](https://stackoverflow.com/questions/28728742/how-do-i-know-what-registers-function-parameters-will-be-mapped-on)  
[Syscalls(2) man page](https://linux.die.net/man/2/syscalls)  
[Linux System Call Table for x86_64](http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)  
[x64 ASM Cheat Sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)  
[NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)  
[How does push and pop work in assembly](https://stackoverflow.com/questions/26026174/how-does-push-and-pop-work-in-assembly)  
[CPU Registers x86](https://wiki.osdev.org/CPU_Registers_x86)  
[Godbolt](https://godbolt.org/)  

---
Made by Nuno Carvalho (Kuninoto) | kuninoto@proton.me  
<div id="badge"> <a href="https://www.linkedin.com/in/nuno-carvalho-218822247"/> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>&nbsp;
