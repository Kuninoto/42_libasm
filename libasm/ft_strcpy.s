;char *strcpy(char *dest, const char *src)
;rdi = dest
;rsi = src

BITS 64

section .text
    global ft_strcpy
    ft_strcpy:
	    push rbp ; Estabilish stack frame
	    mov rbp, rsp ; Setup the base pointer

        xor rcx, rcx ; Set rcx to 0. It'll be our indexing variable
        jmp while ; Jump unconditionally to the while label

    while:
        cmp BYTE[rsi+rcx], 0 ; Compare the byte in rsi+rcx with 0 (to check if it is a null byte)
        je return ; ; Jump if equal

        mov ah, BYTE[rsi+rcx] ; Move the current char on src to ah (serves as a temp variable)
        mov BYTE[rdi+rcx], ah ; Move the char that came from src to dest

        inc rcx ; Increment rcx (our indexing variable)
        jmp while ; Jump unconditionally to the while label

    return:
        mov BYTE[rdi+rcx], 0 ; null-terminate the dest src
        mov rax, rdi ; move the dest pointer (rdi) to rax to return it

        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller 
    