
#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void){
    terminal_initialize();
    printf("hello Kernel World \n");
    printf("this is line 2\n");
    printf("this is line 3\n");
}
