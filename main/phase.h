class Phase{
  public:
    byte phaseReussite=0;
    byte phaseEchec=0;
    byte numPhase=0;

    bool initStat=false;

    bool (*conditionReussite)();
    bool (*conditionEchec)();
    bool (*action)();
    bool (*initPhase)();

    void setConditionReussite(bool (*ptrfonction)()){
      conditionReussite=ptrfonction;
    }
    void setConditionEchec(bool (*ptrfonction)()){
      conditionEchec=ptrfonction;
    }
    void setAction(bool (*ptrfonction)()){
      action=ptrfonction;
    }

    void setInitPhase(bool (*ptrfonction)()){
      initPhase=ptrfonction;
    }

  byte nextPhase(){

    if(initStat==false){
      initStat=true;
      (initPhase)();
    }
    
    (action)();  // appel du pointeur vers la fonction action qui a été assigné
    if(conditionReussite() ){
      return phaseReussite;
    }
    
    if(conditionEchec() ){
      return phaseEchec;
    }
    return numPhase; // retourne son numéro de phase pour rester dedans
  }
};

