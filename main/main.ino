#include <MsTimer2.h> // inclusion de la librairie Timer2
#include "function_software.h"
#include "phase.h"
#include "configuration.h"
#include "function_hardware.h"
#include "screen.h"


signed int listeTimerIncrement[8];
signed int listeTimerDecrement[8];

int configValue[8];

byte listeTimerIncrementEnable;
byte listeTimerDecrementEnable;

int nbTimerIncrement=0;
int nbTimerDecrement=0;

#include "scenario.h"
#include "kernel.h"

void setup() {
  // initialisation interruption Timer 2
  MsTimer2::set(500, InterruptTimer2); // période 1000ms 
  MsTimer2::start(); // active Time
  
  Serial.begin(baudrate);

  if(debug) Serial.println("start init"); 
  initLcd();

  // OUTPUT
  pinMode(pin_bip, OUTPUT);
  pinMode(pin_boum, OUTPUT);
  pinMode(pin_led_green, OUTPUT);
  pinMode(pin_led_red, OUTPUT);

  // INPUT
  pinMode(pin_cle, INPUT_PULLUP);
  pinMode(pin_cable, INPUT_PULLUP);
  pinMode(pin_switch, INPUT_PULLUP);
  pinMode(pin_inclinaison, INPUT_PULLUP);

  // choix du mode de jeu
  if(debug) Serial.println("start config"); 
  captureConfig();
  if(debug) Serial.println("Fin config");
  if(debug) Serial.println("start init"); 
}

void loop() {
  kernel();
}

void InterruptTimer2(){
  if(debug){
  Serial.println("interruption");
  Serial.print("listeTimerIncrementEnable ");
  Serial.println(listeTimerIncrementEnable,BIN);
  Serial.print("listeTimerDecrementEnable ");
  Serial.println(listeTimerDecrementEnable,BIN);
  }
  
  for(int index=0; index<8; index++){
    if(BB_READ(listeTimerIncrementEnable, 1<<index) ){
      listeTimerIncrement[index]++;
      if(debug){
        Serial.print("listeTimerIncrement ");
        Serial.print(index);
        Serial.print(" ");
        Serial.println(listeTimerIncrement[index]);
      }
    }
  }
  
  for(int index=0; index<8; index++){
    if(BB_READ(listeTimerDecrementEnable, 1<<index )){
      listeTimerDecrement[index]--;
      if(debug){
        Serial.print("listeTimerDecrement ");
        Serial.print(index);
        Serial.print(" ");
        Serial.println(listeTimerDecrement[index]);
      }
    }
  }
  
  if(buzzerEnable){
    bip();
  }
  
  print();
}


