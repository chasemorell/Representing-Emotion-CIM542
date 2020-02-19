int ledPin0 = 13;
int ledPin1 = 11;
int ledPin2 = 12;
int pushButton = 8;
int state = 0;
int counter = 0;

int stage = 0;
boolean pressed = false;

int s = 100;
int timeSequence[6] = {s,s,s,s,s,s};
int timeSequenceLength = 6; //adjust based on number of items in array

int curTime = 0;
long prevMillis = 0;
boolean turnOn = false;


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

    digitalWrite(ledPin1, HIGH);

  
}

// the loop function runs over and over again forever
void loop() {

  int buttonState = digitalRead(pushButton);

  if (buttonState == 1) {
    pressed = true;
  }
  if ((pressed == true) && (buttonState == 0)) {
    pressed = false;
    state = ((state + 1) % 3);
    Serial.println("BUTTON PRESSED");
    Serial.println(state);
  }

  
  if (state == 0) {
    digitalWrite(ledPin0, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  } else if (state == 1) {
    digitalWrite(ledPin0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else if (state == 2) {


    if (millis() - prevMillis > timeSequence[curTime]) {
      prevMillis = millis();
     
      
      stage = ((stage + 1) % 6);
      curTime++;

      if (curTime == timeSequenceLength) {
        curTime = 0;
      }
      

    }

    if (stage == 0) {
      digitalWrite(ledPin0, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    } else if (stage == 1){
      digitalWrite(ledPin0, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }else if (stage == 2){
      digitalWrite(ledPin0, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
    }else if (stage == 3){
      digitalWrite(ledPin0, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
    } else if (stage == 4){
      digitalWrite(ledPin0, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
    }else if (stage == 5){
      digitalWrite(ledPin0, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }
   // Serial.print("timeSequence: ");
   // Serial.print(timeSequence[curTime]);
   // Serial.print(" ");
   // Serial.print("curTime: ");
   // Serial.print(curTime);
   // Serial.print(" ");
   // Serial.print("turnOn: ");
   // Serial.println(turnOn);


    delay(30);


   




  }










}
