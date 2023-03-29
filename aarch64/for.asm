.global _start
// .section .text

_start:
	mov x15, #6

loop:
	cmp x15, #0
	beq exit

	bl hello_world

	sub x15, x15, #1
	b loop


// hello_world
	mov x8, #64
	mov x0, #1
	ldr x1, =message
	mov x2, #13
	svc 0
	ret

exit:
	mov x8, #0x5d
	mov x0, #0x41
	svc 0


.data
	message:
	.ascii "Hello, World"