s = tf('s');
Wc = 100;    
PM = 100;
Mg = 1/abs(evalfr(W, 1i*Wc));
Pg = PM - 180 - rad2deg(angle(evalfr(W, 1i*Wc)));

Kp = Mg*cosd(Pg);
Ki = Kp/25;
Kd = (Ki+Mg*sind(Pg)*Wc)/Wc^2;

K = (Kp+Ki/s+s*Kd/(1+s*0.0001));
speed = readtable('Wc25_Ph-150.txt');
ts = 0:dt:(numel(speed.Var2)-1)*dt;
ref = 150;
F = feedback(W*K,1);
[y,ty] = step(F,ts);
y = y*ref;
plot(ty,y);
hold on;
% plot(ts,speed.Var2);