int PWM = 3;
int motorDirection = 4;
int radioDir = 5;
int radioSetSpeed = 6;
int radioPause = 7;
int radioAuto = 8;

int motorSpeed = 0;
int dir = LOW;
int speedCheck = LOW;
int count = 0;
int pauseCheck = LOW;
int autoCheck = LOW;
int tempDir = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(motorDirection, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(radioDir, INPUT);
  pinMode(radioSetSpeed, INPUT);
  pinMode(radioAuto, INPUT);
}

void loop()
{
  pauseCheck = digitalRead(radioPause);
  dir = digitalRead(radioDir);
  autoCheck = digitalRead(radioAuto);

  if(pauseCheck == HIGH)
  {
    analogWrite(PWM, 0);
  }
  else
  {
    if(autoCheck == HIGH)
    {
      analogWrite(PWM, 200);
      digitalWrite(motorDirection, dir);
    }
    else
    {
      speedCheck = digitalRead(radioSetSpeed);
    
      if (speedCheck == HIGH)
      {
        if (count >= 255)
        {
          count = 255;
        }
    
        motorSpeed = 0 + count;
        count++;
        if (motorSpeed >= 255)
        {
          count = 255;
        }
    
        delay(50);
      }
      else
      {
        count = 0;
      }
      analogWrite(PWM, motorSpeed);
      digitalWrite(motorDirection, dir);
    }
  }
}
