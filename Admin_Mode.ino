/*Author: Ryan Coble-Neal
 *Date Last Modified: 28/04/19
 *File: Jerk Compensator
 *Purpose of Program: To slow the monkey down as it reaches the bottom or top of its
 *arc such that there is the least amount of jerk on the system to avoid wear and tear
 *and prevent electrical hazards.
*/

const int admin = 2; 
const int led = 9; 
//Set the 'D' button on the keyfob to activate admin mode if the right sequence is entered.
int count = 0;
int state = 0;
int maxTime = 1500;
unsigned long timerArray[4] = {0, 0, 0, 0};


void setup() 
{
  cli();  //Disable interrupts until the setup is complete
  Serial.begin(9600);
  pinMode(admin, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(admin), adminMode, CHANGE);
  sei();  //Enable interrupts after the setup is complete
}

void loop() 
{
  //Check if the admin sequence has been entered
  if(timerArray[3] != 0)
  {
    if((timerArray[3] - timerArray[0]) < maxTime)
    {
      state = HIGH;
    }
  }

  switch(state)
  {
    case 0:
      {
        digitalWrite(led, LOW);
        break;
      }
    case 1:
      {
        digitalWrite(led, HIGH);
        break;
      }
  }
}

//The interrupt function triggered by pressing 'D'
void adminMode()
{
  if(count > 3)
  {
    count = 0;
  }
  timerArray[count] = millis();
  count++;
}
