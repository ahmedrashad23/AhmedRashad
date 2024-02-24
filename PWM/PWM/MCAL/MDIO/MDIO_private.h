/**
 * @file    MDIO_private.h
 * @author  Ahmed
 * @brief   This file contains private information related to DIO module
 * @date    2024-2-18
 */

/* Header file ground */
#ifndef __MDIO_private_H__
#define __MDIO_private_H__

/**************************************************************/
/*                      DIO regestres                         */
/**************************************************************/

/* PORTA registres */
#define MDIO_PORTA_ADDRESS                   ((volatile u8_t*)(0x3B))
#define MDIO_DDRA_ADDRESS                    ((volatile u8_t*)(0x3A))
#define MDIO_PINA_ADDRESS                    ((volatile u8_t*)(0x39))

/* PORTB registres */
#define MDIO_PORTB_ADDRESS                   ((volatile u8_t*)(0x38))
#define MDIO_DDRB_ADDRESS                    ((volatile u8_t*)(0x37))
#define MDIO_PINB_ADDRESS                    ((volatile u8_t*)(0x36))

/* PORTC registres */
#define MDIO_PORTC_ADDRESS                   ((volatile u8_t*)(0x35))
#define MDIO_DDRC_ADDRESS                    ((volatile u8_t*)(0x34))
#define MDIO_PINC_ADDRESS                    ((volatile u8_t*)(0x33))

/* PORTD registres */
#define MDIO_PORTD_ADDRESS                   ((volatile u8_t*)(0x32))
#define MDIO_DDRD_ADDRESS                    ((volatile u8_t*)(0x31))
#define MDIO_PIND_ADDRESS                    ((volatile u8_t*)(0x30))

#endif