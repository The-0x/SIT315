// C++ code
//Set Pin Constants
const uint8_t DATA_PIN = 2;
const uint8_t LED_PIN = 13;

//Enable Serial Monitor
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //If Motion Sensor detects movement LED turns on
  if(digitalRead(DATA_PIN) == 1){
    digitalWrite(LED_PIN, HIGH);
    Serial.print(digitalRead(DATA_PIN));
    Serial.println(digitalRead(LED_PIN));
  }
  //If no movement LED is off
  else {
    digitalWrite(LED_PIN, LOW);
    Serial.print(digitalRead(DATA_PIN));
    Serial.println(digitalRead(LED_PIN));
  }
  delay(500);
}