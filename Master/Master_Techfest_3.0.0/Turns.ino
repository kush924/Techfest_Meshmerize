void left(){
  brake();
  delay(del_turn_stop);
  moveLeft();
  delay(turn_time);
  while(1){
    moveLeft();
    ledsUpdate();
    if(led[2] >= led_turn_cutoff){ break; }
  }
  brake();
  delay(del_turn_stop);
  PID_control2();
  motorRunPid();
}
void right(){
  brake();
  delay(del_turn_stop);
  moveRight();
  delay(turn_time);
  while(1){
    moveRight();
    ledsUpdate();
    if(led[2] >= led_turn_cutoff){ break; }
  }
  brake();
  delay(del_turn_stop);
  PID_control2();
  motorRunPid();
}
void back(){
  delay(del_turn_forward_stop);
  brake();
  delay(del_turn_stop);
  moveBack();
  delay(turn_time);
  while(1){
    moveBack();
    ledsUpdate();
    if(led[4] >= led_turn_cutoff){ break; }
  }
  brake();
  delay(del_turn_stop);
  PID_control2();
  motorRunPid();
}
void moveLeft(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, turn_speed);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 0);
}
void moveRight(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 0);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, turn_speed);
}
void moveBack(){
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  analogWrite(apwm, turn_speed);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, turn_speed);
}
void straight(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, base_motor_speed );
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, base_motor_speed);
  delay(60);

}
void checkEndLeft(){
  
  delay(del_end);
  // ledPathTrigCheck();
  if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
    path = 'E';
    digitalWrite(led_pin,HIGH);
      // while (final_run_var==0) {
        brake();
      while(final_run_var == 0){
          buttonCheck();
      }
        digitalWrite(led_pin, LOW);
    }
  else{
      path = 'C';left();way[point] = 'L'; point++;
      digitalWrite(led_pin, LOW);
  }
}
void checkEndRight(){
  delay(del_end);
  // ledPathTrigCheck();
  if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
    path = 'E';
      digitalWrite(led_pin,HIGH);
      // while (final_run_var==0) {
        brake();
      while(final_run_var == 0){
          buttonCheck();
      }
        digitalWrite(led_pin, LOW);
    }
  else{
      path = 'C';right();way[point] = 'R'; point++;
      digitalWrite(led_pin, LOW);
  }
}
void brake(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 0);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 0);
}
void retrace(){
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  analogWrite(apwm, turn_speed);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  analogWrite(bpwm, turn_speed);
}