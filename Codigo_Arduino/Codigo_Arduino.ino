
// Programa : Contador utilizando display 7 segmentos,
//            TCRT5000  e botao reset
// Autor : Arduino e Cia  
  
// Carrega a biblioteca SevSeg
#include "SevSeg.h"   

SevSeg sevseg;  

// Cria variaveis globais  
int contador = 0;  

// Ligado ao pino "coletor" do sensor óptico - Porta A5 ao Arduino  
int pinosensor = 19; 
// Pino ligado ao botao de reset
int pino_botao_reset = A0;
// Armazena o valor lido pelo sensor optico
int leitura; 
// Armazena o estado do botao reset
int estadobotao = 0; 

void setup() 
{  
  // Utilizando display de anodo comum, 
  // pinos dos digitos : 10 a 13  
  // Pino dos segmentos : 2 a 9  
  sevseg.Begin(1,13,10,11,12,2,3,4,5,6,7,8,9);  
  // Controla a luminosidade - 0 a 100  
  sevseg.Brightness(20);  
  // Define o pino do sensor optico como entrada 
  pinMode(pinosensor, INPUT);  
  // Define o pino do botao reset como entrada
  pinMode(pino_botao_reset, INPUT);
}  
   
void loop() 
{  
  sevseg.PrintOutput();  
  sevseg.NewNum(contador,(byte) 2);
  
  // Verifica se o botao reset foi pressionado
  estadobotao = digitalRead(pino_botao_reset);
  if (estadobotao != 1)
  {
    // Zera o contador
    contador = 0;
  }

  // Le as informações do pino do sensor optico
  leitura = digitalRead(pinosensor);
  // Verifica se o objeto foi detectado pelo sensor
  if (leitura != 1) 
  {  
    // Incrementa o valor do contador
    contador = contador++;   

    // Loop caso o objeto pare sobre o sensor 
    while(digitalRead(pinosensor) != 1)  
    {  
     sevseg.PrintOutput();  
     sevseg.NewNum(contador,(byte) 2);  
    }  
  }   
}
