 void Systick_Init(void){
    NVIC_ST_CTRL_R=0;    			//clear enable to stop counter 
    NVIC_ST_RELOAD_R=0x00FFFFFF;     //initialize it with the maximum reload value 
    NVIC_ST_CURRENT_R=0;          //clear the counter
    NVIC_ST_CTRL_R=0x00000005;     //enable the systick & depend on the clk_src 
}
