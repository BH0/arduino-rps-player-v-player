//// Arduino Player-Verse-Player Rock-Paper-Scizzors-Circuit & Program 
// somewhat working code 
String player1Choices[4] = {"p1_NONE", "p1_rock", "p1_paper", "p1_scizzors"}; 
String player2Choices[4] = {"p2_NONE", "p2_rock", "p2_paper", "p2_scizzors"}; 

int player1Choice = 0; 
int player2Choice = 0; 

int buttonState1 = 0; 
int buttonState2 = 1; 
int buttonState3 = 2; 

int buttonState4 = 3; 
int buttonState5 = 4; 
int buttonState6 = 5; 

int input1 = 0; 
int input2 = 1; 
int input3 = 2; 

int input4 = 3; 
int input5 = 4; 
int input6 = 5; 

int output1 = 6; 
int output2 = 7; 
int output3 = 8; 

int output4 = 9; 
int output5 = 10; 
int output6 = 11; 

int player1WinOutput = 12; 
int player2WinOutput = 13; 

bool player1HasChosen = false; 
bool player2HasChosen = false; 

int timeBeforeReset = 3000; 

long lastDebounceTime1 = 0;  
long debounceDelay1 = 50;    

long lastDebounceTime2 = 0;  
long debounceDelay2 = 50;    

bool debugMode = true; // if true this will enable the LEDs that represent rock/paper/scizzors for each player 

void setup() { 
  pinMode(input1, INPUT); 
  pinMode(output1, OUTPUT); 

  pinMode(input2, INPUT); 
  pinMode(output2, OUTPUT); 

  pinMode(input3, INPUT); 
  pinMode(output3, OUTPUT); 

  pinMode(input4, INPUT); 
  pinMode(output4, OUTPUT); 

  pinMode(input5, INPUT); 
  pinMode(output5, OUTPUT); 

  pinMode(input6, INPUT); 
  pinMode(output6, OUTPUT); 

  pinMode(player1WinOutput, OUTPUT); 
  pinMode(player2WinOutput, OUTPUT); 

  Serial.begin(9600); 
} 

void loop() { 
  	// digitalWrite(12, HIGH); 
  	// digitalWrite(13, HIGH); 
    digitalWrite(player1WinOutput, HIGH);    
    debugLED(output1); 
    Serial.println("PLAYER ONE WINS");
    delay(timeBeforeReset); 
    reset(); 
  } 
  
  // player 1 wins // may be bugged 
  if (player1Choices[player1Choice] == "p1_paper" && player2Choices[player2Choice] == "p2_rock") { 
    digitalWrite(player1WinOutput, HIGH);    
    debugLED(output2); 
    Serial.println("PLAYER ONE WINS");
    delay(timeBeforeReset); 
    reset(); 
  } 

  // player 1 wins 
  if (player1Choices[player1Choice] == "p1_scizzors" && player2Choices[player2Choice] == "p2_paper") { 
    digitalWrite(player1WinOutput, HIGH);    
    debugLED(output3); 
    Serial.println("PLAYER ONE WINS");
    delay(timeBeforeReset); 
    reset(); 
  } 
	

  // player 2 wins 
  if (player1Choices[player1Choice] == "p1_scizzors" && player2Choices[player2Choice] == "p2_rock") { 
    Serial.println("PLAYER TWO WINS");
    digitalWrite(player2WinOutput, HIGH);    
    debugLED(output4); 
    delay(timeBeforeReset); 
    reset(); 
  } 


  // player 2 wins 
  if (player1Choices[player1Choice] == "p1_rock" && player2Choices[player2Choice] == "p2_paper") { 
    digitalWrite(player2WinOutput, HIGH);    
    debugLED(output5); 
    Serial.println("PLAYER TWO WINS"); 
    delay(timeBeforeReset); 
    reset(); 
  } 
  
  // player 2 wins 
  if (player1Choices[player1Choice] == "p1_paper" && player2Choices[player2Choice] == "p2_scizzors") { 
    digitalWrite(player2WinOutput, HIGH);    
    debugLED(output6); 
    Serial.println("PLAYER TWO WINS"); 
    delay(timeBeforeReset); 
    reset(); 
  } 
  
  if (player1Choices[player1Choice] == "p1_rock" && player2Choices[player2Choice] == "p2_rock" || player1Choices[player1Choice] == "p1_scizzors" && player2Choices[player2Choice] == "p2_scizzors" || player1Choices[player1Choice] == "p1_paper" && player2Choices[player2Choice] == "p2_paper") { 
	Serial.println("DRAW / SOMETHING ELSE"); 
    digitalWrite(player1WinOutput, HIGH);    
    digitalWrite(player2WinOutput, HIGH);    
    delay(timeBeforeReset); 
    reset(); 
  }     
} 

void reset() { 
  player1Choice = 0; 
  player2Choice = 0; 

  digitalWrite(player1WinOutput, LOW);    
  digitalWrite(player2WinOutput, LOW);    

  digitalWrite(output1, LOW); 
  digitalWrite(output2, LOW); 
  digitalWrite(output3, LOW); 

  digitalWrite(output4, LOW); 
  digitalWrite(output5, LOW); 
  digitalWrite(output6, LOW); 
  
  buttonState1 = 0; 
  buttonState2 = 0; 
  buttonState3 = 0; 

  buttonState4 = 0; 
  buttonState5 = 0; 
  buttonState6 = 0; 

} 

void debugLED(int pin) { 
  if (debugMode) { 
	  digitalWrite(pin, HIGH);    
  } 
} 
