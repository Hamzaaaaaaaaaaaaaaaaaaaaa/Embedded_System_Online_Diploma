/*
 * main.c
 *
 *  Created on: May 21, 2024
 *      Author: HAMZA AHMED
 */


#include "CA.h"

void Set_up()
{

	/*
	 * init all drivers
	 * init IRQ
	 * init HAl drivers
	 * init Block
	 * Set State pointer for each block
	 */
	CA_state = STATE(CA_waiting);
}

int main()
{
	Set_up();

	while(1)
	{
		CA_state();
	}
	return 0 ;
}








