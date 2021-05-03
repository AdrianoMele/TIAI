clearvars
close all
clc

% Init parameters
pendulumParameters;

% Design state feedback, tf and ss examples
pendulumStateFeedback;

% Linearized model in simulink
pendulumSimulink;

% NL simulator in matlab
pendulumSimulatorControlled;