#ifndef A2__HASHQP_H_
#define A2__HASHQP_H_

#include <cstdint>
#include <vector>

class HashQP {
 public:
  explicit HashQP(size_t size) : size_(size), container_(size, EMPTY), totalProbeCount_(0), insertions_(0) {};
  void insert(int key) {
    size_t index = hash(key);
    size_t probeCount = 1;
    if (container_[index] == EMPTY) {
      container_[index] = key;
      totalProbeCount_ += probeCount;
      insertions_++;
      return;
    }
    size_t i = 1;
    double c_1 = 1, c_2 = 1;
    while (container_[index] != EMPTY) {
      probeCount++;
      if ((size_ & (size_ - 1)) == 0) {
        c_1 = 0.5;
        c_2 = 0.5;
      }
      index = (size_t)(index + c_1 * i +  c_2 * i * i) % size_;
    }
    container_[index] = key;
    totalProbeCount_ += probeCount;
    insertions_++;
  }

  size_t getTotalProbeCount() const {
    return totalProbeCount_;
  }


  double getAverageProbeCount() const {
    return insertions_ > 0 ? static_cast<double>(totalProbeCount_) / (double)insertions_ : 0.0;
  }

  size_t get_size() const {
    return size_;
  }

  void print() const {
    std::cout << "[";
    for (size_t i = 0; i < size_; ++i) {
      std::cout << (container_[i] == EMPTY ? "0" : "1");
    }
    std::cout << "]";
  }


 private:
  std::vector<int> container_;
  size_t size_;
  size_t totalProbeCount_;
  size_t insertions_;
  [[nodiscard]] size_t hash(int key) const {
    return key % size_;
  }

  enum kStates {
    EMPTY
  };
};
#endif //A2__HASHQP_H_
