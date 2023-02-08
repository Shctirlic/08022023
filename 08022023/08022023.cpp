#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "printer.h"
#include <memory>

using namespace Engine;


//Функторы и лямбды

//функторы это объект, в нашем случае класс, у которого перегружен оператор фигурные кнопки

class Incrementer {

public:
	Incrementer (int x) : _x(x) { }


	int operator()(int y) {
		return _x + y;


	}
	int myFunc(int y) {
		const auto add = [this, y](int a) {
			return _x + y + a;

		};
		return add(5);

	}
private:
	int _x;
};
class Ivehicle {
public:
	virtual int getSpeed() const = 0;
	virtual void printType () const = 0;
	virtual ~Ivehicle () {}
};

class Car : public Ivehicle {
public:
	Car (int speed) : _speed(speed) { }
	int getSpeed() const override {
		return _speed;

	}
private:
	int _speed;

};

class Moto : public Ivehicle {
public:
	Moto(int speed) : _speed(speed) { }
	int getSpeed() const override {
		return _speed;

	}
private:
	int _speed;
};

class Cart : public Ivehicle {
public:
	Cart(int speed) : _speed(speed) { }
	int getSpeed() const override {
		return _speed;

	}
private:
	int _speed;
};


int main() {

	std::shared_ptr<Ivehicle> v = std::make_shared<Car>(50);
	std::cout << "Vehicle speed: " << v->getSpeed() << std::endl;
	v->printType();
	std::cout<< " ====================" << std::endl;


	Incrementer inc(50);

	int a = inc(5);
	std::cout << a << std::endl;

	//лямбда
	// capture clause
	const auto myinc = [a](int number) {
		return number + 5 + a;

	};

	a = 2;

	std::cout << myinc(6) << std::endl;
	std::cout << inc.myFunc(3) << std::endl;

	std::cout << " ============================ " << std::endl;

	std::vector<int> vec{ 1, -4, 3, -2 };

	for (const auto e1 : vec) {
		std::cout << e1 << " ";

	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end());
	for (const auto e1 : vec) {
		std::cout << e1 << " ";
		std::cout << std::endl;

		//сортировка по модулю

		std::sort(vec.begin(), vec.end(), [](int a, int b) {
			return std::abs(a) > std::abs(b);
			});

		for (const auto e1 : vec) {
			std::cout << e1 << " ";

			std::cout << std::endl;

			Printer p;
			p.printerDefault();


		}
	}
}