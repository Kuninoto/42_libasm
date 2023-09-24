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
    
    is_valid_base:
        ; Check if base is null
        ; Check base's length 0 || 1
        ; Check if it has white spaces or signs
        ; Return 1 on error

    return:
        mov rbp, rsp ; Tear down...
        pop rbp ; ...the stack frame
        ret ; Return to the caller
