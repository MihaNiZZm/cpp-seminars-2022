#pragma once

#include "Commands.h"
#include <unordered_map>
#include <functional>
#include <array>

class Interpreter {
  public:
    typedef std::function<Command* (std::string::iterator, std::string::iterator)> creatorT;
    static Interpreter& getInstance() {
        static Interpreter i;
        return i;
    }

    bool registerCreator(char c, creatorT& creator) {
        creators_[c] = creator;
        return true;
    }

    void interpret(const std::string::iterator& begin, const std::string::iterator& end) {
        auto it = begin;
        while (it != end) {
            creatorT creator = creators_[*it];
            Command* command = creator(it, end);
            ++it;
        }
    }
  private:
    Interpreter() {}
    Interpreter(Interpreter& other) = delete;
    static const int MEMORY_SIZE = 30000;
    std::array<uint8_t, MEMORY_SIZE> memory_;
    std::unordered_map<char, creatorT> creators_;
    uint8_t* ptr_;
};