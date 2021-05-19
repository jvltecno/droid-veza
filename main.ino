//-----------------------------Includes--------------------------------------------------------------------------------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 filas
float mash[4][4];//primer valor para temp, segundo para tiempo
float temp;
float tempWash;
float tempTrans;
byte timeBoil;
byte timeAddit [5];
float tempBoil=100;
byte xmash;

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
   cooler();
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

for(byte i=0;i<=xmash,i++){ //xmash es la cantidad 
                          //maxima de etapas elegidas
byte y=i+1 
xTemp=mash[i][i];
xTime=mash[i][y];

while(temp<xTemp){
     Lcd.clear();
     Lcd.cursor(0.0);
     Lcd.print("Subiendo Temp.");
     Lcd.cursor(1,0);
     Lcd.print("Temp=");
     Lcd.print(temp);
     Lcd.cursor(0,9);
     Lcd.print("TemO=");
     Lcd.print(xTemp);
     delay=1000;
}

     Lcd.clear();
     Lcd.print('Iniciando Etapa");
     Lcd.cursor(1,0);
     Lcd.print("Mash:");
     Lcd print(y);
     delay(2000);
     Lcd.clear();

while(timeMeasured<xTime){
    If(timeConcurrent-timeInit<1){ /mide tiempo trnascurrido del proceso
       timeMeasured++;
       timeInit=timeConcurrent;

       Lcd.cursor(0,0); // muestra datos
       Lcd.print("Etapa");
       Lcd.print(y);
       Lcd.cursor(0,9);
       Lcd.print("Time:");
       Lcd.print(timeMessured);
       Lcd.cursor(1,0);
       Lcd.print("Temp=");
       Lcd.print(temp);
       Lcd.cursor(0,9);
       Lcd.print("TemO=");
       Lcd.print(xTemp);

}
}
}

/----------------------------------------------
void boil(){
xTime=timeBoil;
xTemp=tempBoil;

while(timeMeasured<xTime){
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
}
}

/----------------------------------------------

void cooler(){
}

/---------------------------------------------

void buzzer(){
}

/---------------------------------------------


