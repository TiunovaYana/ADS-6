// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int first, last;

 public:
    TPQueue() : first(0), last(0) {}
    void push(T x) {
        if (last - first >= size) {
            throw std::string("Full!");
        } else {
            int a;
            a = last++;
            while (((a-1) >= first) && (arr[a % size].prior < x.prior)) {
                arr[(a+1) % size] = arr[a % size];
            }
            arr[(a+1) % size] = x;
        }
    }
    T pop() {
        if (first == last)
            throw std::string("Empty!");
        else
            return arr[(first++) % size];
    }
    T front() {
        if (first == last)
            throw std::string("Empty!");
        else
            return arr[first % size];
    }
    T back() {
        if (first == last)
            throw std::string("Empty!");
        else
            return arr[(last-1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
