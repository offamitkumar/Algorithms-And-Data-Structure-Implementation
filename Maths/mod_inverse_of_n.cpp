long long mod_Inverse(long long a, long long uMOD = (long long)1e9+7ll) { 
    long long m0 = uMOD; 
    long long y = 0ll, x = 1ll; 
    if (uMOD == 1ll) return 0ll; 
    while (a > 1ll) { 
        long long q = a / uMOD; 
        long long t = uMOD; 
        uMOD = a % uMOD, a = t; t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0ll) x += m0; 
    return x; 
} 
