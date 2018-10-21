#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(LCD_adresse);  // set the LCD address to 0x27 for a 16 chars and 2 line display

char ligne1[17];
char ligne2[17];

char oldLigne1[17];
char oldLigne2[17];

//--- Définition des touches
char touches[LIGNES][COLONNES] = {
  {'1','2','3','a'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','e'}
};

// tableaux de lignes et colonnes
byte BrochesLignes[LIGNES] = {L1, L2, L3, L4}; //connexions utilisées pour les broches de lignes du clavier
byte BrochesColonnes[COLONNES] = {C1, C2, C3, C4}; //connexions utilisées pour les broches de colonnes du clavier

char touche; // variable de stockage valeur touche appuyée
Keypad clavier = Keypad( makeKeymap(touches), BrochesLignes, BrochesColonnes, LIGNES, COLONNES );

void initLcd(){
  Wire.begin();
  Wire.beginTransmission(0x3F);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home(); 
  lcd.clear();
}

 void print(){
  if(strcmp(oldLigne1,ligne1)!=0 || strcmp(oldLigne2,ligne2)!=0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(ligne1);
    
    lcd.setCursor(0, 1);
    lcd.print(ligne2);

    //if(debug)Serial.println(ligne1);
    //if(debug)Serial.println(ligne2);


    memcpy(oldLigne1, ligne1, 17);
    memcpy(oldLigne2, ligne2, 17);
  }
}

void setLigne1( const void * value){
  memcpy(ligne1,value, 17);
}

void setLigne2( const void * value){
  memcpy(ligne2,value, 17);
}

void bip(int nb=1){
  tone(pin_bip, tone_bip, 200);
}

void boum(int nb=1){
  for(int i=0; i<nb; i++){
    digitalWrite(pin_boum, HIGH);
    delay(1000);
    digitalWrite(pin_boum, LOW);
    if(i!=nb-1) delay(300);
  }
}

void explosion(){
  boum(5);
  setLigne1("BOUUUUM");
  setLigne2("PERDU");
  print();
  while(1){}
}

void ledChangeColor(){
  if(BB_READ(ledPACK, BB_led_red) ){
    digitalWrite(pin_led_red, LOW);
    digitalWrite(pin_led_green, HIGH);
    BB_TRUE(ledPACK,BB_led_green);
    BB_FALSE(ledPACK,BB_led_red);
  }else if(BB_READ(ledPACK, BB_led_green)){
    digitalWrite(pin_led_red, HIGH);
    digitalWrite(pin_led_green, LOW);
    BB_TRUE(ledPACK,BB_led_red);
    BB_FALSE(ledPACK,BB_led_green);
  }else{
    digitalWrite(pin_led_red, LOW);
    digitalWrite(pin_led_green, HIGH);
    BB_TRUE(ledPACK,BB_led_green);
    BB_FALSE(ledPACK,BB_led_red);
  }
}

void ledOff(){
  digitalWrite(pin_led_red, LOW);
  digitalWrite(pin_led_green, LOW);
}

void ledRed(){
  digitalWrite(pin_led_red, HIGH);
  digitalWrite(pin_led_green, LOW);
}

void ledGreen(){
  digitalWrite(pin_led_red, LOW);
  digitalWrite(pin_led_green, HIGH);
}


