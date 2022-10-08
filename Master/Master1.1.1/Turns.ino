void straight(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, (int)(base_motor_speed ));
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, base_motor_speed);
  digitalWrite(13, HIGH);
  delay(del_straight);
  digitalWrite(13, LOW);

}
void left(){

}
void right(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, (int)(base_motor_speed ));
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, base_motor_speed);
  delay(del_right);
}
void back(){
  
}
void checkEndLeft(){
  delay(del_end);
  ledPathTrigCheck();
  if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
    path = 'E';
    while (final_run_var==0) {}
    }
  else{
      path = 'C';left();way[point] = 'L'; point++;
  }
}
void checkEndRight(){
  delay(del_end);
  ledPathTrigCheck();
  if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end
    path = 'E';
    while (final_run_var==0) {}
    }
  else{
      path = 'C';right();way[point] = 'R'; point++;
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