clc, close all, clear all;
s = tf('s');
F = 6.55/((1+0.05*s)*(1+0.011*s));
dt = 0.001;
%% FORMULE DI INVERSIONE PER PI
Wc = 66;
Pc = -135;
mod = abs(evalfr(F, 1i*Wc));
phs = rad2deg(angle(evalfr(F, 1i*Wc)));
Kp = cosd(Pc-phs)/mod;
Ki = -Wc*sind(Pc-phs)/mod;
K = (Kp+Ki/s);
Ki=Ki*0.0005; %Digitalizzazione Tustin

%% SIMULAZIONE
speed = readtable('Controllo4.txt');
ts = 0:dt:(numel(speed.Var2)-1)*dt;
ref = 200;
W = feedback(F*K,1);
[y,ty] = step(W,ts);
plot(ts,speed.Var2,'Color','Black');hold on;
plot(ty,y*ref,'LineWidth',2,'Color','Green');
title('Regolatore PI','FontSize',20);
xlabel('Tempo [s]','FontSize',20); ylabel('Velocità [rad/s]','FontSize',20);
grid;

legend('Risposta ideale', 'Risposta misurata','FontSize',15);
axis([0,0.5,0,300]);