section .text
    global _ft_strcpy

_ft_strcpy:
	mov rax, 0	; init 0 (caller-saved)
	mov rcx, 0	; init 0 (caller-saved)
	jmp _copy	; entry loop

_copy:
	mov cl, BYTE [rsi + rax]	; move 1 byte from src to cl
	mov [rdi + rax], cl;		; move 1 byte from cl to dst
	cmp cl, 0					; check if null character
	je _end						; end
	inc rax						; inc idx
	jmp _copy					; loop again

_end:
	mov rax, rdi	; result = dst
	ret				; return
