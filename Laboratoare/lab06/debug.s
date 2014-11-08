	.file	"debug.c"
	.section	.rodata
.LC0:
	.string	"%i "
.LC1:
	.string	"\n%i %i %i \n"
.LC2:
	.string	"%i %i %i \n"
	.text
	.globl	magic
	.type	magic, @function
magic:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
	.cfi_offset 3, -24
.L3:
	movl	-20(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -20(%rbp)
.L2:
	movl	-20(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L3
	movl	$0, -20(%rbp)
	jmp	.L4
.L5:
	movl	-20(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %ecx
	movl	-20(%rbp), %edx
	movl	-44(%rbp), %esi
	movl	%esi, %ebx
	subl	%edx, %ebx
	movl	%ebx, %edx
	movslq	%edx, %rdx
	subq	$1, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %edx
	xorl	%ecx, %edx
	movl	%edx, (%rax)
	movl	-20(%rbp), %eax
	movl	-44(%rbp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	cltq
	salq	$2, %rax
	addq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %ecx
	movl	-20(%rbp), %edx
	movl	-44(%rbp), %esi
	movl	%esi, %ebx
	subl	%edx, %ebx
	movl	%ebx, %edx
	movslq	%edx, %rdx
	subq	$1, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %edx
	xorl	%ecx, %edx
	movl	%edx, (%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %ecx
	movl	-20(%rbp), %edx
	movl	-44(%rbp), %esi
	movl	%esi, %ebx
	subl	%edx, %ebx
	movl	%ebx, %edx
	movslq	%edx, %rdx
	subq	$1, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %edx
	xorl	%ecx, %edx
	movl	%edx, (%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-40(%rbp), %rax
	movl	(%rax), %edx
	movl	$.LC0, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -20(%rbp)
.L4:
	movl	-20(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L5
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %ecx
	movq	-40(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %edx
	movq	-40(%rbp), %rax
	movl	(%rax), %esi
	movl	$.LC1, %eax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
	jmp	.L6
.L7:
	addl	$1, -20(%rbp)
.L6:
	movl	-20(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L7
	movl	-20(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	-40(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %ecx
	movq	-40(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %edx
	movq	-40(%rbp), %rax
	movl	(%rax), %esi
	movl	$.LC2, %eax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	magic, .-magic
	.section	.rodata
.LC3:
	.string	"%i"
.LC4:
	.string	"%d"
.LC5:
	.string	"\n"
.LC6:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$416, %rsp
	movl	$.LC3, %eax
	leaq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$0, -4(%rbp)
	jmp	.L9
.L10:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	-416(%rbp), %rax
	addq	%rax, %rdx
	movl	$.LC4, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -4(%rbp)
.L9:
	movl	-8(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L10
	movl	-8(%rbp), %edx
	leaq	-416(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	magic
	movl	$.LC5, %edi
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L11
.L12:
	addl	$1, -4(%rbp)
.L11:
	movl	-8(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L12
	movl	-4(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %edx
	movl	$.LC6, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
