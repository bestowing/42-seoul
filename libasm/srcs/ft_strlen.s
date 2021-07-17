section .text
    global _ft_strlen

_ft_strlen:
    mov rax, 0	; init 0 (caller-saved)
	jmp _loop	; entry loop

_loop:
	cmp BYTE [rdi + rax], 0	; check if null character
	je _end					; end
	inc rax					; inc len
	jmp _loop				; loop again

_end:
	ret	; simply return
