#include "socks.h"


// ****************************************************************************
// Purpose: Constructor that sets materials, fit and size to default.
// ****************************************************************************
Socks::Socks() : Item()
{
     material = "";
     fit = "";
     size = "";
}

// ****************************************************************************
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor.
// Create an object using the parameters provided.
// ****************************************************************************
Socks::Socks(string barcode, string color, string material, string fit, string size)
     : Item("Socks", barcode, color)
{
     this -> material = material;
     this -> fit = fit;
     this -> size = size;
}

// ****************************************************************************
// Purpose: default destructor to delete sock object.
// ****************************************************************************
Socks::~Socks()
{
     // This is the default destructor.
}

// ****************************************************************************
// Purpose: change the material based on the parameter provided.
// Pre: m - parameter to change the material data member.
// ****************************************************************************
void Socks::setMaterial(string material)
{
     this -> material = material;
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
// Purpose: change the size based on the parameter provided.
// Pre: s - parameter to change the size data member.
// ****************************************************************************
void Socks::setSize(string size)
{
     this -> size = size;
}

// ****************************************************************************
// Purpose: return the material data member
// Post: return the material data member
// ****************************************************************************
string Socks::getMaterial() const
{
     return material;
}

// ****************************************************************************
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************
string Socks::getFit() const
{
     return fit;
}

// ****************************************************************************
// Purpose: return the size data member
// Post: return the size data member
// ****************************************************************************
string Socks::getSize() const
{
     return size;
}
