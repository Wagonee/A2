#include <iostream>
#include <random>
#include "HashQP.h"
#include "HashCP.h"

std::random_device rd;
std::mt19937 gen(rd());

void fill(HashQP& tableQP, HashCP& tableCP) {
  int num;
  for (size_t i = 0; i < (size_t)((double)tableQP.get_size() * 0.8); ++i) {
    std::uniform_int_distribution<> dist(1, (int)tableQP.get_size() * 2);
    num = dist(gen);
    tableQP.insert(num);
    tableCP.insert(num);
  }
}


int main() {


  std::cout << "Average probe count" << '\n' << "Quadratic" << ' ' << "Cubic" << '\n';
  for (size_t n = 4; n <= 16384; n = n * 2) {
    HashQP tableQP(n);
    HashCP tableCP(n);

    fill(tableQP, tableCP);

    std::cout << tableQP.getAverageProbeCount() << ' ' << tableCP.getAverageProbeCount() << '\n';
    if (n <= 32) {
      tableQP.print();
      std::cout << ' ';
      tableCP.print();
      std::cout << '\n';
    }


  }


  return 0;
}
