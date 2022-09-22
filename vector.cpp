#include <algorithm>
#include <iostream>

class vector {
public:
  vector() {
    capacity_ = 8;
    size_ = 0;
    data_ = new int[capacity_]();
  }

  vector(int capacity) {
    if (capacity == 0) {
      std::cout << "Minimum capacity is 1. Capacity has been changed to 1 automatically." << std::endl;
      capacity_ = 1;
    }
    capacity_ = capacity;
    size_ = 0;
    data_ = new int[capacity_]();
  }

  ~vector() {
    delete[] data_;
  }

  vector(const vector& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = new int[capacity_]();
    std::copy(other.data_, other.data_ + capacity_, data_);
  }

  vector& operator=(const vector& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    if (data_ != nullptr) {
      delete[] data_;
    }
    data_ = new int[capacity_]();
    std::copy(other.data_, other.data_ + capacity_, data_);
    return *this;
  }

  // adds element to the last avaialable position,
  // resizes vector if current capacity_ is reached
  void pushBack(int num) {
    if (size_ == this->capacity_) {
      if (capacity_ == 0) {
        resize(1);
      }
      else {
        resize(capacity_ * 2);
      }
    }
    data_[size_] = num;
    ++size_;
  }

  void printVector() {
    std::cout << "Vector >>> ";
    for (int i = 0; i < size_; ++i) {
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  int *data_;
  int size_;
  int capacity_;

  // resizes vector to given capacity_
  void resize(int newcapacity_) {
    int* newdata_ = new int[newcapacity_]();
    for (int i = 0; i < capacity_; ++i) {
      newdata_[i] = data_[i];
    }
    this->capacity_ = newcapacity_;
    delete[] this->data_;
    this->data_ = newdata_;
  }
};

int main(int argc, char **argv) {
  vector v1 = vector();
  v1.pushBack(2);
  v1.pushBack(-7);
  v1.pushBack(99);
  v1.pushBack(0);
  v1.pushBack(1);
  v1.pushBack(35);

  vector v2(v1);
  std::cout << "Vector v2" << std::endl;
  v2.printVector();

  v2.pushBack(737);
  std::cout << "Vector v1" << std::endl;
  v1.printVector();
  std::cout << "Vector v2" << std::endl;
  v2.printVector();

  vector v3 = vector();
  v3 = v1;
  std::cout << "Vector v3" << std::endl;
  v3.printVector();

  v3.pushBack(80808);
  std::cout << "Vector v1" << std::endl;
  v1.printVector(); //v1 shouldn't be changed.
  std::cout << "Vector v2" << std::endl;
  v2.printVector();
  std::cout << "Vector v3" << std::endl;
  v3.printVector(); //v3 should be changed.
  
  return 0;
}