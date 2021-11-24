.set MAGIC,    0x1BADB002
.set FLAGS,	0
.set CHECKSUM, -(MAGIC + FLAGS)
.section .multiboot

# define type to long for each data defined as above
.long MAGIC
.long FLAGS
.long CHECKSUM

   
.section .text
.extern _kernel
.global _loader


_loader:
    mov $kernel_stack, %esp
    push %ebx
    call _kernel
	cli
	
_stop:
    cli
    hlt
    jmp _stop


.section .bss
.space 4*1024*1024 # 4 MiB
kernel_stack:
