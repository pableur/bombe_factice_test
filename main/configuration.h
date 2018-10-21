// SOFTWARE
#define periode 800 // période ajustable de la bombe en ms qui doit être pour 1s
#define baudrate 250000 // vitesse de la liaison série
#define debug  true

// HARDWARE
// definition des PIN de l'arduino 
#define pin_bip A1  // pin connecté au buzzer
#define pin_boum A3 // pin connecté à l'alarme
#define pin_cle 13  // pin connecté à l'interrupteur de clé
#define pin_cable 12  // pin connecté aux cables à couper
#define pin_switch A0 // pin connecté à l'interrupteur
#define pin_inclinaison A2 // pin connecté au capteur d'inclinaison
#define pin_led_green 10     // pin connecté a la led verte
#define pin_led_red   11     // pin connecté a la led rouge
#define LCD_adresse 0x27
#define tone_bip 2000

// configuration du clavier
#define LIGNES  4 // 4 lignes
#define COLONNES  4 //4 colonnes

#if debug==false
  #define C4 2
  #define C3 3
  #define C2 4
  #define C1 5
  #define L4 6
  #define L3 7
  #define L2 8
  #define L1 9
#else
  #define C4 9
  #define C3 8
  #define C2 7
  #define C1 6
  #define L4 5
  #define L3 4
  #define L2 3
  #define L1 2
#endif


