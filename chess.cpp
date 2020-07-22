// number # can be placed on chess board of size n , m
// rooks 
cout << min(m,n) << '\n'; 
// queen 
cout << min(m,n) << '\n'; 
// knight 
cout << (((m+1)/2) * ((n+1)/2)) + ((m/2) * (n/2)) << '\n'; 
// king 
cout << (((m+1)/2) * ((n+1)/2)) << '\n'; 
