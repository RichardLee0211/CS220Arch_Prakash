# this is note file
9c3313693bcbdb70ba295b0e660872fe  ./bomb2.0
tools: tmux, gdb, vim, objdump
highly unlike that string is hard coded in the C code,
so it can't be in the text area, or in the stack
but before comparing, string must be store some where in the heap

# answer
the phase the userName of linux system

mov     bx, 0C3EEh  ; Sign bit of bl is now 1: BH == 1100 0011, BL == 1110 1110
movsx   ebx, bx     ; Load signed 16-bit value into 32-bit register and sign-extend
                    ; EBX is now equal FFFFC3EEh
movzx   dx, bl      ; Load unsigned 8-bit value into 16-bit register and zero-extend
                    ; DX is now equal 00EEh
