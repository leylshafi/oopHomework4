#pragma once
class Computer
{
private:
	
	size_t _id;
	char* _model;
	char* _color;
	size_t _year;
	char* _CPU; // Intel Core i7-8550U
	short _RAM;
	size_t _space; // (Hard disc or SSD)
public:
	static size_t _staticId;
	Computer();

	Computer(const char* model, const char* color, size_t year, const char*cpu, short ram, size_t space);

	Computer(const Computer& other);
	Computer& operator=(const Computer& other);

	void setModel(const char* model);
	void setColor(const char* color);
	void setYear(size_t year);
	void setCpu(const char* cpu);
	void setRam(short ram);
	void setSpace(size_t space);
	

	size_t getID() const;
	const char* getModel()const;
	const char* getColor()const;
	size_t getYear()const;
	const char* getCPU()const;
	short getRAM()const;
	size_t getSpace()const;
	size_t getStaticID()const;


	void print() const ;

	~Computer();
};

size_t Computer::_staticId = 0;

Computer::Computer() {
	_id = ++_staticId;
}

Computer::Computer(const char* model, const char* color, size_t year, const char* cpu, short ram, size_t space)
	:Computer()
{
	
	setModel(model);
	setColor(color);
	setYear(year);
	setCpu(cpu);
	setRam(ram);
	setSpace(space);

}


//////SETTER
void Computer::setModel(const char* model) {
	assert(!(model == nullptr));

	if (_model != nullptr)
		delete[] _model;

	size_t len = strlen(model) + 1;
	_model = new char[len];
	strcpy_s(_model, len, model);
}
void Computer::setColor(const char* color) {
	assert(!(color == nullptr));

	if (_color != nullptr)
		delete[] _color;

	size_t len = strlen(color) + 1;
	_color = new char[len];
	strcpy_s(_color, len, color);
}
void Computer::setYear(size_t year) {
	if (year >= 1822 && year <= 2022)
		_year = year;
	else
		assert(!"year >= 1822 && year <= 2022");
}
void Computer::setCpu(const char* cpu) {
	assert(!(cpu == nullptr));

	if (_CPU != nullptr)
		delete[] _CPU;

	size_t len = strlen(cpu) + 1;
	_CPU = new char[len];
	strcpy_s(_CPU, len, cpu);
}
void Computer::setRam(short ram) {
	if (ram >= 2 && ram <= 64)
		_RAM = ram;
	else
		assert(!"ram >= 2 && ram <= 64");
}
void Computer::setSpace(size_t space)
{
	if (space >= 2 && space <= 2000)
		_space = space;
	else
		assert(!"space >= 2 && space <= 2000");
}


////// GETTER
size_t Computer::getID()const { return _id; }
const char* Computer::getModel()const { return _model; }
const char* Computer::getColor()const { return _color; }
size_t Computer::getYear()const { return _year;}
const char* Computer::getCPU() const { return _CPU; }
short Computer::getRAM()const { return _RAM; }
size_t Computer::getSpace() const { return _space; }
size_t Computer::getStaticID()const { return _staticId; }

/////// DESTRUCTOR
Computer::~Computer() {
	delete[]_model;
	delete[]_color;
	delete[]_CPU;
	_model = _color = _CPU = nullptr;
}

/////FUNCTIONS
void Computer::print() const {
	cout << "ID: " << _id << endl;
	cout << "Model: " << _model<< endl;
	cout << "Color: " << _color << endl;
	cout << "Year: " << _year << endl;
	cout << "CPU: " << _CPU << endl;
	cout << "RAM: " << _RAM << endl;
	cout << "Space: " << _space << endl;
	cout << endl;
}

/////// Copy constructor
Computer::Computer(const Computer& other) {
	cout << "Copy Constructor\n";

	_id = other._id;
	setModel(other._model);
	setColor(other._color);
	setYear(other._year);
	setCpu(other._CPU);
	setRam(other._RAM);
	setSpace(other._space);
}

////// Copy assignment operator
Computer& Computer::operator=(const Computer& other) {
	cout << "Copy assignment operator\n";

	_id = other._id;
	setModel(other._model);
	setColor(other._color);
	setYear(other._year);
	setCpu(other._CPU);
	setRam(other._RAM);
	setSpace(other._space);
	return *this;
}