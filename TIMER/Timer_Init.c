  void systick_delay (uint32_t delay){
        NVIC_ST_RELOAD_R= delay-1;     	 	 // number of counts
      NVIC_ST_CURRENT_R=0;             		// clear the counter
        while ((NVIC_ST_CTRL_R & 0x00010000)==0);    //waiting...  (count bit set to one)
    }

   void Systick_wait10ms(uint32_t delay){  //wait (delay*10ms)
				int i; 
    for ( i=0; i<delay;i++){     
        systick_delay(800000);}
    }

   

void Systick_wait1ms (){
        NVIC_ST_RELOAD_R=(800000-1);     //setting the reload reg with the count(80,0000-1)
        NVIC_ST_CURRENT_R=0;         //clear the counter
        while ((NVIC_ST_CTRL_R &0x00010000)==0);

}  //  //waiting...  (count bit set to one)
