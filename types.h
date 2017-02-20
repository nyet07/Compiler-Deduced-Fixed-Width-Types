#ifndef TYPES_H
#define TYPES_H

//Defined Types
#define TYPES	bool,			        \
		char,			        \
		signed char,		        \
		unsigned char,		        \
		wchar_t,		        \
		char16_t,		        \
		char32_t,		        \
		short int,		        \
		unsigned short int,	        \
		int,			        \
		unsigned int,		        \
		long int,		        \
		unsigned long int,	        \
		long long int,		        \
		unsigned long long int,	        \
		float,			        \
		double,			        \
		long double


//Dummy Struct Declaration to enable Template Specialization
template <typename T>
struct TypeTraits;

//Template Specialization via macro
//Template Specialization is used to distinguish different types
#define REGISTER_TYPE(X) 		        \
	template <> 			        \
	struct TypeTraits <X> {		        \
		static const char * name;       \
	};					\
	const char * TypeTraits<X>::name = #X;

//To get rid of std:: prefix during console output
#define INTRODUCE_NULLPTR_T()	\
	using std::nullptr_t;

//These macros are short-hand for declaring specialized templates of the dummy template declared above
REGISTER_TYPE(bool)
REGISTER_TYPE(char)
REGISTER_TYPE(signed char)
REGISTER_TYPE(unsigned char)
REGISTER_TYPE(wchar_t)
REGISTER_TYPE(char16_t)
REGISTER_TYPE(char32_t)
REGISTER_TYPE(short int)
REGISTER_TYPE(unsigned short int)
REGISTER_TYPE(int)
REGISTER_TYPE(unsigned int)
REGISTER_TYPE(long int)
REGISTER_TYPE(unsigned long int)
REGISTER_TYPE(long long int)
REGISTER_TYPE(unsigned long long int)
REGISTER_TYPE(float)
REGISTER_TYPE(double)
REGISTER_TYPE(long double)

INTRODUCE_NULLPTR_T()
REGISTER_TYPE(nullptr_t)

#endif