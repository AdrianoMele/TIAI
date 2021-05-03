% Matrici della rete
I = [1 0 0; 0 2 0; 1 1 0; 0 0 1];
O = [0 2 0; 1 0 0; 1 0 1; 0 1 0];
C = O-I;

% Marcatura iniziale
M0 = [1 1 1 1]';

% Vettori delle occorrenze
s1 = [1 0 0]';
s2 = [0 1 0]';
s3 = [0 0 1]';

% Esempio: marcatura dopo la sequenza t1t2t3t1
M1231 = M0 + C*(s1 + s2 + s3 + s1);

% P-invarianti
w = null(C'); % ortonormalizzati!

% T-invarianti
s = null(C);

