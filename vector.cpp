#include "vector.h"

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>

vector::vector(int capacity) : capacity_(capacity), size_(0) {
  data_ = new int[capacity];
}

vector::~vector() {
  delete[] data_;
}

vector::vector(const vector& other) : capacity_(other.capacity_), size_(other.size_) {
  data_ = new int[capacity_];
  std::copy(other.data_, other.data_ + capacity_, data_);
}

vector& vector::operator=(vector other) {
  capacity_ = other.capacity_;
  size_ = other.size_;
  std::swap(data_, other.data_);
  return *this;
}

int& vector::operator[](int idx) {
  assert(idx >= 0 && idx < size_);
  return data_[idx];
}

// adds element to the last avaialable position,
// resizes vector if current capacity_ is reached
void vector::pushBack(int num) {
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

void vector::printVector() {
  std::cout << "Vector >>> ";
  for (int i = 0; i < size_; ++i) {
    std::cout << data_[i] << " ";
  }
  std::cout << std::endl;
}

// resizes vector to given capacity_
void vector::resize(int newCapacity) {
  int* newData = new int[newCapacity]();
  for (int i = 0; i < capacity_; ++i) {
    newData[i] = data_[i];
  }
  capacity_ = newCapacity;
  delete[] data_;
  data_ = newData;
}

void vector::printArray(int* begin, int* end) {
  int* current = begin;
  while (current != end) {
    std::cout << *current << std::endl;
    ++current;
  }
}