void trigCheckDist(){
    // Serial.println("Check");
  if(led_line_logic[0][led_arr_trig_lr] || led_line_logic[6][led_arr_trig_lr]){
  //trigger
  
  // moveRevDistDelay(25);
  motorStop();
  triggerLeftRight();
  reset_led_line();
  }
  // if(time_now>=1500){
  if((led_line_logic[3][0]==0) && (led_line_logic[3][2]==0) && (led_line_logic[3][3]==0)){
    //trigger
  triggerBack();
  }
  // }

}

void trigCheckDistFinal(){
  if(led_line_logic[0][led_arr_trig_lr] || led_line_logic[6][led_arr_trig_lr]){
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
    if(ML == 0 && MR == 0 && FC == 0){ Serial.println("000");}
    if(ML == 0 && MR == 0 && FC == 1){ Serial.println("001_right");right();    way[point] = 'R'; point++;}
    if(ML == 0 && MR == 1 && FC == 0){ Serial.println("010");}
    if(ML == 0 && MR == 1 && FC == 1){ Serial.println("011_straight"); straight(); way[point] = 'S'; point++;}
    if(ML == 1 && MR == 0 && FC == 0){ Serial.println("100_left");left();     way[point] = 'L'; point++;}
    if(ML == 1 && MR == 0 && FC == 1){ Serial.println("101_left");left();     way[point] = 'L'; point++;}
    if(ML == 1 && MR == 1 && FC == 0){ Serial.println("110_left");left();     way[point] = 'L'; point++;}
    if(ML == 1 && MR == 1 && FC == 1){ Serial.println("111_check");
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



