//****** Real Bit Level Boolean Utilisation Macro Definitions  ***********
//****** Created by Trevor D.BEYDAG 09 May 2016                ***********
//****** http://lab.dejaworks.com                              ***********
//****** Please keep credits intact when using and/or reproducing ********
//****** http://lab.dejaworks.com/using-real-1-bit-boolean-variable-for-arduino-memory-efficiency/
//************************************************************************
#define BB_TRUE(bp,bb)    bp |= bb
#define BB_FALSE(bp,bb)   bp &= ~(bb)
#define BB_READ(bp,bb)    bool(bp & bb)
 
// Boolean variable definitions are here
#define BB_LED_RED       1
#define BB_LED_ORANGE    2
#define BB_LED_GREEN     4
#define BB_LED_BLUE      8
#define BB_ANY           16
#define BB_OTHER         32
#define BB_VAR1          64
#define BB_VAR2          128
 
// This is one byte variable which contains 8 boolean, so 7 bytes saved!
// If you need more boolean variable you can add another boolPack e.g. boolPack2
// With this method; 24 boolean variable can be stored in 3 bytes intead of 24bytes in SDRAM memory!
byte boolPack = 0;
//BB_TRUE(boolPack, BB_LED_ORANGE);
//BB_READ(boolPack, BB_LED_BLUE);

bool buzzerEnable = false;

#define BB_btn 1
#define BB_btn_press 4
#define BB_btn_relax 2
byte boutonPACK=0;

#define BB_inc_btn 1
#define BB_inc_press 4
#define BB_inc_relax 2
byte boolInclinaisonPack=0;

#define BB_led_red 1
#define BB_led_green 2
byte ledPACK=0;

