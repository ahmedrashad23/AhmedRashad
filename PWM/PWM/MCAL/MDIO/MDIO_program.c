/**
 * @file    MDIO_program.c
 * @author  Ahmed 
 * @brief   This file contains logical implementation related to DIO module
 * @date    2024-2-18
 */

/*****************************************************/
/*                   Includes                       */
/***************************************************/
#include "../../LIB/LBIT_MATH.h"
#include "../../LIB/LSTD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_private.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

/*************************************************************/
/*                   Important macros                       */
/***********************************************************/

#define NUMBER_OF_PORTS     (4)

/****************************************************************/
/*                   Important variables                       */
/**************************************************************/

/*DDRx array*/
static volatile u8_t* garr_DdrArray[NUMBER_OF_PORTS] = {MDIO_DDRA_ADDRESS, MDIO_DDRB_ADDRESS, MDIO_DDRC_ADDRESS, MDIO_DDRD_ADDRESS};
/*PORTx array*/
static volatile u8_t* garr_PortArray[NUMBER_OF_PORTS] = {MDIO_PORTA_ADDRESS, MDIO_PORTB_ADDRESS, MDIO_PORTC_ADDRESS, MDIO_PORTD_ADDRESS};
/*PINx array*/
static volatile u8_t* garr_PinArray[NUMBER_OF_PORTS] = {MDIO_PINA_ADDRESS, MDIO_PINB_ADDRESS, MDIO_PINC_ADDRESS, MDIO_PIND_ADDRESS};

/********************************************************************/
/*                   Functions` definitions                        */
/******************************************************************/

void mdio_SetPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status)
{
    switch (au8_status)
    {
    case (INPUT_FLOAT):
        
        *garr_DdrArray[au8_port] &= ~(au8_pin);

        break;

    case (INPUT_PULLUP):

        *garr_DdrArray[au8_port] &= ~(au8_pin);

        *garr_PortArray[au8_port] |= (au8_pin);

        break;

    case (OUTPUT):

        *garr_DdrArray[au8_port] |= (au8_pin);

        break;       
    
    default:
        break;
    }

    return;
}

void mdio_SetPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value)
{
    switch (au8_value)
    {
    case (LOW):
        
        *garr_PortArray[au8_port] &= ~(au8_pin);

        break;

    case (HIGH):

        *garr_PortArray[au8_port] |= (au8_pin);

        break;

    default:
        break;
    }

    return;
}

void mdio_TogglePinValue(u8_t au8_port, u8_t au8_pin)
{
    *garr_PortArray[au8_port] ^= (au8_pin);

    return;
}

void mdio_GetPinValue(u8_t au8_port, u8_t au8_pin, u8_t* pu8_pinValue)
{
    if ((*garr_PinArray[au8_port] & au8_pin) == LOW)
    {
        *pu8_pinValue = LOW;
    }

    else
    {
        *pu8_pinValue = HIGH;
    }
    
    return;
}
