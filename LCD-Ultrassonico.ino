// inclui a bibilioteca do lcd
#include <LiquidCrystal.h>

// inicializa para a biblioteca os pinos do lcd
LiquidCrystal telinha(12, 11, 5, 4, 3, 2);

//defindo os pinos trigger e echo do ultrassonico
#define pino_echo 8
#define pino_trigger 9

//criando variaveis para o calculo da distancia dada pelo tempo do ultrassonico
float tempo;
float distancia;

void setup() {

  Serial.begin(9600); //determinando a conexao serial com uma taxa de 9600
  telinha.begin(16, 2);  // configura o numero de linhas e colunas do lcd
  pinMode(pino_echo, INPUT); //configurando o pino echo como input (entrada)
  pinMode(pino_trigger, OUTPUT); //configurando o pino trigger como output (saida)


}

void loop() {

  //geraçao de trem de pulso para o funcionamento do ultrassonico
  digitalWrite(pino_trigger, LOW); //trigger em LOW por 2 microsegundos
  delayMicroseconds(2);
  digitalWrite(pino_trigger, HIGH); //trigger em HIGH por 2 microsegundos
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW); //trigger em LOW por 2 microsegundos
  delayMicroseconds(2);

  //salvando os valores nas variaveis
  tempo = pulseIn(pino_echo, HIGH);
  distancia = DISTANCIAMETRO(tempo);

  telinha.setCursor(0, 0); //colando o inicio do texto que sera impresso na coluna 6 da linha 1
  telinha.print("Dist: "); //imprimindo o texto distancia no lcd

  telinha.setCursor(6, 0); //colando o inicio do texto que sera impresso na coluna 6 da linha 1
  telinha.print(distancia); //imprimindo o valor da variavel distancia no lcd
  
  telinha.setCursor(12, 0);
  telinha.print("cm   ");
  
  delay(100);
  
}

int DISTANCIAMETRO(float TEMPO)
{
  int D = 0;
  D = (0.0343) * (TEMPO / 2);
  return (D);

}
