int simTXPin = 16;
int simRXPin = 17;
int simRSTPin = 15;
int buzzPin = 25;

void setup() {
  Serial.begin(115200);
  Serial2.begin(4800, SERIAL_8N1, simTXPin, simRXPin);
  pinMode(simRSTPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(simRSTPin, LOW);
  delay(100);
  digitalWrite(simRSTPin, HIGH);
  digitalWrite(buzzPin, HIGH);
  delay(1000);

  Serial.println("");
  Serial.println("");
  Serial.println("Initializing...");
  delay(1000);

  Serial2.println("AT");
  updateSerial();
  Serial2.println("AT+CSQ");
  updateSerial();
  Serial2.println("AT+CCID");
  updateSerial();
  Serial2.println("AT+CREG?");
  updateSerial();
}

void loop() { updateSerial(); }

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    Serial2.write(Serial.read());
  }
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}