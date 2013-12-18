/*
<generator>
	<handlers doGet="doGet"/>
	<args>
		<arg name="color" type="uint8" size="4" />
	</args>
</generator>
*/

/* simple contents generator */
static char doGet(struct args_t *args) {
    
	rflpc_gpio_set_pin_mode_output(MBED_DIP23, 1);
	rflpc_gpio_set_pin_mode_output(MBED_DIP24, 1);
	rflpc_gpio_set_pin_mode_output(MBED_DIP25, 1);
	
    switch(args->color){
		case 0:
			rflpc_gpio_set_pin(MBED_DIP23);
			rflpc_gpio_set_pin(MBED_DIP24);
			rflpc_gpio_set_pin(MBED_DIP25);
			break;
		case 1:
			rflpc_gpio_clr_pin(MBED_DIP23);
			break;
		case 2:
			rflpc_gpio_clr_pin(MBED_DIP24);
			break;
		case 3:
			rflpc_gpio_clr_pin(MBED_DIP25);
			break;
		case 4:
			rflpc_gpio_clr_pin(MBED_DIP23);
			rflpc_gpio_clr_pin(MBED_DIP25);
			break;
		case 5:
			rflpc_gpio_clr_pin(MBED_DIP23);
			rflpc_gpio_clr_pin(MBED_DIP24);
			break;
		case 6:
			rflpc_gpio_clr_pin(MBED_DIP24);
			rflpc_gpio_clr_pin(MBED_DIP25);
			break;
	}

    return 1;
}
