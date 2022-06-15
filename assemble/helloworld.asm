section .data
msg db "Hello, World!",0x0a
section .text
global _start ;entry point 
_start:
    ;syscall write(1,msg,14)
    mov rax, 1 ;systemcall id
    mov rdi, 1 ;first argument
    mov rsi, msg ;second argument
    mov rdx, 14 ;third argument
    syscall ;call kernel

    ;syscall exit(0)
    mov rax, 60 ;systemcall id
    mov rdi, 0 ;first argument
    syscall ;call kernel