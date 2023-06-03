	;;  Sidhardh Burre, ssb3vk@virginia.edu, 4/15/2021, threexplusone.s

	global binarySearch

	section .text

	;;  Parameter 1 (rdi) is the pointer to the int array
	;;  Parameter 2 (rsi) is the left index of the array
	;;  Parameter 3 (rdx) is the right index of the array
	;;  Parameter 4 (rcx) is the target that we are looking for
	;;  Return type is int, index (success), -1 (failure)

binarySearch:			;Implementation of iterative binarySearch here

	cmp rsi, rdx		; Comparing low and high indeces
	jg searchFail		; If they are equal the element is not in the array

	mov r8, rsi 		; r8 is going to be our mid value
	add r8, rdx		; adding rdx so r8 = rdx + rsi or low + high
	shr r8, 1		; bit shifting by 2 to divide

	cmp ecx, DWORD [rdi + 4*r8]; comparing the target to the mid value
	jg targetRight		   ; This is gonna be first cause on average
	;;  with int based rounding, the value will be on the right
	jl targetLeft		; Gonna be second, cause just a little less likely

	;;  can proceed with success

searchSuccess:			; operation for an odd parameter

	mov rax, r8		; Returning the mid value (index of item)
	ret			; returning
	
targetRight:			; The target is in the right half of the array

	mov rsi, r8		; moving the mid into the low
	inc rsi			; incrementing the low by 1
	;;  low = mid + 1
	jmp binarySearch
	
targetLeft:			; The target is the in left half of the array

	mov rdx, r8		; moving the mid into high
	dec rdx			; decrementing by 1
	;;  high = mid - 1
	jmp binarySearch	; returning
	
searchFail: 			; Fail end case

	mov rax, -1		; We failed and are returning 
	ret		
	


	
