#ifndef IDLL_H
#define IDLL_H

#include <iostream>

// Definição do nó da lista
struct INode {
    int item;       // Valor armazenado no nó
    INode* prev;    // Ponteiro para o nó anterior
    INode* next;    // Ponteiro para o próximo nó

    // Construtor para inicializar um nó com valores padrão
    INode(int item, INode* prev = nullptr, INode* next = nullptr)
        : item(item), prev(prev), next(next) {}
};

// Definição da classe da lista duplamente ligada
class IDll {
private:
    INode* head;    // Ponteiro para o primeiro nó da lista
    INode* tail;    // Ponteiro para o último nó da lista
    int size;       // Tamanho atual da lista

public:
    // Construtor da classe IDll
    IDll();

    // Destrutor da classe IDll
    ~IDll();
    
    // Retorna o tamanho da lista
    int getSize() const;
    
    // Insere um novo nó com o valor item no início da lista
    void insertAtStart(int item);

    // Insere um novo nó com o valor item no final da lista
    void insertAtEnd(int item);

    // Remove o nó do início da lista
    void deleteFromStart();

    // Remove o nó do final da lista
    void deleteFromEnd();

    // Remove todos os nós da lista
    void clear();

    // Imprime os elementos da lista
    void print();

    // Imprime o primeiro elemento da lista
    void printFirst();

    // Imprime o último elemento da lista
    void printLast();

    // Procura por um elemento na lista e imprime a sua posição
    void find(int item);

    // Remove o nó na posição especificada
    void deleteAtPos(int pos);

    // Inverte a ordem dos elementos entre as posições pos1 e pos2
    void invertRange(int pos1, int pos2);

    // Encontra o elemento máximo na lista e imprime a sua posição
    void find_max();
};

#endif