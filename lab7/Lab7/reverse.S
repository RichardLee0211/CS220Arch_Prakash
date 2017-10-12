.intel-syntax noprefix
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
mov eax, [esp + 8]
cmp eax, 0
je null_ret

# headptr = &(head->ptr)
add eax, [esp+Offset_of_offset_from_current_esp]
# ebx is headptr
mov ebx, eax

while_start:
# while(headptr)
cmp haedptr, 0x0
je while_done

# nextptr = (void *)(*((unsigned long *)headptr));
nov nextptr, [headptr]

# *(unsigned long *)headptr = (unsigned long) new_headptr;
mov [headptr], new_headptr

# new_headptr = headptr;
mov new_headptr, headptr

# headptr = nextptr;
mov headptr, nextptr

# next iteration
jmp while_start

while_done:

mov eax, new_headptr
sub eax, [esp + Offset_of_offset_from_current_esp]

null_ret:
pop ebx
ret
