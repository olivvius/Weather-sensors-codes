
//0-45 — completement sec
// 620 maximum humidite sol constate

// Capteur humidite sol
// Connecter pin + a pin allumage_captsol qui sert d'allumage intermittent du capteur (pour pb corrosion)
// Connecter pin - a GND
// Connect pin S au data = capteurhumsol

const int capteurhumsol = A1;
const int allumage_captsol = 2; 
int mesurehumsol = 0;
int humsol = 0;
const int max_humsol = 620;

void setup() {
Serial.begin(9600);
pinMode(allumage_captsol, OUTPUT);
digitalWrite(allumage_captsol, LOW);
}


void loop() {
delay(1000);


digitalWrite(allumage_captsol, HIGH);  
delay(10);
mesurehumsol = analogRead(capteurhumsol);

digitalWrite(allumage_captsol, LOW);
  
humsol = map(mesurehumsol, 0, max_humsol, 0, 100);

Serial.print("valeur numérique = " );
Serial.print(mesurehumsol);

Serial.print(" humidité sol = " );
Serial.println(humsol);
}
