	.file	"lab09.c"
	.section	.rodata
.LC0:
	.string	"\n1) Afisare ordine lungimi: "
.LC1:
	.string	"%s "
	.align 8
.LC2:
	.string	"\n1) Afisare ordine alfabetica: "
	.text
	.globl	ordCresc
	.type	ordCresc, @function
ordCresc:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	movl	$101, %edi
	.cfi_offset 3, -24
	call	malloc
	movq	%rax, -64(%rbp)
	movl	$101, %edi
	call	malloc
	movq	%rax, -56(%rbp)
	movl	$404, %edi
	call	malloc
	movq	%rax, -48(%rbp)
	movl	$88, %edi
	call	malloc
	movq	%rax, -40(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L2
.L3:
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rbx
	addq	-40(%rbp), %rbx
	movl	$100, %edi
	call	malloc
	movq	%rax, (%rbx)
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	addl	$1, -32(%rbp)
.L2:
	cmpl	$9, -32(%rbp)
	jle	.L3
	movl	$0, -32(%rbp)
	jmp	.L4
.L5:
	movl	-32(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rsi
	addq	-48(%rbp), %rsi
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	$-1, -88(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-88(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	movl	%eax, (%rsi)
	addl	$1, -32(%rbp)
.L4:
	movl	-32(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L5
	movl	$.LC0, %eax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
.L9:
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L6
.L8:
	movl	-32(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-48(%rbp), %rax
	movl	(%rax), %edx
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$2, %rax
	addq	-48(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L7
	movl	-32(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-48(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -20(%rbp)
	movl	-32(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-48(%rbp), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$2, %rdx
	addq	-48(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$2, %rax
	addq	-48(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movq	-64(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movl	$1, -28(%rbp)
.L7:
	addl	$1, -32(%rbp)
.L6:
	movl	-76(%rbp), %eax
	subl	$1, %eax
	cmpl	-32(%rbp), %eax
	jg	.L8
	cmpl	$1, -28(%rbp)
	je	.L9
	movl	$0, -32(%rbp)
	jmp	.L10
.L11:
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movq	(%rax), %rdx
	movl	$.LC1, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -32(%rbp)
.L10:
	movl	-32(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L11
	movl	$.LC2, %eax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
.L21:
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L12
.L20:
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strdup
	movq	%rax, -64(%rbp)
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strdup
	movq	%rax, -56(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L13
.L15:
	movl	-24(%rbp), %eax
	cltq
	addq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$64, %al
	jle	.L14
	movl	-24(%rbp), %eax
	cltq
	addq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$90, %al
	jg	.L14
	movl	-24(%rbp), %eax
	cltq
	addq	-64(%rbp), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	-64(%rbp), %rdx
	movzbl	(%rdx), %edx
	addl	$32, %edx
	movb	%dl, (%rax)
.L14:
	addl	$1, -24(%rbp)
.L13:
	movq	-64(%rbp), %rax
	movq	$-1, -88(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-88(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	cmpl	-24(%rbp), %eax
	jg	.L15
	movl	$0, -24(%rbp)
	jmp	.L16
.L18:
	movl	-24(%rbp), %eax
	cltq
	addq	-56(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$64, %al
	jle	.L17
	movl	-24(%rbp), %eax
	cltq
	addq	-56(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$90, %al
	jg	.L17
	movl	-24(%rbp), %eax
	cltq
	addq	-56(%rbp), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	-56(%rbp), %rdx
	movzbl	(%rdx), %edx
	addl	$32, %edx
	movb	%dl, (%rax)
.L17:
	addl	$1, -24(%rbp)
.L16:
	movq	-56(%rbp), %rax
	movq	$-1, -88(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-88(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	cmpl	-24(%rbp), %eax
	jg	.L18
	movq	-56(%rbp), %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jle	.L19
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movq	-64(%rbp), %rdx
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movl	$1, -28(%rbp)
.L19:
	addl	$1, -32(%rbp)
.L12:
	movl	-76(%rbp), %eax
	subl	$1, %eax
	cmpl	-32(%rbp), %eax
	jg	.L20
	cmpl	$1, -28(%rbp)
	je	.L21
	movl	$0, -32(%rbp)
	jmp	.L22
.L23:
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rdx
	movl	$.LC1, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -32(%rbp)
.L22:
	movl	-32(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L23
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	ordCresc, .-ordCresc
	.globl	p1
	.type	p1, @function
p1:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	movl	$0, -20(%rbp)
	movl	$88, %edi
	.cfi_offset 3, -24
	call	malloc
	movq	%rax, -32(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L25
.L26:
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rbx
	addq	-32(%rbp), %rbx
	movl	$101, %edi
	call	malloc
	movq	%rax, (%rbx)
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	fgets
	addl	$1, -20(%rbp)
.L25:
	cmpl	$9, -20(%rbp)
	jle	.L26
	movl	-20(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	ordCresc
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	p1, .-p1
	.section	.rodata
.LC3:
	.string	"Nu este palindroma!"
.LC4:
	.string	"Este palindroma!"
	.text
	.globl	p2
	.type	p2, @function
p2:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	movl	$201, %edi
	.cfi_offset 3, -24
	call	malloc
	movq	%rax, -32(%rbp)
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-32(%rbp), %rax
	movq	$-1, -40(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-40(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	movl	%eax, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L28
.L30:
	movl	-20(%rbp), %eax
	cltq
	addq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L29
	movl	-20(%rbp), %eax
	cltq
	addq	$1, %rax
	addq	-32(%rbp), %rax
	movq	%rax, %rdx
	movl	-20(%rbp), %eax
	cltq
	addq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	subl	$1, -24(%rbp)
.L29:
	addl	$1, -20(%rbp)
.L28:
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L30
	subl	$1, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L31
.L34:
	movl	-20(%rbp), %eax
	cltq
	addq	-32(%rbp), %rax
	movzbl	(%rax), %edx
	movl	-20(%rbp), %eax
	movl	-24(%rbp), %ecx
	movl	%ecx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	cltq
	subq	$1, %rax
	addq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L32
	movl	$.LC3, %edi
	call	puts
	movl	$0, %eax
	jmp	.L33
.L32:
	addl	$1, -20(%rbp)
.L31:
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	-20(%rbp), %eax
	jg	.L34
	movl	$.LC4, %edi
	call	puts
	movl	$0, %eax
.L33:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	p2, .-p2
	.section	.rodata
.LC5:
	.string	" ,.-\n"
	.text
	.globl	p3
	.type	p3, @function
p3:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$200, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movl	$.LC5, %edx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strtok
	movq	%rax, -16(%rbp)
	jmp	.L36
.L37:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movl	$.LC5, %eax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok
	movq	%rax, -16(%rbp)
.L36:
	cmpq	$0, -16(%rbp)
	jne	.L37
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	p3, .-p3
	.section	.rodata
.LC6:
	.string	"numar de aparitii: %i\n"
	.text
	.globl	p4
	.type	p4, @function
p4:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	$201, %edi
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$201, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-16(%rbp), %rax
	movq	$-1, -40(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-40(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	subq	$1, %rax
	addq	-16(%rbp), %rax
	movb	$0, (%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movl	$.LC5, %edx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strtok
	movq	%rax, -32(%rbp)
	jmp	.L39
.L41:
	movq	-16(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L40
	addl	$1, -4(%rbp)
.L40:
	movl	$.LC5, %eax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok
	movq	%rax, -32(%rbp)
.L39:
	cmpq	$0, -32(%rbp)
	jne	.L41
	movl	$.LC6, %eax
	movl	-4(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	p4, .-p4
	.section	.rodata
.LC7:
	.string	"!!!"
	.text
	.globl	p5
	.type	p5, @function
p5:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	$501, %edi
	call	malloc
	movq	%rax, -32(%rbp)
	movl	$501, %edi
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$101, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$101, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	fgets
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movl	$500, %esi
	movq	%rax, %rdi
	call	fgets
	movq	-8(%rbp), %rax
	movq	$-1, -56(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-56(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	subq	$1, %rax
	addq	-8(%rbp), %rax
	movb	$0, (%rax)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	-16(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	jmp	.L43
.L44:
	movq	-40(%rbp), %rsi
	movq	-16(%rbp), %rax
	movq	$-1, -56(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-56(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	subq	$1, %rax
	leaq	(%rsi,%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	-8(%rbp), %rax
	movq	$-1, -56(%rbp)
	movq	%rax, %rdx
	movl	$0, %eax
	movq	-56(%rbp), %rcx
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memmove
	movq	-24(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat
	movq	-40(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strstr
	movq	%rax, -40(%rbp)
	movl	$.LC7, %eax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
.L43:
	cmpq	$0, -40(%rbp)
	jne	.L44
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	p5, .-p5
	.globl	p6
	.type	p6, @function
p6:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	p6, .-p6
	.section	.rodata
.LC8:
	.string	"problema: "
.LC9:
	.string	"%i"
.LC10:
	.string	"%i\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC8, %eax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$.LC9, %eax
	leaq	-4(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-4(%rbp), %edx
	movl	$.LC10, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	cmpl	$6, %eax
	ja	.L47
	movl	%eax, %eax
	movq	.L55(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L55:
	.quad	.L48
	.quad	.L49
	.quad	.L50
	.quad	.L51
	.quad	.L52
	.quad	.L53
	.quad	.L54
	.text
.L49:
	movl	$0, %eax
	call	p1
	jmp	.L56
.L50:
	movl	$0, %eax
	call	p2
	jmp	.L56
.L51:
	movl	$0, %eax
	call	p3
	jmp	.L56
.L52:
	movl	$0, %eax
	call	p4
	jmp	.L56
.L53:
	movl	$0, %eax
	call	p5
	jmp	.L56
.L54:
	movl	$0, %eax
	call	p6
	jmp	.L56
.L48:
	movl	$0, %eax
	jmp	.L57
.L47:
	movl	$0, %eax
	jmp	.L57
.L56:
	movl	$0, %eax
.L57:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
