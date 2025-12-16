#ifndef TTY_H
#define TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(void);
void terminal_write(char c);
void terminal_writestring(const char *data);

#endif


