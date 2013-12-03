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
	/*On fait clignoté la led à l'infini*/
	while(1){
		int i;
		/*Pendant un laps de temps, on allume la LED*/	
		for(i = 0; i < 100000; i++){
			rflpc_pin_set(RFLPC_PIN_P0_10, 1, RFLPC_PIN_MODE_RESISTOR_PULL_UP, 0);
		}
		/*Puis on l'eteint durant la meme duree*/
		for(i = 0; i < 100000; i++){
			rflpc_pin_set(RFLPC_PIN_P0_10, 0, RFLPC_PIN_MODE_RESISTOR_PULL_UP, 0);
		}
	}
    return 0;
}
