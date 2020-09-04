#define TRIG1 26 // Module pins
#define ECHO1 33
#define TRIG2 14 // Module pins
#define ECHO2 13

void setup() {
  Serial.begin(115200);   // Serial monitoring
  pinMode(TRIG1, OUTPUT); // Initializing Trigger Output and Echo Input
  pinMode(ECHO1, INPUT_PULLUP);
  pinMode(TRIG2, OUTPUT); // Initializing Trigger Output and Echo Input
  pinMode(ECHO2, INPUT_PULLUP);
}

void loop() {
  digitalWrite(TRIG1, LOW); // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH); // Send a 10uS high to trigger ranging
  delayMicroseconds(20);
  digitalWrite(TRIG1, LOW);                    // Send pin low again
  int distance1 = pulseIn(ECHO1, HIGH, 26000); // Read in times pulse
  distance1 = distance1 / 58; // Convert the pulse duration to distance
  // You can add other math functions to calibrate it well
  Serial.print("Distance1 ");
  Serial.print(distance1);
  Serial.println("cm");

  digitalWrite(TRIG2, LOW); // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH); // Send a 10uS high to trigger ranging
  delayMicroseconds(20);
  digitalWrite(TRIG2, LOW);                    // Send pin low again
  int distance2 = pulseIn(ECHO2, HIGH, 26000); // Read in times pulse
  distance2 = distance2 / 58; // Convert the pulse duration to distance
  // You can add other math functions to calibrate it well
  Serial.print("Distance2 ");
  Serial.print(distance2);
  Serial.println("cm");
  delay(1000);
}
