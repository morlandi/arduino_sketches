/*
Inizialmente utilizziamo un solo led, e sono 
quando il codice e' opportunamente fattorizzato
introduciamo un secondo (o piu') led.

Questa prima versione non usa il multithreading
e quindi l'azione sul led "blocca" il loop
principale, che non puo' fare nessuna altra attivita'
concorrente.
*/

int led1 = 12;

void processLed(int led) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
}

void setup() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
}

void loop() {
    processLed(led1);
    Serial.print("millis: ");
    Serial.println(millis());
}
          
