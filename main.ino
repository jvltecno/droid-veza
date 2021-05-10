//-------------------------------Includes--------------------------------------------------------------------------------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas


//-------------------------------Constantes------------------------------------------------------------------------------------
char frases[59][35]={
    {"  !Bienvenido¡  iniciando...    "},
    {"       !vamos a    programar¡   "},
    {"   cuantas etapas   de mash?    "},
    {"    mash 1      temp=  tiempo=  "},
    {"    mash 2      temp=  tiempo=  "},
    {"    mash 3      temp=  tiempo=  "},
    {"    mash 4      temp=  tiempo=  "},
    {" temp de lavado?      temp=     "},
    {"   agregados      de lupulos?   "},
    {" agregado numero 1     tiempo=  "},
    {" agregado numero 2     tiempo=  "},
    {" agregado numero 3     tiempo=  "},
    {" agregado numero 4     tiempo=  "},
    {" agregado numero 5     tiempo=  "},
    {" cuanto tiempo  hervor tiempo=  "},
    {"   todo listo?                  "},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
};    
double computePID(double inp){     
    currentTime = millis();                               // obtener el tiempo actual
    elapsedTime = (double)(currentTime - previousTime);     // calcular el tiempo transcurrido
        
    error = Setpoint - Input;                               // determinar el error entre la consigna y la medición
    cumError += error * elapsedTime;                      // calcular la integral del error
    rateError = (error - lastError) / elapsedTime;         // calcular la derivada del error
 
    double output = kp*error + ki*cumError + kd*rateError;     // calcular la salida del PID
 
    lastError = error;                                      // almacenar error anterior
    previousTime = currentTime;                             // almacenar el tiempo anterior
 
    return output;
}


//-------------------------------Char Specified-------------------------------------------------------------------------------

//-------------------------------Variables-------------------------------------------------------------------------------------
float mash [2][3];
float temp;
float tempCleanign;
float tempLevature;
byte timeHervor;
byte timeAddit [5];


//app
void setup(){
	lcd.begin();                      
	lcd.backlight();

    Input = analogRead(PIN_INPUT);
   Setpoint = 100;

	delay(2500);
}

 
void loop(){
   
   mash();
   hervor();

}

/*-------------------------------Functions------------------------------------------------------------------------------------*/

void mash(){

}

//-------------------------------Lcd--------------------------------------------------------------------------------------------

void print (int i , int in[1]){
    lcd.setCursor(in[0],in[1]);
    lcd.print(frases[i]);
}

//--------------------------------Termocupla-------------------------------------------------------------------------------------
void tempConcurrent(){
    temp=;//revisar termocupla
}

bool time (int timeObj){
    time=millis()/1000/60;
    if (time-timeObj<=0){
        return true;
    }
    return false;
}