.global _main
.align 4

_main:
	mov X0, #1          ;
	adr X1, helloworld  ;
	mov X2, #16         ;
	mov X16, #4         ;
	svc #0x80           ;
	
	mov X0, #0          ;
	mov X16, #1         ;
	svc #0xFFFF         ;

helloworld:     .ascii "Hello, World!\n"