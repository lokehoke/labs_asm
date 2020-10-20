	.file	"3.cpp"
	.text
	.globl	c
	.data
	.type	c, @object
	.size	c, 1
c:
	.byte	5
	.globl	s
	.align 2
	.type	s, @object
	.size	s, 2
s:
	.value	5
	.globl	l
	.align 8
	.type	l, @object
	.size	l, 8
l:
	.quad	5
	.globl	ll
	.align 8
	.type	ll, @object
	.size	ll, 8
ll:
	.quad	5
	.globl	ld
	.align 16
	.type	ld, @object
	.size	ld, 16
ld:
	.long	0
	.long	2684354560
	.long	16385
	.long	0
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movzbl	c(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	_Z1fIcET_S0_
	movb	%al, -5(%rbp)
	movzwl	s(%rip), %eax
	cwtl
	movl	%eax, %edi
	call	_Z1fIsET_S0_
	movb	%al, -4(%rbp)
	movq	l(%rip), %rax
	movq	%rax, %rdi
	call	_Z1fIlET_S0_
	movb	%al, -3(%rbp)
	movq	ll(%rip), %rax
	movq	%rax, %rdi
	call	_Z1fIxET_S0_
	movb	%al, -2(%rbp)
	fldt	ld(%rip)
	leaq	-16(%rsp), %rsp
	fstpt	(%rsp)
	call	_Z1fIeET_S0_
	addq	$16, %rsp
	fnstcw	-18(%rbp)
	movzwl	-18(%rbp), %eax
	orb	$12, %ah
	movw	%ax, -20(%rbp)
	fldcw	-20(%rbp)
	fistps	-22(%rbp)
	fldcw	-18(%rbp)
	movzwl	-22(%rbp), %eax
	movb	%al, -1(%rbp)
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text._Z1fIcET_S0_,"axG",@progbits,_Z1fIcET_S0_,comdat
	.weak	_Z1fIcET_S0_
	.type	_Z1fIcET_S0_, @function
_Z1fIcET_S0_:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	addl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z1fIcET_S0_, .-_Z1fIcET_S0_
	.section	.text._Z1fIsET_S0_,"axG",@progbits,_Z1fIsET_S0_,comdat
	.weak	_Z1fIsET_S0_
	.type	_Z1fIsET_S0_, @function
_Z1fIsET_S0_:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movw	%ax, -4(%rbp)
	movzwl	-4(%rbp), %eax
	addl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z1fIsET_S0_, .-_Z1fIsET_S0_
	.section	.text._Z1fIlET_S0_,"axG",@progbits,_Z1fIlET_S0_,comdat
	.weak	_Z1fIlET_S0_
	.type	_Z1fIlET_S0_, @function
_Z1fIlET_S0_:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	%rax, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z1fIlET_S0_, .-_Z1fIlET_S0_
	.section	.text._Z1fIxET_S0_,"axG",@progbits,_Z1fIxET_S0_,comdat
	.weak	_Z1fIxET_S0_
	.type	_Z1fIxET_S0_, @function
_Z1fIxET_S0_:
.LFB5:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	%rax, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_Z1fIxET_S0_, .-_Z1fIxET_S0_
	.section	.text._Z1fIeET_S0_,"axG",@progbits,_Z1fIeET_S0_,comdat
	.weak	_Z1fIeET_S0_
	.type	_Z1fIeET_S0_, @function
_Z1fIeET_S0_:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	fldt	16(%rbp)
	fadd	%st(0), %st
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_Z1fIeET_S0_, .-_Z1fIeET_S0_
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
