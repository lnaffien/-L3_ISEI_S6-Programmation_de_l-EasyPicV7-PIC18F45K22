#include <stdio.h>
#include "7_segment.h"
#include "Uart.h"
#include "Capteur_ultrason.h"

void main()
{
      init_7_segment();
      
     while(1)
     {
      print_7_segment(123);
     }
}