//sketch di eempio per accendere e spegnere un led e regolarne la luminosità 
//con un potenziometro da 10k

#define LED 9                // LED collegato al pin digitale 13  
#define BUTTON 7              // pin di input dove è collegato il pulsante  
#define POT A0
int  val = 0;                 // si userà val per conservare lo stato del pin di input
int  lastVal = LOW;
int changed = 0;
int i = 0;
int o = 0;


void setup() {
  Serial.begin(115200);
  pinMode(POT, INPUT); // pin potenziometro
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input
  digitalWrite(LED, LOW);
  lastVal = LOW;
  changed = 0;
}

void loop() {
  val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva
  i = analogRead(POT); // legge il valore analogico del
  o = map(i, 0, 1023, 0, 255);
  if (val == HIGH && lastVal == LOW && changed == 0) {
    changed = 1;


  }
  else if ( val == HIGH && changed == 1 && lastVal == LOW) {
    changed = 0;

  }
  else if (val == LOW && changed == 1) {
    //if (i > 0 && i < 255) {
      analogWrite(LED, o);
    //}
  }
  else if (val == LOW && changed == 0) {
    analogWrite(LED, LOW);
  }
  if (val != lastVal) {
    lastVal = val;
  }
  Serial.println(i);

}
