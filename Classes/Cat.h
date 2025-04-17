#include "Base.h"
#pragma once


class Cat : public BaseClassName
{
public:

	void Read(ostream& ostream, istream& istream) override
	{
		BaseClassName::Read(ostream, istream);
		ostream << "Enter color: ";
		istream >> m_color;
	}
	void Write(ostream& ostream) override
	{
		BaseClassName::Write(ostream);
		ostream << "Color: " << m_color << endl;
	}
	eType GetType() override
	{
		return eType::CAT;
	}
private:
	string m_color;
};
