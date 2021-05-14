//-----------------------------Includes--------------------------------------------------------------------------------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas


//-------------------------------Constantes------------------------------------------------------------------------------------

//-------------------------------Char Specified-------------------------------------------------------------------------------

//-------------------------------Variables-------------------------------------------------------------------------------------
float mash[4][4];
float temp;
float tempWash;
float tempTrans;
byte timeBoil;
byte timeAddit [5];
float tempBoil=100;

int timeInit=0;
int timeCurrent=millis()/1000;
int timeMeasured=0;
byte xTime=0;
byte xTemp=0;


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
/--------------------------------------------
void mash(){
    
xTime=mash[][];
xTemp=mash[][];

if(timeMeasured<xTime){
    If(timeConcurrent-timeInit<1){ /mide tiempo trnascurrido del proceso
       timeMeasured++;
       timeInit=timeConcurrent;

       Lcd.cursor(0,0); // muestra datos
       Lcd.print("Time=");
       Lcd.print(timeMessured);
       Lcd.cursor(0,9);
       Lcd.print("TimO=");
       Lcd.print(xTime);
       Lcd.cursor(1,0);
       Lcd.print("Temp=");
       Lcd.print(temp);
       Lcd.cursor(0,9);
       Lcd.print("TemO=");
       Lcd.print(xTemp);

}
}

/----------------------------------------------
void boil (){
}

