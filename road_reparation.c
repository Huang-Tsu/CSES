#include <stdio.h>
#include <stdlib.h>

typedef struct Road Road;
struct Road{
  int end1, end2;
  int cost;
};
int compare(const void *a, const void *b){
  return (((Road*)a)->cost - ((Road*)b)->cost);
}
int g_boss[100005]; //group leader(boss) of each member(idx)
int FindBoss(int x){  //find group leader, if the number is negative, it indicates boss, and the abs of the negative value is the number of member in that group
  return g_boss[x]<0 ? x : (g_boss[x]=FindBoss(g_boss[x])); //if x is negative, return. otherwise, find boss recursively and compress the the group tree at the same time(group member x point to boss directly
}
void Union(int boss_a, int boss_b){
  int big_boss, small_boss;

  //check which one have bigger group, merge smaller one to bigger one
  if(-g_boss[boss_a] > -g_boss[boss_b])
    big_boss=boss_a, small_boss = boss_b;
  else
    big_boss=boss_b, small_boss = boss_a; 

  g_boss[big_boss] += g_boss[small_boss];  //add smaller boss's number of member to bigger boss's number of member
  g_boss[small_boss] = big_boss; //let bigger boss be the smaller boss's new boss
}
int main(){
  int city_cnt, road_cnt;
  int boss_a, boss_b;
  long long total_cost = 0;
  Road road[200000];

  scanf("%d%d", &city_cnt, &road_cnt);
  for(int i=0; i<road_cnt; i++){
    scanf("%d%d%d", &(road[i].end1), &(road[i].end2), &(road[i].cost));
  }

  qsort((void*)road, road_cnt, sizeof(road[0]), compare);

  //initialize boss
  for(int i=1; i<city_cnt+1; i++){
    g_boss[i] = -1; //let every city be their own boss
  }

  for(int i=0; i<road_cnt; i++){
    boss_a = FindBoss(road[i].end1); 
    boss_b = FindBoss(road[i].end2); 
    if(boss_a != boss_b){ //belong to different group, union
      Union(boss_a, boss_b);
      total_cost += road[i].cost;
    }
  }
  
  //check whether all cities are reachable
  if(-g_boss[FindBoss(1)] != city_cnt){ //all cities should belong to one group, if any group's member_cnt is not all city, the graph is not connected
    printf("IMPOSSIBLE\n");
    return 0;
  }

  printf("%lld\n", total_cost);
}
