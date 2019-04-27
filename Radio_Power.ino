/*Author: Ryan Coble-Neal
 *Date Last Modified: 27/04/19
 *File: Radio Power
 *Purpose of Program: To toggle the power with the presses of the radio button 
 *labelled 'A' on the 4 button keyfob.
*/

const int radioA = 3; //The interrupt pin used for toggling the power
int power = 0;  //Turn the power off at boot so nothing happens until the user presses the 'A' button

void setup()
{
  Serial.begin(9600);
  pinMode(radioA, INPUT_PULLUP);  //Enable the interrupt pin with an internal pullup resistor
  attachInterrupt(digitalPinToInterrupt(radioA), radioButtonA, CHANGE); 
  //Attaching the interrupt to the pin and calling the function radioButtonA when a change is detected
}

void loop()
{
  //Debugging for the power state
  if(power == LOW)
  {
    Serial.println("Off");  
  }
  if(power == HIGH)
  {
    Serial.println("On");  
  }
}

//The interrupt function that toggles the power
void radioButtonA()
{
  power = !power;
}



