
section .text
	global _ft_strlen
	global _ft_strcpy
	global _ft_strcmp
    global _ft_write
    global _ft_read
    global _ft_strdup

_exit:
    mov rax, 0x2000001
    syscall
    ret
_ft_strlen:
    push rbx
	mov rbx, 0
_ft_strloop:
	mov cl, [rdi]
	cmp cl, 0
	jne _ft_strlenne
	; mov rdx, rbx
	mov rax, rbx
    pop rbx
	ret
_ft_strlenne:
    inc rdi
	inc rbx
    jmp _ft_strloop

_ft_strcpy:
    push rbx
    mov rbx, rdi
_ft_scloop:
	mov cl, [rsi]
    mov [rdi], cl
    inc rsi
    inc rdi
    cmp cl, 0
	jne _ft_scloop
    mov rax, rbx
    pop rbx
    ret

_ft_strcmp:
    push rbx
    mov rbx, 0
    mov rax, 0
    mov r13, 0
_ft_cmploop:
    mov r13b, [rdi]
    mov bl, [rsi]
    cmp r13b, bl
    je _ft_cmpe
    jne _ft_cmpne
    pop rbx
    ret

_ft_cmpne:
    sub r13, rbx
    mov rax, r13
    pop rbx
    ret

_ft_cmpe:
    cmp bl, 0
    je _ft_cmpz
    inc rdi
    inc rsi
    jmp _ft_cmploop
_ft_cmpz:
    pop rbx
    ret

_ft_write:
    mov rax, 0x2000004
    syscall
    jc _err
    ret

_err:
mov rax, -1
ret

_ft_read:
    mov rax, 0x2000003
    syscall
    jc _err
    ret


_ft_strdup:
   push rbp
   mov r12, rdi
   call _ft_strlen
   mov rdi, rax
   inc rdi
   extern _malloc
   call _malloc
   cmp rax, 0
   je .error
   mov r13, rax
   mov rdi, r13
   mov rsi, r12
   ;extern _strcpy
   call _ft_strcpy
   mov rax, r13
   pop rbp
   ret
.error:
	pop rbp
	ret
