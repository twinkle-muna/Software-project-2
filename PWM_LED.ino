const int LED_PIN = 7;

int pwm_period = 1000; 
int pwm_duty   = 0;   

void set_period(int period) {
  pwm_period = constrain(period, 100, 10000);
}

void set_duty(int duty) {
  pwm_duty = constrain(duty, 0, 100);
}

void pwm_cycle() {
  long on_time  = (long)pwm_period * pwm_duty / 100;
  long off_time = pwm_period - on_time;

  if (on_time > 0) {
    digitalWrite(LED_PIN, LOW);  
    delayMicroseconds(on_time);
  }
  if (off_time > 0) {
    digitalWrite(LED_PIN, HIGH); 
    delayMicroseconds(off_time);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  set_period(10000);
}

void loop() {
  int phase = millis() % 1000;  
  int duty;
  if (phase < 500) duty = phase / 5;         
  else             duty = (1000 - phase) / 5; 
  set_duty(duty);
  pwm_cycle();
