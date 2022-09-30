#include <stdio.h>
#include <stdlib.h>

typedef struct SegTree SegTree;
struct SegTree{
  int l, r;
  unsigned long long delta;    //lazy mark
  unsigned long long value;    //range sum
}seg_tree[(200000<<2)+1];
int n, q, a, b, c, act;
int value[200001];

void PushDown(int idx, long long delta){
  seg_tree[idx<<1].value += delta*(seg_tree[idx<<1].r-seg_tree[idx<<1].l+1);  //push to left sub-tree
  seg_tree[idx<<1].delta += delta;
  seg_tree[idx<<1|1].value += delta*(seg_tree[idx<<1|1].r-seg_tree[idx<<1|1].l+1);  //push to right sub-tree
  seg_tree[idx<<1|1].delta += delta;
  seg_tree[idx].delta = 0;
}
unsigned long long Build(int l, int r, int idx){
  seg_tree[idx].delta = 0;
  seg_tree[idx].l = l;
  seg_tree[idx].r = r;
  seg_tree[idx].value = 0;

  if(l == r){
    seg_tree[idx].value = value[l];
    return seg_tree[l].value;
  }
  int mid = (l+r)>>1;
  seg_tree[idx].value += Build(l, mid, idx<<1) + Build(mid+1, r, (idx<<1)+1);
  return seg_tree[idx].value;
}
void Modify(int l, int r, int idx, long long increase){
  if(l==seg_tree[idx].l && r==seg_tree[idx].r){
    seg_tree[idx].value += increase*(r-l+1);
    seg_tree[idx].delta += increase;
    return;
  }

  if(seg_tree[idx].delta)
    PushDown(idx, seg_tree[idx].delta); //push down lazy tag

  int mid = (seg_tree[idx].l+seg_tree[idx].r)>>1;
  if(l > mid){
    Modify(l, r, (idx<<1)+1, increase); //traverse right sub-tree
  }
  else if(r < mid+1){
    Modify(l, r, (idx<<1), increase);   //traverse left sub-tree
  }
  else{
    Modify(l, mid, (idx<<1), increase);
    Modify(mid+1, r, (idx<<1)+1, increase);
  }
  seg_tree[idx].value = seg_tree[idx<<1].value + seg_tree[(idx<<1)+1].value;
}
unsigned long long Query(int l, int r, int idx){
  if(l==seg_tree[idx].l && r==seg_tree[idx].r){
    return seg_tree[idx].value;
  }
  int mid = (seg_tree[idx].l+seg_tree[idx].r)>>1;

  if(seg_tree[idx].delta) //push down lazy tag
    PushDown(idx, seg_tree[idx].delta);

  if(l > mid){
    return Query(l, r, (idx<<1)+1); //traverse right sub-tree
  }
  else if(r < mid+1){
    return Query(l, r, (idx<<1));   //traverse left sub-tree
  }
  else{
    return Query(l, mid, (idx<<1)) + Query(mid+1, r, (idx<<1)+1);
  }
}
int main(){
  scanf("%d%d", &n, &q);
  for(int i=1; i<n+1; i++){
    scanf("%d", &value[i]);
  }
  Build(1, n, 1);
  for(int i=0; i<q; i++){
    scanf("%d", &act);
    if(act == 1){
      scanf("%d%d%d", &a, &b, &c);
      Modify(a, b, 1, c);
    }
    else{
      scanf("%d", &c);
      printf("%lld\n", Query(c, c, 1));
    }
  }
  return 0;
}
