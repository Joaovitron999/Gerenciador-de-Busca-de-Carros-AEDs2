/*------------------------------------------------------------------------/
/ Universidade Federal de Alfenas -Gerenciador-de-Busca-de-Carros-AEDs2  /
/ Nome: Caio Eduardo Marcondes     // Matrícula: 2020.1.08.035          /
/ Nome: João Vitor Fonseca         // Matrícula: 2020.1.08.003         /
/ Nome: Pedro Henrique Borges Luiz // Matrícula: 2020.1.08.036        /
/ Data: 2022                                                         /
-------------------------------------------------------------------*/

#include <stdlib.h>
#include "biblioteca.h"
#include <iostream>
#include <fstream>
#include <locale.h>

//Main

int main(){
  int resposta;
  Lista mainLista;
  Pilha pilha;
  Fila fila;

  string relatorio = "";
  
  lerParaLista(&mainLista);
  string aux;
  Carro carroR;

  //parametros para busca em fila com 2 
  Carro carroP1;
  Carro carroP2;

  do{
      resposta = menu(); //Loop comentado 
      switch (resposta)
      {
       case 1:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          exibeLista(mainLista.cabeca);
          relatorio=(relatorio+"Lista exibida | ");
       break;
    
       case 2:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          incluirVeiculo(&mainLista);
          relatorio=(relatorio+"Carro incluído | ");
       break;
        
        case 3:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "\n\t\t\t Escreva o conjunto que deseja excluir\n \n\tPor exemplo - Digite 'RENAULT' para excluir todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
          
            
            cin >> aux;
            carroR.modelo = aux;
            carroR.marca = aux;
            carroR.tipo = aux;
            carroR.ano = aux;
            carroR.km = aux;
            carroR.potencia = aux;
            carroR.combustivel = aux;
            carroR.cambio = aux;
            carroR.direcao = aux;
            carroR.cor = aux;
            carroR.portas = aux;
            carroR.placa = aux;            
            
            removeColetivo(carroR,&mainLista);
            removeColetivo(carroR,&mainLista);
            relatorio=(relatorio+"Exclusão coletiva ("+aux+")  |");  
        break;
  
        case 4:
            system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
            cout << "\n\t\t\tPlaca do veículo a ser excluido: ";
            
            cin >> carroR.placa;
            removeEspecifico(carroR,&mainLista);
            removeEspecifico(carroR,&mainLista);
            relatorio=(relatorio+"Exclusão de Carro ESPECÍFICO ("+carroR.placa+") | ");
        break;

        case 5:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "\n\t\t\t Escreva a primeira opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
          cin >> aux;
          carroP1.modelo = aux;
          carroP1.marca = aux;
          carroP1.tipo = aux;
          carroP1.ano = aux;
          carroP1.km = aux;
          carroP1.potencia = aux;
          carroP1.combustivel = aux;
          carroP1.cambio = aux;
          carroP1.direcao = aux;
          carroP1.cor = aux;
          carroP1.portas = aux;
          carroP1.placa = aux;    
          

          cout << "\n\t\t\t Adicionar mais um filtro á busca? (1)SIM,(2)Não\n \n\t";
          cin >> aux;
          if(aux=="1"){
            cout << "\n\t\t\t Escreva a segunda opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
            cin >> aux;
            carroP2.modelo = aux;
            carroP2.marca = aux;
            carroP2.tipo = aux;
            carroP2.ano = aux;
            carroP2.km = aux;
            carroP2.potencia = aux;
            carroP2.combustivel = aux;
            carroP2.cambio = aux;
            carroP2.direcao = aux;
            carroP2.cor = aux;
            carroP2.portas = aux;
            carroP2.placa = aux;    

            
            buscaPilha(carroP1,carroP2,mainLista.cabeca,&pilha);
          }else{
            buscaPilha(carroP1,carroP1,mainLista.cabeca,&pilha);            
          }

          exibeLista(pilha.cabeca);
          
        break;

        case 6:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "\n\t\t\t Escreva a primeira opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
          cin >> aux;
          carroP1.modelo = aux;
          carroP1.marca = aux;
          carroP1.tipo = aux;
          carroP1.ano = aux;
          carroP1.km = aux;
          carroP1.potencia = aux;
          carroP1.combustivel = aux;
          carroP1.cambio = aux;
          carroP1.direcao = aux;
          carroP1.cor = aux;
          carroP1.portas = aux;
          carroP1.placa = aux;    
          

          cout << "\n\t\t\t Adicionar mais um filtro á busca? \n\t\t\t(1)SIM, (2)Não\n \n\t";
          cin >> aux;
          if(aux=="1"){
            cout << "\n\t\t\t Escreva a segunda opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
            cin >> aux;
            carroP2.modelo = aux;
            carroP2.marca = aux;
            carroP2.tipo = aux;
            carroP2.ano = aux;
            carroP2.km = aux;
            carroP2.potencia = aux;
            carroP2.combustivel = aux;
            carroP2.cambio = aux;
            carroP2.direcao = aux;
            carroP2.cor = aux;
            carroP2.portas = aux;
            carroP2.placa = aux;    

            
            buscaFila(carroP1,carroP2,mainLista.cabeca,&fila);
          }else{
            buscaFila(carroP1,carroP1,mainLista.cabeca,&fila);            
          }

          exibeLista(fila.cabeca);
          
        break;
  
        case 7:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "RELATÓRIO DO USUÁRIO:  | ";
          cout <<  relatorio;
        break;
       
        
      }
  }while(resposta!=0);

  return 0;
}