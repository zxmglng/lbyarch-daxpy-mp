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

<img width="525" height="85" alt="image" src="https://github.com/user-attachments/assets/5028dd0b-6c9a-4449-a163-4d68576baffe" />

<img width="525" height="212" alt="image" src="https://github.com/user-attachments/assets/8fd2cf7b-26ab-4b4c-ad0e-124ec065ea2a" />

<img width="525" height="212" alt="image" src="https://github.com/user-attachments/assets/e2942778-e70b-44da-af50-67b7b9d9104e" />

<img width="525" height="212" alt="image" src="https://github.com/user-attachments/assets/f7fbdfa5-05d6-4953-a073-954077c7915f" />





---
## 📊 Performance Comparison

| Vector Size | C Time (s) | ASM Time (s) | Faster |
| ----------- | ---------- | ------------ | ------ |
| 2²⁰         | 0.004367   | 0.001800     | ASM    |
| 2²⁴         | 0.067667   | 0.037000     | ASM    |
| 2²⁸         | 1.083667   | 0.472333     | ASM    |

*INSERT SHORT ANALYSIS (arnd 4-5 sentences)*

After running the project, here are the reasons why the x86-64 kernel is faster than the C kernel: Register-Level Optimization, Reduced Abstraction Overhead, Fewer Memory Accesses and Function Calls, Better Instruction Pipelining. For register-level optimization, the assembly code directly uses xmm registers and SIMD instructions like mulsd and addsd, which are optimized for double-precision floating-point operations. For the reduced abstraction overhead, assembly has minimal instruction dispatch which results in lower instruction latency, unlike in C where it goes through several compiler optimization layers and function call overheads. The third reason mentioned states that the loop in assembly avoids complicated indexing or memory safety checks performed implicitly by C, which therefore leads to faster execution especially with large data sets. And for the final reason, the consistent, simple loop with minimal branching enables better CPU pipelining and instruction prefetching.

## 🎥 Demo Video

*Insert YT link for short demo*

---

## 🗂️ MVC

```bash
lbyarch-daxpy-mp/
├── daxpy.c              
├── daxpy.asm                      
└── README.md         
```
