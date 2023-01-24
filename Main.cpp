#include <iostream>
#include <vector>
//API - Application Programming Interface
class  IVehicle
{
public:
	virtual void printName() {
		std::cout << "Ivehicle\n";
	}
	virtual int getSpeed() = 0;//абстрактный метод без реализации
	virtual ~IVehicle() {
		std::cout << "Destraction Ivehicle was called" << '\n';
	}
private:
};
class Car :public IVehicle {
public:
	Car(int speed) :_speed(speed) {}
	void printName() override {
		std::cout << "Car" << std::endl;
	}
	~Car() {
		std::cout << "Destraction Car was called" << '\n';
	}
	int getSpeed() override {
		return _speed;
	}
private:
	int _speed;
};
class Van : public Car {
public:
	Van(int speed) :Car(speed) {}
	~Van() {
		std::cout << "Van destruction was called\n";
	}
};
class Motorcycle :public IVehicle {
public:
	Motorcycle(int speed) :_speed(speed) {}
	~Motorcycle() {
		std::cout << "Destraction Motorcycle was called" << '\n';
	}
	int getSpeed()override {
		return _speed;
	}
private:
	int _speed;
};
void printer(IVehicle* vehicle) {
	vehicle->printName();
	std::cout << vehicle->getSpeed() << '\n';
}
int main() {
	setlocale(LC_ALL, "Russian");
	//IVehicle* a = new IVehicle();
	IVehicle* b = new Car(50);
	IVehicle* c = new Motorcycle(60);
	IVehicle* v = new Van(45);
	//a->printName();
	b->printName();
	std::vector<IVehicle*> vehicle;
	//vehicle.push_back(a);
	vehicle.push_back(b);
	vehicle.push_back(c);
	vehicle.push_back(v);
	std::cout << "==============" << std::endl;
	for (size_t i = 0; i < vehicle.size();i++ ) {
		(*vehicle[i]).printName();//vehicle[i]->printName();
	}
	std::cout << "==============" << std::endl;
	for (size_t i = 0; i < vehicle.size(); i++) {
		printer(vehicle[i]);
	}
	//delete a;
	delete b;
	delete c;
	delete v;
	return 0;
}