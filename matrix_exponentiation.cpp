
const int MOD  = (int)1e9+7;

const int MATRIX_SIZE=2;
struct Matrix{
    int size;
    int64_t mat[MATRIX_SIZE][MATRIX_SIZE];
    Matrix(int r){
        size = r;
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                mat[i][j]=0ll;
            }
        }
    }
};

Matrix operator*(Matrix &A , Matrix &B ){
    Matrix T=Matrix(A.size);
    for(int i=0;i<A.size;++i){
        for(int j=0;j<A.size;++j){
            for(int k=0;k<A.size;++k){
                T.mat[i][j]+=(A.mat[i][k]*B.mat[k][j])%MOD;
                T.mat[i][j]%=MOD;
            }
        }
    }
    return T;
}

Matrix power(Matrix A , int64_t b){
    Matrix temp = Matrix(A.size);
    for(int i=0;i<A.size;++i){
        temp.mat[i][i]=1;
    }
    while(b){
        if(b&1){
            temp = temp*A;
        }
        b>>=1;
        A = A*A;
    }
    return temp;
}

