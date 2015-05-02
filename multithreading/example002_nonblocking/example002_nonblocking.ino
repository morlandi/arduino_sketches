/*
Inizialmente utilizziamo un solo led, e sono
quando il codice e' opportunamente fattorizzato
introduciamo un secondo (o piu') led.

Complichiamo processLed() affinche' sia in grado di capire
se deve cambiare o meno lo stato del led, e in entrambi i casi
(sia se deve farlo che no) ritorni subito (quindi senza delay());
in questo modo il loop principale recupera subito il controllo
della CPU e puo' eseguire altre attivita'
*/

int led1 = 12;
long toggletime1 = 0;
int timeout1 = 1000;
int ledStatus1 = LOW;

void toggleLed(int led) {
  /* Se e' spento, accendo;
     se e' acceso, spengo
  */

  Serial.print("toggleLed(); led vale: ");
  Serial.println(led);

  if ( ledStatus1 == HIGH ) {
    ledStatus1 = LOW;
  }
  else {
    ledStatus1 = HIGH;
  }

  digitalWrite(led, ledStatus1);
}

void processLed(int led) {
  
  long t = millis();
  if ( t - toggletime1 >= timeout1 ) {
    // Poiche' e' scaduto il timeout,
    // eseguiamo il toggle del led
    toggleLed(led);

    // Inoltre aggiorniamo la variabile che ci
    // serve per ricordare l'istante da cui
    // calcolare il prossimo timeout
    toggletime1 = t;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  processLed(led1);
  //Serial.print("millis: ");
  //Serial.println(millis());
}

