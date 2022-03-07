#include "7_segment.h"

nbr = 1234;

void init_7_segment()
{
    TRISA = 0x00;   // RA = sortie
    TRISD = 0x00;   // RD = sortie
    
    LATA = 0;       // clear port A
    LATD = 0;       // clear port D
}

void print_7_segment_1_digit(char number, char digit)
{
    /* En boucle, activer RA0 a RA3
     * Afficher le nombre voulu : RDx
     */
    LATA = get_7_segment_digit_from_number(digit);
    LATD = get_7_segment_number_from_ascii(number);
    
}

void set_7_segment_nbr(char number)
{
     nbr = number;
}

char get_digit_number(char digit)
{
     return nbr << digit;
}

char get_7_segment_digit_from_number(char number)
{
    switch (number)
    {
        case 0:
            return DIGIT0;
            break;
        case 1:
            return DIGIT1;
            break;
        case 2:
            return DIGIT2;
            break;
        case 3:
            return DIGIT3;
            break;
    }
    return DIGIT0;
}

char get_7_segment_number_from_ascii(char number)
{
    switch (number)
    {
        case 0:
            return ZERO;
        case 1:
            return ONE;
            break;
        case 2:
            return TWO;
            break;
        case 3:
            return THREE;
            break;
        case 4:
            return FOUR;
            break;
        case 5:
            return FIVE;
            break;
        case 6:
            return SIX;
            break;
        case 7:
            return SEVEN;
            break;
        case 8:
            return EIGHT;
            break;
        case 9:
            return NINE;
            break;
    }
    return EIGHT;
}

