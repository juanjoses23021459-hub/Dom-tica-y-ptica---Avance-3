% ==========================================================
% Avance 3: Control de Iluminación Automatizada (Óptica/Domótica)
% Fecha: 21 de marzo de 2026
% ==========================================================

% Limpieza del entorno
clear; clc; close all;

% Parámetros de configuración
umbral_luz = 2.5; % Voltaje de referencia (0-5V)
fueste_muestreo = 100; % Hz
duracion = 10; % segundos
t = 0:1/fueste_muestreo:duracion;

% Simulación de lectura de sensor óptico (LDR)
% Nota: En implementación real, usar readVoltage(a, 'A0') para Arduino
senal_sensor = 2.5 + 2*sin(2*pi*0.1*t) + 0.2*randn(size(t));

% Procesamiento de la señal (Filtro de media móvil para suavizar)
ventana = 5;
senal_suavizada = movmean(senal_sensor, ventana);

% Lógica de Control Domótico
estado_actuador = senal_suavizada < umbral_luz; % Encender si hay poca luz

% Visualización de resultados
figure('Color', [1 1 1]);
subplot(2,1,1);
plot(t, senal_sensor, 'Color', [0.7 0.7 0.7], 'DisplayName', 'Señal Bruta'); hold on;
plot(t, senal_suavizada, 'r', 'LineWidth', 1.5, 'DisplayName', 'Señal Filtrada');
line([0 duracion], [umbral_luz umbral_luz], 'Color', 'b', 'LineStyle', '--', 'DisplayName', 'Umbral');
title('Monitoreo de Sensor Óptico');
ylabel('Voltaje (V)');
legend; grid on;

subplot(2,1,2);
stairs(t, estado_actuador, 'Color', [0 0.5 0], 'LineWidth', 2);
title('Estado del Actuador (Iluminación)');
xlabel('Tiempo (s)');
ylabel('0: Apagado | 1: Encendido');
ylim([-0.2 1.2]);
grid on;

fprintf('Sistema operativo. Analizando niveles de luz en tiempo real...\n');
