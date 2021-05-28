int salida_PWM =  9;// Declaramos el pin 3 como salida PWM
String readString;  // Creamos una variable de tipo string
void setup() {
Serial.begin(9600); 
pinMode (salida_PWM, OUTPUT);
}

void loop() {
char dato =Serial.read();
switch(dato) {
  case 'A' :velocidad();
  break;
}
}
void velocidad(){
  delay(15);
  while (Serial.available()){
 char C   = Serial.read(); //almacenamos la lectura serial en la variable C
  readString += C;         //sumanos la cadena de caracteres + la variable C
  }
if (readString.length()>0){ //Si la anchura de la cadena de caracteres es mayor a 0, entonces
                            //que realice las instrucciones que se encuentran dentro de las instrucciones

  analogWrite (salida_PWM,(readString.toInt()));
  readString = "";
}

}
