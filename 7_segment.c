#include "7_segment.h"

int nbr = 1234;
int temp = 0;

void init_7_segment()
{
    //config_timer();
    
    TRISA = 0x00;   // RA = sortie
    TRISD = 0x00;   // RD = sortie
    
    LATA = 0;       // clear port A
    LATD = 0;       // clear port D
}

void print_7_segment(int number)
{
     char nbr3;
     char nbr2;
     char nbr1;
     char nbr0 = number;
     
     nbr3 = nbr0 / 1000;
     nbr0 -= nbr3 * 1000;
     
     nbr2 = nbr0 / 100;
     nbr0 -= nbr2 * 100;
     
     nbr1 = nbr0 / 10;
     nbr0 -= nbr1 * 10;

     //print_7_segment_1_digit(nbr3, 4);
     //Delay_ms(DELAY_MS);
     print_7_segment_1_digit(nbr2, 3);
     Delay_ms(DELAY_MS);
     print_7_segment_1_digit(nbr1, 1);
     Delay_ms(DELAY_MS);
     print_7_segment_1_digit(nbr0, 0);
     Delay_ms(DELAY_MS);

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

void config_timer()
{
     /*
      * - Activation du Timer0
      * - 8 bits
      * - Mode timer //Horloge source : horloge du timer 0
      * - ?
      * - prescaler non assigne
      * - prescaler :
      */
     T0CON |= 1 << TMR0ON && 1 << T08BIT && 0 << T0CS && 1 << T0SE && 1 << PSA;
     // Valeur initiale dans l'accumulateur
     TMR0H = 0x0;
     
     // Activer le TMR0, mettre son drapeau de debordement a 0
      INTCON |= 1 << TMR0IE || 0 << TMR0IF;

}

/*
 * 0x000018 : low priority interrupt
 * 0x000008 : high priority interrupt
 */
 /*
void Timer0_Interrupt() iv 0x000018 ics ICS_AUTO
{
     print_7_segment_1_digit(temp, 2);
     temp ++;
     if (temp > 9)
     {
        temp = 0;
     }
     // On vide l'accumulateur
     TMR0H = 0x0;
     TMR0L = 0x0;
     // On remet le drapeau de debordement de TMR0 a 1
     INTCON |= 1 << TMR0IF;
}    */