struct Node {
    bool isEnd;
    Node* arr[26];
    Node(){
        isEnd =false;
        for(int i=0;i<26;++i){
            arr[i] = nullptr;
        }
    }
};
bool search(Node*root , const string &s){
    Node*temp = root;
    for(int i=0;i<(int)s.size();++i){
        int val = s[i]-'0';
        if(temp->arr[val] != nullptr){
            temp = temp->arr[val];
            if(temp->isEnd){
                return false;
            }
        }else{
            return true;
        }
    }
    return false;
}

void add(Node*root , const string &s){
    Node*temp = root;
    for(int i=0;i<(int)s.size();++i){
        int val = s[i]-'0';
        if(temp->arr[val] == nullptr){
            temp -> arr[val] = new Node;
        }
        temp = temp->arr[val];
    }
    temp->isEnd = true;
}


