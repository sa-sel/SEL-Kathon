// Definir os pinos dos LEDs  // Pinos digitais para os LEDs
int sensorPin = A0;                  // Pino analógico para o sensor de som
int sensorValue = 0;                 // Variável para armazenar o valor do sensor de som          
int ledVerde = 13;
int ledAmarelo1 = 5;
int ledAmarelo2 = 6;
int ledVermelho1 = 9;
int ledVermelho2 = 10;
int ledVermelho3 = 2;
int ledVermelho4 = 3;


void setup() {  
  // Configurar os pinos dos LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  pinMode(ledVermelho3, OUTPUT);
  pinMode(ledVermelho4, OUTPUT);
  pinMode(sensorPin, INPUT);
  // Inicializar a comunicação serial para debug
  Serial.begin(9600); 
}

void loop() {
  // Ler o valor do sensor de som
  sensorValue = analogRead(sensorPin);

  // Imprimir o valor do sensor no monitor serial (para ajuste)
  Serial.println(sensorValue);

  // Lógica de acender os leds conforme o volume 
 if (sensorValue <= 10 || sensorValue <12) {
  analogWrite(ledVerde, 255);
 } else if (sensorValue <= 12 || sensorValue <15){
  analogWrite(ledAmarelo1, 255);
  analogWrite(ledVerde, 255);
 } else if (sensorValue <= 15 || sensorValue <18){
  analogWrite(ledAmarelo2, 255);
  analogWrite(ledAmarelo1, 255);
  analogWrite(ledVerde, 255);
 } else if (sensorValue <= 18 || sensorValue <20){
  analogWrite(ledVermelho1, 255);
  analogWrite(ledAmarelo2, 255);
  analogWrite(ledAmarelo1, 255);
  analogWrite(ledVerde, 255);
 } else if (sensorValue <= 20 || sensorValue <25){
  analogWrite(ledVermelho2, 255);
  analogWrite(ledVermelho1, 255);
  analogWrite(ledAmarelo2, 255);
  analogWrite(ledAmarelo1, 255);
  analogWrite(ledVerde, 255);
 } else if (sensorValue <= 25 || sensorValue <30){
  analogWrite(ledVermelho3, 255);
  analogWrite(ledVermelho2, 255);
  analogWrite(ledVermelho1, 255);
  analogWrite(ledAmarelo2, 255);
  analogWrite(ledAmarelo1, 255);
  analogWrite(ledVerde, 255);
 } else if (sensorValue <= 30 || sensorValue >30){
  analogWrite(ledVermelho4, 255);
  analogWrite(ledVermelho3, 255);
  analogWrite(ledVermelho2, 255);
  analogWrite(ledVermelho1, 255);
  analogWrite(ledAmarelo2, 255);
  analogWrite(ledAmarelo1, 255);
  analogWrite(ledVerde, 255);
 }
 

  // Delay para estabilidade
  delay(150);  

  // Reset dos leds
  analogWrite(ledVermelho4, 0);
  analogWrite(ledVermelho3, 0);
  analogWrite(ledVermelho2, 0);
  analogWrite(ledVermelho1, 0);
  analogWrite(ledAmarelo2, 0);
  analogWrite(ledAmarelo1, 0);
  analogWrite(ledVerde, 0);
}
