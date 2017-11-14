## stack layout

### 32bits version
===TOP of stack===
local varibles
callee-save register
saved Frame pointer //  bar() frame base, address of saved Frame pointer of bar()
caller's return address, // where foo() returns to
===devide line, above is foo()=======
arguments to pass to callee
caller-save registers, // e.g. $eax, $ecx, $edx, so foo() is free to use them
local varibles
callee-save register, // e.g. $esp, $edp, $ebx, $edi, so bar() is free is use them plus others
saved Frame pointer // this Frame pointer pointing to previous Frame base
caller's return address, // where bar() returns to
===botton of stack, above is bar()====


saved Frame pointer // curr_ebp[0]
return address // curr_ebp[1] => &system
====above is ret2libc=====
arguments int 32bits => return address of ret2libc
... => argument of system

// ?? strange that system doesn't push it's return address

saved Frame pointer // curr_ebp[0]
return address // curr_ebp[1] => &system
====above is ret2libc_generic=====
arguments char* 32bits => return address of ret2libc
... => argument of system
