#include "uart.h"

unsigned char string_buffer[100]="learn-in-depth:Hamza";
void main ()
{
  uart_send_string(string_buffer);
}