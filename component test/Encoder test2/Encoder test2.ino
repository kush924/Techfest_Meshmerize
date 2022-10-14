#define ENC_IN 3
volatile long encoderValue = 0;

void setup() {
  pinMode(4, INPUT_PULLUP);
 pinMode(ENC_IN, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);
Serial.begin(9600);  
  
}

void loop() {
Serial.println(encoderValue);
delay(100);
}
void updateEncoder()
{
  if (digitalRead(4) == 1) {
  encoderValue++; 
  }
  if (digitalRead(4) == 0){
  encoderValue--;
  }
}