void dist_delay(int step){
  detachInterrupt(digitalPinToInterrupt(intpin));
  del_step_count = 0;
  attachInterrupt(digitalPinToInterrupt(intpin),isr_delay,RISING);
  while(del_step_count <= step){
    
  }
  detachInterrupt(digitalPinToInterrupt(intpin));
  attachInterrupt(digitalPinToInterrupt(intpin),ledLineISR,RISING);
}

void isr_delay(){
  del_step_count ++;
}