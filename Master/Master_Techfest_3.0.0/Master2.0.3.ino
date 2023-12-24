// float KpAg = 3;
// float KdAg = 15;
// 80 7 20
// 60 5 3

float Kp = 3;              //change the value by trial-and-error (ex: 0.07).                //PID
float Ki = 0;              //change the value by trial-and-error (ex: 0.0008).
float Kd = 10;              //change the value by trial-and-error (ex: 0.6).
int P,I,D;                 
int lastError = 0;
int led_pin = 13;
int left_motor_speed = 0, right_motor_speed = 0,motor_set_speed = 75 ,base_motor_speed_diff = 0;
int base_motor_speed = motor_set_speed;

unsigned long print_oldtime=0 ,print_time=200;   //serial print time delay_steps
unsigned long button_oldtime=0 ,button_time=100;  //  button debounce

int calibration_pin = 10, algo_pin = 11, final_run_pin = 12;                    //button pins
int calibrate_done = 0, algo_toggle_var = 0, final_run_var=0;    //Button toggle state variable

float led[5],led_low[5]={0,0,0,0,0},led_high[5]={1024,1024,1024,1024,1024};   //arrays for LED values
float pos;    //value of the line coordinate
float led_path[3],led_path_low[3]={0,0,0},led_path_high[3]={1024,1024,1024};  //arrays for LED_path values
float cal_led_high[5],cal_led_low[5]; float cal_led_path_high[3],cal_led_path_low[3]; //Led calibration values
int led_path_cutoff = 20, led_cutoff = 50, led_turn_cutoff =70;

int led_path_left = 0, led_path_right = 0, led_path_front = 0, led_path_center = 0; //turn variables

char path; int point = 0;         //algo array store
char way[100] = {'N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N','N'};

int a1 = 4, a2 = 5, apwm = 6, b1 = 7, b2 = 8, bpwm = 9;     //motor pins

int del_point = 0, del_end = 150, del_left = 100, del_right = 100 , del_straight = 100 , del_back = 100, del_turn_stop = 500, del_turn_forward_stop = 100 ;      //delays
int button_press_brake_delay = 1000;
int turn_time = 200;
int calibrate_points = 5000;
int turn_speed = 75;

void setup() {
  Serial.begin(9600);
  buttonInit();
  motorInit();
  indicatorInit();
}

void loop() {

  buttonCheck();            //check if button is pressed
  ledCheck();               //check led array status    //
  ledMap();                                             //
  ledPathCheck();           //check path led status     //
  ledPathMap();                
  cordCalc();               //calculate line coordinate, assigns to pos //
  
  ledPathTrigCheck();       //led detect white and updates led_path_left,right,front,center
  PID_control();            //updates base_motor_speed_diff according to pos

  if (calibrate_done == 2) {
  motorRunPid();            // runs line follower(straight line) according to the base_motor_speed_diff
  pathTrigCheck();          
  }
  
  ledDebugg();
}
