//-----------------------------Includes--------------------------------------------------------------------------------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 filas


byte mashTime[4];
byte mashTemp[4];
float temp;
float tempWash;
float tempTrans;
byte timeBoil;
byte timeAddit [5];
float tempBoil=100;
byte xmash;

//timming
int timeInit=0;
int timeCurrent=millis()/1000;
int timeMeasured=0;
byte xTime=0;
byte xTemp=0;

//pins
int buzzer=11;

//app
void setup(){
        pinMode(buzzer, OUTPUT);
	lcd.begin();                      
	lcd.backlight();
        Lcd.print("Iniciando...");


	delay(5000);
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
    delay(5000);
    Lcd.print("Ingrese el agua,");
    Lcd.cursor(1,0);
    Lcd.print("luego oprima OK");
   

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

        alert();
	       
	while(timeMeasured<xTime){
  	  if(timeConcurrent-timeInit<1){ //mide tiempo trnascurrido del proceso
       		timeMeasured++;
       		timeInit=timeConcurrent;
      
     	        PID();
		// muesra datos
       		Lcd.cursor(0,0); 
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

while(temp <= xTemp){
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
     Lcd.print("Iniciando Etapa");
     Lcd.cursor(1,0);
     Lcd.print("Mash:");
     Lcd print(y);
     delay(2000);
     Lcd.clear();


while(timeMeasured<xTime){
    If(timeConcurrent-timeInit<1){ /mide tiempo trnascurrido del proceso
       timeMeasured++;
       timeInit=timeConcurrent;

           PID();

    switch(timeMeasured){   // controla el tiwmpo de                      
           case=timeAddit[0]  // las adiciones
           Lcd.clear();
           Lcd.print("Adicción 1");
           alert();
           break;
           case=timeAddit[1]
           Lcd.clear();
           Lcd.print("Adición 2");
           alert();
           break;
           case=timeAddit[2]
           Lcd.clear();
           Lcd.print("Adición 3");
           alert();
           break;
           case=timeAddit[3]
           Lcd.clear();
           Lcd.print("Adición 4");
           alert();
           break;
           case=timeAddit[4]
           Lcd.clear();
           Lcd.print("Adicion 5");
           alert();
           break;

Lcd.cursor(0,0); // muestra datos
       Lcd.print("Time=");
       Lcd.print(timeMessured);
       Lcd.cursor(0,9);
       Lcd.print("TimO=");
       Lcd.print(xTime);
       Lcd.cursor(1,0);
       Lcd.print(Etapa Hervido");
       
}
}
}
}

/----------------------------------------------

void cooler(){
}

/---------------------------------------------

void alert(){
           tone(buzzer,880,500);
           delay(750);
           tone(buzzer,880,500);
           delay(750);
           tone(buzzer,440,2000);
           delay(2250);
           tone(buzzer,1760,250);
           noTone(buzzer);
}

/---------------------------------------------

void alarm(){

   for(int i,i=30,i++){
       tone(buzzer,1760,250);
       tone(buzzer,220,250);
       delay(400);
}
}


