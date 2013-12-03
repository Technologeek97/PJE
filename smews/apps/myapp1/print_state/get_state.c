/*
<generator>
	<handlers doGet="doGet"/>
	<args>
		<arg name="led" type="uint8" size="4" />
	</args>
</generator>
*/
volatile int state1 = 0;
volatile int state2 = 0;
volatile int state3 = 0;
volatile int state4 = 0;

/* simple contents generator */
static char doGet(struct args_t *args) {
    
    rflpc_led_init();
    
    if(args->led == 1){
		if(state1 == 0){
			state1=1;
		}
		else{
			state1=0;
		}
	}
	if(args->led == 2){
		if(state2 == 0){
			state2=1;
		}
		else{
			state2=0;
		}
	}
	if(args->led == 3){
		if(state3 == 0){
			state3=1;
		}
		else{
			state3=0;
		}
	}
	if(args->led == 4){
		if(state4 == 0){
			state4=1;
		}
		else{
			state4=0;
		}
	}
	
	if(state1 == 1){
		rflpc_led_set(RFLPC_LED_1);
	}
	if(state2 == 1){
		rflpc_led_set(RFLPC_LED_2);
	}
	if(state3 == 1){
		rflpc_led_set(RFLPC_LED_3);
	}
	if(state4 == 1){
		rflpc_led_set(RFLPC_LED_4);
	}

    return 1;
}
