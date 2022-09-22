#include <iostream>

class vector {
public:
  vector(int capacity_) {
    this->capacity_ = capacity_;
    this->size_ = 0;
    this->data_ = new int[capacity_]();
  }

  ~vector() {
    delete[] data_;
  }

  vector(vector& other) {
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    this->data_ = new int[other.capacity_]();
    for (int i = 0; i < other.capacity_; ++i) {
      this->data_[i] = other.data_[i];
    }
  }

  vector& operator=(const vector& other) {
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    if (this->data_ != nullptr) {
      delete[] this->data_;
    }
    this->data_ = new int[other.capacity_]();
    for (int i = 0; i < other.capacity_; ++i) {
      this->data_[i] = other.data_[i];
    }
    return *this;
  }

  // adds element to the last avaialable position,
  // resizes vector if current capacity_ is reached
  void pushBack(int num) {
    if (this->size_ == this->capacity_) {
      if (this->capacity_ == 0) {
        this->resize(1);
      }
      else {
        this->resize(capacity_ * 2);
      }
    }
    this->data_[this->size_++] = num;
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
  vector* v1 = new vector(0);
  v1->pushBack(2);
  v1->pushBack(-7);
  v1->pushBack(99);
  v1->pushBack(0);
  v1->pushBack(1);
  v1->pushBack(35);

  vector v2(*v1);
  std::cout << "Copy ctor" << std::endl;
  std::cout << "Vector v2" << std::endl;
  v2.printVector();

  vector* v3 = new vector(0);
  v3->operator=(*v1);
  std::cout << "Operator=" << std::endl;
  std::cout << "Vector v3" << std::endl;
  v3->printVector();

  v3->pushBack(80808);

  std::cout << "Vector v1" << std::endl;
  v1->printVector(); //v1 shouldn't change.
  
  std::cout << "Vector v3" << std::endl;
  v3->printVector(); //v3 should change.
  
  return 0;
}