void trigCheckDist(){
  if(led_line_logic[0][led_arr_trig_lr] || led_line_logic[6][led_arr_trig_lr] == 1){
  //trigger
  triggerLeftRight();
  }
  if(led_line_logic[3][led_arr_trig_f]==0){
    //trigger
  triggerBack();
  }
}

void triggerBack(){
  back();
}

void triggerLeftRight(){

  if(led_line_logic[0][led_arr_trig_lr] || led_line_logic[0][led_arr_trig_lr - 1] || led_line_logic[0][led_arr_trig_lr + 1]){
    ML = 1;
  }
  else{
    ML = 0;
  }
  if(led_line_logic[6][led_arr_trig_lr] || led_line_logic[6][led_arr_trig_lr - 1] || led_line_logic[6][led_arr_trig_lr + 1]){
    MR = 1;
  }
  else{
    MR = 0;
  }
  if(led_line_logic[3][led_arr_trig_f] || led_line_logic[3][led_arr_trig_f - 1] || led_line_logic[3][led_arr_trig_f + 1]){
    FC = 1;
  }
  else{
    FC = 0;
  }
  moveTrigLSRB();
}

  void moveTrigLSRB(){
    if(ML == 0 && MR == 0 && FC == 0){ }
    if(ML == 0 && MR == 0 && FC == 1){ right();    }
    if(ML == 0 && MR == 1 && FC == 0){ }
    if(ML == 0 && MR == 1 && FC == 1){ straight(); }
    if(ML == 1 && MR == 0 && FC == 0){ left();     }
    if(ML == 1 && MR == 0 && FC == 1){ left();     }
    if(ML == 1 && MR == 1 && FC == 0){ left();     }
    if(ML == 1 && MR == 1 && FC == 1){ left();     }
  }



