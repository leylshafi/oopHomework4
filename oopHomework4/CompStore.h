#pragma once
class CompStore
{
private:
	char* _name;
	Computer** _computers = nullptr;
	size_t _count;
public:
	
	CompStore();

	CompStore(const char*name, Computer**computers);

	void setStoreName(const char* name);
	void setComputers(Computer** computers);


	const char* getName()const;
	Computer** getComputers()const;


	void print()const;
	void printComputersRAMGreaterThan(short min)const;
	void printComputersYearBetween(size_t minYear, size_t maxYear)const;
	Computer* getComputerById(size_t id);
	Computer** getComputersByColor(const char* color);

	~CompStore();
};

CompStore::CompStore() {
	_count = Computer::_staticId;
}

CompStore::CompStore(const char* name, Computer** computers)
	:CompStore()
{
	setStoreName(name);
	setComputers(computers);
}

/////SETTER
void CompStore::setStoreName(const char* name) {
	assert(!(name == nullptr));

	if (_name != nullptr)
		delete[] _name;

	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

void CompStore::setComputers(Computer** computers) {
	_computers = computers;
}

///// GETTER
const char* CompStore::getName()const { return _name; }
Computer** CompStore::getComputers()const { return _computers; }


///// DESTRUCTOR

CompStore::~CompStore() {
	delete[]_name;
	_name =nullptr;
}

////FUNCTIONS
void CompStore::print()const {
	cout << "Computer store name: " << (_name?_name:"null") << endl;
	cout << "===== Computers =====" << endl;
	for (size_t i = 0; i < _count; i++)
	{
		_computers[i]->print();
	}
	cout << "===== END =====" << endl;
}

void CompStore::printComputersRAMGreaterThan(short min) const {
	for (size_t i = 0; i < _count; i++)
	{
		if(_computers[i]->getRAM()>min)
			_computers[i]->print();
	}
}

void CompStore::printComputersYearBetween(size_t minYear, size_t maxYear) const {
	for (size_t i = 0; i < _count; i++)
	{
		if(_computers[i]->getYear()>minYear && _computers[i]->getYear() < maxYear)
			_computers[i]->print();
	}
}

Computer* CompStore::getComputerById(size_t id) {
	for (size_t i = 0; i < _count; i++)
	{
		if (_computers[i]->getID() == id)
			return _computers[i];
	}
}

Computer** CompStore::getComputersByColor(const char* color) {
	Computer** temp = new Computer * [_count] {};
	for (size_t i = 0,j=0; i < _count; i++)
	{
		if (strcmp(_computers[i]->getColor(), color) == 0)
			temp[j++] = _computers[i];

	}
	return temp;
}