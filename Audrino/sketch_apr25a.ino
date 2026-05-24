#define Sensor 8
#define LED 9

void setup() {
  pinMode(Sensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int status_sensor = digitalRead(Sensor);

  if (status_sensor == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}