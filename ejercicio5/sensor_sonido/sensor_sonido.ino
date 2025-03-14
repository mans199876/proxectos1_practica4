//Declaramos las variables generales
const int sensorPin = 2;  // Pin al que está conectado el sensor HW-484
volatile bool sensorTriggered = false;

//Funciones para la interrupcion
void sensorISR() {
  sensorTriggered = true;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), sensorISR, RISING);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (sensorTriggered) {
    Serial.println("Interrupción detectada: Sensor activado");
    sensorTriggered = false;
  }

}

