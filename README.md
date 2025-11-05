# C Programming Notes

## Table of Contents
- [Casting](#casting)
- [Reading Memory](#reading-memory)
- [Why While Loop](#why-while-loop)
- [Why Unsigned Char](#why-unsigned-char)
- [Const Char Pointers](#const-char--and-char-const-)
- [Memory Leak](#memory-leak)
- [Make File Default Mode](#make-file-default-mode)
- [Make Commands](#make-commands)
- [File Descriptor](#file-descriptor)
- [Static and Dynamic Library](#static-and-dynamic-library)
- [Libraries Include](#libraries-include)
- [Library Define Guard](#library-define-guard)

---

## Casting

**Casting** in C is explicitly converting a value from one data type to another.

- **Implicit cast** → done _automatically_ by the compiler 
  (e.g., `int x = 5; float y = x;`)
- **Explicit cast** → done _manually_ by the programmer using parentheses (e.g., `float y = (float)x;`)

**Note**: casting is not changing the memory binary stored values.

---

## Reading Memory

How exactly the compiler reads memory blocks:
Based on your systems, let's carefully know what is "big and little endianness".

These terms describe how a computer stores multi-byte values in memory:

| Term              | Meaning                                                                                                                                 |
| ----------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| **Big-endian**    | Most Significant Byte (MSB) is stored **at the lowest memory address**. The number is read left to right in memory.                    |
| **Little-endian** | Least Significant Byte (LSB) is stored **at the lowest memory address**. The number is read right to left in memory. (used by modern systems) |

**How char is read:**
- Index 0 is **always the first character**.  
- **Casting does not change the binary values in memory**
- The 2's complement is for both operations: read and store if the type is signed.

---

## Why While Loop

Because they make sure you learn the initializing and incrementing manually and make you master the condition too.

---

## Why Unsigned Char

Because when we treat memory bytes we know that a byte has 8 bits with the range 0 → 255 and to work properly with it you shouldn't use signed that has range from -128 → 127.

---

## Const Char * and Char Const *

These types are the same thing where they mean that you can't change what the pointer points to but you can change the pointer itself (make it point somewhere else).

```c
const char *p = "hello";  // same as: char const *p = "hello";
p = "world";   // ✅ allowed (p now points to another string)
*p = 'H';      // ❌ error: you can't modify the content
```

But `char * const p` is a little different. It means that the const is applied to the pointer itself and you can't change it.

---

## Memory Leak

That means the allocated space still exists in RAM, but the program can no longer access or reuse it — it's **lost** until the process ends.

It's simply when you use malloc, calloc, or realloc without freeing them.

```c 
char **str = malloc(words * sizeof(char*));
... 
...
char *ptr = malloc(len * sizeof(char));
...
...
malloc ...
```

---

## Make File Default Mode

If you don't pass any arguments, **`make`** will:
- Run the _first rule_ it finds in the Makefile.

### What if you don't specify the **compiler** or **rules**?

Even if you don't write any rules at all, `make` still has **built-in default rules** (called _implicit rules_).  
These rules define how to build `.o` files from `.c` files, and even how to link executables.

For example, `make` knows by default:

| Variable  | Default value | Meaning                              |
| --------- | ------------- | ------------------------------------ |
| `CC`      | `cc`          | The default C compiler               |
| `CFLAGS`  | _(empty)_     | Compiler flags                       |
| `LDFLAGS` | _(empty)_     | Linker flags                         |
| `RM`      | `rm -f`       | Used for removing files              |
| `AR`      | `ar`          | For creating static libraries (`.a`) |

**Minimum for the makefile to work:**

1. `make` automatically looks for files named:
   - `Makefile`
   - `makefile`
   - `GNUmakefile`

2. It needs a target even without making a Makefile:
```bash
host23@user$ ls 
    main.c 
host23@user$ make main
    cc     main.c   -o main
```

---

## Make Commands

### That technique in a **Makefile** — `$(SRC:.c=.o)`

This is called a **substitution reference** (or **pattern substitution**).

It tells the makefile to take each .c file and remove the suffix .c and set the .o, this forms matched object files.

---

## File Descriptor

### Definition

A file descriptor is a non-negative number used by the operating system kernel to identify an open file or other input or output streams.

Take the librarian as an example: when you want to access a book, you should ask the librarian to give you a ticket to give you the right to access the book whenever you want.

- When you want to read from the book, you ask the librarian to read 100 letters from the book and put it in your notebook — that is the buffer:
  ```c 
  read(3, buffer, 100);
  ```
- When you want to write: 
  ```c
  write(3, "hello", 5);
  ```
- And when you finish, you close the book and the librarian takes your ticket:
  ```c
  close(3);
  ```

---

## Static and Dynamic Library

| Stage               | Input                 | Output                | Command Example            |
| ------------------- | --------------------- | --------------------- | -------------------------- |
| **1. Preprocessing** | `main.c`              | `main.i`              | `gcc -E main.c -o main.i`  |
| **2. Compilation**   | `main.i`              | `main.s`              | `gcc -S main.c -o main.s`  |
| **3. Assembly**      | `main.s`              | `main.o`              | `gcc -c main.c -o main.o`  |
| **4. Linking**       | `.o` files + libraries | `a.out` (or your exe) | `gcc main.o -o main`       |

### The Difference

| Feature                     | 🧱 **Static Library (.a)**                                                      | ⚡ **Dynamic Library (.so / .dll)**                                                                           |
| --------------------------- | ------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| **Used at**                 | **Link time**                                                                   | **Run time (execution)**                                                                                     |
| **What happens at linking** | The linker **copies the function's machine code** directly into your executable | The linker **adds a reference** (symbol) telling the OS: "Load this function from an external library later" |
| **Executable size**         | ✅ **Bigger**, because it **includes** all used functions' code                  | ⚙️ **Smaller**, because it **only references** functions                                                     |
| **Dependency after build**  | 🧍 **Self-contained** — doesn't need the library to exist anymore               | 🔗 **Depends on the library** at runtime; if it's missing, you get an error (`libXYZ.so not found`)          |
| **Performance**             | Slightly faster at runtime (no need to load anything externally)                | Slightly slower at startup (library must be loaded dynamically)                                              |
| **Updating code**           | Must recompile/relink app if library changes                                    | Can update `.so` / `.dll` file without recompiling the app                                                   |
| **Example names**           | `libft.a`, `libm.a`                                                             | `libm.so`, `libc.so.6`                                                                                       |

---

## Libraries Include

### `#include <file.h>`
These are system or standard library headers. Tells compiler to search only in system include directories (like `/usr/include/` or `/usr/local/include/`).

### `#include "file.h"` 
User-defined (local) headers. The compiler searches **first in the current directory**, then in system include directories.

---

## Library Define Guard

### What #ifndef, #define, and #endif

They are **preprocessor directives** that protect your program from including the **same header file multiple times** — a problem called a **"multiple inclusion" error**.

If you accidentally included the same header twice (directly or indirectly through other headers):

```c
#include "libft.h"
#include "libft.h"

int main(void)
{
    ft_putstr("Hello\n");
    return 0;
}
```

In the preprocessing stage, when the preprocessor expands `#include`, you'll get **duplicate declarations**:

```c
void ft_putstr(char *s);
void ft_putstr(char *s); // duplicate!
```

The preprocessor can consider it as an error:

```c
error: redefinition of 'ft_putstr'
```

---
