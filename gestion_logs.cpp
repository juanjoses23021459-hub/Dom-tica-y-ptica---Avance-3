#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void registrarEvento(std::string dispositivo, std::string estado) {
    std::ofstream archivoLog;
    archivoLog.open("sistema_domotico.log", std::ios_base::app); // Abrir en modo append
    
    if (archivoLog.is_open()) {
        std::time_t ahora = std::time(nullptr);
        std::string dt = std::ctime(&ahora);
        dt.pop_back(); // Quitar el salto de línea de ctime

        archivoLog << "[" << dt << "] " << dispositivo << " -> " << estado << std::endl;
        archivoLog.close();
        std::cout << "Evento registrado exitosamente." << std::endl;
    }
}

int main() {
    registrarEvento("Cerradura Inteligente", "BLOQUEADA");
    registrarEvento("Sensor Movimiento Patio", "DETECTADO");
    return 0;
}
