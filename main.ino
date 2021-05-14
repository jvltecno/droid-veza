//-------------------------------Includes--------------------------------------------------------------------------------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas


//-------------------------------Constantes------------------------------------------------------------------------------------

//-------------------------------Char Specified-------------------------------------------------------------------------------

//-------------------------------Variables-------------------------------------------------------------------------------------
float mash[];
float temp;
float tempWashing;
float tempLevature;
byte timeHervor;
byte timeAddit [5];


//app
void setup(){
	lcd.begin();                      
	lcd.backlight();


	delay(2500);
}

 
void loop(){
   set();
   mash();
   boil();

}

/*-------------------------------Functions------------------------------------------------------------------------------------*/
void set(){
    lcd.setCursor(0,0);
    lcd.print("   Bienvenido   ");
    lcd.setCursor(0,1);
    lcd.print(" a Droid-veza   ");

}
void mash(){
    if(timeMeter-)
}

void boil (){

}



//-------------------------------cd--------------------------------------------------------------------------------------------

//--------------------------------Termocupla-------------------------------------------------------------------------------------
void tempConcurrent(){
    temp=;//revisar termocupla
}

