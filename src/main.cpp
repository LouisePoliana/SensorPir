#include <WiFi.h>
//#include <WebServer.h>
#include <Arduino.h>

#define PinoSensor 22
#define PinoRele 26
#define PinoLed 2

int estadoAtualPir = LOW;
int estadoAnteriorPir = LOW;

// Função de inicialização
void setup()
{
  Serial.begin(115200); // Comunicação serial
  pinMode(PinoSensor, INPUT);
  pinMode(PinoRele, OUTPUT);
  pinMode(PinoLed, OUTPUT);
}
// Função de loop principal
void loop()
{
  estadoAnteriorPir = estadoAtualPir; // Armazena estado antigo
  estadoAtualPir = digitalRead(PinoSensor);
  if (estadoAnteriorPir == LOW && estadoAtualPir == HIGH)
  {
    Serial.println("Movimento detectado, ligando o relé");
    digitalWrite(PinoLed, HIGH);
    digitalWrite(PinoRele, LOW);
  }
  else if (estadoAnteriorPir == HIGH && estadoAtualPir == LOW)
  {
    Serial.println("Não há movimento, desligando o relé");
    digitalWrite(PinoRele, HIGH);
    digitalWrite(PinoLed, LOW);
  }
}