#include <Arduino.h>

float temperatura_atual; // No Arduino, 'float' e 'double' têm a mesma precisão na maioria das placas (como o Uno)
const int limite_temperatura = 30;
bool ventoinha_ligada = false;


const int pinoVentoinha = 8; // Opcional: pino físico onde a ventoinha (ou LED) estaria conectada

void setup() {

  Serial.begin(9600);   // Inicia a comunicação serial com o computador a 9600 bits por segundo
  pinMode(pinoVentoinha, OUTPUT);

  Serial.println("=== Controlador de temperatura ===");
  Serial.print("Limite de temperatura: ");
  Serial.println(limite_temperatura);
  Serial.println("Digite a temperatura atual no Monitor Serial:");
}

void loop() {
  // Verifica se o usuário digitou algo no Monitor Serial
  if (Serial.available() > 0) {
    // Lê o número decimal enviado (substitui o std::cin)
    temperatura_atual = Serial.parseFloat();

    // Limpa caracteres extras como 'Enter' (\n) do buffer
    while (Serial.available() > 0) {
      Serial.read();
    }

    Serial.print("Temperatura lida: ");
    Serial.println(temperatura_atual);

    if (temperatura_atual >= limite_temperatura) {
      ventoinha_ligada = true;
      digitalWrite(pinoVentoinha, HIGH); // Aciona o pino físico
      Serial.println("Ventoinha ligada");
    } else {
      ventoinha_ligada = false;
      digitalWrite(pinoVentoinha, LOW);  // Desliga o pino físico
      Serial.println("Ventoinha desligada");
    }
    
    Serial.println("\nDigite a proxima temperatura:");
  }
}
