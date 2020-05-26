#ifdef __MSC_VER__
#define RGM_FORCEINLINE __forceinline
#elif defined __GUNC__
#define RGM_FORCEINLINE __inline__ __attribute__((always_inline))
#else
#define RGM_FORCEINLINE
#endif


#define RGM_VECTOR2
#define RGM_VECTOR3

#include<cmath>
#include<iostream>

typedef float RG_FLOAT;