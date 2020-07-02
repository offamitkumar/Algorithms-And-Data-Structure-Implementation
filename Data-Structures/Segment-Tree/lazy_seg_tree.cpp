


int64_t seg_tree[4 * MAXN];
vector<int64_t>seg_tree(4*MAXN);
vector<int64_t>lazy_tree(4*MAXN);
vector<int64_t>arr(MAXN);

void build(int64_t current_node , int64_t start , int64_t end ){
    if(start > end){
        return ;
    }
    if(start == end ){
        seg_tree[current_node] = arr[start];
        return;
    }
    int64_t mid = (start + end) / 2ll;
    build(2*current_node , start , mid);
    build(2*current_node +1ll , mid + 1ll, end);
    seg_tree[current_node] = 0ll;
    lazy_tree[current_node] = 0ll;
}
void push_updates(int64_t current_node , int64_t start , int64_t end){
    if(start == end){
        seg_tree[current_node] += lazy_tree[current_node];
    }
    if(start != end){
        lazy_tree[2*current_node] += lazy_tree[current_node];
        lazy_tree[2*current_node + 1] += lazy_tree[current_node];
    }
    lazy_tree[current_node] = 0ll;
}
void update(int64_t current_node , int64_t start , int64_t end , int64_t q_start , int64_t q_end , int64_t value){
    if( start > q_end || end < q_start || start > end ){
        return ;
    }
    if(lazy_tree[current_node] != 0ll){
        push_updates(current_node , start , end);
    }
    if(start >= q_start && end <= q_end){
        if(start == end){
            seg_tree[current_node] += value;
        }else{
            lazy_tree[current_node] += value;
        }
        return;
    }
    int64_t mid = (start + end)/2;
    update(2*current_node , start , mid , q_start , q_end , value);
    update(2*current_node+1 , mid+1 ,  end , q_start , q_end , value);
}
int64_t query(int64_t current_node , int64_t start , int64_t end , int64_t pos){
    if(lazy_tree[current_node]!=0){
        push_updates(current_node , start , end);
    }
    if(start > pos || end < pos){
        return -1;
    }
    if(start == pos && end == pos){
        return seg_tree[current_node];
    }
    int64_t mid = (start + end) /2;
    if(mid >= pos){
        return query(2*current_node , start , mid , pos);
    }else{
        return query(2*current_node +1 , mid+1 , end , pos);
    }
}



