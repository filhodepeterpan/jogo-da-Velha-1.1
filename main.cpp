#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>
#include <locale>
#include "jdv.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    string jogador1, jogador2;
    string vezDoJogador;
    string vencedor;
    char simbolo;
    char resposta;
    char A[3]={ ' ', ' ', ' ' };
    char B[3]={ ' ', ' ', ' ' };
    char C[3]={ ' ', ' ', ' ' };
    string linha;
    int coluna;
    int marcacoes=1;
    int opcao;
    int vitoriasJogador1=0;
    int vitoriasJogador2=0;
    int empates=0;
    bool novoJogo=true;

    cout<<"Vamos jogar o jogo da velha! Você precisa de 2 pessoas para jogar.\n\n";

    jogador1=insereJogador(1);
    jogador2=insereJogador(2);
    classificaJogador(jogador1, jogador2);

    while (novoJogo==true){
        while(marcacoes<=9){
            exibeTabuleiro(A, B, C);

            vezDoJogador=mudaTurno(marcacoes, vezDoJogador, jogador1, jogador2);
            simbolo=mudaSimbolo(marcacoes, simbolo);

            cout<<"\n"<<vezDoJogador<<", é a sua vez de jogar. Escolha o espaço que deseja preencher com "<< simbolo<< ", começando pela linha: ";
            cin>>linha;

            while(linha!="A" && linha!="B" && linha!="C" && linha!="a" && linha!="b" && linha!="c"){
                cout<<"Linha inválida. Escolha apenas A, B ou C: ";
                cin>>linha;
            }

            cout<<"\nAgora escolha a coluna: ";
            cin>>coluna;

            while(coluna>2 || coluna<0 || !cin){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Digite apenas um número: ";
                }
                else{
                    cout<<"Coluna inválida. Escolha apenas 0, 1 ou 2: ";
                }
                cin>>coluna;
            }

            if((linha=="A" || linha=="a") && A[coluna]==' '){
                A[coluna]=simbolo;
            } 
            else if((linha=="B" || linha=="b") && B[coluna]==' '){
                B[coluna] = simbolo;
            } 
            else if((linha=="C" || linha=="c") && C[coluna]==' '){
                C[coluna]=simbolo;
            } 
            else{
                cout<<"\nEsse espaço já está preenchido. Tente novamente:\n";
                continue;
            }

            if(identificaVencedor(A, B, C, simbolo)==true){
                vencedor=vezDoJogador;

                if(vencedor==jogador1){
                    vitoriasJogador1++;
                } 
                else if(vencedor==jogador2){
                    vitoriasJogador2++;
                }
                break;
            }
            marcacoes++;
        }

        exibeTabuleiro(A, B, C);

        if(vencedor==vezDoJogador){
            cout<<"\nParabéns "<<vencedor<<", você venceu o jogo!\n";
        } 
        else{
            cout<<"\nDeu velha! Vocês empataram.\n";
            empates++;
        }

        cout<<"\nDeseja jogar novamente? Responda 'S' para sim e 'N' para não: ";
        cin>>resposta;
        cout<<"\n";

        if(resposta=='S' || resposta=='s'){
            cout<<"Digite a opção que deseja para iniciar um novo jogo:\n\n1 - Jogar com os mesmos jogadores\n2 - Inserir novos jogadores\n\n";
            cin>>opcao;

            while(opcao!=1 && opcao!=2 && isalpha(opcao)){
                "\n\nOpção Inválida. Digite apenas 1 ou 2: ";
                cin >> opcao;
            }
            
            if(opcao==1){
                exibeVitorias(jogador1, jogador2, &vitoriasJogador1, &vitoriasJogador2, empates);
                novoJogo=true;
                marcacoes=1;
                limpaTabuleiro(A, B, C);
            } 
            else if(opcao==2){
                exibeVitorias(jogador1, jogador2, &vitoriasJogador1, &vitoriasJogador2, empates);
                novoJogo=true;
                marcacoes=1;
                vitoriasJogador1=0;
                vitoriasJogador2=0;
                empates=0;
                limpaTabuleiro(A, B, C);
                cin.ignore();
                cout<<"\n";
                jogador1=insereJogador(1);
                jogador2=insereJogador(2);
                classificaJogador(jogador1, jogador2);
            }
        } 
        else{
            exibeVitorias(jogador1, jogador2, &vitoriasJogador1, &vitoriasJogador2, empates);
            novoJogo=false;
        }
    }
    cout<<"\nObrigado por jogar :)\n\nDesenvolvido por Douglas Soares\nGithub: @filhodepeterpan";

    return 0;
}
