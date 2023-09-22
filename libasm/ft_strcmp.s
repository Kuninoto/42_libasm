;char *strcpy(const char *__s1, const char *__s2)
;rdi = __s1
;rsi = __s2

BITS 64

global ft_strcmp

ft_strcmp:
	push rbp ; Estabilish stack frame
	mov rbp, rsp ; Setup the base pointer

	mov rcx, 0x00 ; Set rcx to 0. It'll be equivalent to an i (index) variable in C 
    jmp while ; Jump unconditionally to the while label

while:
	

return:
    mov rbp, rsp ; Tear down...
    pop rbp ; ...the stack frame
    ret ; Return to the caller 
