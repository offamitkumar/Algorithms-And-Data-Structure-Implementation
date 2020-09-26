double x1,x2,x3,y1,y2,y3,x1sq,x2sq,x3sq,y1sq,y2sq,y3sq; 
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
x1sq = x1*x1; 
x2sq = x2*x2; 
x3sq = x3*x3; 
y1sq = y1*y1;
y2sq = y2*y2;
y3sq = y3*y3;
double A , B , C , D;
A = x1*(y2 - y3) - y1*(x2 - x3) + x2*y3 - x3*y2; 
B = ((x1sq + y1sq)*(y3 - y2))+((x2sq + y2sq)*(y1- y3)) + ((x3sq+y3sq)*(y2-y1)); 
C = ((x1sq + y1sq)*(x2 - x3))+((x2sq + y2sq)*(x3- x1)) + ((x3sq+y3sq)*(x1-x2)); 
D = ((x1sq + y1sq)*(x3*y2 - x2 * y3)) + ((x2sq + y2sq)*(x1*y3 -x3*y1)) + ((x3sq+y3sq)*(x2*y1-x1*y2)); 
// Radius 
double r = sqrt((B*B + C*C - 4*A*D)/(4.0f*A*A)); 

// Center X-co-ordinate 
x = -(B / (2.0f*A)) 
y = -(C / (2.0f*A))
