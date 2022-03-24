 ### Gerenciador-de-Busca-de-Carros-AEDs2
Trabalho de Algoritmos e Estruturas de Dados

#
### Enunciado
Data de entrega: 25 de mar.

### Objetivo:

adquirir conhecimentos de manipulação de listas com alocação dinâmica (lista ligada ou encadeada) numa aplicação que cria uma pilha e uma fila como resultado da busca numa lista principal de carros, vans e utilitários.

### Descrição:

o aplicativo desenvolvido no projeto deve criar uma lista ligada principal com os dados lidos de um arquivo de entrada. Cada linha do arquivo deve ser armazenada em um nó da lista. Então o aplicativo deve construir uma pilha e uma fila a partir de buscas realizadas na lista principal, sem realocar ou duplicar os nós da lista principal, mediante as 2 opções selecionadas. Além disso também devem ser implementadas as funções de inserção e remoção de nós da lista principal.

Arquivo de Dados: conterá um número ilimitado de linhas, onde cada linha conterá os dados de um veículo: modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, número de portas e placa. Segue em anexo um arquivo-texto de exemplo.

Requisitos:
o aplicativo deverá:
apresentar um menu ao usuário com as opções de inclusão, exclusão, buscas e relatório;
realizar buscas na lista criada permitindo configurar as opções com algumas características: resultado em pilha ou fila, escolha da 1ª opção e escolha da 2ª opção;
o resultado da busca deve permanecer na memória até que uma nova busca for realizada;
as opções são escolhidas pelos dados do veículo;
quando terminar a busca apresente os dados na tela;
realizar a operação de inclusão de forma ordenada pela placa do veículo;
apresentar o relatório de todos os clientes na tela do computador;
ao final da execução todas as estruturas devem ser desalocadas.
![estrutura2](https://user-images.githubusercontent.com/61283617/159601892-6a4ed160-7e6a-4ac5-b23e-2557d0dd15b1.png)


    arquivo >> c1.modelo;
    arquivo >> c1.marca;
    arquivo >> c1.tipo;
    arquivo >> c1.ano;
    arquivo >> c1.km;
    arquivo >> c1.potencia;
    arquivo >> c1.combustivel;
    arquivo >> c1.cambio;
    arquivo >> c1.direcao;
    arquivo >> c1.cor;
    arquivo >> c1.portas;
    arquivo >> c1.placa;