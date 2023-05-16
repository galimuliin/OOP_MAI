#pragma once
#include <stdexcept>
#include <utility>
#include <iostream>

const double PI = 3.141592653589793;
// ��������� ��������
template <class T>
std::pair<T, T> operator + (const std::pair<T, T> a, const std::pair<T, T> b) {
	return { a.first + b.first, a.second + b.second };
}
// ��������� ���������
template <class T>
std::pair<T, T> operator - (const std::pair<T, T> a, const std::pair<T, T> b) {
	return { a.first - b.first, a.second - b.second };
}
// ��������� ��������� ��������
template <class T>
T operator * (const std::pair<T, T> a, const std::pair<T, T> b) {
	return a.first * b.first + a.second * b.second;
}
// ��������� �� ������
template <class T>
std::pair<T, T> operator * (const T a, const std::pair<T, T> b) {
	return { a * b.first, a * b.second };
}

// ����� ��������� �����
template <class T>
std::ostream& operator<< (std::ostream& out, const std::pair<T, T>& p) {
	out << '(' << p.first << " , " << p.second << ')';
	return out;
};

// ���� ���������
template <class T>
std::istream& operator>> (std::istream& in, std::pair<T, T>& p) {
	in >> p.first >> p.second;
	return in;
}

// ������� ������� pair �� ���� angle
template <class T>
std::pair<T, T> rotate(std::pair<T, T> pair, const double angle) {
	std::pair<T, T> rotated;
	rotated.first = (T)(pair.first * std::cos(angle) - pair.second * std::sin(angle));
	rotated.second = (T)(pair.first * std::sin(angle) + pair.second * std::cos(angle));
	return rotated;
}


template<typename T>
class Triangle {
public:
	using Vertex = std::pair<T, T>;

	Triangle();
	Triangle(Vertex center, Vertex vertex);

	// ���������� ������� ������������
	double Square() const;
	
	friend std::ostream& operator<< (std::ostream& out, const Triangle<T>& t) {
		const double ANGLE = 2 * PI / Triangle<T>::vertex_count; // ���� ����� ����� ��������� ��������� � �������

		out << "���������� ������������: ";
		out << t.vertex;		// ������� ������ �������
		auto vec = t.vertex - t.center;
		for (int i = 2; i <= Triangle<T>::vertex_count; ++i)
		{
			vec = rotate(vec, ANGLE); // �������� ���������� ��������� �������
			out << ' ' << t.center + vec;
		}
		out << "\t �������: " << t.Square() << '\n';
		return out;
	}

	friend std::istream& operator>> (std::istream& in, Triangle<T>& t) {
		in >> t.center >> t.vertex;
		if (t.center == t.vertex)
			in.setstate(std::ios_base::failbit);
		return in;
	}

private:
	static const int vertex_count = 3; // ���-�� ������ ������������

	Vertex center; // ����� ��������� ����������
	Vertex vertex; // ���� �� ������ ������������
};

template<typename T>
Triangle<T>::Triangle()
{}

template<typename T>
Triangle<T>::Triangle(Vertex center, Vertex vertex) 
	: center{ center }, vertex{ vertex } 
{
	if (center == vertex)
		throw std::invalid_argument("center cannot be eq to the vertex");
}

template<typename T>
double Triangle<T>::Square() const {
	auto vecRadius = vertex - center; // ������-������ ��������� ����������
	double sqRadius = vecRadius * vecRadius;	   // ������� ������� ��������� ����������
	return vertex_count / 2. * sqRadius * std::sin(2 * PI / vertex_count);
}