
#ifndef HACKING_H
#define HACKING_H

void dump(const char *data_buffer,const unsigned int length);
void fatal(char *message);
void *ec_malloc(unsigned int size);
#endif
