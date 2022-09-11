class vector {
  int *data;
  int size;
  int capacity;

  public: vector(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->data = new int[capacity]();
  }

  ~vector() { delete[] data; }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
  public: void pushBack(int num) {
    if (this->size == this->capacity) {
      if (this->capacity == 0) {
        this->resize(1);
      }
      else {
        this->resize(capacity * 2);
      }
    }
    this->data[this->size++] = num;
  }

  // resizes vector to given capacity
  void resize(int newCapacity) {
    int* newData = new int[newCapacity]();
    for (int i = 0; i < capacity; ++i) {
      newData[i] = data[i];
    }
    this->capacity = newCapacity;
    delete[] this->data;
    this->data = newData;
  }

  // void set(int num, int idx);
  // int at(int idx);
};

int main(int argc, char **argv) {
  vector* newVector = new vector(0);
  newVector->pushBack(5);
  newVector->pushBack(12);
  newVector->pushBack(49);
  newVector->pushBack(0);
  newVector->pushBack(-345);
  newVector->pushBack(1);
  newVector->pushBack(42);
  newVector->pushBack(904);
  delete newVector;
  return 0;
}