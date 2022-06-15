#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "hacking.h"

//#define FILENAME "./var/notes"
//#define FILENAME "var/notes"
#define FILENAME "/var/notes"

void usage(char *prog_name,char*filename){
    printf("Usage: %s <data add to %s>\n",prog_name,filename);
    exit(0);
}



int main(int argc,char* argv[]){
    int userid,fd;
    char *buffer, *datafile;

    buffer = (char*)ec_malloc(100);
    datafile = (char*)ec_malloc(50);
    strcpy(datafile,FILENAME);

    if(argc<2){
        usage(argv[0],datafile);
    }

    strcpy(buffer,argv[1]);

    printf("[DEBUG] buffer @%p: \' %s \'\n",buffer,buffer);
    printf("[DEBUG] datafile @%p: \' %s \'\n",datafile,datafile);

    fd=open(datafile,O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
   
    if(fd==-1)
        fatal("in main(), error opening the file");
    printf("file descriptor=%d\n",fd);


    userid=(int)getuid();

    if(write(fd,&userid,4)==-1)
        fatal("In main(), Error occured when writing user id ");
    write(fd,"\n",1);
        
    if(write(fd,buffer,strlen(buffer))==-1)
        fatal("In main(), Error occured when writing buffer to the file");
    write(fd,"\n",1);


    if(close(fd)==-1){
        fatal("Error occured when closing file\n");
    }

    printf("memo is reserved\n");
    free(buffer);
    free(datafile);


}
