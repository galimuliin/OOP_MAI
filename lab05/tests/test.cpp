#include "pch.h"
#include "../src/figure.hpp"
#include "../src/vector.hpp"

// Тесты для треугольника

TEST(Figure, Create) {
	Triangle<int> t{ Triangle<int>::Vertex{0, 0}, Triangle<int>::Vertex{1, 0} };
}

TEST(Figure, Square) {
	Triangle<double> t{ {0, 0}, {0, 3} };
	ASSERT_NEAR(t.Square(), 11.691342951, 0.000000001);
}

TEST(Figure, Output) {
	Triangle<double> t{ {0, 0}, {0, 3} };
	std::stringstream strs;
	strs << t;
}

TEST(Figure, Input) {
	Triangle<double> t{ {0,0}, {0,1} };
	std::stringstream s{ "0 0 0 3" };
	s >> t;
}

// Тесты для динамического массива

TEST(Vector, InitAndDeinit) {
	Vector<int> v;
	Vector<double> v2(10);
}

TEST(Vector, OperatorSquareBrackets) {
	Vector<int> v = { 1, 2, 3, 4 };

	ASSERT_TRUE(v[0] == 1 && v[3] == 4);
	ASSERT_THROW(v[-1], std::out_of_range);
	ASSERT_THROW(v[4], std::out_of_range);
}

TEST(Vector, Iterator) {
	Vector<int> v = { 1, 2, 3, 4 };
	Vector<int>::iterator begin = v.begin();
	Vector<int>::iterator end = v.end();

	ASSERT_EQ(*begin, 1);
	ASSERT_EQ(*++begin, 2);
	ASSERT_NE(begin, end);
	ASSERT_THROW(*end, std::out_of_range);

	Vector<int> empty_vec;
	ASSERT_EQ(empty_vec.begin(), empty_vec.end());
}

TEST(Vector, push_back) {
	Vector<int> v;
	v.push_back(10);
	ASSERT_EQ(v[0], 10);
}

TEST(Vector, Insert) {
	Vector<int> v(0);
	v.insert(v.begin(), 10);
	v.insert(v.end(), 42);
	v.insert(++v.begin(), 36);
	ASSERT_EQ(v[0], 10);
	ASSERT_EQ(v[1], 36);
	ASSERT_EQ(v[2], 42);
}

TEST(Vector, Erase) {
	Vector<int> v = { 1,2,3,4 };
	auto it = v.erase(v.begin());
	ASSERT_TRUE(it == v.begin() && v.size() == 3 && v[0] == 2);
}