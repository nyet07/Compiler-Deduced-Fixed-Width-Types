#ifndef FIXED_TYPES_HPP
#define FIXED_TYPES_HPP

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

//Programmer defined fixed-witdh types
using int8 = alias<BYTE, SIGNED>::Type;
using uint8 = alias<BYTE, UNSIGNED>::Type;

using int16 = alias<WORD, SIGNED>::Type;
using uint16 = alias<WORD, UNSIGNED>::Type;

using int32 = alias<DWORD, SIGNED>::Type;
using uint32 = alias<DWORD, UNSIGNED>::Type;

using int64 = alias<QWORD, SIGNED>::Type;
using uint64 = alias<QWORD, UNSIGNED>::Type;

#endif
