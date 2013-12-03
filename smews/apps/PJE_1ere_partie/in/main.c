/* This file is part of rflpc. Copyright 2010-2011 Michael Hauspie
 *
 * rflpc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rflpc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rflpc.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
  Created:
  Time-stamp: <2012-12-14 16:10:18 (hauspie)>
*/
#include <rflpc17xx/rflpc17xx.h>

int main(){

	/*On met la pin 27 en mode entree*/
	rflpc_gpio_set_pin_mode_input(RFLPC_PIN_P0_23);	//PIN27
    
	/*On met la pin 28 en mode sortie*/
	rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P0_10, 0);	//PIN28

	/*On met le courant sur la pin 28 a 0*/
	rflpc_gpio_clr_pin(RFLPC_PIN_P0_10);

    /*On ecoute l'etat de la pin 27*/
	while(1){
		/*Si la pin 27 recoit du courant :*/
		if(rflpc_gpio_get_pin(RFLPC_PIN_P0_23)){
			/*On envoie du courant sur la pin 28*/
			rflpc_gpio_set_pin(RFLPC_PIN_P0_10);
		}
		/*Sinon :*/
		else{
			/*On retire le courant sur la pin 28*/
			rflpc_gpio_clr_pin(RFLPC_PIN_P0_10);
		}
	}

    return 0;
}
