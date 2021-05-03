% Parametri pendolo
global M m b g l

M = 0.5;
m = 0.2;
b = 0.1;
g = 9.8;
l = 0.3;

theta0 = 0.3;

% Modello linearizzato
% x1=x; x2=xdot; x3=theta; x4=thetadot;
A = [0       1            0         0;
     0     -b/M         m*g/M       0;
     0       0            0         1;
     0    -b/(l*M)   (M+m)*g/(M*l)   0];
B = [    0; 
        1/M;
         0;
      1/(l*M)];
C = eye(4);
D = [0;
     0;
     0;
     0];
   
