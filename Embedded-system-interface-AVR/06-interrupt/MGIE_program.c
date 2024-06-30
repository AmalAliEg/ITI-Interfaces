/*
 * INT_program.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MGIE_private.h"
#include "MGIE_config.h"
#include "MGIE_interface.h"


void MGIE_Init(void)
{
	switch (GIE_MODE)
	{
	case enable:
		SET_BIT(SREG, 7);
		break;
	case disable:
		CLR_BIT(SREG, 7);
		break;
	}
}
