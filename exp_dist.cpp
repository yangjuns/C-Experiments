#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::default_random_engine generator;

void ExponentialDelay(int n, double beta) {
  std::exponential_distribution<double> distribution(beta);
  // draw number from exp distribution for each vertex
  std::vector<double> exp_dist;
  double X_max = 0.0;
  for (int i = 0; i < n; i++) {
    double v = distribution(generator);
    exp_dist.emplace_back(v);
    if (v > X_max)
      X_max = v;
  }
  printf("X_max: %lf. Expected: %lf\n", X_max, 2 * log(n) / beta);
}

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  double beta = atof(argv[2]);
  ExponentialDelay(n, beta);
  return 0;
}
