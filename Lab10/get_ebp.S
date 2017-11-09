.intel_syntax noprefix

.text

.global get_ebp

# 32bits version

get_ebp:
    push ebp
    mov eax, esp
    ret
