% parametri Maxon A-max 32 20 watt
Va = 24;              % tensione nominale (V)
w0 = 6460*2*pi/60;    % velocità a vuoto (rpm-->rad/s)
i0 = 42.7e-3;         % corrente a vuoto (A)
wn = 5020*2*pi/60;    % velocità nominale (rpm-->rad/s)
tn = 44.4e-3;         % coppia nominale(Nm)
in = 1.30;            % corrente nominale (A)
ts = 205e-3;          % coppia di stallo (Nm)
ia = 5.81;            % corrente di avviamento (A)
rmax = 0.83;          % rendimento massimo

R = 4.13;             % resistenza ai terminali (Ohm)
L = 0.555e-3;         % induttanza ai terminali (mH)
k = 35.2e-3;          % costante del motore (coppia: Nm/A, velocità: V/rad/s)

taum = 15.1e-3;       % costante di tempo meccanica
J = 45e-7;            % momento di inerzia del rotore

I_max = 1.31;
sigma = tn/wn;        % coefficiente di attrito viscoso