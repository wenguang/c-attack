	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	__ZN13CSimpleBufferC2Ev
	.align	4, 0x90
__ZN13CSimpleBufferC2Ev:                ## @_ZN13CSimpleBufferC2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	$0, (%rdi)
	movl	$0, 8(%rdi)
	movl	$0, 12(%rdi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN13CSimpleBufferC1Ev
	.align	4, 0x90
__ZN13CSimpleBufferC1Ev:                ## @_ZN13CSimpleBufferC1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN13CSimpleBufferC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN13CSimpleBufferD2Ev
	.align	4, 0x90
__ZN13CSimpleBufferD2Ev:                ## @_ZN13CSimpleBufferD2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$0, 8(%rdi)
	movl	$0, 12(%rdi)
	cmpq	$0, (%rdi)
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	je	LBB2_2
## BB#1:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	callq	_free
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	$0, (%rax)
LBB2_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN13CSimpleBufferD1Ev
	.align	4, 0x90
__ZN13CSimpleBufferD1Ev:                ## @_ZN13CSimpleBufferD1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN13CSimpleBufferD2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN13CSimpleBuffer6ExtendEj
	.align	4, 0x90
__ZN13CSimpleBuffer6ExtendEj:           ## @_ZN13CSimpleBuffer6ExtendEj
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movl	12(%rdi), %esi
	addl	-12(%rbp), %esi
	movl	%esi, 8(%rdi)
	movl	8(%rdi), %esi
	shrl	$2, %esi
	addl	8(%rdi), %esi
	movl	%esi, 8(%rdi)
	movq	(%rdi), %rax
	movl	8(%rdi), %esi
                                        ## 
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	_realloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	LBB4_2
## BB#1:
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movq	%rax, (%rcx)
LBB4_2:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN13CSimpleBuffer5WriteEPvj
	.align	4, 0x90
__ZN13CSimpleBuffer5WriteEPvj:          ## @_ZN13CSimpleBuffer5WriteEPvj
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	-8(%rbp), %rsi
	movl	12(%rsi), %edx
	addl	-20(%rbp), %edx
	cmpl	8(%rsi), %edx
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	jbe	LBB5_2
## BB#1:
	movl	-20(%rbp), %esi
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN13CSimpleBuffer6ExtendEj
LBB5_2:
	cmpq	$0, -16(%rbp)
	je	LBB5_4
## BB#3:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rcx
	movl	12(%rax), %edx
	movl	%edx, %esi
	addq	%rsi, %rcx
	movq	-16(%rbp), %rsi
	movl	-20(%rbp), %edx
                                        ## 
	movq	%rcx, %rdi
	callq	_memcpy
LBB5_4:
	movl	-20(%rbp), %eax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	addl	12(%rcx), %eax
	movl	%eax, 12(%rcx)
	movl	-20(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZN13CSimpleBuffer4ReadEPvj
	.align	4, 0x90
__ZN13CSimpleBuffer4ReadEPvj:           ## @_ZN13CSimpleBuffer4ReadEPvj
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	-8(%rbp), %rsi
	movl	-20(%rbp), %edx
	cmpl	12(%rsi), %edx
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	jbe	LBB6_2
## BB#1:
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movl	12(%rax), %ecx
	movl	%ecx, -20(%rbp)
LBB6_2:
	cmpq	$0, -16(%rbp)
	je	LBB6_4
## BB#3:
	movq	-16(%rbp), %rdi
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rsi
	movl	-20(%rbp), %ecx
	movl	%ecx, %edx
	callq	_memcpy
LBB6_4:
	movl	-20(%rbp), %eax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movl	12(%rcx), %edx
	subl	%eax, %edx
	movl	%edx, 12(%rcx)
	movq	(%rcx), %rdi
	movq	(%rcx), %rsi
	movl	-20(%rbp), %eax
	movl	%eax, %r8d
	addq	%r8, %rsi
	movl	12(%rcx), %eax
	movl	%eax, %edx
	callq	_memmove
	movl	-20(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
