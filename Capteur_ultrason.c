#include "Capteur_ultrason.h"

void init_capteur()
{
     // trigger = entree et echo = sortie
     TRISB |= 1 << PIN_TRIG && 0 << PIN_ECHO;
}

int get_distance()
{
    // Envoie de l'initialisation du maitre
    LATB |= 1 << PIN_TRIG;
    // Attente de la reponse de l'esclave
    while(0)
    {

    }
}