#pragma once

#include <string>

class Entity
{
private:
	std::string m_name;
	std::string m_description;

public:
	Entity(const std::string& name, const std::string& description)
		: m_name{ name }, m_description{ description }
	{

	}

	virtual ~Entity() {}

	const std::string& GetName() const
	{
		return m_name;
	}

	const std::string& GetDescription() const
	{
		return m_description;
	}

	virtual void Describe() const;

};