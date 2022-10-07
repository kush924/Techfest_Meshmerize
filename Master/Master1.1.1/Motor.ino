// A-> right
// B-> left

void motorInit(){
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(apwm, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(bpwm, OUTPUT);
}

void motorCheck(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 255);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 255);
}

void motorRun(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, (int)(motor_speed * 1.07));
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, motor_speed);
}
void motorStop(){
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(apwm, 0);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 0);
}
void motorSpin(){
  digitalWrite(a1, LOW);    //clockwise
  digitalWrite(a2, HIGH);
  analogWrite(apwm, (int)(50 * 1.07));
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(bpwm, 50);
}
void motorSpinCounterclock(){
  digitalWrite(a1, HIGH);    //counter clockwise
  digitalWrite(a2, LOW);
  analogWrite(apwm, (int)(50 * 1.07));
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  analogWrite(bpwm, 50);
}