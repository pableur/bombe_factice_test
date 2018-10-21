Phase *listePhase[8]; // tableau de toute les phases

void captureConfig(){
  // configuration utilisateur
  setLigne1("Temps phase 1");
  int tpsAmorcage = read_temps();
  configValue[0]=tpsAmorcage;

  setLigne1("Temps phase 2");
  int tpsDesamorcage = read_temps();
  configValue[1]=tpsDesamorcage;

  ///////////////////////////////////////////////////////////////////
  // phase amorcage
  ///////////////////////////////////////////////////////////////////
    listePhase[0]=new Phase();
    listePhase[0]->numPhase=0;
    listePhase[0]->setInitPhase(
      [=](){
        buzzerEnable=true;
        BB_TRUE(listeTimerDecrementEnable,1);
        listeTimerDecrement[0]=configValue[0];
        return true;
      } 
    );

    // jusqu'a la fin du chrono
      listePhase[0]->phaseReussite=3;
      listePhase[0]->setConditionReussite([](){
        if(listeTimerDecrement[0]==0){return true;}
        else{return false;}
        });
        
    //activation de la clé
      listePhase[0]->phaseEchec=1;
      listePhase[0]->setConditionEchec([](){
        if(BB_READ(boolInclinaisonPack, BB_inc_press)==1){return true;}
        else{return false;}});
    
    listePhase[0]->setAction([](){
      setLigne1("Phase 1");
      setLigne2(charClock(listeTimerDecrement[0]).c_str());
      
      return true;
      });
      
  ///////////////////////////////////////////////////////////////////
  // phase desamorcage
  ///////////////////////////////////////////////////////////////////
  listePhase[1]=new Phase();
  listePhase[1]->numPhase=1;
  listePhase[1]->setInitPhase(
      [=](){
        buzzerEnable=true;
        BB_FALSE(listeTimerDecrementEnable,1);
        BB_TRUE(listeTimerDecrementEnable,2);
        listeTimerDecrement[1]=configValue[1];
        ledOff();
        return true;
      } 
    );
    // jusqu'a la fin du chrono
      listePhase[1]->phaseReussite=2;
      listePhase[1]->setConditionReussite([](){
        if(listeTimerDecrement[1]==0){return true;}
        else{return false;}
        });
    //si cable coupé
      listePhase[1]->phaseEchec=3;
      listePhase[1]->setConditionEchec([](){
        if(BB_READ(boolPack, BB_btn_press)){return true;}
        else{return false;}
        });
    
  listePhase[1]->setAction([](){
      setLigne1("Phase 2");
      setLigne2(charClock(listeTimerDecrement[1]).c_str());
      ledChangeColor();
      return true;
      });
    
  ///////////////////////////////////////////////////////////////////
  // phase perdu
  ///////////////////////////////////////////////////////////////////
  listePhase[2]=new Phase();
  listePhase[2]->numPhase=2;
  listePhase[2]->setInitPhase([](){ledRed();buzzerEnable=false;return true;} );
  // jusqu'a la fin du chrono
    listePhase[2]->phaseReussite=2;
    listePhase[2]->setConditionReussite([](){return true;});

    listePhase[2]->phaseEchec=2;
    listePhase[2]->setConditionEchec([](){return false;});
  
  listePhase[2]->setAction([](){
    setLigne1("perdu");
    setLigne2("");
    return true;});

  ///////////////////////////////////////////////////////////////////
  // phase gagné
  ///////////////////////////////////////////////////////////////////
  listePhase[3]=new Phase();
  listePhase[3]->numPhase=3;
  listePhase[3]->setInitPhase([](){ledGreen();buzzerEnable=false;return true;} );
  // jusqu'a la fin du chrono
    listePhase[3]->phaseReussite=3;
    listePhase[3]->setConditionReussite([](){return true;});

    listePhase[3]->phaseEchec=3;
    listePhase[3]->setConditionEchec([](){return false;});
  
  listePhase[3]->setAction([](){
    setLigne1("gagne");
    setLigne2("");
    return true;});
}

