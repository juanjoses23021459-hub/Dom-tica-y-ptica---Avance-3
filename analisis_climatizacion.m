#include <iostream>

// Configuración de Hardware (Simulada para C++ estándar)
const int PIN_LDR = 0;       // Entrada analógica
const int PIN_LED = 13;      // Salida digital
const int UMBRAL_LUZ = 500;  // Valor de activación (0-1023)
const int HISTERESIS = 50;   // Margen para evitar oscilaciones

bool estadoLuz = false;

void procesarControlLuminico(int lecturaLDR) {
    // Lógica de control con histéresis para domótica
    if (lecturaLDR < (UMBRAL_LUZ - HISTERESIS)) {
        estadoLuz = true;  // Encender: Hay poca luz
    } 
    else if (lecturaLDR > (UMBRAL_LUZ + HISTERESIS)) {
        estadoLuz = false; // Apagar: Hay suficiente luz natural
    }

    // Visualización del estado del sistema
    std::cout << "Lectura Sensor: " << lecturaLDR 
              << " | Iluminación: " << (estadoLuz ? "[ENCENDIDA]" : "[APAGADA]") 
              << std::endl;
}

int main() {
    // Simulación de un ciclo de monitoreo
    int lecturasSimuladas[] = {800, 600, 400, 420, 550, 700};
    
    std::cout << "--- Sistema de Control Óptico Automático ---" << std::endl;

    for (int lectura : lecturasSimuladas) {
        procesarControlLuminico(lectura);
    }

    return 0;
}
