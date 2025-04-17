#include "Base.h"
#include "Dog.h"
#include "Cat.h"
#pragma once
#include <vector>

class Database {
public:
	vector<BaseClassName*> objects;
	~Database() {
		for (BaseClassName* obj : objects)
		{
			delete obj;
		}
	}
	void Create(BaseClassName::eType type) {
		BaseClassName* obj = nullptr;
		switch (type)
		{
		case BaseClassName::eType::CAT:
			obj = new Cat;
			break;
		case BaseClassName::eType::DOG:
			obj = new Dog;
			break;
		}
		obj->Read(std::cout, std::cin);
		objects.push_back(obj);
	}
	void DisplayAll() {
		for (BaseClassName* obj : objects)
		{
			obj->Write(std::cout);
		}
	}
	void Display(const std::string& name) {
		for (BaseClassName* obj : objects){
			if (obj->GetName() == name)
			{
				obj->Write(std::cout);
			}
		}
	}
	void Display(BaseClassName::eType type) {
		for (BaseClassName* obj : objects) {
			if (obj->GetType() == type) {
				obj->Write(std::cout);
			}
		}
	}
};
