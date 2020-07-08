vector<int>table;
void pre(string&a){
    table.assign(a.size() , 0);
    table[0] =-1;
    int j=-1 , i = 0;
    while(i < (int)a.size()){
        while(j>=0 && a[i] != a[j]){
            j = table[j];
        }
        ++j;
        ++i;
        table[i] = j;
    }
}
void search(string &a , string &b){
    pre(a);
    int i=0 , j = 0;
    while(i < (int)b.size()){
        while(j >= 0 && b[i] != a[j]){
            j = table[j];
        }
        ++j;
        ++i;
        if(j==(int)a.size()){
            cout << i - j << ' ' ;
            j = table[j];
        }
    }
    cout << '\n'; 
} 
