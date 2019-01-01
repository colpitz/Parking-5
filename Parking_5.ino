// Include Librerias
#include "Servo.h"
#include "LiquidCrystal_I2C.h"

// Pin Definiciones
#define SENS_1    2    // Sensor plaza 1
#define SENS_2    3    // Sensor plaza 2
#define SENS_3    4     // Sensor plaza 3
#define SENS_4    5     // Sensor plaza 4
#define SENS_5    6      // Sensor plaza 5
#define SENS_IN_6        7    // Sensor suelo Entrada
#define SENS_IN_7        8    // Sensor suelo Entrada
#define SENS_OUT_8    9    // Sensor suelo Salida
#define SENS_OUT_9    10     // Sensor suelo Salida
#define BUTT_1        11    // Pulsador de entrada
#define BUTT_2        12    // Pulsador de salida
#define SERVO_IN        13    // pin del servo entrada
#define SERVO_OUT        14    // pin del servo salida

const int servoIN_down   = 90;     //Starting position
const int servoIN_up = 180;         //Position when event is detected
const int servoOUT_down   = 90;     //Starting position
const int servoOUT_up = 180;     //Position when event is detected

int S_1;  // Sensor plaza 1
int S_2;  // Sensor plaza 2
int S_3;  // Sensor plaza 3
int S_4;  // Sensor plaza 4
int S_5;  // Sensor plaza 5
int S_IN_6;  // Sensor suelo Entrada
int S_IN_7;  // Sensor suelo Entrada
int S_OUT_8;  // Sensor suelo Salida
int S_OUT_9;  // Sensor suelo Salida
int S_BU_1;     // Pulsador de entrada
int S_BU_2;     // Pulsador de salida

int S_OC = 0;         // numero total de plazas ocupadas
int S_EMP = 0;    // numero total de plazas libres
int time0;
int S_UP_1 = 0; //posicion de barrera entrada
int S_OUT_2 = 0; //posicion de barrera salida

// object initialization
Servo servoiIN;
Servo servoOUT;

LiquidCrystal_I2C lcdI2C(0x27,16,2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

void setup() 
{
    lcdI2C.init();                      // initialize the lcd
    lcdI2C.backlight();  
 
    servoIN.attach(SERVO_IN);
    servoIN.write(servoIN_down);
    delay(100);
    servoIN.detach();
   
    servoOUT.attach(SERVO_OUT);
    servoOUT.write(servoOUT_down);
    delay(100);
    servoOUT.detach();
}

void loop() 
{

    lcdI2C.clear();                  // Clear LCD screen. Poner el cursor al principio de la linea 1
    lcdI2C.print("Libres: ");    // Print print String to LCD on first line
    lcdI2C.print(S_EMP);  
    lcdI2C.selectLine(2);                // Poner el cursor al principio de la linea 2
    lcdI2C.print("Ocupadas:  ");                   // Print print String to LCD on second line
    lcdI2C.print(S_OC);  
    delay(1000);

S_1 = digitalRead(SENS_1);
S_2 = digitalRead(SENS_2);
S_3 = digitalRead(SENS_3);
S_4 = digitalRead(SENS_4);
S_5 = digitalRead(SENS_5);
S_IN_6 = digitalRead(SENS_IN_6);
S_IN_7 = digitalRead(SENS_IN_7);
S_OUT_8 = digitalRead(SENS_OUT_8);
S_OUT_9_ = digitalRead(SENS_OUT_9);
S_BU_1 = digitalRead(BUTT_1);
S_BU_2 = digitalRead(BUTT_2);
S_OC = S_1 + S_2 + S_3 + S_4 + S_5;  // plazas ocupadas
S_EMP = 5 - S_TOT;            // plazas vacias

// levantar barrera de entrada
if ( S_IN_6 = 1 & S_BU_1 = 1){
    servoIN.attach(SERVO_IN);
    servoIN.write(servoIN_up);
    delay(100);
    servoIN.detach();
    S_UP_1 =1          //recuerda barrera de entrada arriba
}

 // bajar la barrera de entrada
if ( S_UP_1 =1 & S_IN_7 = 1) {
    servoIN.attach(SERVO_IN);
    servoIN.write(servoIN_down);
    delay(100);
    servoIN.detach();
    S_UP_1 = 0;                  //recuerda barrera  de entrada abajo

}

// levantar barrera de salida
if ( S_OUT_8 = 1 & S_BU_2 = 1){
    servoOUT.attach(SERVO_OUT);
    servoOUT.write(servoOUT_down);
    delay(100);
    servoOUT.detach();
    S_OUT_2 = 1;       //recuerda barrera de salida arriba

}

// bajar barrera de salida
if ( S_OUT_2 = 1 & S_OUT_9 = 1){
    servoOUT.attach(SERVO_OUT);
    servoOUT.write(servoOUT_down);
    delay(100);
    servoOUT.detach();
    S_OUT_2 = 0;        //recuerda barrera de salida abajo

}

            time0 = millis();
       
}
