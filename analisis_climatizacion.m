% Simulación de sensor de temperatura durante 24 horas
t = 0:0.1:24; % Tiempo en horas
temp_ambiente = 22 + 5*sin(pi*t/12) + randn(size(t))*0.5; % Señal con ruido

% Umbral de confort
setpoint = 24;
indices_ac = temp_ambiente > setpoint;

% Visualización
figure;
plot(t, temp_ambiente, 'b', 'LineWidth', 1.5); hold on;
yline(setpoint, 'r--', 'Umbral AC', 'LineWidth', 2);
fill([t(indices_ac) fliplr(t(indices_ac))], [temp_ambiente(indices_ac) setpoint*ones(size(t(indices_ac)))], 'r', 'FaceAlpha', 0.2);

title('Monitoreo Térmico y Activación de Climatización');
xlabel('Tiempo (horas)');
ylabel('Temperatura (°C)');
grid on;
legend('Temp. Habitación', 'Límite Confort', 'AC Activo');
