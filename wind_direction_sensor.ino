// N = 887 - NE = 815 - E = 930 - SE = 865 - S = 946 - SO = 790 - O = 845 - NO = 750

// Capteur direction du vent
// Connecter pin 1 (fil rouge) du capteur a capteur_direction
// Connecter pin 2 (fil vert) a GND
// Connecter pin 1 (fil rouge) du capteur vers resistance 10K puis +5V

const int capteur_direction = A3;
int mesuredirection;
String direction_vent = "rien";
String nord = "Nord";
String nordest = "Nord-Est";
String est= "Est";
String sudest = "Sud-Est";
String sud = "Sud"; 
String sudouest = "Sud-Ouest";
String ouest = "Ouest";
String nordouest = "Nord-Ouest";

void setup() {
Serial.begin(9600);

}

void loop() {
mesuredirection = analogRead(capteur_direction);
//Serial.println(mesuredirection);
delay(1000);
if (mesuredirection > 880 && mesuredirection < 900) {
direction_vent = nord;
}
else if (mesuredirection > 800 && mesuredirection < 835) {
direction_vent = nordest;
}
else if (mesuredirection > 920 && mesuredirection < 937) {
direction_vent = est;
}
else if (mesuredirection > 856 && mesuredirection < 879) {
direction_vent = sudest;
}
else if (mesuredirection > 938 && mesuredirection < 970) {
direction_vent = sud;
}
else if (mesuredirection > 770 && mesuredirection < 799) {
direction_vent = sudouest;
}
else if (mesuredirection > 836 && mesuredirection < 855) {
direction_vent = ouest;
}
else if (mesuredirection > 720 && mesuredirection < 769) {
direction_vent = nordouest;
}

Serial.print(F(" Direction du vent: "));
Serial.println(direction_vent);

}
