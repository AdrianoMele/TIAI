function sqm = ideal_tf1(par, t, w, in)
    tau = par(1);                           %Costante di tempo del sistema
    dcg = par(2);                           %Guadangno della FdT
    s = tf('s');
    G = dcg/(s*(1+s*tau));                  %FdT Obbiettivo
    [y,ty] = step(G,t);                     %Risposta al gradino
    y = y*in;                               %Normalizzazione
    y = interp1(ty,y,t,'linear','extrap')'; %Interpolazione lineare
    sqm = mean((y-w).^2);                   %Scarto quadratico medio
end

