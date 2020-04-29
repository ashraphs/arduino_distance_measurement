 
int echoPin      = 9;
int triggerPin   = 8;
int GREEN_LED_PIN = 2;
int YELLOW_LED_PIN = 3;
int RED_LED_PIN   = 4;
long duration;
int distanceCm;
long distanceInch;
 
void setup()
{
  Serial.begin(9600);
  // Set i/o pins
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

}
 
void loop()
{
  // Send trigger pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0340 / 2;

  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  Serial.println(distanceCm);

  if (distanceCm <= 10){
     digitalWrite(RED_LED_PIN, HIGH);

  }else if(distanceCm > 11  && distanceCm <= 20){
     digitalWrite(YELLOW_LED_PIN, HIGH);

  }else if(distanceCm > 21 && distanceCm <= 30){
     digitalWrite(GREEN_LED_PIN, HIGH);

  }else if (distanceCm > 31){
     digitalWrite(GREEN_LED_PIN, HIGH);
     digitalWrite(YELLOW_LED_PIN, HIGH);
     digitalWrite(RED_LED_PIN, HIGH);
  }

}
