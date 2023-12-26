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

void trigCheckDistFinal(){
  if(led_line_logic[0][led_arr_trig_lr] || led_line_logic[6][led_arr_trig_lr] == 1){
  // LSRB Algo
      if(way[point] == 'R'){right();point++;}
      if(way[point] == 'S'){straight();point++;}
      if(way[point] == 'L'){left();point++;}
      if(way[point] == 'E'){digitalWrite(led_pin,HIGH);brake();}
    }
  }


void triggerBack(){
  back();way[point] = 'B'; point++;
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
    if(ML == 0 && MR == 0 && FC == 1){ right();    way[point] = 'R'; point++;}
    if(ML == 0 && MR == 1 && FC == 0){ }
    if(ML == 0 && MR == 1 && FC == 1){ straight(); way[point] = 'S'; point++;}
    if(ML == 1 && MR == 0 && FC == 0){ left();     way[point] = 'L'; point++;}
    if(ML == 1 && MR == 0 && FC == 1){ left();     way[point] = 'L'; point++;}
    if(ML == 1 && MR == 1 && FC == 0){ left();     way[point] = 'L'; point++;}
    if(ML == 1 && MR == 1 && FC == 1){ 
      if(led_line_logic[0][0] == 1 ||led_line_logic[6][0] == 1 ){
          digitalWrite(led_pin,HIGH);
        brake();
        }
      else{
        left();     way[point] = 'L'; point++;
        }
      }
      LSRBalgo();
  }



