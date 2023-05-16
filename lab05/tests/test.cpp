#include "pch.h"
#include "../src/figure.hpp"
#include "../src/vector.hpp"


TEST(Figure, Create) {
	Rhombus<int> t{ Rhombus<int>::Vertex{1, 0}, Rhombus<int>::Vertex{0, 0}, 1 };
}

TEST(Figure, Square) {
	Rhombus<double> t{ Rhombus<int>::Vertex{1, 0}, Rhombus<int>::Vertex{0, 0}, 1 };
	ASSERT_NEAR(t.Square(), 4.0, 0.0000000001);
}

TEST(Figure, Output) {
	Rhombus<double> t{ Rhombus<int>::Vertex{1, 0}, Rhombus<int>::Vertex{0, 0}, 1 };
	std::stringstream strs;
	strs << t;
}

TEST(Figure, Input) {
	Rhombus<double> t{ Rhombus<int>::Vertex{1, 0}, Rhombus<int>::Vertex{0, 0}, 1 };
	std::stringstream s{ "1 0 0 0 1" };
	s >> t;
}