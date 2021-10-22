
#include "psp_vfpu.h"

/*---------------------------------------------------------
	cos
- cosf(v) = 0.921061, cycles: 990
- vfpu_cosf(v) = 0.921061, cycles: 154
---------------------------------------------------------*/

float vfpu_cosf(float rad)
{
	float result;
	__asm__ volatile (
		"mtv     %1, S000\n"
		"vcst.s  S001, VFPU_2_PI\n"
		"vmul.s  S000, S000, S001\n"
		"vcos.s  S000, S000\n"
		"mfv     %0, S000\n"
		: "=r"(result) : "r"(rad));
	return (result);
}
