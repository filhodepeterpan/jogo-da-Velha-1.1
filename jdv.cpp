#include <iostream>
#include <string>
#include <cctype>
#include "jdv.h"

using namespace std;

string insereJogador(int numeroDoJogador){
    string nome;
    cout<<"Digite o nome do "<<numeroDoJogador<<"º jogador: ";
    getline(cin, nome);
    return nome;
}

void classificaJogador(string a, string b){
    cout<<"\n"<<a<<", você é o X.";
    cout<<"\n"<<b<<", você é o O.\n";
}

string mudaTurno(int m, string t, string a, string b){
    if(m%2!=0) {
        t=a;
    } 
    else{
        t=b;
    }
    return t;
}

char mudaSimbolo(int m, char s){
    if(m%2!=0){
        s='X';
    } 
    else{
        s='O';
    }
    return s;
}

void exibeTabuleiro(char A[3], char B[3], char C[3]){
    cout << "\n";
    cout << "    0  1   2\n";
    cout << "A: " << A[0] << " | " << A[1] << " | " << A[2] << "\n";
    cout << "B: " << B[0] << " | " << B[1] << " | " << B[2] << "\n";
    cout << "C: " << C[0] << " | " << C[1] << " | " << C[2] << "\n";
}

void limpaTabuleiro(char A[3], char B[3], char C[3]){
    for(int i=0; i<=2; i++){
        A[i]=' ';
        B[i]=' ';
        C[i]=' ';
    }
}

bool identificaVencedor(char A[3], char B[3], char C[3], char simbolo) {
    return(
        (A[0]==simbolo && A[1]==simbolo && A[2]==simbolo) ||
        (B[0]==simbolo && B[1]==simbolo && B[2]==simbolo) ||
        (C[0]==simbolo && C[1]==simbolo && C[2]==simbolo) ||
        (A[0]==simbolo && B[0]==simbolo && C[0]==simbolo) ||
        (A[1]==simbolo && B[1]==simbolo && C[1]==simbolo) ||
        (A[2]==simbolo && B[2]==simbolo && C[2]==simbolo) ||
        (A[0]==simbolo && B[1]==simbolo && C[2]==simbolo) ||
        (A[2]==simbolo && B[1]==simbolo && C[0]==simbolo)
    );
}

void exibeVitorias(string nomeJogador1, string nomeJogador2, int* vitoriasJogador1, int* vitoriasJogador2, int empates){
    cout<<"\nPONTUAÇÃO:\n\n";
    cout<<nomeJogador1<<": "<<*vitoriasJogador1<<"\n";
    cout<<nomeJogador2<<": "<<*vitoriasJogador2<<"\n";
    cout<<"Empates: "<<empates<<"\n";
}
