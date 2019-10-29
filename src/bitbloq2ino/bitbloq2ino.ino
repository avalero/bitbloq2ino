

void parseCommand(String command);
void parseSetup(String command);
void parseAction(String command);
String readDigitalInputs(String const &inputs);
String readAnalogInputs(String const &inputs);
String readI2CInputs(String const &inputs);
void sendInputs(String const &digital, String const &analog, String const &i2c);

String command;

String digitalInputs;
String analogInputs;
String i2cInputs;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop()
{
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    if (c == '(')
      command = "";
    else if (c == ')')
    {
      parseCommand(command);
      command = "";
    }
    else
      command.concat(c);
  }

  sendInputs(digitalInputs, analogInputs, i2cInputs);
}

void sendInputs(String const &digital, String const &analog, String const &i2c)
{
  String toSend = "(";
  toSend += readDigitalInputs(digital);
  toSend += readAnalogInputs(analog);
  toSend += readI2CInputs(i2c);
  toSend += ")";

  Serial.println(toSend);
}

/***
 * S: Setup
 * A: Action
*/
void parseCommand(String command)
{
  const char c = command.charAt(0);
  switch (c)
  {
  case 'S': // setup
    parseSetup(command.substring(1));
    break;
  case 'A': // Action
    parseAction(command.substring(1));
    break;
  }
}

/**
 * Codification
 * [PinNumber][Digital/Analog/Object/I2C][INPUT/OUTPUT/Object][Initialization]
 * Examples
 * 01DI -> Pin 1, Digital Input
 * 12AI -> Pin 12, Analog Input
 * 03DO -> Pin 03, Digital Output
 */
void parseSetup(String command)
{
  uint8_t pin = (command.charAt(0) - '0') * 10 + (command.charAt(1) - '0');
  char type = command.charAt(2);
  char mode = command.charAt(3) == 'O' ? OUTPUT : INPUT;
  switch (type)
  {
  case 'D':
  case 'A':
    pinMode(pin, mode);
    break;
  }
};
void parseAction(String command){

};

String readDigitalInputs(String const &inputs)
{
}
String readAnalogInputs(String const &inputs)
{
}
String readI2CInputs(String const &inputs)
{
}