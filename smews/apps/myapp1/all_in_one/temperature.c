/*
<generator>
	<handlers doGet="doGet"/>
</generator>
*/

static char doGet(struct args_t *args) {
    unsigned i;
    
    rflpc_pin_set(MBED_DIP12, 0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN, 0);
    out_str(0x40);
	
    return 1;
}

