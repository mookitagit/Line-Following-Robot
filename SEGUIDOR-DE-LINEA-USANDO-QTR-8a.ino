# TEAM markoboquiñechainajesu

# Este codigo sirve para seguir una línea negra usando sensores y control PID proporcional-derivativo.
.

# 06 / 02 / 2025 - V. 1. 0. 0 - SEGUIDOR-DE-LINEA-USANDO-QTR
#include <QTRSensors.h> // Se incluye la librería para el sensor QTR

// Definición de constantes para el control PID y velocidad de motores
#define SETPOINT 2500     // Valor ideal del centro de la línea negra
#define KP       .068     // Constante proporcional del control PID
#define KD       0.3      // Constante derivativa del control PID
#define MAX_SPEED   130   // Velocidad máxima permitida para los motores
#define SET_SPEED   130   // Velocidad objetivo (base) de los motores
#define MIN_SPEED   0     // Velocidad mínima de los motores

// Variable para guardar el error anterior en el control PID
int lastError = 0;

// Definición de pines para el motor derecho
int IN1 = 4;               // Control de dirección del motor derecho
int IN2 = 7;               // Control de dirección del motor derecho
int MOTORDERECHO = 11;     // Pin PWM para velocidad del motor derecho

// Definición de pines para el motor izquierdo
int IN3 = 8;               // Control de dirección del motor izquierdo
int IN4 = 12;              // Control de dirección del motor izquierdo
int MOTORIZQUIERDO = 3;    // Pin PWM para velocidad del motor izquierdo

// Configuración del sensor QTR
QTRSensors qtr;                   // Objeto del sensor QTR
const uint8_t SensorCount = 6;    // Número de sensores en uso
uint16_t sensorValues[SensorCount]; // Arreglo para almacenar valores de sensores

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios

  qtr.setTypeAnalog(); // Se define que los sensores son del tipo analógico
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount); // Se definen los pines de los sensores
  qtr.setEmitterPin(2); // Se define el pin que controla los emisores infrarrojos

  pinMode(LED_BUILTIN, OUTPUT);      // Se configura el LED incorporado como salida
  digitalWrite(LED_BUILTIN, HIGH);   // Se enciende el LED para indicar que comienza la calibración

  // 🔧 Calibración de los sensores
  for (int i = 0; i < 400; i++) {
    qtr.calibrate(); // Ejecuta la rutina de calibración
    delay(2);        // Pequeña pausa entre lecturas
  }

  digitalWrite(LED_BUILTIN, LOW);    // Se apaga el LED para indicar que terminó la calibración

  // Configuración de los pines de control de motores como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(MOTORDERECHO, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(MOTORIZQUIERDO, OUTPUT);
}

void loop() {
  // Configuración de dirección del motor derecho (avanzar)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Configuración de dirección del motor izquierdo (avanzar)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Lectura de la posición de la línea negra
  unsigned int linePos = qtr.readLineBlack(sensorValues);

  // Cálculo del error respecto al punto central de la línea
  int error = SETPOINT - linePos;

  // Cálculo de la corrección PID
  float adjust = error * KP + KD * (error - lastError);

  // Guarda el error actual para la siguiente iteración
  lastError = error;

  // Ajuste de velocidad para cada motor usando la corrección PID
  analogWrite(MOTORIZQUIERDO, constrain(SET_SPEED - adjust, MIN_SPEED, MAX_SPEED)); // Ajusta motor izquierdo
  analogWrite(MOTORDERECHO, constrain(SET_SPEED + adjust, MIN_SPEED, MAX_SPEED));   // Ajusta motor derecho

  // Muestra por el monitor serial los valores leídos y calculados
  Serial.print("Line pos: "); Serial.print(linePos);       // Muestra posición de la línea
  Serial.print(" | Error: "); Serial.print(error);         // Muestra error PID
  Serial.print(" | Adjust: "); Serial.println(adjust);     // Muestra valor de ajuste PID
}

