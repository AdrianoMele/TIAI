%% Definizione di vettori e matrici
a = [1 2 3];
b = [1
     2
     3];
M = [1 3 5; 6 8 3; 9 1 3];

% Cell array
cc = {1, 'ciao', true};

%% Operazioni fondamentali 

% Prodotto riga per colonna
prod = a*M*b;

% Somma e differenza di vettori
c = a-b';
d = a+c;

% Prodotto elemento per elemento
e = a.*b';

% Elevamento a potenza
f = 2^3;
g = a.^2; % elemento per elemento

% Accesso agli elementi di un vettore
elemento = a(3);

%% Matrici standard

Z = zeros(2);
U = ones(size(M));
I = eye(numel(a));

R = rand(2,3);

%% Operazioni matriciali 

% Inversa
Minv = inv(M);

% Rango
rr = rank(R);

% Pseudoinversa
Rinv = pinv(R);

% Interi random
v = randi(100,2,1);

% Inverse
v1 = Rinv*v;
v2 = R\v;

%% Funzioni utili per il design di sistemi di controllo

% Autovalori
ee = eig(M);
[V,D] = eig(M);

% Definizione di un sistema dinamico
A = [-1 -1; 0 -1];
B = [0; 1];
C = [1 0];
D = 0;

% I-S-U
sys = ss(A,B,C,D);

% Grafici
bode(sys)
margin(sys)
nyquist(sys)
nichols(sys)
rlocus(sys)

% I-U
sys2 = tf(sys);
bode(sys2)

s = tf('s');
G = 1/(1+2*s+s^2);

G2 = tf([1 0],[1 2 1]);

zpk(G2)

% Risposta indiciale
step(G)

% Realizzazione I-S-U standard
g = ss(G);

% Numeratore e denominatore di una fdt
n = G.num{1};
d = G.den{1};

poli = roots(d);
zeri = roots(n);

%% Funzioni matematiche

close all

x = 0.01 : 1e-2 : 2*pi; % da 0 a 2pi con passo 10^-2
figure(1)
plot(x,sin(x))
shg

x = linspace(0,2*pi,1000); % da 0 a 2pi in 1000 passi
figure(2)
plot(x,cos(x))
shg

figure(1)
title('Questo è il seno di x')

figure(3)
title('esempio di funzioni sovrapposte')
subplot(1,2,1)
plot(x, exp(x));

subplot(1,2,2)
plot(x,log(x)), hold on
plot(x,log(x/2))
legend('log(x)','log(0.5x)')

