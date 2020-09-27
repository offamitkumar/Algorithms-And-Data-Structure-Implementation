// eval function will evaluate the function for x
double bisection(void) {
    double low = 0.0f , high = 1.0f; 
    while (low + EPS < high) {
        double mid = (low + high) /(double)2.0f; 
        if (eval(mid) * eval(low) <= 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (high + low) / (double)2.0f;
}
