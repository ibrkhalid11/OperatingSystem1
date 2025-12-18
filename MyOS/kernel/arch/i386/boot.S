#compile using i686-elf-as boot.s -o boot.o
.set MULTIBOOT2_MAGIC, 0xE85250D6
.set MULTIBOOT2_ARCHITECTURE, 0
.set MULTIBOOT2_HEADER_LENGTH, (multiboot_header_end - multiboot_header_start)
.set MULTIBOOT2_CHECKSUM, -(MULTIBOOT2_ARCHITECTURE + MULTIBOOT2_HEADER_LENGTH + MULTIBOOT2_MAGIC)
# Declare a header as in the Multiboot Standard.
.section .multiboot2
.align 8


multiboot_header_start:
    .long MULTIBOOT2_MAGIC
    .long MULTIBOOT2_ARCHITECTURE
    .long MULTIBOOT2_HEADER_LENGTH
    .long MULTIBOOT2_CHECKSUM

    .align 8
    .short 0
    .short 0
    .long 8
multiboot_header_end:

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
