//Código feito por Rayan;
//C++
//

#include <LiquidCrystal.h> //Inclui biblioteca do LCD
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

//Declara o led do LCD;
int backLight = 13;// pino 13 responsável pelo controle do LED

//Declara os leds coloridos;
int ledVermelho = A0;
int ledAmarelo = A1;
int ledVerde = A2;

//Declara Buzzer;
int Buzzer = A3;

//Declara Motor;
int MotorRapido = A5;

//Declara Motor;
int MotorDevagar = A4;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(MotorRapido, OUTPUT);
  pinMode(MotorDevagar, OUTPUT);
  pinMode(backLight, OUTPUT);
  // set up start communications
  Serial.begin(9600);
  // ## Display LCD
  ligaLed();
  
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Clear the display of the LCD.
  lcd.clear();
  
  // Display Message Initializing on Display LCD
  
  delay(500);
  
  lcd.setCursor(0, 0);
  lcd.print("Inicializando");
  
  lcd.setCursor(6, 1);
  lcd.print("Projeto.");
  delay (200);
  
  lcd.setCursor(6, 1);
  lcd.print("Projeto..");
  delay (200);
  
  lcd.setCursor(6, 1);
  lcd.print("Projeto...");
  delay (200);
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Inicializando");
  
  lcd.setCursor(6, 1);
  lcd.print("Projeto.");
  delay (200);
  
  lcd.setCursor(6, 1);
  lcd.print("Projeto..");
  delay (200);
  
  lcd.setCursor(6, 1);
  lcd.print("Projeto...");
  delay (200);
  
  
  lcd.clear();
  
  delay(1000);
  
  
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Bem-Vindo Rayan!");
  delay(1000);
  lcd.clear();
  delay(1000);
  

  
  // Iteração do display LCD inicial movendo as letras em um FOR LOOP
  for (int i = 0; i <= 6; i++) {
    lcd.setCursor(0, 0);
    lcd.print("Carregando.");
    delay (200);
    
    
    lcd.setCursor(0, 0);
    lcd.print("Carregando..");
    delay (200);
    
    lcd.setCursor(0, 0);
    lcd.print("Carregando...");
    delay (200);
    
    lcd.clear();
    
  	}
  delay (200);
  
  ligaBuzzer();
  lcd.setCursor(0, 0);
  lcd.print("Finalizado!");
  delay(1000);
  desligaBuzzer();
  lcd.clear();
  
  desligaLed();
  delay(1000);
  
  
}

void loop() {
    lcdPare();
  	lcdSiga();
  	lcdAtencao();
}

//ACENDE O LED VERMELHO;
void acenderLedVermelho(){
    digitalWrite(ledVermelho, HIGH);
 
}
//APAGA O LED VERMELHO;
void apagarLedVermelho(){
    digitalWrite(ledVermelho, LOW);
}



//ACENDE O LED AMARELO;
void acenderLedAmarelo(){
    digitalWrite(ledAmarelo, HIGH);
}
//APAGA O LED AMARELO;
void apagarLedAmarelo(){
    digitalWrite(ledAmarelo, LOW);
}



//ACENDE O LED VERDE;
void acenderLedVerde(){
    digitalWrite(ledVerde, HIGH);
}
//APAGA O LED VERDE;
void apagarLedVerde(){
    digitalWrite(ledVerde, LOW);
}



//LIGA O BUZZER;
void ligaBuzzer(){
    digitalWrite(Buzzer, HIGH);
}
//DESLIGA O BUZZER;
void desligaBuzzer(){
    digitalWrite(Buzzer, LOW);
}



//LIGA O MOTOR RAPIDO;
void ligaMotorRapido(){
    digitalWrite(MotorRapido, HIGH);
}
//DESLIGA O MOTOR RAPIDO;
void desligaMotorRapido(){
    digitalWrite(MotorRapido, LOW);
}



//LIGA O MOTOR DEVAGAR;
void ligaMotorDevagar(){
    digitalWrite(MotorDevagar, HIGH);
}
//DESLIGA O MOTOR DEVAGAR;
void desligaMotorDevagar(){
    digitalWrite(MotorDevagar, LOW);
}



//LIGA O LED DO LCD
void ligaLed(){
    digitalWrite(backLight, HIGH);
}
//DESLIGA O LED DO LCD
void desligaLed(){
    digitalWrite(backLight, LOW);
}




void lcdPare(){ 
  	//Inicializa a comunicação serial em 9600 bits por segundo
    ligaLed();
    acenderLedVermelho();
	delay(200);
  	
    
  
    lcd.begin(16, 2);//Colunas, linhas. Use 16,2 para display LCD 16x2
    lcd.clear();// Inicializa o display com uma tela vazia
  	
  	lcd.setCursor(5, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("PARE!");//Escreve o texto desejado
  	delay(500);
  	lcd.setCursor(0, 1);//Posiciona o cursor para a coluna 0, linha 1 (segunda linha)
    lcd.print("----------------");
    delay(2000);
  
  	lcd.clear();
  	
  	
      for(int i = 0; i<=15; i++){
		//
        //
  		lcd.setCursor(5, 0);
    	lcd.print("PARE!");
        
        lcd.setCursor(i, 1);//Posiciona o cursor para a coluna 0, linha 1 (segunda linha)
    	lcd.print("----------------");
        delay(1200);
		lcd.clear();
  		
      }
  	lcd.setCursor(5, 0);
    lcd.print("PARE!");
  	delay(1200);
	lcd.clear();
  
    desligaLed();
  	apagarLedVermelho();
  	delay(200);
}

void lcdAtencao(){ 
  	//Inicializa a comunicação serial em 9600 bits por segundo
    ligaLed();
    acenderLedAmarelo();
	delay(200);
  	
    
  
    lcd.begin(16, 2);//Colunas, linhas. Use 16,2 para display LCD 16x2
    lcd.clear();// Inicializa o display com uma tela vazia
  	
  	lcd.setCursor(3, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("ATENCAO!");//Escreve o texto desejado
  	desligaMotorRapido();
  	
  	ligaMotorDevagar();
  	ligaBuzzer();
  
  	delay(3000);
  
    lcd.clear();
  	desligaMotorDevagar();
  	desligaBuzzer();
  	delay(200);
    desligaLed();
  
  	apagarLedAmarelo();
  	delay(200);
    

  
}


void lcdSiga(){ 
  	//Inicializa a comunicação serial em 9600 bits por segundo
    ligaLed();
    acenderLedVerde();
	delay(200);
  	
    
  
    lcd.begin(16, 2);//Colunas, linhas. Use 16,2 para display LCD 16x2
    lcd.clear();// Inicializa o display com uma tela vazia
  	
  	lcd.setCursor(5, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
    lcd.print("SIGA!");//Escreve o texto desejado
  	delay(500);
  	lcd.setCursor(0, 1);//Posiciona o cursor para a coluna 0, linha 1 (segunda linha)
    lcd.print("----------------");
    delay(2000);
  
  	lcd.clear();
  	
  	ligaMotorRapido();
      for(int i = 0; i<=15; i++){
		//
        //
  		lcd.setCursor(5, 0);
    	lcd.print("SIGA!");
        
        lcd.setCursor(i, 1);//Posiciona o cursor para a coluna 0, linha 1 (segunda linha)
    	lcd.print("----------------");
        delay(800);
		lcd.clear();
  		
      }
  	lcd.setCursor(5, 0);
    lcd.print("SIGA!");
  	delay(800);
	lcd.clear();
  
    desligaLed();
  	apagarLedVerde();
  	delay(200);
    

  
}


//
//Final do Código