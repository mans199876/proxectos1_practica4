#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

void ajuste_inicial() {
    // Desplazamos a la posición 0°
    servoMotor.write(0);
    // Esperamos 1 segundo
    delay(1000);
}

void setup() {
    // Iniciamos el monitor serie para mostrar el resultado
    Serial.begin(9600);

    // Iniciamos el servo para que empiece a trabajar con el pin 9
    servoMotor.attach(9); // Nos permite indicar en qué pin PWM tenemos conectado nuestro servo
    ajuste_inicial();
}

void tres_angulos() {
    // Desplazamos a la posición 0°
    servoMotor.write(0);
    // Esperamos 3 segundos
    delay(500);

    // Desplazamos a la posición 90°
    servoMotor.write(90);
    // Esperamos 4 segundos
    delay(500);

    // Desplazamos a la posición 180°
    servoMotor.write(180);
    // Esperamos 5 segundos
    delay(500);
}

void vigilancia() {
    for (int i = 0; i <= 180; i++) {
        // Desplazamos al ángulo correspondiente
        servoMotor.write(i);
        // Hacemos una pausa de 10ms
        delay(10);
    }

    // Para el sentido negativo
    for (int i = 179; i >= 0; i--) {
        // Desplazamos al ángulo correspondiente
        servoMotor.write(i);
        // Hacemos una pausa de 10ms
        delay(10);
    }
}

void loop() {
    //Puedes llamar a la función que necesites aquí
    delay(1000);
     vigilancia();
}
