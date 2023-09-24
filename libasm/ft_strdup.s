;char *strdup(const char *s);
;rdi = s

BITS 64

extern malloc
extern ft_strlen
extern ft_strcpy
section .text
    global ft_strdup
    ft_strdup:
        push rbp ; Estabilish stack frame
	    mov rbp, rsp ; Setup the base pointer

        push rdi
        call ft_strlen ; Call ft_strlen to get the length of s
        inc rax ; Increment the value of rax (returned value of ft_strlen) to account for the null byte

        mov rdi, rax ; Move the length that we want to the first arg of malloc
        call malloc WRT ..plt ; Call malloc
        cmp rax, 0x00 ; Compare the return value of malloc with NULL
        je return ; If expression evaluated to true, return NULL

        mov rdi, rax ; Move the value in rax (returned ptr from malloc) to the rdi (the first argument of ft_strcpy)
        pop rsi
        call ft_strcpy ; Call ft_strcpy
        jmp return ; Jump unconditionally to return

    return:
        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller 
