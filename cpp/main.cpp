#include <iostream>

int main() {

    double temperatura_atual; // 28.5f = float
    const int limite_temperatura = 30;
    bool ventoinha_ligada = false;
 
    std::cout << " === Controlador de temperatura === \n"; 
    std::cout << "Limite de temperatura: " << limite_temperatura << "\n";

    while (true) {
        std::cout << "Digite a temperatura atual: ";
        std::cin  >> temperatura_atual;

        if (temperatura_atual >= limite_temperatura) {
            ventoinha_ligada = true;
            std::cout << "Ventoinha ligada\n";
        }
        else {
            ventoinha_ligada = false;
            std::cout << "Ventoinha desligada\n";
        }
    }
  
    return 0;
}