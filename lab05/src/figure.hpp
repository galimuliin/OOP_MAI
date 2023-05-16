#pragma once
#include <stdexcept>
#include <utility>
#include <iostream>

const double PI = 3.141592653589793;

// сложение двух векторов, заданных типом T
template <class T>
std::pair<T, T> operator + (const std::pair<T, T> a, const std::pair<T, T> b) {
	return { a.first + b.first, a.second + b.second };
}

// вычетание двух точек, заданных типом T
template <class T>
std::pair<T, T> operator - (const std::pair<T, T> a, const std::pair<T, T> b) {
	return { a.first - b.first, a.second - b.second };
}

// скалярное произведение точек в R^2, заданное типом T
template <class T>
T operator * (const std::pair<T, T> a, const std::pair<T, T> b) {
	return a.first * b.first + a.second * b.second;
}
// умножение точки на константу в типе T
template <class T>
std::pair<T, T> operator * (const T a, const std::pair<T, T> b) {
	return { a * b.first, a * b.second };
}

// ввод точки заданной типом T
template <class T>
std::ostream& operator<< (std::ostream& out, const std::pair<T, T>& p) {
	out << '(' << p.first << " , " << p.second << ')';
	return out;
};

// вывод точки заданной типом T
template <class T>
std::istream& operator>> (std::istream& in, std::pair<T, T>& p) {
	in >> p.first >> p.second;
	return in;
}

// расстояние между двумя точками заданными парой вершин(координаты типа T)
template <class T>
T len(const std::pair<T, T> a, const std::pair<T, T> b) {
	return std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
}

template <class T>
T abs(const std::pair<T, T> a) {
	return std::sqrt(std::pow(a.first, 2) + std::pow(a.second, 2));
}

template <class T>
std::pair<T, T> rotate(std::pair<T, T> pair, const double angle) {
	std::pair<T, T> rotated;
	rotated.first = (T)(pair.first * std::cos(angle) - pair.second * std::sin(angle));
	rotated.second = (T)(pair.first * std::sin(angle) + pair.second * std::cos(angle));
	return rotated;
}

template<typename T>
class Rhombus {
public:
	using Vertex = std::pair<T, T>;

	Rhombus();
	Rhombus(Vertex center, Vertex vertex, T second_diag_length);

	double Square() const;
	
	friend std::ostream& operator<< (std::ostream& out, const Rhombus<T>& t) {

		out << "point coordinates: ";
		out << t.vertex << "; "
			<< t.vertex + (T)(2) * (t.center - t.vertex) << "; "
			<< t.center +  t.second_diag_length / (T)(2) * ((T)(1) / abs(t.center - t.vertex)) * rotate(t.center - t.vertex,PI/2) << "; "
			<< t.center -  t.second_diag_length / (T)(2) * ((T)(1) / abs(t.center - t.vertex)) * rotate(t.center - t.vertex,PI/2);
		out << "\t Square: " << t.Square() << '\n';
		return out;
	}

	friend std::istream& operator>> (std::istream& in, Rhombus<T>& t) {
		in >> t.center >> t.vertex >> t.second_diag_length;
		if (t.center == t.vertex)
			in.setstate(std::ios_base::failbit);
		return in;
	}

private:
	static const int vertex_count = 3;

	Vertex center;
	Vertex vertex;
	T second_diag_length;
};

template<typename T>
Rhombus<T>::Rhombus()
{}

template<typename T>
Rhombus<T>::Rhombus(Vertex center, Vertex vertex, T second_diag_length) 
	: center{ center }, vertex{ vertex }, second_diag_length{second_diag_length}
{
	if (center == vertex)
		throw std::invalid_argument("center cannot be eq to the vertex");
}

template<typename T>
double Rhombus<T>::Square() const {
	return len(vertex, center) * second_diag_length;
}