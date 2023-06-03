; Sidhardh Burre, ssb3vk@virginia.edu, 4/8/2021, mathlib.s
;
; Purpose : This file contains the implementation of two functions: 
; 	product and power. The first calculates x*y the second calculates
; 	x^y.
;
; Parameter 1 (in rdi) is the x term
; Parameter 2 (in rsi) is the y term
; Return value is a long that is either x*y or x^y
;

	global product
	global power

	section .text

product: 
	; Addition-based iterative multiplication

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	rdx, rdx	 ; zero out the counter i
	
start:	
	cmp	rdx, rsi	 ; does i == y?
	je	ProdDone	 ; if so, we are done with the loop
	add	rax, rdi	 ; add x to rax
	inc	rdx		 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
ProdDone:	
				 ; reflection of above push
	ret
	
	
	
power:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.
	; Recursion-based power finding 

	cmp rdi, 1	;is the x value 1? If so we can just return 1
	je powBase
	cmp rsi, 0	;is the y value 0? If so we can just return 1
	je powBase
	
	; recursively compute the power
	dec rsi	; setting up y-1 for the recursive cal
	call power	; calling recursively
	
	mov rsi, rax	; moving the return value into the second register for multiplying
	call product	; multiply 
	ret		; return
	
powBase:	

	mov rax, 1
	ret

