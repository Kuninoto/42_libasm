;size_t ft_strlen(const char *__s)
;rdi = __s

BITS 64

section .text
    global ft_strlen

    ft_strlen:
        push rbp ; Estabilish stack frame
        mov rbp, rsp ; Setup the base pointer

        xor rcx, rcx ; Set rcx to 0. It'll be our indexing variable 
        jmp while ; Jump unconditionally to the while label

    while:
        cmp BYTE[rdi+rcx], 0 ; Compare the byte in rdi+rcx with 0 (to check if it is a null byte)
        je return ; if condition evaluates to true jump to return label

        inc rcx ; Increment rcx (our indexing variable)
        jmp while ; Jump back to the while block

    return:
        mov rax, rcx ; Move the value of rcx to rax to return its value to the caller
        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller 
