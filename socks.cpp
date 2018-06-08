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
// Purpose: Constructor that takes in all three parameters.
// Create an object using the parameters provided.
// ****************************************************************************
Socks::Socks(string style, string barcode, string color, string material, string fit, string size) : Item("Socks", string barcode, string color)
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
void Socks::setMaterial(string m)
{
     material = m;
}

// ****************************************************************************
// Purpose: change the fit based on the parameter provided.
// Pre: f - parameter to change the fit data member.
// ****************************************************************************
void Socks::setFit(string f)
{
     fit = f;
}

// ****************************************************************************
// Purpose: change the size based on the parameter provided.
// Pre: s - parameter to change the size data member.
// ****************************************************************************
void Socks::setSize(string s)
{
     size = s;
}

// ****************************************************************************
// Purpose: return the material data object
// Post: return the material data object
// ****************************************************************************
string Socks::getMaterial() const
{
     return material;
}

// ****************************************************************************
// Purpose: return the fit data object
// Post: return the fit data object
// ****************************************************************************
string Socks::getFit() const
{
     return fit;
}

// ****************************************************************************
// Purpose: return the size data object
// Post: return the size data object
// ****************************************************************************
string Socks::getSize() const
{
     return size;
}
