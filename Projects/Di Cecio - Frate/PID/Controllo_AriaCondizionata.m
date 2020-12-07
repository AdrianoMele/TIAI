clear all
close all
clc

%% Impianto

C_th = 15000;  %Capacità termica aria in una cabina
K_th = 600;    %Coefficiente di scambio termico

A = -K_th/C_th;   
B = [1 K_th/C_th];
C = 1;
D = [0 0];

Gs = tf(ss(A,B,C,0));
Gs = Gs(1);


%bode(Gs);
%nyquist(Gs);

%% PID - Formule di inversione Wg = 1, PM = 120

Wg = 1;    
PM = 120;
Mg = 1/abs(evalfr(Gs, 1i*Wg));
Pg = PM - 180 - rad2deg(angle(evalfr(Gs, 1i*Wg)));

Kp = Mg*cosd(Pg);
Ki = Kp/25;
Kd = (Ki+Mg*sind(Pg)*Wg)/Wg^2;

s = tf('s');
Ks = Kp + Ki/s + Kd*s;
Fs = Ks*Gs;
margin(Fs);
