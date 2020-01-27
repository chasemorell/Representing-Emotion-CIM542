//Chase Morell, CIM 542, Janurary 2020

//speed of the animation loop
const int DELAY = 150;
const int NUM_GREEN_FLASHES = 8;

//numbers correspond to the pin number connected to the LED
const int white1 = 10;
const int white2 = 12;
const int yellow = 13;
const int green = 11;

// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize pins
  pinMode(yellow, OUTPUT);
  pinMode(white2, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(white1, OUTPUT);


}

// the loop function runs over and over again forever
void loop() {

  //loop consists of 4 LED lights arranged in a line. order of lights is white-white-yellow-green. white light turns on first, and the pattern creates a sense of movement toward the final green light, which flashes rapidly and represents triumpth.

  digitalWrite(yellow, LOW);   
  digitalWrite(white2, LOW);   
  digitalWrite(green, LOW); 
  digitalWrite(white1, HIGH); 
  delay(DELAY);             
  digitalWrite(yellow, LOW);   
  digitalWrite(white2, HIGH);   
  digitalWrite(green, LOW); 
  digitalWrite(white1, HIGH); 
  delay(DELAY);                       
  digitalWrite(yellow, HIGH); 
  digitalWrite(white2, HIGH);   
  digitalWrite(green, LOW); 
  digitalWrite(white1, LOW); 
  delay(DELAY);
  digitalWrite(yellow, HIGH); 
  digitalWrite(white2, LOW);   
  digitalWrite(green, HIGH); 
  digitalWrite(white1, LOW); 
  delay(DELAY/2);
  digitalWrite(yellow, LOW); 
  digitalWrite(white2, LOW);   
  digitalWrite(green, HIGH); 
  digitalWrite(white1, LOW); 
  delay(DELAY/3);


  for(int i = 0;i < NUM_GREEN_FLASHES;i++){
    digitalWrite(yellow, LOW); 
    digitalWrite(white2, LOW);   
    digitalWrite(green, LOW); 
    digitalWrite(white1, LOW); 
    delay(DELAY);
    digitalWrite(yellow, LOW); 
    digitalWrite(white2, LOW);   
    digitalWrite(green, HIGH); 
    digitalWrite(white1, LOW); 
    delay(DELAY);
  }
  
  //turn off all lights before loop repeats 
  digitalWrite(yellow, LOW); 
  digitalWrite(white2, LOW);   
  digitalWrite(green, LOW); 
  digitalWrite(white1, LOW); 
  delay(DELAY);
  
}
