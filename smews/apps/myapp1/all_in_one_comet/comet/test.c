/*
<generator>
	<handlers init="init" initGet="initGet" doGet="doGet"/>
	<properties persitence="volatile" channel="test"/>
	<args>
		<arg name="joystick" type="uint16" />
	</args>
</generator>

*/

#include <stdio.h>

#include "generators.h"
#include "timers.h"
#include "channels.h"

static int joystick = 0;
static int joy = 0;

static void timer() {

	if(rflpc_gpio_get_pin(MBED_DIP12) && joy != 3){
		joy = 3;
		server_push(&test);
	}
	if(rflpc_gpio_get_pin(MBED_DIP13) && joy != 4){
		joy = 4;
		server_push(&test);
	}
	if(rflpc_gpio_get_pin(MBED_DIP14) && joy != 5){
		joy = 5;
		server_push(&test);
	}
	if(rflpc_gpio_get_pin(MBED_DIP15) && joy != 1){
		joy = 1;
		server_push(&test);
	}
	if(rflpc_gpio_get_pin(MBED_DIP16) && joy != 2){
		joy = 2;
		server_push(&test);
	}
}

static char initGet(struct args_t *args) {
	rflpc_pin_set(MBED_DIP12, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP13, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
  	rflpc_pin_set(MBED_DIP14, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
  	rflpc_pin_set(MBED_DIP15, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
  	rflpc_pin_set(MBED_DIP16, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
	return 1;
}

static char init(void) {
	
	return set_timer(&timer,500);
}

static char doGet(struct args_t *args) {
	joy = args->joystick;
	out_uint(joy);
	return 1;
}
