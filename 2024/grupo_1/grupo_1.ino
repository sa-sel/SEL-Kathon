// Pinos usados
#define LED1 6
#define LED2 7
#define LED3 8
#define LED4 9
#define TRIGGER 11
#define ECHO 12
#define BUZZER 3

#define tempo 260
#define songLength 31
char notes[] = "eee eee egcde fff ffee eeggfdc " ;
int beats[] = {2,2,3,1, 2,2,3,1, 2,2,3,1,4,4, 2,2,3,0, 1,2,2,2,0, 1,1,2,2,2,2,4,4};
 
// Constantes utilizadas
const float som = 34300.0; // Velocidade do som em cm/s
const float limite1 = 30.0; // Limites de distância em cm
const float limite2 = 20.0;
const float limite3 = 10.0;
const float limite4 = 5.0;
 
void setup() {
 
Serial.begin(9600);
 
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(ECHO, INPUT);
pinMode(TRIGGER, OUTPUT);
pinMode(BUZZER, OUTPUT);
 
desligarLEDs();
 
}
 
void loop() {
 
inicializarTrigger();
float distancia = calcularDistancia ();
desligarLEDs();
if (distancia < limite1){
alertas(distancia);
}
 
}
 
// Função de desligar os LEDs
void desligarLEDs()
{
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
}
 
// Verifique se algum alerta visual ou sonoro é necessário
void alertas (float distancia){
 
// Se a distância estiver entre o limite1 e o limite2
if (distancia < limite1 && distancia >= limite2){
 
// Ligue o LED 1
digitalWrite(LED1, HIGH);
tone(BUZZER, 1500, 50);
}
 

else if (distancia < limite2 && distancia >= limite3){
 
// Ligue o LED 2
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
tone(BUZZER, 2000, 100);
}
 

else if (distancia < limite3 && distancia >= limite4){
 
// Ligue o LED 3
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, HIGH);
tone(BUZZER, 2750, 150);
}
 

else if (distancia < limite4){
 
// Ligue o LED 4
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
digitalWrite(LED3, HIGH);
digitalWrite(LED4, HIGH);
int i, b, duration;

  
  for (i = 0; i < songLength; i++) 
  {
    duration = beats[i] * tempo;  
    
    if (notes[i] == ' ')         
    {
      delay(duration);           
    }
    else                         
    {
      tone(BUZZER, frequency(notes[i]), duration);
      digitalWrite(13, HIGH);
      delay(duration);            
    }
    digitalWrite(13, LOW);
    delay(tempo/10);             
  }
}
}

int frequency(char note) 
{
  
  
  int i;
  const int numNotes = 8;  
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {528, 592, 665, 704, 791, 888, 997, 1056};
  

  
  for (i = 0; i < numNotes; i++)  
  {
    if (names[i] == note)         
    {
      return(frequencies[i]);     
    }
  }
  return(0);  
}


// Função usada para calcular a distância entre o som e o objeto
float calcularDistancia(){
unsigned long time = pulseIn(ECHO, HIGH);
float distancia = time* 0.000001 * som / 2.0;
Serial.print(distancia);
Serial.print("cm");
Serial.println();
delay(500);
return distancia;
}
 

void inicializarTrigger(){
digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(15);
digitalWrite(TRIGGER, LOW);
}