#include "idll.h" // Inclui o cabeçalho da classe IDll

// Função auxiliar para apagar um nó
void deleteNode(INode* node) {
    delete node; // Apaga o nó da memória
}

// Construtor da classe IDll
IDll::IDll() : head(nullptr), tail(nullptr), size(0) {}

// Destrutor da classe IDll
IDll::~IDll() {
    clear(); // Chama a função clear() para libertar a memória ocupada pelos nós
}

// Retorna o tamanho da lista
int IDll::getSize() const {
    return size;
}

// Insere um novo nó com o valor item no início da lista
void IDll::insertAtStart(int item) {
    INode* newNode = new INode(item, nullptr, head); // Cria um novo nó
    if (head != nullptr) {
        head->prev = newNode; // Atualiza o ponteiro prev do nó cabeça
    } else {
        tail = newNode; // Atualiza o ponteiro cauda se a lista estiver vazia
    }
    head = newNode; // Atualiza o ponteiro cabeça
    size++; // Incrementa o tamanho da lista
}

// Insere um novo nó com o valor item no final da lista
void IDll::insertAtEnd(int item) {
    INode* newNode = new INode(item, tail, nullptr); // Cria um novo nó
    if (tail != nullptr) {
        tail->next = newNode; // Atualiza o ponteiro next do nó cauda
    } else {
        head = newNode; // Atualiza o ponteiro cabeça se a lista estiver vazia
    }
    tail = newNode; // Atualiza o ponteiro cauda
    size++; // Incrementa o tamanho da lista
}

// Remove o nó do início da lista
void IDll::deleteFromStart() {
    if (head == nullptr) return; // Verifica se a lista está vazia
    INode* temp = head; // Armazena o endereço do nó a ser removido
    head = head->next; // Atualiza o ponteiro cabeça
    if (head != nullptr) {
        head->prev = nullptr; // Atualiza o ponteiro prev do novo nó cabeça
    } else {
        tail = nullptr; // Atualiza o ponteiro cauda se a lista ficar vazia
    }
    deleteNode(temp); // Apaga o nó
    size--; // Decrementa o tamanho da lista
}

// Remove o nó do final da lista
void IDll::deleteFromEnd() {
    if (tail == nullptr) return; // Verifica se a lista está vazia
    INode* temp = tail; // Armazena o endereço do nó a ser removido
    tail = tail->prev; // Atualiza o ponteiro cauda
    if (tail != nullptr) {
        tail->next = nullptr; // Atualiza o ponteiro next do novo nó cauda
    } else {
        head = nullptr; // Atualiza o ponteiro cabeça se a lista ficar vazia
    }
    deleteNode(temp); // Apaga o nó
    size--; // Decrementa o tamanho da lista
}

// Remove todos os nós da lista
void IDll::clear() {
    while (head != nullptr) {
        INode* temp = head; // Armazena o endereço do nó a ser removido
        head = head->next; // Atualiza o ponteiro cabeça
        deleteNode(temp); // Apaga o nó
    }
    tail = nullptr; // Reseta o ponteiro cauda
    size = 0; // Reseta o tamanho da lista
}

// Imprime os elementos da lista
void IDll::print() {
    if (head == nullptr) {
        std::cout << "Comando print: Lista vazia!\n"; // Se a lista estiver vazia, imprime uma mensagem
        return;
    }

    INode* current = head; // Inicia a partir do nó cabeça
    std::cout << "Lista= "; // Imprime a mensagem inicial
    while (current != nullptr) { // Itera sobre todos os nós
        std::cout << current->item; // Imprime o valor do nó atual
        if (current->next != nullptr) {
            std::cout << " "; // Imprime um espaço entre os elementos
        }
        current = current->next; // Move para o próximo nó
    }
    std::cout << "\n"; // Imprime uma nova linha no final
}

