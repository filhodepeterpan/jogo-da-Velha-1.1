*******************************

Desenvolvido por Douglas Soares
GitHub: @filhodepeterpan

*******************************

JOGO DA VELHA (PT-BR)
Linguagem: C++
IDE: Visual Studio 2022

O Jogo da Velha foi estruturado com base na aula de arrays no 1º ano de Informática para Internet na ETEC de Praia Grande, na matéria de Programação e Algoritmos.
Os jogadores começam fornecendo os seus nomes para uma eventual customização na forma que o programa refere-se a eles. Em seguida, o programa insere num tabuleiro(arquitetado com arrays) "X" ou "O", a depender do jogador da vez, em uma célula específica referenciada a partir da solicitação de uma linha e de uma coluna.
O vencedor é denominado a partir de uma função que confere se o jogador da vez preencheu três células diretamente ligadas horizontalmente, verticalmente ou diagonalmente.

VERSÃO 1.1:

- Novo método de organização no código. Adicionado protótipos de funções em uma biblioteca criada (arquivo de extensão .h) e um outro arquivo .cpp onde estão expostas as definições das funções.
- O terminal é configurado a partir do código para suportar a língua ptbr e o alfabeto UTF-8, eliminando os problemas de acentuação da versão 1.0
- REPLAY: Agora você pode repetir o jogo com mais facilidade. Ao invés de ter que abrir e fechar o jogo, você deve escolher ente uma nova partida ou finalizar o programa. Caso escolha uma nova partida, poderá selecionar entre inserir novos jogadores ou jogar com os mesmos da partida passada.
- CONTABILIZADOR DE VITÓRIAS: Ao encerrar o programa ou escolher inserir novos jogadores em uma nova partida, o programa exibe o nome dos jogadores da última partida e a quantidade de vezes que cada um venceu. Os empates também são contabilizados à parte.