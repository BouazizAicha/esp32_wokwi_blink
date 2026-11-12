#include <Arduino.h>

const int pinLED = 23;     // Broche connectée à la LED
const int pinBouton = 16;  // Broche connectée au bouton-poussoir

void setup() {
  // 1. Configurer la broche de la LED en sortie
  pinMode(pinLED, OUTPUT);

  // 2. Configurer la broche du bouton avec la résistance de rappel interne
  pinMode(pinBouton, INPUT_PULLUP);

  // 3. Initialiser la communication série à 115200 bauds
  Serial.begin(115200);

  // 4. Afficher le message de bienvenue dans le moniteur série
  Serial.println("Hello, ESP32!");
}

void loop() {
  // Lire l'état du bouton-poussoir
  int etatBouton = digitalRead(pinBouton);

  // Si le bouton est appuyé (valeur lue LOW)
  if (etatBouton == LOW) {
    digitalWrite(pinLED, HIGH); // Allumer la LED
    delay(1000);                // Attendre une seconde (1000 ms)
  }

  // Dans tous les cas, éteindre la LED et attendre une seconde
  digitalWrite(pinLED, LOW);
  delay(1000);
}
