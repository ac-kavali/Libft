#the sizeof explaine
    - unsigned integer type used to represent sizes of objects in memory.
    - It’s guaranteed to be big enough to store the size of the largest possible object your system can handle.
    - in sumary it used to specify the size of an objects because it can safly hold ony object size and cannot be negative.

#explain the memset use 
    - it a function that assig a value to  a block of memory byte per byte and not type
    - used to inicialize memory bytes with 0 and som other uses 

#take int 1 and char 'A' like an example
    - if you entred a 1 like a parametre in the memset funtion to fill an array with it will
    - fill each byte with 00000001 = 0x00(hex) then you will get the 16843009 in each int size
    - the resault of the test will be 
        16843009, 16843009, 16843009, 16843009, 
        AAAA 


#why we use the `void *` type when we treath memory functions ?
    - the `void *` type means a memory block of unknow type and it called a generic pointer.
    - functions like `memcpy`, `memset`, `memmove`, `memcmp`... are designed to work with any type of data.
    - and for the `void *` of function name it used because every in every function you need to return the original pointer of any type.
