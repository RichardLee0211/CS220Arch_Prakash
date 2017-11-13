.intel_syntax noprefix

.text

.global reverse_asm

reverse_asm:
	push ebx

	# headptr = nextptr = new_headptr = NULL
	# we use eax as the scratch register
	mov eax, 0x0
	mov ebx, eax # ebx headptr
	mov ecx, eax # ecx nextptr
	mov edx, eax # edx new_headptr

	# it's if(head == NULL) return NULL
	# esp points to top of stack
	# mov eax, [esp + Offset_of_head_from_current_esp]
	mov eax, [esp + 0x8]
	cmp eax, 0x0
	je null_ret

	# headptr = &(head->ptr)
	# add eax, [esp+Offset_of_offset_from_current_esp]
	add eax, [esp+ 0xc]
	# ebx is headptr
	mov ebx, eax

while_start:
	# while(headptr)
	cmp ebx, 0x0
	je while_done

	# nextptr = (void *)(*((unsigned long *)headptr));
	mov ecx, [ebx]

	# *(unsigned long *)headptr = (unsigned long) new_headptr;
	mov [ebx], edx 

	# new_headptr = headptr;
	mov edx, ebx

	# headptr = nextptr;
	mov ebx, ecx

	# next iteration
	jmp while_start

while_done:

	mov eax, edx
	# sub eax, [esp + Offset_of_offset_from_current_esp]
	sub eax, [esp + 0xc]

null_ret:
	pop ebx
	ret
