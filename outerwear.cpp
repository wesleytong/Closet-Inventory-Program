#include "outerwear.h"

// ****************************************************************************
// Purpose: default constructor sets data members to the default.
// ****************************************************************************
Outerwear::Outerwear() : Item()
{
     purpose = "";
     size = "";
}

// ****************************************************************************
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************
Outerwear::Outerwear(string barcode, string color, string purpose, string size)
     : Item("Outerwear", barcode, color)
{
     this -> purpose = purpose;
     this -> size = size;
}

// ****************************************************************************
// Purpose: default destructor
// ****************************************************************************
Outerwear::~Outerwear()
{
     // default destructor
}

// ****************************************************************************
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************
void Outerwear::setPurpose(string purpose)
{
     this -> purpose = purpose;
}

// ****************************************************************************
// Purpose: change the size based on the parameter provided.
// Pre: size - parameter to change the size data member.
// ****************************************************************************
void Outwear::setSize(string size)
{
     this -> size = size;
}

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
string Outerwear::getPurpose() const
{
     return purpose;
}

// ****************************************************************************
// string getSize() const
// Purpose: return the size data member
// Post: return the size data member
// ****************************************************************************
string Outerwear::getSize() const
{
     return size;
}
