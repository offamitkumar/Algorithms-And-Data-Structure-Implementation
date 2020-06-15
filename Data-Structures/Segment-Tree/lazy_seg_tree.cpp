
const int MAXN = (int)2 * 1e5+10000;
const int MOD = (int)1e9+7;

long long seg_tree[4 * MAXN];
long long arr[MAXN];
long long lazy_tree[4 * MAXN];

void build(long long current_node , long long start , long long end ){
    if(start > end){
        return ;
    }
    if(start == end ){
        seg_tree[current_node] = arr[start];
        return;
    }
    long long mid = (start + end) / 2ll;
    build(2*current_node , start , mid);
    build(2*current_node +1ll , mid + 1ll, end);
    seg_tree[current_node] = 0ll;
    lazy_tree[current_node] = 0ll;
}
void push_updates(long long current_node , long long start , long long end){
    if(start == end){
        seg_tree[current_node] += lazy_tree[current_node];
    }
    if(start != end){
        lazy_tree[2*current_node] += lazy_tree[current_node];
        lazy_tree[2*current_node + 1] += lazy_tree[current_node];
    }
    lazy_tree[current_node] = 0ll;
}
void update(long long current_node , long long start , long long end , long long q_start , long long q_end , long long value){
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
    long long mid = (start + end)/2;
    update(2*current_node , start , mid , q_start , q_end , value);
    update(2*current_node+1 , mid+1 ,  end , q_start , q_end , value);
}
long long query(long long current_node , long long start , long long end , long long pos){
    if(lazy_tree[current_node]!=0){
        push_updates(current_node , start , end);
    }
    if(start > pos || end < pos){
        return -1;
    }
    if(start == pos && end == pos){
        return seg_tree[current_node];
    }
    long long mid = (start + end) /2;
    if(mid >= pos){
        return query(2*current_node , start , mid , pos);
    }else{
        return query(2*current_node +1 , mid+1 , end , pos);
    }
}
