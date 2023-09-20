;size_t ft_strlen(const char *__s)
;rdi = __s
; refer to: http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

BITS 64
extern __errno_location

global ft_strlen

ft_strlen:
    push rbp ; Estabilish stack frame
    mov rbp, rsp ; Setup the base pointer

    mov rcx, 0 ; Set rcx to 0. It'll be equivalent to an i (index) variable in C 
    jmp while ; Jump unconditionally to the while label

while:
    cmp BYTE[rdi+rcx], 0 ; Compare the byte in rdi+rdx with 0 (to check if it is a null byte)
    je return ; if condition evaluates to true jump to return label

    inc rcx ; Increment rcx
    jmp while ; Jump back to the while block

return:
    mov rax, rcx ; Move the value of rcx to  
    mov rbp, rsp ; Tear down...
    pop rbp ; ...the stack frame
    ret ; Return to the caller 
