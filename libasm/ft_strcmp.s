;char *strcmp(const char *__s1, const char *__s2)
;rdi = __s1
;rsi = __s2

BITS 64

section .text
    global ft_strcmp
    ft_strcmp:
	    push rbp ; Estabilish stack frame
	    mov rbp, rsp ; Setup the base pointer

        jmp while ; Jump unconditionally to the while label

    while:
        cmp BYTE[rdi], 0 ; Compare the byte in rdi with 0 (to check if it is a null byte)
        je return ; Jump if equal
        
        cmp BYTE[rsi], 0 ; Compare the byte in rsi with 0 (to check if it is a null byte)
        je return ; Jump if equal

        mov ah, BYTE[rsi] ; Move the current char on __s2 to ah (serves as a temp variable)
        cmp BYTE[rdi], ah ; Compare the current chars on both strings
        jne return ; Jump if not equal

        inc rdi ; Increment rdi (our s1 ptr)
        inc rsi ; Increment rsi (our s2 ptr)
        jmp while ; Jump back to the while block

    return:
        movzx rax, BYTE[rdi] ; Move the current character on __s1 to rax
        movzx rbx, BYTE[rsi] ; Move the current charactere on __s2 to rbx
        sub rax, rbx ; Subtract the last characters where the loop ended (s1[i] - s2[i])

        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller 
