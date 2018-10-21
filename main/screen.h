 bool choix(){
  bool sortir = false;
  bool choix_value = true;
  while(sortir==false){
    if(choix_value) setLigne2((">oui  non"));
    else            setLigne2((" oui >non"));
    print();
    touche = clavier.getKey();
    if (touche != NO_KEY){
      Serial.println(touche);
      char temp = touche;
      if(temp == '\n' || temp == '\r'){ }
      else{ bip();}
      if(temp=='e'){sortir = true;}
      else if(temp=='e'){
        choix_value=false;
        sortir = false;
       }
      else if (temp=='*'){
        choix_value=true;
      }
      else if (temp=='#'){
        choix_value=false;
      }
    }
  }
  return choix_value;
}

byte charToByte(String temp_str){
  char temp_char[2]={' ','\0'};
  memcpy(temp_char,temp_str.c_str(), 2);
  return atoi((temp_char));
}

double read_temps(bool heure=true, bool minute=true, bool seconde = true ){
  bool continu = true;
  byte heure_int = 0;
  byte minute_int = 0;
  byte seconde_int = 0;
  
  if(heure){
    continu = false;
    while(continu ==false){
      setLigne2(("heure :"+String(heure_int)).c_str());
      print();
      touche = clavier.getKey();
      if (touche != NO_KEY){
        if(touche == '\n' || touche == '\r'){ }
        else{ 
          bip();
          if(touche =='e' ){
            continu = true;
          }
          else{
            heure_int =charToByte(String(heure_int)+String(touche));
          }
        }
      }
    }
  }
    if(minute){
      continu = false;
      while(continu ==false){
        setLigne2(("min :"+String(minute_int)).c_str());
        print();
        touche = clavier.getKey();
        if (touche != NO_KEY){
          if(touche == '\n' || touche == '\r'){ }
          else{ 
            bip();
            if(touche =='e' ){
              continu = true;
            }
            else{
              minute_int =charToByte(String(minute_int)+String(touche));
            }
          }
        }
      }
    }
    if(seconde){
      continu = false;      
      while(continu ==false){
        setLigne2(("sec :"+String(seconde_int)).c_str());
        print();
        touche = clavier.getKey();
        if (touche != NO_KEY){
          if(touche == '\n' || touche == '\r'){ }
          else{ 
            bip();
            if(touche =='e' ){
              continu = true;
            }
            else{
              seconde_int =charToByte(String(seconde_int)+String(touche));
            }
          }
        }
      }
    }

    if(minute_int>59) minute_int=59;
    if(seconde_int>59)seconde_int=59;
    
    setLigne2((String(heure_int)+"h "+String(minute_int)+"min "+String(seconde_int)+"s").c_str());
    print();
    continu=false;
     while(continu ==false){
      touche = clavier.getKey();
      if (touche != NO_KEY){
        char temp = touche;
        if(temp == '\n' || temp == '\r'){ }
        else{ 
          bip();
          if(temp =='e' ){
            continu = true;
          }
          if (temp =='a' ){
            return read_temps(heure, minute, seconde);
          }
        }
      }
     }
     if(debug)Serial.println((String(heure_int)+"h "+String(minute_int)+"min "+String(seconde_int)+"s").c_str());
     return heure_int*3600 + minute_int*60+seconde_int;
}

String charClock(unsigned int value){
  byte heure   = value/3600;
  byte minute  = (value-(3600*heure))/60;
  byte seconde = value-(heure*3600+minute*60);

  return (String(heure)+":"+String(minute)+":"+String(seconde)+"s").c_str();
}

