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

int led2 = 11;
long toggletime2 = 0;
int timeout2 = 500;
int ledStatus2 = LOW;

void toggleLed(int led, int& ledStatus) {
  
  if ( ledStatus == HIGH ) {
    ledStatus = LOW;
  }
  else {
    ledStatus = HIGH;
  }

  digitalWrite(led, ledStatus);
}

void processLed(int led, int& ledStatus, int timeout, long& toggletime) {

  long t = millis();
  if ( t - toggletime >= timeout ) {
    // Poiche' e' scaduto il timeout,
    // eseguiamo il toggle del led
    toggleLed(led, ledStatus);

    // Inoltre aggiorniamo la variabile che ci
    // serve per ricordare l'istante da cui
    // calcolare il prossimo timeout
    toggletime = t;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  processLed(led1, ledStatus1, timeout1, toggletime1);
  processLed(led2, ledStatus2, timeout2, toggletime2);
}

