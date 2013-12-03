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

/*variable "booleenne" global qui represente l'etat courant de la LED*/
static int cpt = 0;

/*
Version System tick timer :
*/

/*fonction executee a chaque top d'horloge'*/
static void handler(){
	/*on change l'etat de cpt qui correspond a si on allume ou si l'on eteint la led*/
	cpt = !cpt;

	/*Si le compteur est a vrai, on allume la LED*/
	if (cpt)
		rflpc_gpio_set_pin(RFLPC_PIN_P0_10);
	/*Si le compteur est a faux, on eteint la LED*/
	else
		rflpc_gpio_clr_pin(RFLPC_PIN_P0_10);

}

static int doClignote(){

	/*On initialise le timer*/
	rflpc_sys_timer_init();

	/*On met la pin 28 en mode sortie*/
	rflpc_gpio_set_pin_mode_output(RFLPC_PIN_P0_10, 1);
	
	/*On donne la fonction "handler (au-dessus)" que doit lancer le timer a chaque periode*/
	rflpc_sys_timer_set_callback(handler);

	/*On règle la periode du timer a 100000 ce qui correspond a une interruption toutes les 1 seconde approximativement*/
	rflpc_sys_timer_set_period(100000);

	/*On demarre le timer*/
	rflpc_sys_timer_start ();

	/*On boucle infiniment*/
	while(1);

    return 0;
}
