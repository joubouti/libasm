
section .text
	global _ft_strlen
	global _ft_putstr
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
    push rdi
	mov rbx, 0
_ft_strloop:
	inc rdi
	inc rbx
	mov cl, [rdi]
	cmp cl, 0
	jne _ft_strloop
    pop rdi
	mov rdx, rbx
	mov rax, rdx
	ret

_ft_putstr:
    call _ft_strlen
    mov rdx, rax
    mov rax, 0x2000004
    mov rsi, rdi
    mov rdi, 1
    syscall
    ret

_ft_strcpy:
    ;call _ft_strlen
    ;add rdi, rax
    mov rbx, 0
_ft_scloop:
	mov cl, [rsi]
    mov [rdi], cl
    inc rsi
    inc rdi
    cmp cl, 0
	jne _ft_scloop
    ret

_ft_strcmp:
    mov rbx, 0
_ft_strcmpl:
    mov cl, [rdi]
    mov dl, [rsi]
    inc rdi
    inc rsi
    cmp cl, dl
    je _ft_strcmpl
    jg _ft_topos
    jl _ft_toneg
    ret
_ft_toneg:
    sub dl, cl
    xor rcx, rcx
    mov cl, dl
    neg rcx
    mov rax, rcx
    ret
_ft_topos:
    sub cl, dl
    xor rax, rax
    mov al, cl
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
