function drawPendulum(fh,x,theta,l,w,h)
% Draws pendulum on a cart

if nargin == 4
  w = 0.15;
  h = 0.10;
end

if not(isempty(fh))
  figure(fh)
else
  gcf;
end
clf, hold on, grid on

% draw cart
rectangle('Position',[x,0,w,h],'FaceColor','r')

% draw link
plot([x+w/2, x+w/2-l*sin(theta)], [h*0.9, h+l*cos(theta)], '-ok', 'linewidth', 2)

% draw mass
plot(x+w/2-l*sin(theta),h+l*cos(theta),'or','markersize',10, 'MarkerFaceColor','y')

hold off