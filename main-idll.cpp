#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>
#include "idll.h" // Inclui o cabeçalho da classe IDll

int main() {
    IDll list; // Cria uma instância da lista duplamente ligada
    std::string line, cmd; // Declara variáveis para armazenar as linhas de entrada e os comandos

    // Cria um mapa de strings para funções usando lambdas
    std::unordered_map<std::string, std::function<void(std::istringstream&)>> command_map;

    // Mapeia o comando "insert_0" para a função de inserção no início da lista
    command_map["insert_0"] = [&list](std::istringstream& iss) {
        int item;
        while (iss >> item) {
            list.insertAtStart(item);
        }
    };

    // Mapeia o comando "insert_end" para a função de inserção no fim da lista
    command_map["insert_end"] = [&list](std::istringstream& iss) {
        int item;
        while (iss >> item) {
            list.insertAtEnd(item);
        }
    };

    // Adiciona outros comandos ao mapa e associa cada um à sua função correspondente
    command_map["print_0"] = [&list](std::istringstream&) { list.printFirst(); };
    command_map["print_end"] = [&list](std::istringstream&) { list.printLast(); };
    command_map["print"] = [&list](std::istringstream&) { list.print(); };
    command_map["delete_0"] = [&list](std::istringstream&) {
        if (list.getSize() == 0) {
            std::cout << "Comando delete_0: Lista vazia!\n";
        } else {
            list.deleteFromStart();
        }
    };
    command_map["delete_end"] = [&list](std::istringstream&) {
        if (list.getSize() == 0) {
            std::cout << "Comando delete_end: Lista vazia!\n";
        } else {
            list.deleteFromEnd();
        }
    };
    command_map["dim"] = [&list](std::istringstream&) {
        std::cout << "Lista tem " << list.getSize() << " itens\n";
    };
    command_map["clear"] = [&list](std::istringstream&) {
        if (list.getSize() == 0) {
            std::cout << "Comando clear: Lista vazia!\n";
        } else {
            list.clear();
        }
    };
    command_map["find"] = [&list](std::istringstream& iss) {
        int item;
        if (iss >> item) {
            list.find(item);
        }
    };
    command_map["delete_pos"] = [&list](std::istringstream& iss) {
        int pos;
        if (iss >> pos) {
            list.deleteAtPos(pos);
        }
    };
    command_map["invert_range"] = [&list](std::istringstream& iss) {
        int pos1, pos2;
        if (iss >> pos1 >> pos2) {
            list.invertRange(pos1, pos2);
        }
    };
    command_map["find_max"] = [&list](std::istringstream&) {
        list.find_max();  // Executa a função para encontrar o máximo (implementação necessária na classe IDll)
    };

    // Processa cada linha de entrada
    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == '#') continue; // Ignora linhas vazias ou comentadas
        std::istringstream iss(line); // Cria um stringstream para a linha atual
        if (!(iss >> cmd)) continue; // Lê o comando da linha

        auto it = command_map.find(cmd); // Procura o comando no mapa
        if (it != command_map.end()) {
            it->second(iss);  // Executa a função associada ao comando, passando os parâmetros (se houver)
        } else {
            std::cout << "Comando desconhecido: " << cmd << "\n"; // Se o comando não for reconhecido, exibe uma mensagem de erro
        }
    }

    return 0;
}