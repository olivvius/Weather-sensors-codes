//calibre mentionné dans le datasheet pluviometre : 0.2794 mm de pluie créé un contact digital

// Capteur pluviometrie
// Connecter pin 1 (fil rouge) du capteur a capteur_pluie
// Connecter pin 2 (fil vert) a +5V
// Connecter pin 1 (fil rouge) du capteur vers resistance 10K puis GND
// Connecter pin 1 (fil rouge) du capteur vers condensateur 100 nF puis GND pour eviter les rebonds

const int capteur_pluie = 0; //correspond a pin 2: capteur attacheinterupt sur une Uno ou Mega
const int tempsmesurepluie = 3;      //Temps de mesure de la pluie en seconde
int pluie_ct = 0;           // compteur d'impulsion de pluie
float pluie = 0.0;          // valeur de pluviometrie
unsigned long time = 0;
const float calibrepluie = 0.2974;

void setup()
{
  Serial.begin(9600);
  time = millis();
}

void loop()
{
 pluie_ct = 0;
  time = millis();
  attachInterrupt(capteur_pluie, compteurpluie, RISING);
  delay(1000 * tempsmesurepluie);
  detachInterrupt(capteur_pluie);
  pluie = (float)pluie_ct / (float)tempsmesurepluie * calibrepluie;

  Serial.print("Pluie: ");
  Serial.print(pluie);   
  Serial.println(" mm");
}

void compteurpluie() {
  pluie_ct ++;
}
