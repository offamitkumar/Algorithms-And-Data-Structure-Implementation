struct Matrix{
    int matrixSize;
    vector< vector < int64_t > >mat;
    Matrix(const int &r){
        matrixSize = r;
        mat.assign(r , vector<int64_t>(r, 0));
    }
    Matrix operator*(const Matrix &B){
        Matrix T(matrixSize);
        for ( int i = 0 ; i < matrixSize; ++i) {
            for ( int j = 0 ; j < matrixSize; ++j) {
                for ( int k = 0 ; k < matrixSize; ++k) {
                    T.mat[i][j] += (mat[i][k] * B.mat[k][j]) % MOD;
                    T.mat[i][j] %= MOD;
                }
            }
        }
        return T;
    }
    void operator*=(const Matrix &B){
        Matrix T(matrixSize);
        for ( int i = 0 ; i < matrixSize; ++i) {
            for ( int j = 0 ; j < matrixSize; ++j) {
                for ( int k = 0 ; k < matrixSize; ++k) {
                    T.mat[i][j] += (mat[i][k] * B.mat[k][j]) % MOD;
                    T.mat[i][j] %= MOD;
                }
            }
        }
        for (int i = 0; i < matrixSize; ++i){
            for ( int j = 0; j < matrixSize; ++j ) {
                mat[i][j] = T.mat[i][j];
            }
        }
    }
    void makeIdentity(){
        for ( int i = 0; i < matrixSize; ++i ) {
            mat[i][i] = 1;
        }
    }
    friend Matrix power(Matrix &A , int64_t b){
        Matrix temp(A.matrixSize);
        temp.makeIdentity();
        while(b){
            if(b&1){
                temp = temp*A;
            }
            b>>=1;
            A = A*A;
        }
        return temp;
    }
    friend ostream& operator<<(ostream&cout, const Matrix &a) {
        for(int i=0; i < a.matrixSize; ++i) {
            for ( int j = 0; j < a.matrixSize; ++j ) {
                cout << a.mat[i][j] <<' ';
            }
            cout << '\n'; 
        }
        return cout;
    }
};
