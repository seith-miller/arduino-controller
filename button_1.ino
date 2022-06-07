const int BUTTON0 = 0;
const int BUTTON1 = 1;
const int BUTTON2 = 2;
const int BUTTON3 = 3;

const int LED0 = 8;
const int LED1 = 9;
const int LED2 = 10;
const int LED3 = 11;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  
  // put your setup code here, to run once:
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(BUTTON0, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
}

void loop() {
  readButton(BUTTON0, LED0);
  readButton(BUTTON1, LED1);
  readButton(BUTTON2, LED2);
  readButton(BUTTON3, LED3);
}

int readButton(int buttonID, int ledID) {
  bool did_i_print = false;

  int val = digitalRead(buttonID);

  // check whether the input is HIGH (button pressed)
  if (val == HIGH) {
    digitalWrite(ledID, HIGH);

    if (did_i_print == false) {
      Serial.print(buttonID);
      did_i_print = true;
    }
  } else {
    digitalWrite(ledID, LOW);
    did_i_print = false;
  }
}
