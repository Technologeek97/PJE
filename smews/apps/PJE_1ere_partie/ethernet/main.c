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

int main()
{
	/*On initialise le port ethernet de la carte*/
    rflpc_eth_init();
    /*On met la pin 28 en mode sortie*/
    rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P0_10, 1);
    
    /*On ecoute l'etat du port ethernet*/
    while(1){
		if (rflpc_eth_link_state()){
			/*Si l'etat passe en mode branche, on met du courant sur la pin 28*/
			rflpc_gpio_set_pin(RFLPC_PIN_P0_10);
		}
		else{ 
			/*Si l'etat reste inchange ou si il passe en mode debranche, on enleve le courant sur la pin 28*/
			rflpc_gpio_clr_pin(RFLPC_PIN_P0_10);
		}
    }
    return 0;
}
