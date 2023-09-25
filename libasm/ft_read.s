;ssize_t read(int __fd, void *__buf, size_t __nbytes);
;rdi = fd
;rsi = buf
;rdx = nbytes
; refer to: http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

BITS 64
extern __errno_location

section .text
    global ft_read
    ft_read:
        push rbp ; Estabilish stack frame
        mov rbp, rsp ; Setup the base pointer

        mov rax, 0 ; Move 0 to rax (read syscall number)
        syscall ; Call kernel

        cmp rax, 0 ; Compare the value in rax (return value) with 0
        jl on_error ; Jump if condition evaluated to less than (in case of error a negative value is returned)

        jmp return ; Jump unconditionally

    on_error:
        neg rax ; Get the absolute value of the return value
        mov rdi, rax ; Preserve return value by saving it on another register
        call __errno_location WRT ..plt; Get the address of errno on rax
        mov [rax], rdi  ; Dereference errno's address and set it to value of rdi (where we stored the absolute return value, which is our error number)
        mov rax, -1 ; Move -1 to rax so that the caller receives -1 as the return value

        jmp return ; Jump unconditionally

    return:
        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller
