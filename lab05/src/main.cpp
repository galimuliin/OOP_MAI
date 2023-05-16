
#include <iostream>
#include <algorithm>
#include "vector.hpp"
#include "figure.hpp"


void clear()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void help()
{
	std::cout <<
		"список команд:\n"
		"    help        -- помощь в управлении\n"
		"    exit        -- Выйти из программы\n"
		"    print       -- Вывести элемент коллекции\n"
		"    square <par>  -- Вывести кол-во фигур с площадью меньше заданной\n"
		"    erase <id> -- удалить элемент по id\n"
		"    push <<center> <vertex(left,bottom)> <len of the second diag> -- добавьте новый ромб в коллекцию с заданным id\n"
		"    pop  -- удалить из стека последний элемент"
		<< std::endl;
}

template<class T>
void print(Vector<T>& figures) {
	std::for_each(figures.begin(), figures.end(), [](T& val) { 
		std::cout << val;
	});
}

template<class T>
void square(Vector<T>& figures) {
	double par;
	if (!(std::cin >> par)) {
		std::cout << "плохое значение площади для условия.\n";
		clear();
		return;
	}

	long long count = std::count_if(figures.begin(), figures.end(), [par](T& val){
		return val.Square() <= par;
	});
	std::cout << "Найдено фигур, с полщадью меньше " << par << ", в кол-ве: "  << count << '\n';
}

template<class T>
void erase(Vector<T>& vec) {
	int del_element_idx;
	if (!(std::cin >> del_element_idx) || del_element_idx < 0 || del_element_idx >= vec.size()) {
		std::cout << "плохое значение индекса для удаления.\n";
		clear();
		return;
	}

	vec.erase(vec.iterator_by_index(del_element_idx));
}

template<class T>
void insert(Vector<T>& vec) {
	int new_element_index;
	if (!(std::cin >> new_element_index) || new_element_index < 0 || new_element_index > vec.size()) {
		std::cout << "невалидный новый индекс.\n";
		clear();
		return;
	}
	
	T new_el;
	if (!(std::cin >> new_el))
	{
		std::cout << "плохой формат ввода фигуры.\n";
		clear();
		return;
	}

	vec.insert(vec.iterator_by_index(new_element_index), new_el);
}

template<class T>
void push_back(Vector<T>& vec) {
	T new_el;
	if (!(std::cin >> new_el))
	{
		std::cout << "плохой формат ввода фигуры.\n";
		clear();
		return;
	}

	vec.push_back(new_el);
}

template<class T>
void pop_back(Vector<T>& vec) {
	vec.pop_back();
}

int main()
{
	setlocale(LC_ALL, "russian");
	Vector<Rhombus<float> > figures;

	std::string cmd;
	std::cout << '>';
	while (std::cin >> cmd)
	{
		if (cmd == "help")
			help();
		else if (cmd == "exit")
			break;
		else if (cmd == "print")
			print(figures);
		else if (cmd == "square")
			square(figures);
		else if (cmd == "erase")
			erase(figures);
		else if (cmd == "insert")
			insert(figures);
		else if (cmd == "push")
			push_back(figures);
		else if (cmd == "pop")
			pop_back(figures);
		else
		{
			std::cout << "Программа позволяет работать с коллекцией экземпляров фигур(ромбов). Для большей информации нажмите \"help\"" << std::endl;
			clear();
		}

		std::cout << '>';
	}

	return 0;
}