	.file	"MyClass.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.section	.text$_ZN4CubeC1Eddd,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4CubeC1Eddd
	.def	__ZN4CubeC1Eddd;	.scl	2;	.type	32;	.endef
__ZN4CubeC1Eddd:
LFB1447:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-4(%ebp), %eax
	fldl	-16(%ebp)
	fstpl	(%eax)
	movl	-4(%ebp), %eax
	fldl	-24(%ebp)
	fstpl	8(%eax)
	movl	-4(%ebp), %eax
	fldl	-32(%ebp)
	fstpl	16(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$24
	.cfi_endproc
LFE1447:
	.section	.text$_ZNK4Cube10calcVolumeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK4Cube10calcVolumeEv
	.def	__ZNK4Cube10calcVolumeEv;	.scl	2;	.type	32;	.endef
__ZNK4Cube10calcVolumeEv:
LFB1452:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	fldl	(%eax)
	movl	-4(%ebp), %eax
	fldl	8(%eax)
	fmulp	%st, %st(1)
	movl	-4(%ebp), %eax
	fldl	16(%eax)
	fmulp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1452:
	.section	.text$_ZNK4Cube13calcPerimeterEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK4Cube13calcPerimeterEv
	.def	__ZNK4Cube13calcPerimeterEv;	.scl	2;	.type	32;	.endef
__ZNK4Cube13calcPerimeterEv:
LFB1453:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	fldl	(%eax)
	movl	-4(%ebp), %eax
	fldl	8(%eax)
	faddp	%st, %st(1)
	movl	-4(%ebp), %eax
	fldl	16(%eax)
	faddp	%st, %st(1)
	fadd	%st(0), %st
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1453:
	.section	.text$_ZNK4Cube11cubeCompareERKS_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK4Cube11cubeCompareERKS_
	.def	__ZNK4Cube11cubeCompareERKS_;	.scl	2;	.type	32;	.endef
__ZNK4Cube11cubeCompareERKS_:
LFB1454:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK4Cube10calcVolumeEv
	fstpl	-24(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNK4Cube13calcPerimeterEv
	fldl	-24(%ebp)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jp	L15
	fldl	-24(%ebp)
	fucompp
	fnstsw	%ax
	sahf
	jne	L7
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK4Cube13calcPerimeterEv
	fstpl	-24(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNK4Cube13calcPerimeterEv
	fldl	-24(%ebp)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jp	L16
	fldl	-24(%ebp)
	fucompp
	fnstsw	%ax
	sahf
	jne	L7
	movl	$1, %eax
	jmp	L10
L15:
	fstp	%st(0)
	jmp	L7
L16:
	fstp	%st(0)
L7:
	movl	$0, %eax
L10:
	testb	%al, %al
	je	L11
	movl	$1, %eax
	jmp	L12
L11:
	movl	$0, %eax
L12:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1454:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC4:
	.ascii "\347\253\213\346\226\271\351\253\224\351\235\242\347\251\215: \0"
LC5:
	.ascii "\347\253\213\346\226\271\351\253\224\345\221\250\351\225\267: \0"
LC6:
	.ascii "\347\233\270\347\255\211\0"
LC7:
	.ascii "\344\270\215\347\233\270\347\255\211\0"
LC8:
	.ascii "\345\205\251\347\253\213\346\226\271\351\253\224\346\230\257\345\220\246\347\233\270\347\255\211: \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1455:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$96, %esp
	call	___main
	leal	-32(%ebp), %eax
	fldl	LC1
	fstpl	16(%esp)
	fldl	LC2
	fstpl	8(%esp)
	fldl	LC3
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZN4CubeC1Eddd
	subl	$24, %esp
	leal	-32(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK4Cube10calcVolumeEv
	fstpl	-64(%ebp)
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-64(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leal	-32(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK4Cube13calcPerimeterEv
	fstpl	-64(%ebp)
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-64(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leal	-56(%ebp), %eax
	fldl	LC1
	fstpl	16(%esp)
	fldl	LC2
	fstpl	8(%esp)
	fldl	LC3
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZN4CubeC1Eddd
	subl	$24, %esp
	leal	-32(%ebp), %eax
	leal	-56(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK4Cube11cubeCompareERKS_
	subl	$4, %esp
	xorl	$1, %eax
	testb	%al, %al
	je	L18
	movl	$LC6, %ebx
	jmp	L19
L18:
	movl	$LC7, %ebx
L19:
	movl	$LC8, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1455:
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1889:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1889:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1888:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L24
	cmpl	$65535, 12(%ebp)
	jne	L24
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L24:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1888:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1890:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1890:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.section .rdata,"dr"
	.align 8
LC1:
	.long	0
	.long	1074921472
	.align 8
LC2:
	.long	858993459
	.long	1074475827
	.align 8
LC3:
	.long	1717986918
	.long	1073899110
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
