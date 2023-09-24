;char *strdup(const char *s);
;rdi = s

BITS 64

extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

ft_strdup:
    push rbp ; Estabilish stack frame
	mov rbp, rsp ; Setup the base pointer

    push rdi
    call ft_strlen ; Call ft_strlen to get the length of s
    inc rax ; Increment the value of rax (returned value of ft_strlen) to account for the null byte

    mov rdi, rax ; move the length that we want to the first arg of malloc
    call malloc WRT ..plt
    cmp rax, 0x00 ; Compare the return value of malloc with NULL
    je return

    mov rdi, rax
    pop rsi
    call ft_strcpy
    jmp return

return:
    mov rbp, rsp ; Tear down...
    pop rbp ; ...the stack frame
    ret ; Return to the caller 
