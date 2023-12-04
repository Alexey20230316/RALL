#include<iostream>

class Smart_arry
{
public:
	Smart_arry(const Smart_arry&) = delete;               // запрещаем конструктор копирования 
	Smart_arry& operator=(const Smart_arry&) = delete;    // запрещаем конструктор присваивания
	Smart_arry(int size);
	void add_element(int element);
	int get_element(int element);
	~Smart_arry();
private:
	int* arr;   // указатель на обьект типа int
	int i = 0; // наполненность массива
	int size;  // размер
};

Smart_arry::Smart_arry(int size)
{
	this->size = size;
	arr = new int[size] {0};
}

Smart_arry::~Smart_arry()
{
	delete[] arr;
}

void Smart_arry::add_element(int element)
{
	if (i >= size)
	{
		throw std::exception("No vacant tables!!!");
	}
	arr[i] = element;
	i = i++;	
}
int Smart_arry::get_element(int element)
{	
	if (element > i)   // если индекс запрашиваемого элемента больше i
	{
		throw std::exception("Index is greater than allowed!!! ");
	}
	return arr[element];
}

int main() {

	try
	{

		Smart_arry arr(5);
		arr.add_element(1);
		arr.add_element(2);
		arr.add_element(3);
		arr.add_element(4);
		arr.add_element(5);
		//arr.add_element(6);
		std::cout << arr.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.get_element(2) << std::endl;
		std::cout << arr.get_element(3) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
		//std::cout << arr.get_element(5) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	
	

	return 0;
}