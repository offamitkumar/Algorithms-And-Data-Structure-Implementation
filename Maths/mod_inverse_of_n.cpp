int64_t mod_Inverse(int64_t a, int64_t uMOD = (int64_t)1e9+7ll) { 
    int64_t m0 = uMOD; 
    int64_t y = 0ll, x = 1ll; 
    if (uMOD == 1ll) return 0ll; 
    while (a > 1ll) { 
        int64_t q = a / uMOD; 
        int64_t t = uMOD; 
        uMOD = a % uMOD, a = t; t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0ll) x += m0; 
    return x; 
} 
