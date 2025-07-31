# ⚙️ [Group 8] DAXPY (C + x86-64)

This is our implementation of the **DAXPY** operation using **both C and x86-64**, built and benchmarked under Windows for our LBYARCH machine project.

---

## 🔬 Project Description & Specifications 

**DAXPY** stands for “**Double precision A·X Plus Y**”. Our project implements this operation in both C and Assembly, compares their runtime performance, checks result correctness, and scales the computation across large vector sizes ranging from 2²⁰ up to 2²⁸ elements.

<img width="571" height="368" alt="image" src="https://github.com/user-attachments/assets/a0593413-b79a-45aa-a738-57072ec1a9c4" />


---

## 💻 Language & Tools

- **C** 
- **x86-64** 
- Compiled using: `gcc`, `nasm`
- Platform: Windows 10, CLI
- Timing: `clock()` from `<time.h>`
- Output: `printf` for results, correctness, and time (in seconds)

---

## 📐 Build & Run Instructions

```bash
# Compile ASM and C:
nasm -f win64 daxpy.asm -o asm_daxpy.obj
gcc -c daxpy.c -o c_daxpy.obj -m64
gcc c_daxpy.obj asm_daxpy.obj -o daxpy.exe -m64

# Run executable:
daxpy.exe
```

---

## ⏱️ Output Screenshots 

<img width="632" height="149" alt="image" src="https://github.com/user-attachments/assets/332146d0-7da6-43b4-88fb-bc4826e20ccc" />

<img width="632" height="278" alt="image" src="https://github.com/user-attachments/assets/ce0cd4e2-c0dc-4174-a4be-0138f5a49459" />

<img width="632" height="278" alt="image" src="https://github.com/user-attachments/assets/63b99f36-bd1d-4f61-aea4-1b70983f10be" />

<img width="632" height="278" alt="image" src="https://github.com/user-attachments/assets/eef31171-f0cb-4ef7-863a-5340f8e23b90" />

---
## 📊 Performance Comparison

| Vector Size | C Time (s) | ASM Time (s) | Faster |
| ----------- | ---------- | ------------ | ------ |
| 2²⁰         | 0.004200   | 0.001567     | ASM    |
| 2²⁴         | 0.068367   | 0.036400     | ASM    |
| 2²⁸         | 1.092833   | 0.426200     | ASM    |

As we can see on the table, the Average Time of the x86-64 kernel is faster than the C kernel in all three vector sizes. Here are the reasons why: Register-Level Optimization, Reduced Abstraction Overhead, Fewer Memory Accesses and Function Calls, Better Instruction Pipelining. For register-level optimization, the assembly code directly uses xmm registers and SIMD instructions like mulsd and addsd, which are optimized for double-precision floating-point operations. For the reduced abstraction overhead, assembly has minimal instruction dispatch which results in lower instruction latency, unlike in C where it goes through several compiler optimization layers and function call overheads. The third reason mentioned states that the loop in assembly avoids complicated indexing or memory safety checks performed implicitly by C, which therefore leads to faster execution especially with large data sets. And for the final reason, the consistent, simple loop with minimal branching enables better CPU pipelining and instruction prefetching.

---

## 🗂️ MVC

```bash
lbyarch-daxpy-mp/
├── daxpy.c              
├── daxpy.asm                      
└── README.md         
```
