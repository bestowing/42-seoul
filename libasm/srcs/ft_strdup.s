section .text
    global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
	extern ___error	; error handling for malloc()

_ft_strdup:
	call _ft_strlen	; get length of src string
	inc rax			; length + 1 (for null character)
	push rdi		; store rdi value (src string) in stack
	mov rdi, rax	; parameter for malloc func (size)
	call _malloc	; dynamic allocate
	pop rsi			; load prev rdi value (src string) from stack
	cmp rax, 0		; check if malloc was failed
	je _handle_err	; catch exception
	mov rdi, rax	; move allocated memory to rdi (strcpy parameter)
	call _ft_strcpy	; copy from src to dst, and result = dst
	ret				; so simply return

_handle_err:
	push 12			; store ENOMEM (error value) in stack
	call ___error	; ___error func call (error address returned in rax)
	pop rdx			; load prev rax value (error value) from stack
	mov	[rax], rdx	; store error value in error address of memory
	mov rax, 0		; if malloc was failed, result = null
	ret				; simply return
