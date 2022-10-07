void buttonInit(){
  pinMode(10,INPUT_PULLUP);   //Blue    calibration button
  pinMode(11,INPUT_PULLUP);   //Red     algo toggle
  pinMode(12,INPUT_PULLUP);   //Yellow  final run button
}

void buttonCheck(){
  if (millis() - button_oldtime >= button_time) {
  // button_oldtime = millis();   //

    if (digitalRead(calibration_pin) == LOW) {
        //  calibrate();
        button_oldtime = millis();
    }
    if (digitalRead(algo_pin) == LOW) {
        algo_toggle_var = ! algo_toggle_var;
        button_oldtime = millis();
    }
    if (digitalRead(final_run_pin) == LOW) {
        final_run_var = ! final_run_var;
        button_oldtime = millis();
    }
  }
}

void calibrate(){
  for(int c = 0;c<=4;c++){
   cal_led_high[c] = 0;  
  }
  for(int c = 0;c<=2;c++){
   cal_led_path_high[c] = 0;  
  }
  for(int c = 0;c<=4;c++){
   cal_led_low[c] = 1024;  
  }
  for(int c = 0;c<=2;c++){
   cal_led_path_low[c] = 1024;  
  }
  motorSpin();
  for(int b=0;b<=1000;b++){
  ledCal();
  }
  for(int b=0;b<=1000;b++){
  ledPathCal();
  }
  motorStop();
}
void ledCal(){
  for (int i = 7, j = 0; i >= 3; i--){
    float temp = analogRead(i);
    if(temp > cal_led_high[j]){
    cal_led_high[j] = temp;
    }
    if(temp < cal_led_low[j]){
    cal_led_low[j] = temp;
    }
    j++;
  }
}
void ledPathCal(){
  for (int i = 2, j = 0; i >= 0; i--){
    float temp = analogRead(i);
    if(temp > cal_led_high[j]){
    cal_led_high[j] = temp;
    }
    if(temp < cal_led_low[j]){
    cal_led_low[j] = temp;
    }
    j++;
  }
}