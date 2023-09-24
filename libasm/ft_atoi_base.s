;int ft_atoi_base(char *str, char *base);
;rdi = fd
;rsi = buf
;rdx = nbytes
; refer to: C04 ex05

BITS 64

section .text
    global ft_atoi_base
    ft_atoi_base:
        push rbp ; Estabilish stack frame
	    mov rbp, rsp ; Setup the base pointer
    

    return:
        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller
