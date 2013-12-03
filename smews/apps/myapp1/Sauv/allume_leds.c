/*
<generator>
	<handlers doGet="doGet"/>
	<args>
		<arg name="led" type="uint8" size="4" />
	</args>
</generator>
*/

/* simple contents generator */
static char doGet(struct args_t *args) {
    
    rflpc_led_init();
    
    if(args->led == 1){
		rflpc_led_set(RFLPC_LED_1);
	}
	if(args->led == 2){
		rflpc_led_set(RFLPC_LED_2);
	}
	if(args->led == 3){
		rflpc_led_set(RFLPC_LED_3);
	}
	if(args->led == 4){
		rflpc_led_set(RFLPC_LED_4);
	}

    return 1;
}
