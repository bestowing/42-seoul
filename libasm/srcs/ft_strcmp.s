section .text
	global _ft_strcmp

_ft_strcmp:
	mov rax, 0	; init 0 (caller-saved)
	mov r8, 0	; init 0 (caller-saved)
	mov r9, 0	; init 0 (caller-saved)
	jmp _loop	; entry loop

_loop:
	mov r8b, BYTE [rdi + rax]	; move 1 byte to r8
	mov r9b, BYTE [rsi + rax]	; move 1 byte to r9
	cmp r8b, 0					; check exit loop
	je _end						; exit loop
	cmp r9b, 0					; check exit loop
	je _end						; exit loop
	cmp r8b, r9b				; check exit loop
	jne _end					; exit loop (s1 != s2 or s1 == 0 or s2 == 0)
	inc rax						; inc idx (to next character)
	jmp _loop					; loop again

_end:
	cmp r8, r9		; compare r8 to r9
	je _equal		; r8 == r9
	jl _less		; r8 < r9
	sub r8, r9		; in case of r8 > r9
	mov rax, r8		; result = r8 - r9
	ret				; return

_equal:
	mov rax, 0		; result = 0
	ret				; return 0

_less:
	sub r9, r8		; in case of r8 < r9
	mov rax, r9		; result = r9 - r8
	neg rax			; result *= -1
	ret				; return
