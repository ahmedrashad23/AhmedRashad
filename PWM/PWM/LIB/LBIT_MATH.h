/**
 * @file    LBIT_MATH.h
 * @author  Ahmed
 * @brief   This file contains the bits mathematics macros
 * @date    2024-2-18
 */


/* Header file ground */
#ifndef __LBIT_MATH_H__
#define __LBIT_MATH_H__

/* Bit manipulation operations */
#define SET_BIT(REG, BIT)       (REG |= (1 <<  BIT))
#define CLEAR_BIT(REG, BIT)     (REG &= ~(1 <<  BIT))
#define TOGGLE_BIT(REG, BIT)    (REG ^= (1 <<  BIT))
#define GET_BIT(REG, BIT)       ((REG >>  BIT) & 0x1)

#endif