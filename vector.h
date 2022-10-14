#pragma once

class vector {
public:
  vector(int capacity = 8);
  vector(const vector& other);

  ~vector();

  vector& operator=(vector other);

  int& operator[](int idx);

  // adds element to the last avaialable position,
  // resizes vector if current capacity_ is reached
  void pushBack(int num);
  void printVector();
  void printArray(int* begin, int* end);

  class iterator {
  public:
    iterator(const iterator& other) = default;
    iterator(int idx, vector& v) : idx_(idx), v_(v) {};

    bool operator==(const iterator& other) const;
    bool operator!=(const iterator& other) const;

    int& operator*();

    iterator& operator++(); 
    iterator operator++(int);

  private:
    int idx_;
    vector& v_;
  };

  iterator begin();
  iterator end();
 
private:
  int *data_;
  int size_;
  int capacity_;

  // resizes vector to given capacity_
  void resize(int newCapacity);
};