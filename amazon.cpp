// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include <set>
#include <iostream>
#include <vector>
using namespace std;
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
vector<int> selectPackages(int truckSpace, vector<int> packagesSpace)
{
 // researve safety space
 truckSpace-=30;

 // user defined comparator
 auto comp = [](const pair<int, int> &a, const pair<int,int> &b){
     return a.first < b.first;
 };
 set<pair<int, int>, decltype(comp)> items(comp);
 // populate the set
 for(uint32_t i =0; i < packagesSpace.size(); i++){
     items.insert(make_pair(packagesSpace[i], i));
 }

 int max_sum = 0;
 vector<int> result(2);
 int max_size = 0;
 for(uint32_t i =0; i < packagesSpace.size(); i++){
    pair<int, int> cur = make_pair(packagesSpace[i], i);
    // remove self from the set
    items.erase(cur);
    // find the another item
    //printf("need to find item such %d + values <= %d", packagesSpace[i], truckSpace);
    auto it = items.upper_bound(make_pair(truckSpace - packagesSpace[i], -1));
    it--;
    //printf("it : (%d, %d)\n", it->first, it->second);
    // update max
    int cur_sum = packagesSpace[i]+ it->first;
    if(cur_sum >= max_sum && cur_sum <= truckSpace){
        int cur_max_size = max(it->first, packagesSpace[i]);
        //printf("cur_max_size: %d\n", cur_max_size);
        //printf("pair %d %d\n", packagesSpace[i], it->first);
        if(cur_sum > max_sum || cur_max_size > max_size){
                result[0]= i;
                result[1] = it->second;
                max_sum = cur_sum;
                max_size = cur_max_size;
                //printf("update max_size: %d\n", max_size);
        }
    }
    // insert me back
    items.insert(cur);
 }
 return result;
}
// FUNCTION SIGNATURE ENDS
int main(int argc, char const *argv[]) {
  vector<int> result = selectPackages(250, {100,180,40,120,10});
  std::cout<< result[0] << " " << result[1] << std::endl;
  return 0;
}
