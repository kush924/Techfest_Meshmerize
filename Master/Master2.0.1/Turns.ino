void left(){
  brake();
  delay(500);
  moveLeft();
  delay(turn_time);
  while(1){
    moveLeft();
    ledsUpdate();
    if(led[2] >= 70){ break; }
  }
  brake();
  delay(500);
  PID_control2();
  motorRunPid();
}
void right(){
  brake();
  delay(500);
  moveRight();
  delay(turn_time);
  while(1){
    moveRight();
    ledsUpdate();
    if(led[2] >= 70){ break; }
  }
  brake();
  delay(500);
  PID_control2();
  motorRunPid();
}
void back(){
  brake();
  delay(500);
  moveBack();
  delay(turn_time);
  while(1){
    moveBack();
    ledsUpdate();
    if(led[4] >= 70){ break; }
  }
  brake();
  delay(500);
  PID_control2();
  motorRunPid();
}
void moveLeft(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 55);
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
  analogWrite(bpwm, 55);
}
void moveBack(){
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  analogWrite(apwm, 55);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 55);
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
    digitalWrite(13,HIGH);
      // while (final_run_var==0) {
        brake();
      while(final_run_var == 0){
          buttonCheck();
      }
        digitalWrite(13, LOW);
    }
  else{
      path = 'C';left();way[point] = 'L'; point++;
      digitalWrite(13, LOW);
  }
}
void checkEndRight(){
  delay(del_end);
  // ledPathTrigCheck();
  if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
    path = 'E';
      digitalWrite(13,HIGH);
      // while (final_run_var==0) {
        brake();
      while(final_run_var == 0){
          buttonCheck();
      }
        digitalWrite(13, LOW);
    }
  else{
      path = 'C';right();way[point] = 'R'; point++;
      digitalWrite(13, LOW);
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
  analogWrite(apwm, 50);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  analogWrite(bpwm, 50);
}