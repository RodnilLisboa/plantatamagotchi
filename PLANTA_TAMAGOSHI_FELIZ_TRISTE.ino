#include <LedControl.h>

// Define os pinos para comunicação com o MAX7219
#define DATA_IN 3
#define CLK 6
#define CS 5
#define SENSOR_PIN A0

// Cria uma instância do LedControl
LedControl dotMatrixDisplay = LedControl(DATA_IN, CLK, CS, 1);

// Variável para armazenar o valor de umidade
int Umidade = 0;

void setup() {
  // Configura a matriz de LEDs
  dotMatrixDisplay.shutdown(0, false); // Inicializa a matriz de LEDs
  dotMatrixDisplay.setIntensity(0, 8); // Define a intensidade do brilho (0-15)
  dotMatrixDisplay.clearDisplay(0);    // Limpa a matriz de LEDs

  // Configura o pino do sensor como entrada
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do sensor de umidade
  Umidade = analogRead(SENSOR_PIN);

  // Exibe umidade no monitor serial
  Serial.println(Umidade);

  // Define o padrão de LED com base no valor de umidade
  if (Umidade < 600) {
    // Exibe um rosto feliz
    displayHappyFace();
  } else {
    // Limpa a matriz de LEDs quando a umidade for baixa
    displaySadFace();
  }
}

// Função para exibir um rosto feliz na matriz de LEDs
void displayHappyFace() {
  byte happyFace[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  };
  for (int i = 0; i < 8; i++) {
    dotMatrixDisplay.setRow(0, i, happyFace[i]);
  }
}

  void displaySadFace() {
  byte sadFace[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100
  };
   for (int i = 0; i < 8; i++) {
    dotMatrixDisplay.setRow(0, i, sadFace[i]);
  }
  }

  

