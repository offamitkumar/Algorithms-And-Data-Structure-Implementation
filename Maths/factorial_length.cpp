
// Use Kamenetsky formula to calculate 
// the number of digits 

int64_t factorial_digit(int64_t n) 
{ 
    if (n < 0) 
        return 0; 
    if (n <= 1) 
        return 1; 
  
    double x = ((n * log10(n / M_E) +  log10(2ll * M_PI * n) / 2.0)); 
  
    return floor(x) + 1; 
}
