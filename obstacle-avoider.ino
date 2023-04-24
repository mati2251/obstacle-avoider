#define FRONT_START_LEFT 0
#define BACK_START_LEFT 1
#define FRONT_START_RIGHT 2
#define BACK_START_RIGHT 3
#define TRIG 4
#define ECHO 5
#define DANGER_OBSTACLE_DISTANCE 20

void setup() {
  pinMode(FRONT_START_LEFT, OUTPUT);
  pinMode(BACK_START_LEFT, OUTPUT);
  pinMode(BACK_START_RIGHT, OUTPUT);
  pinMode(FRONT_START_LEFT, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
} 

void loop() {
  int cm = get_distance_in_cm();
  if(cm < DANGER_OBSTACLE_DISTANCE){
    ride_left();
    Serial.print("Obstacle Detected");
  } else {
    ride_front();
  }
  delay(200); 
}

int get_distance_in_cm(){
  digitalWrite(TRIG, LOW);  
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);   
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  digitalWrite(ECHO, HIGH); 
  int time = pulseIn(ECHO, HIGH);
  return time / 58;
}

void ride_front(){
  left_wheel_ride_front();
  right_wheel_ride_front();
}

void ride_back(){
  left_wheel_ride_back();
  right_wheel_ride_back();
}

void ride_left(){
  left_wheel_ride_back();
  right_wheel_ride_front();
}

void ride_right(){
  left_wheel_ride_front();
  right_wheel_ride_back();
}

void left_wheel_ride_front(){
  wheel_change_drection(BACK_START_LEFT, FRONT_START_LEFT);
}

void left_wheel_ride_back(){
  wheel_change_drection(FRONT_START_LEFT, BACK_START_LEFT);
}

void right_wheel_ride_front(){
  wheel_change_drection(BACK_START_RIGHT, FRONT_START_RIGHT);
}

void right_wheel_ride_back(){
  wheel_change_drection(FRONT_START_RIGHT, BACK_START_RIGHT);
}

void stop(){
  digitalWrite(FRONT_START_LEFT, LOW);
  digitalWrite(BACK_START_LEFT, LOW);
  digitalWrite(BACK_START_RIGHT, LOW);
  digitalWrite(FRONT_START_RIGHT, LOW);
}

void wheel_change_drection(int pin_change_to_low, int pin_change_to_high){
  digitalWrite(pin_change_to_low, LOW);
  digitalWrite(pin_change_to_high, HIGH);
}