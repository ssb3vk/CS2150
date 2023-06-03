; Sidhardh Burre, ssb3vk@virginia.edu, 4/8/2021, mergeSort.s
;University of Virginia
; CS 2150 In-Lab 8
; Spring 2018
; mergeSort.s	

	global mergeSort
	global merge

	section .text


; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array 
; Parameter 3 is the right index in the array
; Return type is void 
mergeSort:

	; Implement mergeSort here
	
	
	cmp rsi, rdx		; checking if left = right, if so we are done 
	je mergeSortBase	; this is the jump from the cmp in line 21
	

	mov rcx, rdx		; moving the third parameter into the fourth parameter for merge
	xor rdx, rdx		; zeroing out rdx for future use in div (don't need anymore)
	xor rax, rax		; zeroing out rax before using 
	add rax, rsi		; adding rsi (second param) left index
	add rax, rcx		; adding rcx (fourth param for merge, third for mSort) right index
	
	mov r8, 2		; moving 2 into r8 for division by 2 (future use)
	idiv r8		; dividing by 2
	
	mov rdx, rax		; moving the value (rax) for mid index into third parameter for merge
				; at this point we have rdi, rsi, rdx, rcx as pointer, left, middle, right respectively
	
	push rdi		; have to do these egregious number of push/pops cause 
	push rsi
	push rdx
	push rcx
	
	call mergeSort		; mergeSort(pointer, left, middle)
	
	pop rcx
	pop rdx
	pop rsi
	pop rdi 
	
	push rdi
	push rsi
	push rdx
	push rcx
	
	push rsi		; need to store this one as it gets "lost"
	
	inc rdx		; maybe we dont need to increment rdx
	mov rsi, rdx	
	mov rdx, rcx
	
	call mergeSort		; mergeSort(pointer, middle, right)
	
	mov rcx, rdx
	dec rsi
	mov rdx, rsi
	pop rsi		; at this point we have rdi, rsi, rdx, rcx as pointer, left, middle, right respectively
	
	pop rcx
	pop rdx
	pop rsi
	pop rdi 
	
	push r11		; now we can call merge
	push r10		; need to store these values cause merge uses them
	
	call merge
	
	pop r10
	pop r11

mergeSortBase: 
	
	ret			; just return
	


; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void 
merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret
