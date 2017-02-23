#ifndef FIXED_TYPES_HPP
#define FIXED_TYPES_HPP

#include <cstddef>
#include <type_traits>
                                                /*      Author : Ugur Buyukdurak      */

//Naming Convention is Used Based on Microsoft Win32 API
#define BYTE 1
#define WORD 2
#define DWORD 4
#define QWORD 8

//Mark sign-ness
enum Sign {
        SIGNED,
        UNSIGNED
};

//Dummy Struct Declaration to enable template Specialization
template <size_t N, Sign S>
struct alias;

//Macros defining template Specializatons
#define REGISTER_SIGNED_ALIAS(X)                \
	template <>           		        \
	struct alias <sizeof(X), SIGNED> {	\
               using Type = X;                  \
	};                                      


#define REGISTER_UNSIGNED_ALIAS(X)              \
        template <>           		        \
        struct alias <sizeof(X), UNSIGNED> {    \
                using Type = X;                 \
        };

//Register Signed Aliases
REGISTER_SIGNED_ALIAS(signed char)
REGISTER_SIGNED_ALIAS(signed short int)
REGISTER_SIGNED_ALIAS(signed int)
REGISTER_SIGNED_ALIAS(signed long long int)

//Register Unsigned Aliases
REGISTER_UNSIGNED_ALIAS(unsigned char)
REGISTER_UNSIGNED_ALIAS(unsigned short int)
REGISTER_UNSIGNED_ALIAS(unsigned int)
REGISTER_UNSIGNED_ALIAS(unsigned long long int)

//Helper Macro to format static_assert output messages
#define STRINGIFY_HELPER(X) #X

//X is meant to be signed alias, Y is meant to be unsigned alias, Z is their intended size
//Used to make sure aliases have intended properties
#define VERIFY(X, Y, Z)                                                                                 \
        static_assert(sizeof(X) == Z, #X " is not " STRINGIFY_HELPER(Z) " byte(s), FAILED");            \
        static_assert(sizeof(Y) == Z, #Y " is not " STRINGIFY_HELPER(Z) " byte(s), FAILED");            \
        static_assert(std::is_signed<X>::value == true, #X " is not signed, FAILED");                   \
        static_assert(std::is_unsigned<Y>::value == true, #Y " is not unsigned, FAILED");

//Compiler deduced fixed-witdh types
using int8 = alias<BYTE, SIGNED>::Type;
using uint8 = alias<BYTE, UNSIGNED>::Type;

VERIFY(int8, uint8, BYTE)

using int16 = alias<WORD, SIGNED>::Type;
using uint16 = alias<WORD, UNSIGNED>::Type;

VERIFY(int16, uint16, WORD)

using int32 = alias<DWORD, SIGNED>::Type;
using uint32 = alias<DWORD, UNSIGNED>::Type;

VERIFY(int32, uint32, DWORD)

using int64 = alias<QWORD, SIGNED>::Type;
using uint64 = alias<QWORD, UNSIGNED>::Type;

VERIFY(int64, uint64, QWORD)

//Undefine Macro Byte to enable alias BYTE
#undef BYTE
using BYTE = uint8;

//Undefine Macro Word to enable alias WORD
#undef WORD
using WORD = uint32;

#endif
