import java.util.ArrayList;
import java.util.List;

public class GestionIluminacion {

    private final int umbralActivacion;
    private boolean lucesEncendidas;
    private final List<Integer> historialLecturas;
    private static final int MAX_HISTORIAL = 50; // Límite para evitar saturar memoria

    public GestionIluminacion(int umbral) {
        this.umbralActivacion = umbral;
        this.lucesEncendidas = false;
        this.historialLecturas = new ArrayList<>();
    }

    public void analizarEntradaOptica(int lecturaLDR) {
        // Mantener el historial bajo control
        if (historialLecturas.size() >= MAX_HISTORIAL) {
            historialLecturas.remove(0);
        }
        historialLecturas.add(lecturaLDR);
        
        // Lógica de control con histéresis (umbral + 100 para evitar parpadeo)
        if (lecturaLDR < umbralActivacion && !lucesEncendidas) {
            setEstadoLuces(true);
        } else if (lecturaLDR > (umbralActivacion + 100) && lucesEncendidas) {
            setEstadoLuces(false);
        }
        
        imprimirEstadoActual(lecturaLDR);
    }

    // Método para obtener el promedio (Filtro digital básico)
    public double getPromedioLecturas() {
        if (historialLecturas.isEmpty()) return 0;
        return historialLecturas.stream().mapToInt(Integer::intValue).average().orElse(0.0);
    }

    private void setEstadoLuces(boolean estado) {
        this.lucesEncendidas = estado;
        String accion = estado ? "ENCENDIENDO" : "APAGANDO";
        System.out.println("\n[SISTEMA] >> COMANDO: " + accion + " luces del sector...");
    }

    private void imprimirEstadoActual(int actual) {
        String icono = lucesEncendidas ? "💡 [ON]" : "🌑 [OFF]";
        System.out.printf("Sensor LDR: %4d | Promedio: %6.1f | Estado: %s %n", 
                          actual, getPromedioLecturas(), icono);
    }

    public static void main(String[] args) {
        System.out.println("--- Monitor de Sensores Ópticos v3.0 ---");
        
        GestionIluminacion pasilloPrincipal = new GestionIluminacion(400);
        
        // Simulación de cambios de luz ambiental (Dia -> Noche -> Amanecer)
        int[] simulacionDia = {900, 750, 500, 380, 200, 450, 600, 850};
        
        for (int lectura : simulacionDia) {
            pasilloPrincipal.analizarEntradaOptica(lectura);
            try {
                Thread.sleep(800); 
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt(); // Buena práctica en Java
            }
        }
    }
}