// Imprime o primeiro elemento da lista
void IDll::printFirst() {
    if (head != nullptr) {
        std::cout << "Lista(0)= " << head->item << "\n"; // Se a lista não estiver vazia, imprime o primeiro elemento
    }
}

// Imprime o último elemento da lista
void IDll::printLast() {
    if (tail != nullptr) {
        std::cout << "Lista(end)= " << tail->item << "\n"; // Se a lista não estiver vazia, imprime o último elemento
    }
}

// Procura por um elemento na lista e imprime a sua posição
void IDll::find(int item) {
    int index = 0; // Inicia o índice a partir de zero
    for (INode* current = head; current != nullptr; current = current->next) { // Itera sobre todos os nós
        if (current->item == item) {
            std::cout << "Item " << item << " na posicao " << index << "\n"; // Se encontrar o elemento, imprime a sua posição
            return;
        }
        index++; // Incrementa o índice
    }
    std::cout << "Item " << item << " nao encontrado!\n"; // Se o elemento não for encontrado, imprime uma mensagem
}

// Remove o nó na posição especificada
void IDll::deleteAtPos(int pos) {
    if (pos < 0 || pos >= size) {
        std::cout << "Comando delete_pos: Posicao invalida!\n"; // Se a posição for inválida, imprime uma mensagem de erro
        return;
    }
    if (pos == 0) {
        deleteFromStart(); // Se a posição for zero, remove o primeiro nó
        return;
    }
    if (pos == size - 1) {
        deleteFromEnd(); // Se a posição for a última, remove o último nó
        return;
    }

    INode* current = head; // Inicia a partir do nó cabeça
    for (int i = 0; i < pos; i++) {
        current = current->next; // Move para o nó na posição especificada
    }

    current->prev->next = current->next; // Atualiza os ponteiros para remover o nó
    current->next->prev = current->prev;
    deleteNode(current); // Apaga o nó
    size--; // Decrementa o tamanho da lista
}

// Inverte a ordem dos elementos entre as posições pos1 e pos2
void IDll::invertRange(int pos1, int pos2) {
    if (pos1 < 0 || pos2 >= size || pos1 > pos2) {
        std::cout << "Comando invert_range: Posicao invalida!\n"; // Se as posições forem inválidas, imprime uma mensagem de erro
        return;
    }

    INode *current1 = head, *current2 = tail; // Inicia a partir dos nós cabeça e cauda
    for (int i = 0; i < pos1; i++) current1 = current1->next; // Move para o nó na posição pos1
    for (int i = size - 1; i > pos2; i--) current2 = current2->prev; // Move para o nó na posição pos2

    while (current1 != current2 && current1->prev != current2) { // Enquanto os nós não se encontram
        std::swap(current1->item, current2->item); // Troca os valores dos nós
        current1 = current1->next; // Move para o próximo nó
        current2 = current2->prev; // Move para o nó anterior
    }
}

// Encontra o elemento máximo na lista e imprime a sua posição
void IDll::find_max() {
    if (head == nullptr) {
        std::cout << "Comando find_max: Lista vazia!\n"; // Se a lista estiver vazia, imprime uma mensagem de erro
        return;
    }

    int maxItem = head->item; // Inicia o valor máximo com o valor do primeiro elemento
    int maxPosition = 0; // Inicia a posição máxima com zero
    int currentPosition = 0; // Inicia a posição atual com zero
    INode* current = head; // Inicia a partir do nó cabeça

    while (current != nullptr) { // Itera sobre todos os nós
        if (current->item > maxItem) { // Se encontrar um valor maior
            maxItem = current->item; // Atualiza o valor máximo
            maxPosition = currentPosition; // Atualiza a posição máxima
        }
        current = current->next; // Move para o próximo nó
        currentPosition++; // Incrementa a posição atual
    }

    std::cout << "Max Item " << maxItem << " na posicao " << maxPosition << "\n"; // Imprime o valor máximo e a sua posição
}