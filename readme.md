# basics
## the size_t explaine
- unsigned integer type used to represent sizes of objects in memory.
- It’s guaranteed to be big enough to store the size of the largest possible object your system can handle.
-  in sumary it used to specify the size of an objects because it can safly hold ony object size and cannot be negative.

## explain the memset use
- it a function that assig a value to  a block of memory byte per byte and not type
- used to inicialize memory bytes with 0 and som other uses 

## take int 1 and char 'A' like an example
- if you entred a 1 like a parametre in the memset funtion to fill an array with it will fill each byte with 00000001 = 0x00(hex) then you will get the 16843009 in each int size
- the resault of the test will be 
       16843009, 16843009, 16843009, 16843009, 
        AAAA 
    ```c
    #include <stdio.h>
    #include <string.h>

        int main(void)
        {
            int arr[4];  // array of 4 integers

            // Fill the array with byte value 1
            memset(arr, 1, sizeof(arr));

            // Print the integers
            for (int i = 0; i < 4; i++)
                printf("%d, ", arr[i]);
            printf("\n");

            // Print the integers in hexadecimal
            for (int i = 0; i < 4; i++)
                printf("%X, ", arr[i]);
            printf("\n");
            return 0;
        }
    
## why we use the `void *` type when we treat memory functions ?
- the `void *` type means a memory block of unknow type and it called a generic pointer.
- functions like `memcpy`, `memset`, `memmove`, `memcmp`... are designed to work with any type of data.
- and for the `void *` of function name it used because every in every function you need to return the original pointer of any type.

## what means an **`overlap`**: 
- Overlap occurs when any memory addresses used by `src` and `dest` are shared, i.e., the ranges intersect,simply "when `src` share memory blocks range with the `dest`"
### safe overlap :
- Safe overlap happens when the memory areas share addresses, but the copy order doesn’t cause corruption in memcpy.

    If src and dest overlap, memcpy can behave unpredictably. Some bytes may get overwritten before they are copied.

    You said: “if the size to copy is smaller than dest - src, nothing happens”.

    True in practice: if n <= dest - src, then the copied bytes won’t overwrite the source bytes during the copy, so it might work as expected.

    But: memcpy does not guarantee safety with overlap—it’s still officially undefined behavior. You should use memmove instead if overlap is possible.

    ✅ Simple analogy: Think of moving blocks on a table. If the source blocks are far enough from the destination, moving them works fine. If they are close or overlap, some blocks might get knocked over (overwritten) while moving.

### unsafe overlap :
- Unsafe overlap happens when memcpy is used and dest overlaps src in a way that forward copying overwrites source bytes before they are copied.
- Example: dest starts inside src and you copy forward:
    ```c
        char str[10] = "123456789";
        memcpy(str + 2, str, 5);  // dest = [2,6], src = [0,4]
keys in simple way :

| Type of overlap      | Safe with |    Unsafe with    | Notes           |
|----------------------|-----------|:-----------------:|-----------------|
| Forward safe overlap | `memmove` | `memcpy` may fail | dest before src |
| Backward overlap     | `memmove` | `memcpy` may fail | dest after src  |
| No overlap           | both      | both              | no problem      |

The simplest way to understand unsafe overlap: it occurs when the destination is within the source range and you're copying forward.



#### strlcpy: 
**Goal**: Copy up to `size - 1` characters from `src` into `dest`, always null-terminating (`\0`) if `size > 0`.
**Return value:** Always returns the **length of `src`** (the total number of characters in the source string, not the number copied).
- the case if `dest[]`'s size = 1, When `strlcpy(dest, src, size)` is called, it calculate the dest size, and it copy `size-1` to `dest` ~ 0, and let 1 element for the `\0` then it fill the only element wity `\0`, and will retun the size of `src`.
- `return value` = `strlen(src);`
- `strlcpy(dest, src, size)` copies a string **only if `size > 0`**.
If **either** of these is true, it _returns immediately_ without copying anything:
- - `dest == NULL` → undefined behavior (the function _should not_ be called with NULL).  
However, if you check manually and return before using `dest`, that avoids the crash.    
- `size == 0` → the function doesn’t copy anything, but it **still returns the length of `src`**.
- hello 

##### case 1:
```c
	char dest[3];
	char src[] = "hello world\n";
	strlcpy(dest, src, 5);  // size argument = 5
```
*here the `strlcpy` will not know magicaly what is the real size of dest it know this just from the arrgument entred by the function call, it will try to copy 5 element and this occure a buffer overflow.

##### case 2:
```c
	char dest[10];
	char src[] = "abc"; // src_len = 3
	strlcpy(dest, src, sizeof(dest)); // size = 10
```
`strlcpy` will **never copy more than the actual length of `src`**, even if the `size` argument allows more space.

