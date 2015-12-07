# Cancela

Este projeto é um sistema de cancela para a entrada de um estacionamento de carros. A cancela deve liberar a entrada do carro após o motorista apertar um botão e retirar o cartão. Em seguida, a cancela fecha quando o carro terminar de passar por ela.

Para isso, são utilizados os seguintes componentes:

1. um Arduino Uno, para controlar e integrar os outros componentes;
2. um motor de passo, para abrir e fechar a cancela;
3. um motor DC, para a emissão do cartão;
4. um botão, para o motorista solicitar o cartão e a abertura da cancela;
5. dois sensores de luminosidade, para detectar quando o carro se aproxima e quando ele está passando pela cancela;
6. uma fonte de luz, para garantir o bom funcionamento dos sensores em qualquer momento;
7. um display LCD, para exibir mensagens;
8. um speaker, para emitir mensagens de voz.

# Esquemático

Disponível [aqui](http://schematics.com/project/cancela-24156/).

![Esquemático](/Esquematico.png)

# Implementação

## Motor de passo
Para o controle do motor de passo, utilizou-se a biblioteca *Stepper.h*, que foi apresentada durante a disciplina e contém funções para determinar a velocidade do motor e o número de passos que se deseja movimentar.

## Motor DC
O motor DC, neste projeto, tem a única função de emitir o cartão e, portanto, gira sempre na mesma direção. Sendo assim, sua implementação em hardware é simples, sem a necessidade de uma ponte H, apenas um transistor. 

## Sensor de luminosidade
Foram utilizados dois sensores de luminosidade do kit Grove. Um deles se localiza próximo a onde está o botão que o motorista deve apertar e, assim, reconhece quando o carro está lá. O outro se localiza exatamente onde está a cancela, a fim de detectar quando o carro passa por ela e libera seu fechamento.

## Display
Utilizou-se um display LCD de 16 colunas e 2 linhas, e a biblioteca *LiquidCrystal.h*, que permite escrever no display facilmente usando a função print(). A implementação em hardware foi feita seguindo o esquemático abaixo.

![Esquemático do LCD](/Esquematico LCD.png)

## Sintetização de voz
Para emitir mensagens de voz, conectou-se uma caixa de som e utilizou-se, a princípio, a biblioteca *TTS.h*, uma biblioteca de sintetização text-to-speech para Arudino desenvolvida por [Stephen Crane](https://github.com/jscrane/TTS/blob/master/TTS.h). Com essa biblioteca, pode-se escrever em uma string o texto a ser convertido em voz e basta utilizar a função say() para realizar a conversão.

Houve, contudo, alguns problemas com essa implementação: 
em primeiro lugar, só se leem strings em inglês;
além disso, a voz é semelhante a de um robô e, assim, é basicamente incompreensível.
Como alternativa, foi utilizada a biblioteca *talkie.h*, desenvolvida por [Peter Knight](https://github.com/going-digital/Talkie), com funcionamento semelhante à opção anterior. Esta biblioteca ainda só emite mensagens em inglês, mas elas são muito mais inteligíveis.

# Vídeo

Disponivel [aqui](https://www.youtube.com/watch?v=om_v2uHnFMI).
