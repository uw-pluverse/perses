_Complex int t = 0 ;
int f ( void )
{ asm (
"	.data\n"
"	.align	3\n"
"	.globl	stack_chk_guard_ptr\n"
"stack_chk_guard_ptr:\n"
"	.word	__stack_chk_guard\n"
"	.weak	__stack_chk_guard\n"
"__stack_chk_guard:\n"
"	.word	0xdead4321\n"
"	.text\n"
"	.type	__stack_chk_fail, %function\n"
"__stack_chk_fail:\n"
"	movs	r0, #0\n"
"	b	exit\n"
"	.size	__stack_chk_fail, .-__stack_chk_fail"
) ;
}
