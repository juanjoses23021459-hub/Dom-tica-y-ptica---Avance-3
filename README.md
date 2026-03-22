#include <iostream>
#include <string>

struct Alarma {
    bool armada;
    int nivelSeguridad; // 1: Bajo, 2: Alto
};

void checkSeguridad(Alarma sistema, bool movimientoDetectado) {
    if (sistema.armada && movimientoDetectado) {
        std::cout << "!!! ALERTA !!! Movimiento detectado en zona restringida." << std::endl;
        if (sistema.nivelSeguridad == 2) {
            std::cout << ">> Enviando notificación al smartphone y activando sirena." << std::endl;
        }
    } else {
        std::cout << "Estado: Sistema seguro." << std::endl;
    }
}

int main() {
    Alarma casaJuan = {true, 2}; // Alarma armada en modo alto
    
    std::cout << "Monitoreando..." << std::endl;
    checkSeguridad(casaJuan, false); // Todo tranquilo
    checkSeguridad(casaJuan, true);  // Se detecta alguien
    
    return 0;
}
