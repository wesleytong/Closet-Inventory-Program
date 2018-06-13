#include "socks.h"


// ****************************************************************************
// Purpose: Constructor that sets materials, fit and size to default.
// ****************************************************************************
Socks::Socks() : Item()
{
     fit = "";
}

// ****************************************************************************
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor.
// Create an object using the parameters provided.
// ****************************************************************************
Socks::Socks(string barcode, string color, string material, string size, string fit, string description)
     : Item("Socks", barcode, color, description, material, size)
{
     this -> fit = fit;
}

// ****************************************************************************
// Purpose: default destructor to delete sock object.
// ****************************************************************************
Socks::~Socks()
{
     // This is the default destructor.
}

// ****************************************************************************
// Purpose: change the fit based on the parameter provided.
// Pre: f - parameter to change the fit data member.
// ****************************************************************************
void Socks::setFit(string fit)
{
     this -> fit = fit;
}

// ****************************************************************************
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************
string Socks::getFit() const
{
     return fit;
}
