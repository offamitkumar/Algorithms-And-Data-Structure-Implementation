// eval function evaluate value f(x)
double secant(void) {
    if (eval(0) == 0) {
        return 0;
    }
    double x1 =1.0f , x0 = 0.0f;
    while (true) {
        double temp = (eval(x1) * (x1-x0)) / (eval(x1) - eval(x0)); 
        if (fabs(temp) < EPS) {
            return x1; 
        }
        x0 = x1; 
        x1 = x1 - temp;
    }
}
