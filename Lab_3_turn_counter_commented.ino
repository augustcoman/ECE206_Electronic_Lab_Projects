// These are the pins we use to control the LED segments
// instead of writing the pin number, it is often more
// useful to create a variable or some other method
// to your code easier to modify and  more legible.
const short int A = 7, B = 8, C = 4, D = 3;
const short int E = 2, F = 9, G = 5;

const short int digit1 = A3, digit2 = A2;

// Since each segment assumes a certain state given a specific digit,
// an array of boolean values is created for each of these segments, with 
// 10 different values for digits 0-9. The state of the segment is at the
// index equivalent to the value of the digit.
const bool A_val[10] = {0, 1, 0, 0, 1, 0, 0, 0, 0, 0};
const bool B_val[10] = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0};
const bool C_val[10] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
const bool D_val[10] = {0, 1, 0, 0, 1, 0, 0, 1, 0, 0};
const bool E_val[10] = {0, 1, 0, 1, 1, 1, 0, 1, 0, 1};
const bool F_val[10] = {0, 1, 1, 1, 0, 0, 0, 1, 0, 0};
const bool G_val[10] = {1, 1, 0, 0, 0, 0, 0, 1, 0, 0};

//counts the number of rotations
long int counter = 0;

//Used to alternatively display one digit at a time, allowing faster measurements
bool side = true;

short int state = 0;  //0 is all are high, 1 is A dropped. 2 is both. 3 is B dropped
//This variable remembers the previous state of the encoder. This is to avoid errors
//in position. Negative denotes counterclockwise.

// Code that runs once
void setup() 
{
  // Set up the LED Pins
  pinMode(A,OUTPUT); // A
  pinMode(B,OUTPUT); // B
  pinMode(C,OUTPUT); // C
  pinMode(D,OUTPUT); // D
  pinMode(E,OUTPUT); // E
  pinMode(F,OUTPUT); // F
  pinMode(G,OUTPUT); // G

  //Setting pins for digits.
  pinMode(digit1, OUTPUT);  //digit 2
  pinMode(digit2, OUTPUT);  //digit 1

  pinMode(A6, INPUT);
  pinMode(A4, INPUT);

  // Turn off the segments (by setting them high)
  digitalWrite(A,HIGH); // A
  digitalWrite(B,HIGH); // B
  digitalWrite(C,HIGH); // C
  digitalWrite(D,HIGH); // D
  digitalWrite(E,HIGH); // E
  digitalWrite(F,HIGH); // F
  digitalWrite(G,HIGH); // G
}

// repeated code
void loop() 
{
  //A set of 'if' statements advance/rollback the states given when
  //the encoder readings change.
  if(state == 0) {
    if(digitalRead(A4) == LOW) {
      state++;
    } else if(digitalRead(A6) == LOW) {
      state--;
    }
  }
  if(state == 1) {
    if(digitalRead(A6) == LOW) {
      state++;
    } else if(digitalRead(A4) == HIGH) {
      state = 0;
    }
  }
  if(state == 2) {
    if(digitalRead(A4) == HIGH) {
      state++;
    } else if(digitalRead(A6) == HIGH) {
      state--;
    }
  }
  if(state == 3) {
    if(digitalRead(A6) == HIGH) {
      state = 0;
      counter++;
    } else if(digitalRead(A4) == LOW) {
      state--;
    }
  }
  if(state == -1) {
    if(digitalRead(A4) == LOW) {
      state--;
    } else if(digitalRead(A6) == HIGH) {
      state = 0;
    }
  }
  if(state == -2) {
    if(digitalRead(A6) == HIGH) {
      state--;
    } else if(digitalRead(A4) == HIGH) {
      state++;
    }
  }
  if(state == -3) {
    if(digitalRead(A4) == HIGH) {
      state = 0;
      counter--;
    } else if(digitalRead(A6) == LOW) {
      state++;
    }
  }
  //Displays one side at a time, which allows faster encoder measurements.
  //side variable determines which digit side is displayed
  side = !side;
  counter = constrain(counter, 0, 99);
  displayDoubleFast(counter, side);
}

// Given a digit 0-9, it sets the values of the segments to match
// that of the specific digit. This uses the boolean arrays declared earlier.
void displayDigit(unsigned short int i) {
  if(i < 10) {
    digitalWrite(A,A_val[i]); // A
    digitalWrite(B,B_val[i]); // B
    digitalWrite(C,C_val[i]); // C
    digitalWrite(D,D_val[i]); // D
    digitalWrite(E,E_val[i]); // E
    digitalWrite(F,F_val[i]); // F
    digitalWrite(G,G_val[i]); // G
  }
}

void displayDouble(unsigned short int i) {
  if(i < 100) {
    digitalWrite(digit2, HIGH);
    digitalWrite(digit1, LOW);
    displayDigit(i % 10);
    delay(10);
    digitalWrite(digit2, LOW);
    digitalWrite(digit1, HIGH);
    displayDigit(i / 10);
    delay(10);
  }
}

//Displays one digit on one side, denoted by bool b.
void displayDoubleFast(unsigned short int i, bool b) {
  if(i < 100) {
    digitalWrite(digit2, b);
    digitalWrite(digit1, !b);
    displayDigit(b?(i % 10):(i / 10));
    delay(1);
    digitalWrite(A,HIGH); // A
    digitalWrite(B,HIGH); // B
    digitalWrite(C,HIGH); // C
    digitalWrite(D,HIGH); // D
    digitalWrite(E,HIGH); // E
    digitalWrite(F,HIGH); // F
    digitalWrite(G,HIGH); // G
  }
}
