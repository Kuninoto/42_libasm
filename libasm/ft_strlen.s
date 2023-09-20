;size_t ft_strlen(const char *__s)
;rdi = __s

BITS 64

global ft_strlen

ft_strlen:
    push rbp ; Estabilish stack frame
    mov rbp, rsp ; Setup the base pointer

    mov rbx, 0 ; Set rbx to 0. It'll be equivalent to an i (index) variable in C 
    jmp while ; Jump unconditionally to the while label

while:
    cmp BYTE[rdi+rbx], 0 ; Compare the byte in rdi+rbx with 0 (to check if it is a null byte)
    je return ; if condition evaluates to true jump to return label

    inc rbx ; Increment rbx (our indexing variable)
    jmp while ; Jump back to the while block

return:
    mov rax, rbx ; Move the value of rbx to rax to return its value to the caller
    mov rbp, rsp ; Tear down...
    pop rbp ; ...the stack frame
    ret ; Return to the caller 
