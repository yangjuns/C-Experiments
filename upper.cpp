#include <iostream>
#include <set>

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow1,itup1,itlow2,itup2;

  for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

  itlow1=myset.lower_bound (29);                //
  itlow2=myset.lower_bound (60);                //        ^
  itup1=myset.upper_bound (29);                 //
  itup2=myset.upper_bound (60);                 //                  ^
  //std::cout << *(itlow1--) << std::endl;
  std::cout << *(--itlow1) << std::endl;
  std::cout << *(--itlow2) << std::endl;
  std::cout << *itup1 << std::endl;
  std::cout << *itup2 << std::endl;
//  myset.erase(itlow,itup);                     // 10 20 70 80 90

  // std::cout << "myset contains:";
  // for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';

  return 0;
}
