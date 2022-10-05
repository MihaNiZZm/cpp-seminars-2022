#pragma once

class vector {
public:
  vector(int capacity = 8);

  ~vector();

  vector(const vector& other);

  vector& operator=(vector other);

  int& operator[](int idx);

  // adds element to the last avaialable position,
  // resizes vector if current capacity_ is reached
  void pushBack(int num);

  void printVector();

  void printArray(int* begin, int* end);

private:
  int *data_;
  int size_;
  int capacity_;

  // resizes vector to given capacity_
  void resize(int newCapacity);
};