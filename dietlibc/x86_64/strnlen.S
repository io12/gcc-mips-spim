.text
.global strnlen
.type strnlen,@function
strnlen:
	/* incoming: rdi = ptr, rsi = len */
	mov %rdi,%r8
	mov %rsi,%r9
	mov %rsi,%rdx
	xor %esi,%esi
#ifdef __PIC__
	call memchr@PLT
#else
	call memchr
#endif
	test %rax,%rax
	jz .Lnotfound
	sub %r8,%rax
	ret
.Lnotfound:
	mov %r9,%rax
	ret

.Lhere:
	.size	 strnlen,.Lhere-strnlen

	.section	.note.GNU-stack,"",@progbits
