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
- [strlcpy](#strlcpy)
- [strlcat](#strlcat)
- [calloc](#calloc)
- [substr](#substr)

---

![[img.png]]

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
| **Big-endian**    | Most Significant Byte (MSB) is stored **at the lowest memory address**. Bytes are stored in their natural order.                    |
| **Little-endian** | Least Significant Byte (LSB) is stored **at the lowest memory address**. Bytes are stored in reverse order. (used by modern systems) |

**Important Note:** Endianness only affects the **byte order**, not the bit order within each byte. Bits within a single byte are always read the same way in both systems.

**Example:** The number `0x12345678` in memory:
- **Big-endian**: `0x12 0x34 0x56 0x78` (MSB first)
- **Little-endian**: `0x78 0x56 0x34 0x12` (LSB first)

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

## strlcpy

**Goal**: Copy up to `size - 1` characters from `src` into `dest`, always null-terminating (`\0`) if `size > 0`.

**Return value:** Always returns the **length of `src`** (the total number of characters in the source string, not the number copied).

- The case if `dest[]`'s size = 1: When `strlcpy(dest, src, size)` is called, it calculates the dest size, and it copies `size-1` to `dest` (0 characters), and leaves 1 element for the `\0`, then it fills the only element with `\0`, and will return the size of `src`.
- `return value` = `strlen(src);`
- `strlcpy(dest, src, size)` copies a string **only if `size > 0`**.

If **either** of these is true, it _returns immediately_ without copying anything:
- `dest == NULL` → undefined behavior (the function _should not_ be called with NULL). However, if you check manually and return before using `dest`, that avoids the crash.
- `size == 0` → the function doesn't copy anything, but it **still returns the length of `src`**.

### Case 1:
```c
char dest[3];
char src[] = "hello world\n";
strlcpy(dest, src, 5);  // size argument = 5
```
Here the `strlcpy` will not know magically what is the real size of dest. It knows this just from the argument entered by the function call. It will try to copy 5 elements and this causes a buffer overflow.

### Case 2:
```c
char dest[10];
char src[] = "abc"; // src_len = 3
strlcpy(dest, src, sizeof(dest)); // size = 10
```
`strlcpy` will **never copy more than the actual length of `src`**, even if the `size` argument allows more space.

---

## strlcat

The function **`strlcat`** is used to **concatenate (append)** one string to another, but **safely**, by preventing buffer overflows.

**Prototype:**
```c
size_t strlcat(char *dst, const char *src, size_t size);
```

- The loop of `strlcat` continues until one of these two conditions is met:
```c
while (src[i] && (dst_len + i) < (size - 1))
```

- It completely depends on the size given in the arguments — if the user sets a size larger than the destination buffer, an overflow will occur.

```c
char dest[5] = "abc";
ft_strlcat(dest, "defghijkl", 20);  // ❌ dangerous
```

- Remember to use:
```c 
dst[dst_len + i] = '\0'; // ❌ NOT dst[size-1] = '\0'
```
Because using `dst[size-1] = '\0'` will cause undefined behaviors if `src + dest < size`.

- You return the `src_len` + `dst_len` to compare it with the final `dest` to know if the append was corrupted.

- Optimize the code with the case if the `size <= dst_len`, it should return `size + src_len`:
```c
if (size <= dst_len)
    return size + src_len;
```
This avoids writing outside the buffer and the return value is used to tell the total size needed to append next time.

---

## calloc

Basically libft uses just the `malloc` and `memset` functions in its source code, but you should optimize calloc to avoid problems with memory like overflows:

- The function uses the type `size_t` that can hold on a `32-bit system`, `size_t` is typically 32 bits, and `SIZE_MAX` is `2^32 - 1` (approximately 4 billion). On `64-bit systems` it can be up to 1.8 x 10^19.
- Then in the case of `(nmemb * size)` > `SIZE_MAX`, this will cause a buffer overflow.
- Then, optimize your code:
```c
if (nmemb != 0 && size > SIZE_MAX / nmemb) // first thing in the code
    return NULL;
```

### calloc(0, 0):
The return of `malloc(0)` varies by system — it may return `NULL` or a unique pointer.  
To ensure consistent behavior on all systems, 42 requires handling it manually:  
If the total size is `0`, return `malloc(1)`.  
`free(NULL)` is safe, but 42 wants **consistency**, not just correctness.

**Always return a unique pointer (malloc(1)) for the zero case.**

---

## substr

**Prototype:**
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

### Why `unsigned int` and not `size_t` type for the start index?
`unsigned int` is used because the 42 project subject defines it that way. Part of the reason why we mostly use this type is to stay loyal to other languages that use this too like Java, Python, etc.

### Special Cases:

**1. Passing a null pointer → segfault:**
```c
if (!s)      // optimize your code with this test
    return (NULL);
```

**2. No protection when `start` is bigger than `strlen(s)`:**
```c
if (start >= s_len)
    return (ft_strdup(""));
```
In this case you should return an empty string, not `NULL`.  
Using `ft_strdup` will return a pointer to an empty string.

**3. If `len` > `s_len - start`:**
```c
if (len > s_len - start)
    len = s_len - start;
```
This case if not optimized will cause a buffer overflow. We limit the `len` inside the interval of `s_len - start` to not copy something after `\0`.

### Summary

| Problem               | Description            | Fix                                         |
| --------------------- | ---------------------- | ------------------------------------------- |
| if (len = 0)          | (want an empty str)    | auto allocate 1 for \0                      |
| start >= strlen(s)    | causes segfault        | return an empty string by strdup            |
| len > s_len-start     | causes buffer overflow | adjust the len to be in the valid range     |
| taking `NULL` string  | segfault               | if(!s) return NULL                          |

---
