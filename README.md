# ⚙️ [Group 8] DAXPY Kernel (C + x86-64)

This is our implementation of the **DAXPY** operation using **both C and x86-64**, built and benchmarked under Windows for our LBYARCH machine project.

---

## 🔬 Project Description

**DAXPY** stands for “**Double precision A·X Plus Y**”. Our project implements this operation in both C and Assembly, compares their runtime performance, checks result correctness, and scales the computation across large vector sizes ranging from 2²⁰ up to 2²⁸ elements.

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
nasm -f win64 daxpy.asm -o daxpy.obj
gcc -m64 daxpy.c daxpy.obj -o daxpy.exe

# Run executable:
daxpy.exe
```

---

## ⏱️ Output Screenshots (C vs Assembly)

<img width="600" height="950" alt="image" src="https://github.com/user-attachments/assets/3b90fa82-8d07-4d8d-bd62-4df4996ec2bc" />


---
## 📊 Performance Comparison

| Vector Size | C Time (s) | ASM Time (s) | Faster |
| ----------- | ---------- | ------------ | ------ |
| 2²⁰         | 0.004167   | 0.001733     | ASM    |
| 2²⁴         | 0.067967   | 0.034233     | ASM    |
| 2²⁸         | 1.091200   | 0.453767     | ASM    |

*INSERT SHORT ANALYSIS (arnd 4-5 sentences?)*

---

## 🎥 Demo Video

*Insert YT link for short demo*

---

## 🗂️ MVC

```bash
lbyarch-daxpy-mp/
├── daxpy.c              
├── daxpy.asm           
├── README.md            
└── screenshots/         
```
