#define FRONT_START_LEFT 0
#define BACK_START_LEFT 1
#define TRIG 2
#define ECHO 3
#define DANGER_OBSTACLE_DISTANCE 20

void setup() {
  pinMode(FRONT_START_LEFT, OUTPUT);
  pinMode(BACK_START_LEFT, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  int cm = get_distance_in_cm();
  if(cm < DANGER_OBSTACLE_DISTANCE){
    left_wheel_ride_back();
    Serial.print("Obstacle Detected");
  } else {
    left_wheel_ride_front();
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

void left_wheel_ride_front(){
  digitalWrite(BACK_START_LEFT, LOW);
  digitalWrite(FRONT_START_LEFT, HIGH);
}

void left_wheel_ride_back(){
  digitalWrite(FRONT_START_LEFT, LOW);
  digitalWrite(BACK_START_LEFT, HIGH);
}
