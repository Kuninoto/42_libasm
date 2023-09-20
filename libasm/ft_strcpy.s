;char *strcpy(char *dest, const char *src)
;rdi = dest
;rsi = src

BITS 64

ft_strcpy:
	push rbp ; Estabilish stack frame
	mov rbp, rsp ; Setup the base pointer

    mov rbx, 0 ; Set rbx to 0. It'll be equivalent to an i (index) variable in C 
    jmp while ; Jump unconditionally to the while label

while:
    cmp BYTE[rsi+rbx], 0 ; Compare the byte in rsi+rbx with 0 (to check if it is a null byte)
    je return ; if condition evaluates to true jump to return label

    mov BYTE[rdi+rbx], BYTE[rsi+rbx] ; Figure out why I cant do this operation

    inc rbx ; Increment rbx (our indexing variable of the src str)
    jmp while ; Jump back to the while block

return:
    mov BYTE[rdi+rbx], 0 ; null-terminate the dest src
    mov rax, rdi ; move the dest pointer (rdi) to rax to return it
    mov rbp, rsp ; Tear down...
    pop rbp ; ...the stack frame
    ret ; Return to the caller 
    
