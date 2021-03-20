// Copyright 2020 Michael Zogin
#include "CircularBuffer.h"

int main() {
  CircularBuffer test(100);
  test.enqueue(1);
  test.enqueue(2);
  test.enqueue(3);
  test.enqueue(4);
  test.enqueue(5);
  test.output();
  return 0;
}
