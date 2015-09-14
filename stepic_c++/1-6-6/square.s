	.file	"square.cpp"
	.text
	.globl	_Z6squarei
	.def	_Z6squarei;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6squarei
_Z6squarei:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	imull	16(%rbp), %eax
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 4.9.3"
