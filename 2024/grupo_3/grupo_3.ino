// Definição dos pinos
#define TRIG_PIN 9          // Pino TRIG do HC-SR04
#define ECHO_PIN 10         // Pino ECHO do HC-SR04
#define SOUND_PIN A0        // Pino do sensor de som KY-037
#define LED_GREEN 3         // Pino do LED verde
#define LED_YELLOW 5        // Pino do LED amarelo
#define LED_RED 7          // Pino do LED vermelho
#define BUZZER_PIN 12        // Pino do buzzer

int DO = 261;
int RE = 294;
int MI = 329;
int FA = 349;
int SOL = 392;
int LA = 440;
int SI = 493;

void tocarNota(int nota, int duracao) {
  tone(BUZZER_PIN, nota, duracao); // Toca a nota no buzzer
  delay(duracao); // Espera a duração da nota
  noTone(BUZZER_PIN); // Para o som
  delay(50); // Pequeno intervalo entre as notas
}

// Limite de distância (em cm)
#define DISTANCE_THRESHOLD 20

// Limite de sensibilidade do som
#define SOUND_THRESHOLD 2100
void setup() {
  // Configuração de pinos
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Inicialização do monitor serial (opcional para depuração)
  Serial.begin(9600);
}

void loop() {
  // Medir a distância
  float distance = measureDistance();
  Serial.print(distance );
   Serial.print("\n");
  // Ler o nível de som
  int soundLevel = analogRead(SOUND_PIN)*(150.0);
  Serial.print(soundLevel);
 Serial.print("\n");
  
   // Lógica de LEDs e buzzer
  if (distance < DISTANCE_THRESHOLD) {
    activateLED(LED_GREEN);   // Acende o LED verde
    deactivateLED(LED_RED);   // Apaga o LED vermelho
    deactivateBuzzer();       // Desativa o buzzer
  } else {
    activateLED(LED_RED);     // Acende o LED vermelho
    deactivateLED(LED_GREEN); // Apaga o LED verde
    activateBuzzer();         // Ativa o buzzer
  }
/*  
  activateLED(LED_RED);     // Acende o LED vermelho
  deactivateLED(LED_GREEN); // Apaga o LED verde
  activateBuzzer();         // Ativa o buzzer

  while (distance < DISTANCE_THRESHOLD){
    activateLED(LED_GREEN);   // Acende o LED verde
    deactivateLED(LED_RED);   // Apaga o LED vermelho
    deactivateBuzzer();       // Desativa o buzzer
  }
*/

  if (soundLevel < SOUND_THRESHOLD) {
    activateLED(LED_YELLOW);  // Acende o LED amarelo
  } else {
    deactivateLED(LED_YELLOW); // Apaga o LED amarelo
  }

  // Pequena pausa antes do próximo loop
  delay(250);
}

// Função para medir a distância usando o HC-SR04
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Calcular a duração do pulso ECHO
  float duration = pulseIn(ECHO_PIN, HIGH);

  // Converter duração em distância (cm)
  return (duration * 0.034 / 2); // Fórmula para calcular a distância
}

// Função para ativar um LED
void activateLED(int ledPin) {
  digitalWrite(ledPin, HIGH);
}

// Função para desativar um LED
void deactivateLED(int ledPin) {
  digitalWrite(ledPin, LOW);
}

// Função para ativar o buzzer
void activateBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}

// Função para desativar o buzzer
void deactivateBuzzer() {
  digitalWrite(BUZZER_PIN, LOW);
}

