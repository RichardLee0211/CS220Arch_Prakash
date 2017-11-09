## stack layout

### 32bits version
===TOP of stack===
local varibles
callee-save register
saved Frame pointer //  bar() frame base, address of saved Frame pointer of bar()
===devide line, above is foo()=======
caller's return address
arguments to pass to callee
caller-save registers, // e.g. $eax, $ecx, $edx, so foo() is free to use them
local varibles
callee-save register, // e.g. $esp, $edp, $ebx, $edi, so bar() is free is use them plus others
saved Frame pointer // this Frame pointer pointing to previous Frame base
===botton of stack, above is bar()====
