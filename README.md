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
    using int32 = alias<DWORD, SIGNED>::Type;
    
BYTE and DWORD are macros that correspond to value 1 and 4. Expressions,

    alias<BYTE,SIGNED>::Type
    alias<DWORD, SIGNED>::Type
    
return any signed numeric data type that has data size of 1 byte(8 bits) and 4 bytes(32 bits) respectively. Since data sizes and types are deduced by the compiler, there is no need for hardcoded typedefs.

###Difference Between Secure and Normal Version

####-Normal version has no dependecy other than C++11 specs 
Normal version of fixed_types has no assertions to check whether fixed-width aliases match their intended sizes and signed-ness. In addition, it does not include size_t type from any of the libraries nor does it include any system header files, rather uses decltype keyword to decide type of any size returned by sizeof operator. The header file is standalone and requires no other modules to be included.

####-Secure version has dependecy on two system header files
Secure version uses static_assertion keyword to make sure compiler deduced aliases are in their intended sizes. If aliases fail to meet with their assertion criterias, compilation will fail. Moreover, signed-ness of alises are also checked through utilies provided via type_traits library. size_t is included from cstddef instead of relying on data type provided by decltype operator. Of course, such changes resulted in dependency on two different header files. 
