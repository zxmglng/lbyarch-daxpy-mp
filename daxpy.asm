section .text
global asm_daxpy
default rel

asm_daxpy:
    push rbp
    mov rbp, rsp
    sub rsp, 32              

    movsd xmm3, xmm0         

    xor r10, r10     

function:
    cmp r10, rcx
    jge finish

    movsd xmm1, [rdx + r10*8]
    movsd xmm2, [r8 + r10*8] 

    mulsd xmm1, xmm3      
    addsd xmm1, xmm2        

    movsd [r9 + r10*8], xmm1  

    inc r10
    jmp function

finish:
    add rsp, 32
    pop rbp
    ret
