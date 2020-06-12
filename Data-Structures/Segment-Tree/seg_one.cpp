const int MAXN = (int)2e5+100;
const int MOD = (int)1e9+7;


// default size is considered MAXN
long long arr[MAXN];
long long seg_tree[4*MAXN];

// FILL THIS FUNCTION 
inline long long funct(const long long &value_one , const long long &value_two){
    return value_one ************** value_two;
}


// build the segment tree 
void build(int current_node , int left_, int right_){
    if(left_ == right_) {
        seg_tree[current_node] = arr[left_];
        return ;
    }
    int mid_point = left_ + (right_ - left_) / 2;
    build(2*current_node, left_ , mid_point);
    build(2*current_node+1, mid_point+1 , right_);
    seg_tree[current_node] = funct(seg_tree[2*current_node], seg_tree[2*current_node+1]);
    return ;
}

// range queries 
long long query(int current_node , int start_, int end_, int q_start, int q_end){
    if(q_start > end_ || q_end < start_ || start_ > end_){
        return 0; // CHANGE IT IF FUNCTION IS MIN OR MAX 
    }
    if(start_ == end_){
        return seg_tree[current_node];
    }
    if(q_start <= start_ && end_ <=q_end){
        return seg_tree[current_node];
    }
    int mid_point = start_ + (end_ - start_) / 2;
    long long left_ans = query(current_node*2,start_,mid_point,q_start, q_end);
    long long right_ans= query(current_node*2+1,mid_point+1,end_,q_start, q_end);
    return funct(left_ans, right_ans);
}

// just for simple position update 
void update(int current_node , int start , int end , int pos , int value){
    if(start > end || pos > end || pos < start ){
        return ;
    }
    if(start == pos && end == pos){
        seg_tree[current_node] = value;
        return ;
    }
    int mid = (start + end) /2;
    update(current_node*2 , start , mid , pos , value);
    update(current_node*2+1, mid+1 , end , pos , value);
    seg_tree[current_node] = funct(seg_tree[2*current_node] , seg_tree[2*current_node+1]);
}

