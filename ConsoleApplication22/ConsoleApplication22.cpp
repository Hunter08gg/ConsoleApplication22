#include <iostream>
#include <string>

class Component {
public:
	Component(const std::string& name, float price) : name(name), price(price) {}

	virtual void displayInfo() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Price: $" << price << std::endl;
	}

protected:
	std::string name;
	float price;
};

class Processor : public Component {
public:
	Processor(const std::string& name, float price, const std::string& socket, int numCores)
		: Component(name, price), socket(socket), numCores(numCores) {}

	void displayInfo() const override {
		Component::displayInfo();
		std::cout << "Socket: " << socket << std::endl;
		std::cout << "Number of cores: " << numCores << std::endl;
	}

private:
	std::string socket;
	int numCores;
};

class Memory : public Component {
public:
	Memory(const std::string& name, float price, int capacity, int speed)
		: Component(name, price), capacity(capacity), speed(speed) {}

	void displayInfo() const override {
		Component::displayInfo();
		std::cout << "Capacity: " << capacity << "GB" << std::endl;
		std::cout << "Speed: " << speed << "MHz" << std::endl;
	}

private:
	int capacity;
	int speed;
};

class GraphicsCard : public Component {
public:
	GraphicsCard(const std::string& name, float price, int memory, int numCores)
		: Component(name, price), memory(memory), numCores(numCores) {}

	void displayInfo() const override {
		Component::displayInfo();
		std::cout << "Memory: " << memory << "GB" << std::endl;
		std::cout << "Number of cores: " << numCores << std::endl;
	}

private:
	int memory;
	int numCores;
};

int main() {
	Component* processor = new Processor("Intel Core i7", 299.99f, "LGA1151", 8);
	Component* memory = new Memory("Corsair Vengeance", 89.99f, 16, 3200);
	Component* graphicsCard = new GraphicsCard("Nvidia GeForce RTX 3080", 699.99f, 10, 8704);

	processor->displayInfo();
	std::cout << std::endl;
	memory->displayInfo();
	std::cout << std::endl;
	graphicsCard->displayInfo();

	delete processor;
	delete memory;
	delete graphicsCard;

	return 0;
}