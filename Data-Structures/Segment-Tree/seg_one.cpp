// Segment Tree {{{
// default size is considered MAXN {{{
vector<int64_t>arr(MAXN);
vector<int64_t>seg_tree(4*MAXN);
// }}}
// FILL THIS FUNCTION  {{{
inline int64_t funct(const int64_t &value_one , const int64_t &value_two){
    return value_one ************** value_two; // ERROR POINT 1
}
//  }}}
// BUILD THE SEGMENT TREE  {{{
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
//   }}}
// RANGE QUERIES  {{{
int64_t query(int current_node , int start_, int end_, int q_start, int q_end){
    if(q_start > end_ || q_end < start_ || start_ > end_){
        return 0; // ERROR POINT 2 , CHANGE WITH MIN OR MAX QUERY 
    }
    if(start_ == end_){
        return seg_tree[current_node];
    }
    if(q_start <= start_ && end_ <=q_end){
        return seg_tree[current_node];
    }
    int mid_point = start_ + (end_ - start_) / 2;
    int64_t left_ans = query(current_node*2,start_,mid_point,q_start, q_end);
    int64_t right_ans= query(current_node*2+1,mid_point+1,end_,q_start, q_end);
    return funct(left_ans, right_ans);
}
//     }}}
// FOR POINT UPDATE    {{{
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
//  }}}
// 0 BASED INDEXING , BE CAREFUL WITH QUESTION QUERY TYPE
// BUILD (CURRENT_NODE, ARRAY_START_POINT , ARRAY_END_POINT);
// QUERY(CURRENT_NODE, ARRAY_START_POINT , ARRAY_END_POINT, Q_START, Q_END);
// UPDATE(CURRENT_NODE, ARRAY_START_POINT, ARRAY_END_POINT, POSITION, VALUE);
// }}}
