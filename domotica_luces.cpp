#include <iostream>

class SistemaIluminacion {
private:
    bool estadoLuces;
    int umbralLuz;

public:
    SistemaIluminacion(int umbral) : umbralLuz(umbral), estadoLuces(false) {}

    void procesarSensor(int lecturaLDR) {
        // Si la luz ambiental es menor al umbral, encender luces
        if (lecturaLDR < umbralLuz && !estadoLuces) {
            estadoLuces = true;
            std::cout << "[DOMÓTICA] Luz ambiental baja (" << lecturaLDR << "). Encendiendo luces..." << std::endl;
        } 
        else if (lecturaLDR >= umbralLuz && estadoLuces) {
            estadoLuces = false;
            std::cout << "[DOMÓTICA] Luz ambiental suficiente (" << lecturaLDR << "). Apagando luces..." << std::endl;
        }
    }
};

int main() {
    SistemaIluminacion miCasa(400); // Umbral de 400 unidades
    
    // Simulación de lecturas de sensor
    int lecturas[] = {800, 600, 300, 200, 500};
    
    for (int l : lecturas) {
        miCasa.procesarSensor(l);
    }

    return 0;
}
