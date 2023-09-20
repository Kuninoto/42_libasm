; ----------------------------------------- ;
; CLI:                                      ;
;	nasm -f elf64 ft_write.s                ;
;   ld ft_write.o -o ft_write && ./ft_write ; 
; ----------------------------------------- ;

;ssize_t write(int __fd, const void *__buf, size_t __n);
;rdi = fd
;rsi = buf
;rdx = count
; refer to: http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

BITS 64
extern __errno_location

global ft_write

ft_write:
	push rbp ; Estabilish the stack frame
	mov rbp, rsp ; Setup the base pointer

	mov rax, 1 ; move 1 to rax, the write syscall number 
	syscall ; call kernel

	cmp rax, 0 ; compare the value in rax (return value of write) with 0
	jl on_error ; jump if condition evaluated to less (in case of an error a negative value is returned)

	mov rbp, rsp ; tear down...
	pop rbp ; ...the stack frame
	ret ; return to the caller

; review this
on_error:
	neg rax ; get the absolute value of syscall return
    mov rdi, rax ; preserve syscall return value by saving it in rdi
    call __errno_location WRT ..plt; get the address of errno on rax
    mov [rax], rdi  ; set the value of errno onto the address of errno
    mov rax, -1 ; move -1 to rax so that the caller receives -1 as the return value

	mov rbp, rsp ; tear down...
	pop rbp ; ...the stack frame
	ret ; return to the caller
