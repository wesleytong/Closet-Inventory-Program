#include "pants.h"

// ****************************************************************************
// Purpose: default constructor sets data members to the default.
// ****************************************************************************
Pants::Pants() : Item()
{
	purpose = "";
	fit = "";
}

// ****************************************************************************
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************
Pants::Pants(string barcode, string color, string material, string size, string purpose, string fit, string description)
	: Item("Pants", barcode, color, description, material, size)
{
	this->purpose = purpose;
	this->fit = fit;
}

// ****************************************************************************
// Purpose: default destructor
// ****************************************************************************
Pants::~Pants()
{
	// default destructor
}

// ****************************************************************************
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************
void Pants::setPurpose(string purpose)
{
	this->purpose = purpose;
}

// ****************************************************************************
// Purpose: change the fit based on the parameter provided.
// Pre: f - parameter to change the fit data member.
// ****************************************************************************
void Pants::setFit(string fit)
{
	this->fit = fit;
}

// ****************************************************************************
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
string Pants::getPurpose() const
{
	return purpose;
}

// ****************************************************************************
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************
string Pants::getFit() const
{
	return fit;
}