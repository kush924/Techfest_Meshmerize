
unsigned long print_oldtime=0 ,print_time=200;   //time calculations
unsigned long button_oldtime=0 ,button_time=100;

int calibration_pin = 10, algo_pin = 11, final_run_pin = 12;
int calibration_var = 0, algo_toggle_var = 0, final_run_var=0;    //Button toggle state variable

float led[5],led_low[5]={0,0,0,0,0},led_high[5]={1024,1024,1024,1024,1024};   //arrays for LED values
float pos;    //value of the line coordinate
float led_path[3],led_path_low[3]={0,0,0},led_path_high[3]={1024,1024,1024};
float cal_led_high[5],cal_led_low[5]; float cal_led_path_high[3],cal_led_path_low[3];

int a1 = 4, a2 = 5, apwm = 6, b1 = 7, b2 = 8, bpwm = 9, motor_speed = 100;     //motor pins and speed

void setup() {
  Serial.begin(9600);
  buttonInit();
  motorInit();
  indicatorInit();
}

void loop() {

  ledCheck();               //check led array status
  ledPathCheck();           //check path led status
  cordCalc();               //calculate line coordinate
  // ledDebugg();
  delay(1000);
  calibrate();
  delay(1000);
  ledPathCalShow();
}
