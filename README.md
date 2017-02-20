# Compiler-Deduced-Fixed-Width-Types

Fixed-width types are important because C/C++ specification does not enforce numeric types to have a precise size. Although there are limitations on integral types as to what size they should have at minimum, result sizes are mostly implementation defined. To close the gap, C99 and C++11 have come up with typedefs which are guaranteed to be fixed in their sizes. Typedefs providing fixed-width data types are included within stdint.h(C99) and cstdint(C++11).

One problem with typedef approach is having to hardcode typedefs based on the architecture. For example in one architecture int can be 16 bits and long long can be 32 bits whereas in another architecture int type can be 32bits and long long can be 64bits.

How to accomplish fixed-width types then? The header file containing typedefs that comes with compiler has them hardcoded. An example follows,

    /* A computer where int type is 32bits and long long is 64bits */
    typedef int int32_t;
    typedef long long int64_t;
    
    /* A computer where int type is 16bits and long long is 32bits */
    typedef long long int32_t;
    typedef (whatever type is 64 bits) int64_t;
   
My implementation of fixed-width types aims to get rid of hardcoded typedefs by using compiler's ability to deduce types through template specialization and sizeof operator. Sizeof operator is used to determine size of numeric types, template specialization is used to mimic if-else statements at compile-time. Below is an example,

    /* 8 bit Fixed-Width types */
    using int8 = alias<BYTE, SIGNED>::Type;
    using uint8 = alias<BYTE, UNSIGNED>::Type;
    
BYTE is a macro that corresponds to value 1. Expression,

    alias<BYTE,SIGNED>::Type
    
returns any signed numeric data type that has data size of 1 byte(8 bits). Since data sizes and types are deduced by the compiler, there is no need for hardcoded typedefs.
