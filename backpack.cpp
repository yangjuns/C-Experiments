#include<vector>
#include<iostream>
int BackPack(std::vector<int>&values, std::vector<int>&costs, int limit){
  int n = values.size();
  std::vector<std::vector<int>> mem;
  std::vector<int> result;
  mem.emplace_back(limit+1,0);
  for(int i =1; i <= n; i++)
    mem.emplace_back(limit+1, -1);
  // induciton
  for(int i =1; i <= n; i++){
    for(int j=0; j <= limit; j++){
      // we are looking at values[i] / mem[i][j]
      if(costs[i-1] > j){
        mem[i][j] = mem[i-1][j];
      }else{
        mem[i][j] = std::max(mem[i-1][j], values[i-1] + mem[i-1][j-costs[i-1]]);
      }
    }
  }
  int profit = mem[n][limit];
  int obj_idx = n-1;
  int cur_limit = limit;
  while( obj_idx>=0 && cur_limit >=0){
    if(mem[obj_idx][cur_limit] == mem[obj_idx+1][cur_limit]){
      // we don't include obj_idx
      obj_idx--;
    }else{
      // we include n
      result.emplace_back(values[obj_idx]);
      cur_limit = cur_limit - costs[obj_idx];
      obj_idx--;
    }
  }
  std::cout << profit << std::endl;
  for(auto &e: result){
    std::cout << e << " ";
  }
  std::cout << std::endl;;
  return profit;
}


int main(int argc, char const *argv[]) {
  std::vector<int> values = {7,9,5,12,14,6,12};
  std::vector<int> costs = {3,4,2,6,7,3,5};
  int limit = 15;
  int profit = BackPack(values, costs, 15);
  std::cout << "total profix: " << profit << std::endl;
  return 0;
}
