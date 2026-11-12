#include <Arduino.h>
#include <WiFi.h>

// Remplacez par les identifiants de votre réseau Wi-Fi
// Sur Wokwi, utilisez le réseau virtuel "Wokwi-GUEST" sans mot de passe ("")
const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {
  // 1. Initialiser la communication série à 115200 bauds
  Serial.begin(115200);
  delay(1000);

  // 2. Configurer l'ESP32 en mode Station (client Wi-Fi)
  WiFi.mode(WIFI_STA);

  // 3. Lancer la connexion au point d'accès
  Serial.print("Connexion au réseau : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // 4. Attendre que la connexion soit établie
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // 5. Afficher la confirmation et l'adresse IP obtenue
  Serial.println("");
  Serial.println("Connexion Wi-Fi réussie !");
  Serial.print("Adresse IP de l'ESP32 : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Rien à répéter pour ce test de connexion
}
