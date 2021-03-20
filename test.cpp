// Copyright 2020 Michael Zogin
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include "CircularBuffer.h"
#include <boost/test/unit_test.hpp>

// checks constructors
BOOST_AUTO_TEST_CASE(constructor) {
  BOOST_REQUIRE_NO_THROW(CircularBuffer(100));

  BOOST_REQUIRE_THROW(CircularBuffer(0), std::exception);
  BOOST_REQUIRE_THROW(CircularBuffer(-1), std::invalid_argument);
}

// makes sure size function works properly
BOOST_AUTO_TEST_CASE(size) {
  CircularBuffer test(10);

  BOOST_REQUIRE(test.size() == 0);
  test.enqueue(99);
  BOOST_REQUIRE(test.size() == 1);

  test.dequeue();
  BOOST_REQUIRE(test.size() == 0);
}

BOOST_AUTO_TEST_CASE(isEmpty) {
  CircularBuffer test1(1);

  BOOST_REQUIRE(test1.isEmpty() == true);

  CircularBuffer test2(1);
  test2.enqueue(1);
  BOOST_REQUIRE(test2.isEmpty() == false);
}

BOOST_AUTO_TEST_CASE(isFull) {
  CircularBuffer test1(1);

  BOOST_REQUIRE(test1.isFull() == false);

  CircularBuffer test2(1);
  test2.enqueue(1);
  BOOST_REQUIRE(test2.isFull() == true);
}

BOOST_AUTO_TEST_CASE(enqueue) {
  CircularBuffer test(3);

  BOOST_REQUIRE_NO_THROW(test.enqueue(1));
  BOOST_REQUIRE_NO_THROW(test.enqueue(1));
  BOOST_REQUIRE_NO_THROW(test.enqueue(1));
  BOOST_REQUIRE_THROW(test.enqueue(1), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(dequeue) {
  CircularBuffer test(3);
  test.enqueue(0);
  test.enqueue(1);
  test.enqueue(2);
  BOOST_REQUIRE(test.dequeue() == 0);
  BOOST_REQUIRE(test.dequeue() == 1);
  BOOST_REQUIRE(test.dequeue() == 2);
  BOOST_REQUIRE_THROW(test.dequeue(), std::runtime_error);
}
