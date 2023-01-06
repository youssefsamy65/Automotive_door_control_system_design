#include "gpio_private.h"
/**
 * 
 * @brief to enable clock on the port   
 * @param port_t 
 * @return no return state 
 *          
 *          
 */
void DIO_port(port_t Port){
switch(Port){
	case DIO_PORTA:
SET_BIT(RCGCGPIO,0);
	break;
 case DIO_PORTB:
SET_BIT(RCGCGPIO,1);
	break;
case DIO_PORTC:
SET_BIT(RCGCGPIO,2);
	break;
case DIO_PORTD:
SET_BIT(RCGCGPIO,3);
break;
}
}
/**
 * @brief Initialize the direction  of a specific pin also  Initialize that it is a digital input and 8 mA and use pull up register  
 * @param port_t & pint_t and direction_t
 * @return have no return state 
 *          
 *          
 */
void DIO_SetPinDirection(port_t Port, pin_t Pin, direction_t Direction)
{
	switch(Direction)
	{
		case DIO_INPUT:
		switch (Port)
		{
			case DIO_PORTA:
			CLR_BIT(GPIODIRA, Pin);
			SET_BIT(GPIODENA,Pin);
		  SET_BIT(GPIODR8RA, Pin);
			SET_BIT(GPIOPURA, Pin);
			CLR_BIT(GPIOAFSELA,Pin);
			break;
			case DIO_PORTB:
			CLR_BIT(GPIODIRb , Pin);
			SET_BIT(GPIODENB,Pin);
			SET_BIT(GPIODR8RB, Pin);
			SET_BIT(GPIOPURB, Pin);
			CLR_BIT(GPIOAFSELB,Pin);
			break;
			case DIO_PORTC:
			CLR_BIT(GPIODIRc, Pin);
			SET_BIT(GPIODENC,Pin);
			SET_BIT(GPIODR8RC, Pin);
			SET_BIT(GPIOPURC, Pin);
			CLR_BIT(GPIOAFSELC,Pin);
			break;
			case DIO_PORTD:
			CLR_BIT(GPIODIRD, Pin);
			SET_BIT(GPIODEND,Pin);
			SET_BIT(GPIODR8RD, Pin);
			SET_BIT(GPIOPURD, Pin);
			CLR_BIT(GPIOAFSELD,Pin);
			break;

		}
break ;
		case DIO_OUTPUT:
		switch (Port)
		{
			case DIO_PORTA:
			SET_BIT(GPIODIRA, Pin);
			SET_BIT(GPIODENA,Pin);
			SET_BIT(GPIODR8RA, Pin);
			SET_BIT(GPIOPURA, Pin);
			CLR_BIT(GPIOAFSELA,Pin);
			break;
			case DIO_PORTB:
			SET_BIT(GPIODIRb , Pin);
			SET_BIT(GPIODENB,Pin);
			SET_BIT(GPIODR8RB, Pin);
			SET_BIT(GPIOPURB, Pin);
			CLR_BIT(GPIOAFSELB,Pin);
			break;
			case DIO_PORTC:
			SET_BIT(GPIODIRc, Pin);
			SET_BIT(GPIODENC,Pin);
			SET_BIT(GPIODR8RC, Pin);
			SET_BIT(GPIOPURC, Pin);
			CLR_BIT(GPIOAFSELC,Pin);
			break;
			case DIO_PORTD:
			SET_BIT(GPIODIRD, Pin);
			SET_BIT(GPIODEND,Pin);
			SET_BIT(GPIODR8RD, Pin);
			SET_BIT(GPIOPURD, Pin);
			CLR_BIT(GPIOAFSELD,Pin);
			break;
}
break;
	}
}
/**
 * 
 * @brief to define the state high or low  
 * @param port_t & pin_t and state_t
 * @return no return state 
 *          
 *          
 */
void DIO_SetPinValue(port_t Port, pin_t Pin, state_t State)
{
	switch(State)
	{
		case DIO_LOW:
		switch (Port)
		{
			case DIO_PORTA:
			CLR_BIT(portA, Pin);
		
			break;
			case DIO_PORTB:
			CLR_BIT(portB , Pin);
		
			break;
			case DIO_PORTC:
			CLR_BIT(portC, Pin);
		
			break;
			case DIO_PORTD:
			CLR_BIT(portD, Pin);
		
			break;

		}
		break;
		case DIO_HIGH:
		switch (Port)
		{
			case DIO_PORTA:
			SET_BIT(portA,Pin);
	
			break;
			case DIO_PORTB:
			SET_BIT(portB,Pin);
		
			break;
			case DIO_PORTC:
			SET_BIT(portC,Pin);

			break;
			case DIO_PORTD:
			SET_BIT(portD,Pin);

			break;

		}
		break;
	}
}
/**
 * 
 * @brief To get pin value (High/Low) 
 * @param port_t & pin_t 
 * @return it return if the pin high or low 
 *          
 *          
 */
uint8t GPIO_ReadPinValue(port_t Port, pin_t Pin)
{
	uint8t data = 3;
	switch (Port)
	{
		case DIO_PORTA:
		data = GET_BIT(portA, Pin);
		break;
		case DIO_PORTB:
		data = GET_BIT(portD, Pin);
		break;
		case DIO_PORTC:
		data = GET_BIT(portC, Pin);
		break;
		case DIO_PORTD:
		data = GET_BIT(portB, Pin);
		break;
}
	return data;
}
void GPIO_special_pin(port_t Port, pin_t Pin)
{

	switch (Port)
	{
		case DIO_PORTA:
		SET_BIT(GPIOAFSELA,Pin);
		break;
		case DIO_PORTB:
	 SET_BIT(GPIOAFSELB, Pin);
		break;
		case DIO_PORTC:
		 SET_BIT(GPIOAFSELC, Pin);
		break;
		case DIO_PORTD:
		 SET_BIT(GPIOAFSELD, Pin);
		break;
}

}
void GPIO_analoge_pin(port_t Port, pin_t Pin)
{

	switch (Port)
	{
		case DIO_PORTA:
		CLR_BIT(GPIODENA,Pin);
		SET_BIT(GPIOAMSELA,Pin);
		break;
		case DIO_PORTB:
	 CLR_BIT(GPIODENB, Pin);
		SET_BIT(GPIOAMSELB,Pin);
		break;
		case DIO_PORTC:
		 CLR_BIT(GPIODENC, Pin);
		SET_BIT(GPIOAMSELC,Pin);
		break;
		case DIO_PORTD:
		 CLR_BIT(GPIODEND, Pin);
		SET_BIT(GPIOAMSELD,Pin);
		break;
}

}