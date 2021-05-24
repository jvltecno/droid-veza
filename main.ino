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
byte timeAddit []={255,255,255,255,255};
byte xmash;

//timming

unsigned long timeCurrent=millis();
byte timeMeasured=0;
byte xTime=0;
byte xTemp=0;

//pins
byte buzzer=11;
int buttons=A0;

//data
int pushed;

//app
void setup(){
    pushed=map(buttons,0,1023,0,255);

    pinMode(buzzer, OUTPUT);

	Lcd.begin();                      
	Lcd.backlight();
    Lcd.print("Iniciando...");

	delay(5000);
}

 
void loop(){
   set();
   mash();
   mashOut();
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

    
    if(pulsoBoton()==0){
    void Menu();
   }

}
void PID(){
    
}
//--------------------------------------------
void mash(){
	for(byte i=0;i<=xmash;i++){ //xmash es la cantidad 
    //maxima de etapas elegidas 
        xTemp=mashTemp[i];
        xTime=mashTime[i];
        while(temp<xTemp){
    	    Lcd.clear();
            Lcd.cursor(0.0);
            Lcd.print("Subiendo Temp.");
            PID(xtemp);
            Lcd.cursor(1,0);
            Lcd.print("Temp=");
            Lcd.print(temp);
            Lcd.cursor(0,9);
            Lcd.print("TemO=");
            Lcd.print(xTemp);
            delay(1000);
        }
        if (xmash==0)
        {
            Lcd.clear();
            Lcd.print("Por favor");
            Lcd.cursor(1,0);
            Lcd.print("encender Bomba");

        }
        
        Lcd.clear();
        Lcd.print("Iniciando Etapa");
        Lcd.cursor(1,0);
        Lcd.print("Mash:");
        Lcd.print(i++);
        delay(2000);
        Lcd.clear();

        alert();
	       
	    while(timeMeasured<=xTime){
  	        if(timeConcurrent-timeInit<1){ //mide tiempo trnascurrido del proceso
       		    timeMeasured++;
       		    timeInit=timeConcurrent;
      
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
            PID();
        }
    }
}


//----------------------------------------------

void mashOut(){

}

//----------------------------------------------
void boil(){
    xTime=timeBoil;

    Lcd.clear();
    Lcd.print("Por favor");
    Lcd.cursor(1,0);
    Lcd print("apagar Bomba");


    while(temp < 100){
        //RESISTENCE IN OFF
        Lcd.clear();
        Lcd.cursor(0.0);
        Lcd.print("Subiendo Temp.");
        Lcd.cursor(1,0);
        Lcd.print("Temp=");
        Lcd.print(temp);
        Lcd.cursor(0,9);
        Lcd.print("TemO=");
        Lcd.print(xTemp);
    }

        Lcd.clear();
        Lcd.print("Iniciando Etapa");
        Lcd.cursor(1,0);
        Lcd.print("Hervido");
        Lcd print(y);
        delay(2000);
        Lcd.clear();


    while(timeMeasured<xTime){
        timeConcurrent = millis();
        timeMeasured++;
        for (int i = 0; i < 3; i++){

            if(timeMeasured == timeAddit[i]){
                      
               Serial.println("adiccion");
               Serial.print(i);
               delay(3000);
            }
            if(timeMeasured != timeAddit[i]){
                    
                Serial.print("Time=");
                Serial.println(timeMeasured);
                Serial.print("TimO=");
                Serial.println(xTime);
                Serial.print("Etapa Hervido");
                    
            }
            while(millis() < timeConcurrent+1000){
            // espere [periodo] milisegundos
            }
           
            }
    }
        timeMeasured=0;
            
}


//----------------------------------------------

void cooler(){
}

//---------------------------------------------

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

//---------------------------------------------

void alarm(){
   for(int i,i=30,i++){
       tone(buzzer,1760,250);
       tone(buzzer,220,250);
       delay(400);
    }
}

//----------------------------------------------

int pulsoboton(){
analogRead(buttons);

  if(pushed>25 && pushed<50){
     return 0;//Enter
    }
  if(pushed>75 && pushed<100){
      return 1;//Up
    }
  if(pushed>125 && pushed<150){
      return 2;//Down
    }
  if(pushed>175 && pushed<200){
      return 3;//Right
    }
  if(pushed>225 && pushed<250){
      return 4;//Left
    }
}


