; SUBJECT TO EDIT/CHANGE
  
section .text
global asm_daxpy
default rel

asm_daxpy:
    ; RCX = n         ; int n
    ; XMM1 = a        ; double a
    ; RDX = x[]       ; double* x
    ; R8  = y[]       ; double* y
    ; R9  = z[]       ; double* z

    push rbp
    mov rbp, rsp
    sub rsp, 32         

    xor r10, r10         ; i = 0

.loop:
    cmp r10, rcx         ; if (i >= n) break
    jge .done

    movsd xmm2, [rdx + r10*8]
    movsd xmm3, [r8 + r10*8]
    mulsd xmm2, xmm1
    addsd xmm2, xmm3

    movsd [r9 + r10*8], xmm2

    inc r10
    jmp .loop

.done:
    mov rsp, rbp
    pop rbp
    ret
