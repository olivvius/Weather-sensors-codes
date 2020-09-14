// Capteur photoresistane
// Connecter patte 1 a  pin analogique capteur_lum
// Connecter patte 1 a resistance 10K puis vers GND
// Connecter patte 2  a +5V

int capteur_lum = A2; // la photorésistance est connecté au pin A0
int lum; // lecture de la photorésistance

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  lum = map(analogRead(capteur_lum),0, 1023, 0, 100);
  
//  Serial.print("Valeur numérique luminosite ");
//  Serial.print(analogRead(capteur_lum)); // lecture de la photoresistance
  Serial.print(" Luminosite: ");
  Serial.print(lum);
  Serial.println("%");
  delay(1000); // lire toute les secondes
}
