#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<elf.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>

static int elfdump(char *head){
    Elf64_Ehdr *ehdr;

    ehdr=(Elf64_Ehdr*)head;

    if(memcmp(ehdr->e_ident,"\x7f""ELF",4)!=0){
        fprintf(stderr,"This is not elf file\n");
        return 1;
    }else{
        fprintf(stderr,"This is elf file\n");   
    }

    int i;
    printf("  ehdr->e_ident = ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", ehdr->e_ident[i]);
    }
}

int main(int argc,char *argv[]){
    int fd;
    struct stat sb;
    char *head;
    fd = open(argv[1],O_RDONLY);
    if(fd<0) exit(1);
    fstat(fd,&sb);
    head = mmap(NULL,sb.st_size,PROT_READ,MAP_SHARED,fd,0);
    elfdump(head);
    munmap(head,sb.st_size);
    close(fd);

    exit(0);

}