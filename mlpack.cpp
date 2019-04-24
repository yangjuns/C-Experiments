#include <mlpack/methods/logistic_regression/logistic_regression.hpp>
#include <armadillo>
#include <iostream>
int main(int argc, char const *argv[]) {
  std::cout << "Hello world" << std::endl;
  arma::mat A(10, 10, arma::fill::randu);
  arma::Row<size_t> row(10, arma::fill::zeros);
  row[5]=1;
  row[1]=1;
  row[0]=1;
  row[8]=0;
  mlpack::regression::LogisticRegression<arma::mat> lr(A, row);

  std::cout << A << std::endl;
  std::cout << row << std::endl;
  //lr.Train();
  std::cout << lr.Lambda() << std::endl;
  std::cout << lr.Parameters() << std::endl;

  std::vector<double> a = {1,2,3,4};
  std::vector<double> b= {5,6,7,8};
  a.insert(a.end(), std::begin(b), std::end(b));

  for(auto &e: a){
    std::cout << e << " "<< std::endl;
  }

  arma::mat matrix(a, 2, 4);
  std::cout << matrix << std::endl;
  return 0;
}
