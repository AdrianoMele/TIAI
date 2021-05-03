clearvars
close all
clc

% Dichiarazione di un vettore colonna
a = [1; 2; 3];
b = [4 5 6]';

% prodotto righe per colonne
ab1 = a'*b;

% dimensione di un vettore
sz = size(a);
nr = sz(1);
nc = sz(2);

% prodotto elemento per elemento
ab2 = a.*b;

% potenza elemento per elemento
a2 = a.^2;

% matrici
A = [1 2 3; 
     4 5 6; 
     7 8 9];
   
I = eye(3);
U = ones(3);
Z = zeros(3);

% autovalori
ee = eig(A);

% rango
rr = rank(A);

%% Comandi controlli automatici
A = [1 -1; 0 1];
B = [0; 1];
C = [1 0];
D = 0;

% I-S-U
sys = ss(A,B,C,D);

bode(sys);
margin(sys);
nyquist(sys);
nichols(sys);
rlocus(sys);

% I-S-U -> I-U
Sys = tf(sys);

% variabile di Laplace
s = tf('s');
G = 1/(1+2*s+s^2);
G = tf(1,[1 2 1]); % equivalente

% step response
step(G);

% I-U -> I-S-U standard
g = ss(G);

% numeratore e denominatore funzione di trasferimento
num = G.num{1};
den = G.den{1};

poli = roots(den);
zeri = roots(num);

% plot
figure('Position',[100 100 300 500])
plot(real(poli), imag(poli), 'o');
grid on, hold on
plot(real(zeri), imag(zeri), 'xr');
xlabel('Real part')
ylabel('Imaginary part')
title('Poli e zeri')

