int green_LED_PIN =9;
int blue_LED_PIN =10;
int red_LED_PIN =11;
int buzzer =6;
int gas_sensor =A0;
int limit =60;

void setup() 
{
  pinMode(green_LED_PIN, OUTPUT);
  pinMode(blue_LED_PIN, OUTPUT);
  pinMode(red_LED_PIN, OUTPUT);
  pinMode(buzzer,  OUTPUT);
  pinMode(gas_sensor, INPUT);
  Serial.begin(9600); 
}

void  loop() 
{
  int sensor_read = analogRead(gas_sensor); 
  Serial.print("Smoke  Density: ");
  Serial.println(sensor_read);
  
  if (sensor_read > limit)
  {
    analogWrite(red_LED_PIN,255);
    analogWrite(green_LED_PIN, 0);
    Serial.print("Urgent, Gas detected!");
    tone(buzzer,500, 100); 
  }
  else
  {
    analogWrite(green_LED_PIN, 255);
    analogWrite(red_LED_PIN,0);
    Serial.print("Safe, No gas detected");
    noTone(buzzer);
  }
  delay(50);
}
