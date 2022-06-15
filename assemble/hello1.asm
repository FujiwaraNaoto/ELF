section .data
    call mark_below ;
    db "Hello, World!",0x0a,0x0d ; 
mark_below:
    ;syscall ssize_t write(int fd,const void *buf,size_t count)
    ;syscall size_t write(1,msg,14)
    pop rcx ;return address
    mov rax, 4 ;systemcall id
    mov rdi, 1 ;first argument
    mov rdx, 14 ;third argument
    syscall ;call kernel

    ;syscall exit(0)
    mov rax, 60 ;systemcall id
    mov rdi, 0 ;first argument
    syscall ;call kernel