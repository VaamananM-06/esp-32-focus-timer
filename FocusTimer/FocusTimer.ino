enum State { BOOT, MODE_SELECT, TIME_SET, RUNNING, FINISHED }; //enum used for a fixed set
State state = BOOT; 

enum Mode { STUDYING, BREAK };
Mode mode = STUDYING;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//opens the serial connection so you can see output, communication speed (baud rate) 115200 bits per second 
  delay(1000);//delay by a second
  Serial.println("FOCUS TIMERv2");//for each line of my how to for the oled
  Serial.println("Button 1 is used to pick the mode");
  Serial.println("Buzzer and LED are both turned OFF");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char c = Serial.read();
    
    if (c == '1' && state == BOOT) {
      state = MODE_SELECT;
      Serial.println("Studying Mode");
    }
    else if (c == '1' && state == MODE_SELECT) {
      if (mode==STUDYING){
        mode = BREAK;
        Serial.println("Break Mode");
      } else {
        mode = STUDYING;
        Serial.println("Studying Mode");
      }
    } 
    else {
        Serial.println("Invalid Button!");
      }
    }
  }

