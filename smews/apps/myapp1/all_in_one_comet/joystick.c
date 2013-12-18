/*
<generator>
	<handlers init="init" initGet="initGet" doGet="doGet"/>
	<properties persitence="volatile" channel="test"/>
	<handlers doGet="doGet"/>
</generator>
*/

/* simple contents generator */
static void change_state(){
	if(rflpc_gpio_get_pin(MBED_DIP12)){
		out_str("BAS");
	}
	if(rflpc_gpio_get_pin(MBED_DIP13)){
		out_str("GAUCHE");
	}
	if(rflpc_gpio_get_pin(MBED_DIP14)){
		out_str("CENTER");
	}
	if(rflpc_gpio_get_pin(MBED_DIP15)){
		out_str("HAUT");
	}
	if(rflpc_gpio_get_pin(MBED_DIP16)){
		out_str("DROITE");
	}
}

static char init(void) {    
    rflpc_pin_set(MBED_DIP12, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP13, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP14, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP15, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP16, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);

	change_state();
}

static char doGet(struct args_t *args) {
    unsigned i;
    
    rflpc_pin_set(MBED_DIP12, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP13, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP14, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP15, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    rflpc_pin_set(MBED_DIP16, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);

	change_state();
	
    return 1;
}
