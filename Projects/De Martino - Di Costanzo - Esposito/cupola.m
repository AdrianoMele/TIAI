clear all
close all
clc

%suppongo massa 1kg per ogni gas
k=0.128; %coefficiente di scambio termico dell'Aerogel
k3=500; %coefficiente di scambio termico del Lexan
c=1030; %capacita  termica di una generica atmosfera terrestre
Ca=0.52; %capacita  termica del gas Argon

%Matrici del sistema
A=[-k/c k/c 0;-(k^2)/Ca k*(k-1)/Ca k/Ca;0 -(k*k3)/Ca k3*(k-1)/Ca];
B=[1/c 0;0 0;0 k3/Ca];
C=[1 0 0];
D=[0 0];

sys=ss(A,B,C,D);%interpreta le 4 matrici come un sistema dinamico

W=tf(sys); %ottengo le funzioni di trasferimento

t=(0:1e-2:2000)'; %scelgo un vettore dei tempi di 2000 secondi
r=24*ones(size(t)); %scelgo un riferimento costantemente pari a 24C°

%lancio la simulazione con simulink
out = sim('simulazione.slx');
uCLP = out.uCLP;
yCLP = out.yCLP;

figure(2)
plot(t,r,'k','linewidth',1)
plot(yCLP.time,yCLP.signals.values,'b','linewidth',2)
set(gcf,'Position',[100 100 750 350]);

figure(3), hold on, grid on
plot(t,r,'k','linewidth',1)
plot(uCLP.time,uCLP.signals.values,'r','linewidth',2)
plot(yCLP.time,yCLP.signals.values,'b','linewidth',2)
legend('riferimento', 'controllo PID', 'uscita')
title('Control action')


