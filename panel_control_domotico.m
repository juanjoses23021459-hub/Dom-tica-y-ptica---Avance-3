% Panel de Control de Temperatura Inteligente
fig = uifigure('Name', 'Panel Central Domótico', 'Position', [100 100 450 350]);
ga = uigauge(fig, 'Position', [150 180 150 150], 'Value', 22);
ga.Limits = [0 50];
ga.Label = 'Temperatura Actual (°C)';

ax = uiaxes(fig, 'Position', [50 30 350 130]);
title(ax, 'Histórico de Sensores');
xlabel(ax, 'Tiempo (s)');
ylabel(ax, 'Temp');

% Simulación de lectura en tiempo real
t = 0;
datos = [];
stop_btn = uibutton(fig, 'Text', 'Detener Sistema', 'Position', [165 310 120 30]);

while ishandle(fig)
    temp_actual = 20 + 5*rand(); % Simula lectura de sensor
    ga.Value = temp_actual;
    
    % Actualizar gráfica
    t = t + 1;
    datos = [datos, temp_actual];
    plot(ax, datos, 'Color', [0 0.5 0.8], 'LineWidth', 2);
    
    pause(0.5); % Frecuencia de muestreo
    if t > 50, break; end % Seguridad para el bucle
end
