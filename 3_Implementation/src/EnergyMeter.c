/**
 * @file EngergyMeter.c
 * @author Ritik Parashar
 * @brief 
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#include "Engergymeter.h"

void send_a_command(unsigned char command)

{
  
   
    PORTB = command;
    PORTD &= ~ (1<<registerselection);
    PORTD |= 1<<enable;
    _delay_ms(20);
    PORTD &= ~1<<enable;
    PORTB = 0;
}


void send_a_character(unsigned char character)

{
    PORTB = character;
    PORTD |= 1<<registerselection;
    PORTD |= 1<<enable;
    _delay_ms(20);
    PORTD &= ~1<<enable;
    PORTB = 0;
}

void send_a_string(char *string_of_characters)
{
   
  while(*string_of_characters > 0)
    
    {
    
      send_a_character(*string_of_characters++);
    }
}
