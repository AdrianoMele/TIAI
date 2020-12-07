close all, clear all, clc;
syms z n;

%% INIZIALIZZAZIONE
s=tf('s');
T = 0.05;           %Polo per la fisica realizzabilità

numH = (19.8*z-19.8);
denH = (z-0.9802);
H = numH/denH;
h = iztrans(H,z,n); %Antitrasformata Z

D = s/(1+s*T);
Dd = c2d(D,0.001,'tustin');

tab = readtable('Spazio_50_50kHz.txt');
theta = tab.Var2*36;

%% DOMINIO DELLA FREQUENZA
[y,ty] = lsim(Dd,theta);
figure
plot(y);
title('Dominio della frequenza');
xlabel('Tempo [step]'); ylabel('Velocita [rad/step]'); 

%% DOMINIO DEL TEMPO - Simulazione per il microcontrollore
 a = 20.2000;
 b = -0.4000;
 c = 0.9802;
CONV = 1000;
vettore_theta = zeros(1, CONV);
vettore_convoluzione = zeros(1,CONV);
for i=0:CONV-1
    vettore_convoluzione(i+1) = c^i;
end
for i=1:length(theta)
    vettore_theta = inserisci(vettore_theta,theta(i),CONV);
    prod_conv = 0;
    somma_differenziale = 0;
    for k=1:CONV
        prod_conv = vettore_theta((CONV-k)+1)*vettore_convoluzione(k);
        somma_differenziale = somma_differenziale+prod_conv;
    end
    omega(i) = a*theta(i) + b*somma_differenziale;
end
figure;
plot(omega);
title('Dominio del tempo');
xlabel('Tempo [step]'); ylabel('Velocita [rad/step]'); 


function vect = inserisci(vettore,elemento,dimensione)
    temp = vettore;
  for i=1:dimensione-1
    temp(i) = temp(i+1);
  end
  temp(dimensione) = elemento;
  vect = temp;
end