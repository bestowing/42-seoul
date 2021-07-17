section .text
    global _ft_read
	extern	___error	; error handling for syscall

_ft_read:
	; param :
	; 	file descriptor param in $rdi
	; 	buffer to print in $rsi
	;	length of buffer in $rdx
	mov rax, 0x2000003	; syscall read()
	syscall
	jc _handle_err		; check if carry flag is true
	ret					; simply return

_handle_err:
	push rax			; store rax value (error value) in stack
	call ___error		; ___error func call (error address returned in rax)
	pop rdx				; load prev rax value (error value) from stack
	mov	[rax], rdx		; store error value in error address of memory
	mov	rax, -1			; if error occur, result should be -1
	ret					; return
