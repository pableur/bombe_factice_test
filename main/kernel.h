void lectureClavier(){
  //if(debug)Serial.println("lectureClavier");
  touche = clavier.getKey();
    if (touche != NO_KEY){
    Serial.println(touche);
    }
}

void lectureBouton(){
  bool sensorVal = digitalRead(pin_switch);
 
  BB_FALSE(boolPack, BB_btn_press);
  BB_FALSE(boolPack, BB_btn_relax);

  // si changement d'état
  if(sensorVal != BB_READ(boolPack, BB_btn)){
    // si appuis 
    if(sensorVal){
      BB_TRUE(boolPack, BB_btn_press);
      BB_TRUE(boolPack, BB_btn);
      Serial.println("bouton relache");
    }else{
      BB_TRUE(boolPack, BB_btn_relax);
      BB_FALSE(boolPack, BB_btn);
      Serial.println("bouton appuis");
    }
  }
}

void secousse(){
  bool sensorVal = digitalRead(pin_inclinaison);
  BB_FALSE(boolInclinaisonPack, BB_inc_press);
  BB_FALSE(boolInclinaisonPack, BB_inc_relax);

  // si changement d'état
  if(sensorVal != BB_READ(boolInclinaisonPack, BB_btn)){
    // si appuis 
    if(sensorVal){
      BB_TRUE(boolInclinaisonPack, BB_inc_press);
      BB_TRUE(boolInclinaisonPack, BB_inc_btn);
      Serial.println("secousse relache");
    }else{
      BB_TRUE(boolInclinaisonPack, BB_inc_relax);
      BB_FALSE(boolInclinaisonPack, BB_inc_btn);
      Serial.println("secousse appuis");
    }
  }
}


void lectureDB9(){
}

void refresh(){  
  //if(debug)Serial.println("Refresh");
  print(); // mise a jour de l'écran
}

void (*Fonction[])(void)={lectureClavier, lectureBouton, refresh,  lectureDB9, secousse};
byte nbFonction=5;
byte nextPhase=0;
int oldPhase=0;
bool initialiastion=false;

void kernel(){
	for(byte index=0; index<nbFonction; index++){
	  Fonction[index]();
	}

 // premiere boucle sans lancer les phases pour initialiser l'état des fonctions
 if(initialiastion){
  nextPhase=listePhase[nextPhase]->nextPhase();
  if(nextPhase!=oldPhase){
    Serial.print("Prochaine phase ");
    Serial.println(nextPhase);
    oldPhase=nextPhase;
  }
 }
 else{
  initialiastion=true;
 }
}


