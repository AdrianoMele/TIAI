clc, close all, clear all;

name1 = 'Spazio_';
name2 = '_50kHz.txt';

%% Estrazione ed elaborazione dati
Vcc = 12;
dt = 1e-3;                      % [s]
dx = 36*pi/180;                 % [rad]
N = (70-20)/5 +1;               % Numero di esperimenti
s = tf('s');                    % Variabile per Fdt Continua
j=1;
for i=20:5:70
    name = [name1, int2str(i),name2];
    tab = readtable(name);
    theta(j,:) = tab.Var2*dx;
    duty_cicle(j) = i;
    in(j) = duty_cicle(j);
    j = j+1;
end
t = 0:dt:(numel(theta(1,:))-1)*dt;


%% FdT
polo = 0.2;
gain = 20;
cost0 = [polo, gain];
for i=1:N
    temp = theta(i,:);
    cost(i,:) = fminsearch(@(x)ideal_tf1(x,t,temp',in(i)),cost0);
end
dc = 20:5:70;
subplot(1,2,1);

plot(dc,cost(:,1),'*','LineWidth',3);
xlabel('Duty-Cycle');
ylabel('tau');
grid;
axis([20,70,0,0.02]);
title('Variazione della costante di tempo');
tau = mean(cost(:,1));

subplot(1,2,2);
grid;
hold on;
plot(dc,cost(:,2), '*', 'LineWidth',3);
xlabel('Duty-Cycle');
ylabel('gain');
axis([20,70,0,10]);
title('Variazione del guadagno');