
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>
void kernel_main(void){
    terminal_initialize();
    initGdt();
    printf("GDT is initialized \n");
    printf("hello Kernel World \n");
    printf("this is line 2\n");
    printf("this is line 3\n");
}
