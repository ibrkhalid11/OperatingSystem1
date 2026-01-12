#include <stdint.h>
#include <utils.h>
#include <kernel/idt.h>
#include <kernel/timer.h>
#include <stdio.h>
uint64_t ticks;
const uint64_t freq = 100;

void onIrq0(struct InterruptRegisters *regs){
	ticks += 1;
	printf("timer ticked\n");
}

void initTimer(void){
	ticks = 0;
	irq_install_handler(0,&onIrq0);
	uint32_t divisor = 1193180/freq;
	outPortB(0x43, 0x36);
	outPortB(0x40, (uint8_t)(divisor & 0xFF));
	outPortB(0x40, (uint8_t)((divisor >> 8) & 0xFF));

	
}

