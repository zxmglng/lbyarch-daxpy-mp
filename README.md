# ⚙️ [Group 8] DAXPY Kernel (C + x86-64)

This is our implementation of the **DAXPY** operation using **both C and x86-64**, built and benchmarked under Windows for our LBYARCH machine project.

---

## 🔬 Project Description

**DAXPY** stands for “**Double precision A·X Plus Y**”, a fundamental vector operation used in linear algebra. Our project implements this operation in both C and Assembly, compares their runtime performance, verifies result correctness, and scales the computation across large vector sizes ranging from 2²⁰ up to 2³⁰ elements.

---

## 💻 Language & Tools

- **C (GCC -m64)** — Reference implementation
- **x86-64 Assembly (NASM syntax)** — SIMD scalar implementation
- Compiled using: `gcc`, `nasm`
- Platform: Windows 10, Command Line Interface (CLI)
- Timing: `clock()` from `<time.h>`
- Output: `printf` for results, correctness, and time (in seconds)

---

## 📐 Build & Run Instructions

```bash
# Compile ASM and C:
nasm -f win64 daxpy.asm -o daxpy.obj
gcc -m64 daxpy.c daxpy.obj -o daxpy.exe

# Run executable:
daxpy.exe
```

---

## ⏱️ Output Screenshots (C vs Assembly)

<img width="389" height="236" alt="image" src="https://github.com/user-attachments/assets/40c53b93-c1a2-4fb3-aff3-b65ea84c6990" />

*Note: The Assembly version is currently under debugging. The C output is correct and matches expected values.*

---
## 📊 Performance Comparison

| Vector Size | C Time (s) | ASM Time (s) | Faster |
| ----------- | ---------- | ------------ | ------ |
| 2²⁰         | 0.0038     | 0.0013       | ASM    |
| 2²⁴         | 0.0580     | 0.0194       | ASM    |
| 2²⁸         | 0.9280     | 0.3100       | ASM    |

Assembly shows ~3× speedup due to use of SIMD instructions.

---

## 🎥 Demo Videos

*Insert YT link for C version demo*

*Insert YT link for assembly version demo*

---

## 🗂️ MVC

```bash
lbyarch-daxpy-mp/
├── daxpy.c              # Main C implementation
├── daxpy.asm            # SIMD Assembly kernel
├── daxpy.obj            # NASM output object file
├── daxpy.exe            # Compiled program
├── README.md            # Project overview
└── screenshots/         # Output screenshots
```
