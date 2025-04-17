#include "Base.h"
#pragma once

class Dog : public BaseClassName
{
public:

	void Read(ostream& ostream, istream& istream) override
	{
		BaseClassName::Read(ostream, istream);
		ostream << "Enter breed: ";
		istream >> m_breed;
	}
	void Write(ostream& ostream) override
	{
		BaseClassName::Write(ostream);
		ostream << "Breed: " << m_breed << endl;
	}
	eType GetType() override
	{
		return eType::DOG;
	}
private:
	string m_breed;
};
