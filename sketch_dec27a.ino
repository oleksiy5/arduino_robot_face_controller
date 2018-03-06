void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

String inputString = "";

void loop() {
  serialEvent();

  if (inputString.indexOf("HAPPY_ON") > -1 ) {
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    inputString = "";
  }
  if (inputString.indexOf("HAPPY_OFF") > -1) {
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    inputString = "";
  }

  if (inputString.indexOf("ANGRY_ON") > -1 ) {
    digitalWrite(13, HIGH);
    digitalWrite(7, HIGH);
    inputString = "";
  }
  if (inputString.indexOf("ANGRY_OFF") > -1) {
    digitalWrite(13, LOW);
    digitalWrite(7, LOW);
    inputString = "";
  }
}


void serialEvent() {
  while (Serial.available() > 0) {
    char inChar = (char)Serial.read();
    inputString += inChar;
  }
}


