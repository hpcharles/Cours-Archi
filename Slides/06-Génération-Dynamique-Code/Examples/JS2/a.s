	.file	"a.c"
	.comm	program,1024,32
	.comm	stack,4096,32
	.comm	PCcounter,4,4
	.comm	STACKcounter,4,4
	.text
	.globl	functionInterpret
	.type	functionInterpret, @function
functionInterpret:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	PCcounter(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, PCcounter(%rip)
	movslq	%eax, %rdx
	leaq	program(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	testl	%eax, %eax
	je	.L3
	cmpl	$1, %eax
	je	.L4
	jmp	.L5
.L3:
	movl	STACKcounter(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	stack(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	STACKcounter(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	stack(%rip), %rax
	movl	(%rcx,%rax), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	STACKcounter(%rip), %eax
	subl	$1, %eax
	movl	%eax, STACKcounter(%rip)
	movl	STACKcounter(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	stack(%rip), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rcx,%rax)
	jmp	.L2
.L4:
	movl	$0, -4(%rbp)
	movl	STACKcounter(%rip), %eax
	subl	$1, %eax
	movl	%eax, STACKcounter(%rip)
	movl	STACKcounter(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	stack(%rip), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rcx,%rax)
	nop
.L2:
.L5:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	functionInterpret, .-functionInterpret
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
