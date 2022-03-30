#include <fstream>
#include "biblioteca.cpp"
#include <cstdlib>

using namespace std;

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

//Inicio

struct Carro;

class No;

class Lista;

class Pilha;

class Fila;

int menu();

void exibeCarro(Carro c1);

void exibeLista(No* cabeca);

void removeEspecifico(Carro c, Lista* lista);

void removeColetivo(Carro c, Lista* lista);

void buscaPilha(Carro c1,Carro c2,No* cabecaLista,Pilha* pilha);

void buscaFila(Carro c1,Carro c2,No* cabecaLista,Fila* fila);

void lerParaLista(Lista *lista);

void incluirVeiculo(Lista* lista);

#endif