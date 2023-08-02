//Asign Pin Constants
const uint8_t DATA_PIN = 2;         
const uint8_t LED_PIN = 13;           


//Setup is done to set correct pin mode, intialise interruptpin(DATA_PIN) & start serial monitor
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(DATA_PIN), pin_ISR, CHANGE);
  Serial.begin(9600);
}



void loop() {
  //Print Sensor & Light Value every 5 seconds
  Serial.print(digitalRead(DATA_PIN));
  Serial.println(digitalRead(LED_PIN));
  delay(500);
}

//Pin ISR will run when an interrupt is detected, changing LED value to match sensor
void pin_ISR() {
  digitalWrite(LED_PIN, digitalRead(DATA_PIN)); 
}
