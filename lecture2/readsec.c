// /usr/local/include 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<elf.h>
#include<sys/stat.h>
#include<sys/mman.h>

int main(int argc,char *argv[])
{
    int fd,i;
    struct stat sb;
    char *head;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    Elf64_Shdr *shstr;


    fd = open(argv[1],O_RDONLY);
    fstat(fd,&sb);
    head = mmap(NULL,sb.st_size, PROT_READ, MAP_SHARED,fd,0);

    ehdr = (Elf64_Ehdr*)head;
    //printf("test\n");    
    
    //if(!IS_ELF(*ehdr)){
    //    fprintf(stderr,"This is not ELF file. (%s)\n",argv[1]);
    //}
    
    

    shstr = (Elf64_Shdr*)(head + ehdr->e_shoff + ehdr->e_shentsize * ehdr->e_shstrndx);

    for(i=0;i<ehdr->e_shnum;i++){
        shdr = (Elf64_Shdr*)(head + ehdr->e_shoff + ehdr->e_shentsize*i);
        printf("%s\n",(char*)(head + shstr->sh_offset + shdr->sh_name));
    }

    //printf("test\n");    
    munmap(head,sb.st_size);
    close(fd);

    exit(0);
    
}

/*
int main(int argc,char *argv[])
{
    int fd,i;
    struct stat sb;
    char *head;
    Elf32_Ehdr *ehdr;
    Elf32_Shdr *shdr;
    Elf32_Shdr *shstr;


    fd = open(argv[1],O_RDONLY);
    fstat(fd,&sb);
    head = mmap(NULL,sb.st_size, PROT_READ, MAP_SHARED,fd,0);

    ehdr = (Elf32_Ehdr*)head;
    
    
    //if(!IS_ELF(*ehdr)){
    //    fprintf(stderr,"This is not ELF file. (%s)\n",argv[1]);
    //}
    
    

    shstr = (Elf32_Shdr*)(head + ehdr->e_shoff + ehdr->e_shentsize*ehdr->e_shstrndx);

    for(i=0;i< ehdr->e_shnum;i++){
        shdr = (Elf32_Shdr*)(head + ehdr->e_shoff + ehdr->e_shentsize*i);
        printf("%s\n",(char*)(head + shstr->sh_offset + shdr->sh_name));
    }
    
    munmap(head,sb.st_size);
    close(fd);

    exit(0);
    
}
*/
