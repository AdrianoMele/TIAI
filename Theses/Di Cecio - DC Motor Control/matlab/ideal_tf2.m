function sqm = ideal_tf2(par, t, w, in)
    tau1 = par(1);                           %Costante di tempo del sistema
    tau2 = par(2);                           %Guadangno della FdT
    a = par(3);
    b = par(4);
    s = tf('s');
    G = a/(s*((s+tau1)*(s+tau2)+a*b));  %FdT Obbiettivo
    [y,ty] = step(G,t);                     %Risposta al gradino
    y = y*in;                               %Normalizzazione
    y = interp1(ty,y,t,'linear','extrap')'; %Interpolazione lineare
    sqm = mean((y-w).^2);                   %Scarto quadratico medio
end

