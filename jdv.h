#ifndef JDV_H
#define JDV_H

#include <string>

using namespace std;

string insereJogador(int);
void classificaJogador(string, string);
string mudaTurno(int, string, string, string);
char mudaSimbolo(int, char);
void exibeTabuleiro(char[3], char[3], char[3]);
void limpaTabuleiro(char[3], char[3], char[3]);
bool identificaVencedor(char[3], char[3], char[3], char);
void exibeVitorias(string, string, int*, int*, int);

#endif