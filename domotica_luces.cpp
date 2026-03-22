import Foundation

// ==========================================================
// Avance 3: Módulo de Control Lumínico Inteligente
// Implementación en Swift para Sistemas de Domótica
// ==========================================================

struct ControladorOptico {
    let umbralReferencia: Int
    private(set) var lucesActivas: Bool = false
    private var historial: [Int] = []
    private let capacidadHistorial = 10

    init(umbral: Int) {
        self.umbralReferencia = umbral
    }

    mutating func procesarLectura(_ valorLDR: Int) {
        // Mantener el historial optimizado
        if historial.count >= capacidadHistorial {
            historial.removeFirst()
        }
        historial.append(valorLDR)

        // Lógica de control con histéresis (Swift Style)
        switch valorLDR {
        case ..<umbralReferencia where !lucesActivas:
            actualizarEstado(true)
        case (umbralReferencia + 80)... where lucesActivas:
            actualizarEstado(false)
        default:
            break
        }
        
        mostrarReporte(actual: valorLDR)
    }

    private mutating func actualizarEstado(_ nuevoEstado: Bool) {
        lucesActivas = nuevoEstado
        let mensaje = nuevoEstado ? "ENCENDIDO 💡" : "APAGADO 🌑"
        print("\n[ACTUADOR] Cambio de estado detectado: \(mensaje)")
    }

    func mostrarReporte(actual: Int) {
        let promedio = Double(historial.reduce(0, +)) / Double(historial.count)
        print("Lectura Actual: \(actual) | Promedio: \(String(format: "%.1f", promedio)) | Sistema: \(lucesActivas ? "Activo" : "Inactivo")")
    }
}

// --- Simulación del Ciclo de Monitoreo ---
print("--- Iniciando Servicio de Óptica (Swift) ---")
var miSistema = ControladorOptico(umbral: 420)

let lecturasSimuladas = [850, 600, 400, 380, 250, 500, 700, 900]

for lectura in lecturasSimuladas {
    miSistema.procesarLectura(lectura)
    Thread.sleep(forTimeInterval: 0.6)
}

print("\n--- Monitoreo Finalizado ---")
