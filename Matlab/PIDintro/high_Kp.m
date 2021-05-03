clear
close all
clc

% Define a 3rd order transfer function
s = tf('s');
G = 1/(s+1)^3;

% Try increasing Kp gains
figure
for Kp = [1 2 5 8]
W = feedback(Kp*G,1);
hold on
step(W)
pause
end
legend('Kp = 1','Kp = 2','Kp = 5','Kp = 8');

% Verify eigenvalues of last Kp 
% (2 imaginary poles cross the imaginary axis for Kp = 8)
roots(W.den{1})