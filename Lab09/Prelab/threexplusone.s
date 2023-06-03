	;;  Sidhardh Burre, ssb3vk@virginia.edu, 4/15/2021, threexplusone.s

	global threexplusone

	section .text

	;;  Parameter 1 (rdi) is the value of the collatz input a 4 byte unsigned int

	;;  Optimization list, all tested at 27, 1000000
	;;  test instead of cmp for comparison
	;;  bit shifting for even collatz instead of dividing
	;;  imul + add for odd instead of register move, bit shift, increment ~0.01 ms
	;;  imul + add for odd instead of lea [3*rdi + 1] ~0.03 ms
	;;  rax increments instead of add rax, 1 ~0.04 ms
	;;  removing the jz even command saves a lot of time ~0.04 ms
	;;  having no push/pops is probably a optimization as well

threexplusone:			; Implementation of recursive collatz here

	cmp rdi, 1		; comparing the input to one
	je one			; if equal we can just perform our base case

	test dil, 1   ; this is slighlty faster than cmp
	jnz odd	      ; jump to odd if the least significant bit is 1
	;;  don't need to jump to even as that's what comes next anyway
	
	
even:				; operation for an even parameter

	shr rdi, 1		; shifting right, dividing by 2
	call threexplusone	; effectivley calling collatz(input/2)
	inc rax			; incrementing rax
	ret			; returning
	
odd:				; operation for an odd parameter

	imul rdi, 3		; multiplying the input by 3 rdi = rdi * 3
	inc rdi			; incrementing rdi rdi = 3* rdi + 1
	call threexplusone	; the recursive call
	inc rax			; incrementing rax, doing our part of the recursion
	ret			; returning
	
one:				; end case 

	xor rax, rax		; zeroing out rax
	ret			; returning
	


	
