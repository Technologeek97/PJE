/*
<generator>
	<handlers doGet="doGet"/>
</generator>
*/

/* simple contents generator */
static char doGet(struct args_t *args) {
	int j,i = 0;
    
    out_str("Generated Hello World ! ");
    
    rflpc_led_init();
    
    rflpc_led_set(RFLPC_LED_1);
    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_set(RFLPC_LED_2);
    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_set(RFLPC_LED_3);
    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_set(RFLPC_LED_4);

    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_clr(RFLPC_LED_1);
    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_clr(RFLPC_LED_2);
    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_clr(RFLPC_LED_3);
    for (j = 0 ; j < 10000000 ; ++j);
    rflpc_led_clr(RFLPC_LED_4);


    while (1)
    {
	rflpc_led_binary_value((i++)%16);
	for (j = 0 ; j < 1000000 ; ++j);
    }
    return 1;
}
