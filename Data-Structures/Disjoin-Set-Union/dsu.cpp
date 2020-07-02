


vector<int>parent(MAXN);

int find_parent(int node){
    if(node == parent.at(node)){
        return node;
    }
    return parent.at(node) = find_parent(parent.at(node));
}

void add(int node1, int node2){
    node1 = find_parent(node1);
    node2 = find_parent(node2);
    if(node2 != node1){
        parent.at(node1) = node1;
    }
}



