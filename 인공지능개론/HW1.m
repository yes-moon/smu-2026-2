clear all; close all;

Height = [];
Height(:,1) = [160; 165; 170; 175;  180; 185];
Height(:,2) = ones(length(Height(:,1)), 1);


Weight = [];
Weight(:,1) = [62; 63; 64; 65; 66; 67];

t = [0.2; 30];

OUT = Height*t

Weight - OUT
