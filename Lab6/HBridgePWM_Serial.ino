//this is a global variable all functions can access
int spd = 140; // PWM speed value
int dir = 0; // direction (0/1)
const int pinPWM = 3, pinDir = 4; // PWM / motor control


void setup() 
{
  Serial.begin(115200); // setup serial with a baud speed of 115200
  pinMode(pinDir, OUTPUT); // setup gate of MOSFET A
  pinMode(pinPWM, OUTPUT); // setup gate of MOSFET B
  digitalWrite(pinDir,dir); // start spinning in dir
  analogWrite(pinPWM, spd); // start spinning at spd
}

void loop() 
{
  char input;

  if(Serial.available() > 0)
  {
    input = Serial.read(); // takes input
    // spits the input back out
    Serial.println(input); // so you can see your past input 
    
    if (input == '4') // first input
    {
      //change direction
      dir = 0;
    }
    else if (input == '6')
    {
      //change direction other way
      dir = 1;
    } 
    else if (input == '8')
    {
      //  faster 
      spd += 10;
    }
    else if (input == '2')
    {
      // slower
      spd -= 10;
    }
  }
    // Put some code here to make sure it's within the bounds 0 to 255 for the speed
    spd = constrain(spd, 0, 255);
   
        
    // Change direction as needed 

    
  // Change direction as needed 
  digitalWrite(pinDir,dir);
  
  // The speed changes depending on direction
  if (dir == 1)
  {
    // make it go a speed
    analogWrite(pinPWM, 255 - spd);
  }
  else
  {
    // make it go the same speed when it's going the other direction
    analogWrite(pinPWM, spd);
  }
  delay(10);
}
