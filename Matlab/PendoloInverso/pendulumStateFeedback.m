% Sistema dinamico, funzione di trasferimento, controller

% Verifica autovalori
ee = eig(A);
figure(1), plot(real(ee),imag(ee),'x');   
title('System eigenvalues')

% Test controllabilità e osservabilità
fprintf('Rango matrice di controllabilità: %d \n', rank(ctrb(A,B)))
fprintf('Rango matrice di osservabilità: %d \n', rank(obsv(A,C)))

% State feedback design
K = place(A,B,[-5,-4,-3,-2]);

% Rappresentazione in spazio di stato
pendSys = ss(A,B,C,D);       % I-S-U a ciclo aperto
disp('Autovalori a ciclo aperto:')
disp(eig(pendSys))

clSys = feedback(pendSys,K); % genera il sistema a ciclo chiuso
disp('Autovalori a ciclo chiuso:')
disp(eig(clSys))

% Simulazione a ciclo chiuso
t  = 0:1e-3:5;
x0 = [0 0 theta0 0]';
[y,t] = lsim(clSys,0*t,t,x0);
x     = y(:,1);
v     = y(:,2);
theta = y(:,3);
w     = y(:,4);

% Funzione di trasferimento
pendTf = tf(pendSys);
disp('Funzione di trasferimento a ciclo aperto: ')
thetaTf = pendTf(3,1);   % canale da F a theta
zpk(thetaTf)             % rappresentazione zpk
den = thetaTf.den;       % denominatore e numeratore come cell array
num = thetaTf.num;
poles = roots(den{:});   % estrae poli e zeri trattando num e den come polinomi
zeros = roots(num{:});
gain  = dcgain(thetaTf); % guadagno statico del sistema

