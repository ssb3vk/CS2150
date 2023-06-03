	;;  Sidhardh Burre, ssb3vk@virginia.edu, 4/9/2021, linearSearch.s

	global linearSearch

	section .text

	;;  Parameter 1 is a pointer to the int array
	;;  Parameter 2 is the size of the array
	;;  Parameter 3 is the value that we are searching for

linearSearch:			; Implementation of linearSearch here

	dec rsi	; this enables us to use rsi as our comparator
	xor rcx, rcx	; zeroing out rcx to iterate through the loop
	
searchLoop:			; This is our loop for the search

	cmp rcx, rsi 
	jg searchFailure		; We have iterated over our loop and haven't found our element
	mov r8d, DWORD [rdi + 4*rcx]
	cmp edx, r8d		; Accessing value at index rdx to compare
	je searchSuccess	; We have found our element
	inc rcx		; Iterating backwards so decrement
	jmp searchLoop

searchSuccess:			; We have succeeded in finding the value

	mov rax, rcx
	ret
	
searchFailure: 		; We have failed in finding the value

	mov rax, -1		; moving -1 into rax as a sign of failure
	ret
	


	
