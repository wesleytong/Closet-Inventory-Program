#include "miscellaneous.h"
#include "Item.h"

// ****************************************************************************
// Purpose: Constructor that sets materials, fit and size to default.
// ****************************************************************************
Miscellaneous::Miscellaneous() : Item()
{

}

// ****************************************************************************
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor.
// Create an object using the parameters provided.
// ****************************************************************************
Miscellaneous::Miscellaneous(string style, string barcode, string color, string material, string description, string size)
	: Item(style, barcode, color, description, material, size)
{

}

// ****************************************************************************
// Purpose: default destructor to delete Miscellaneous object.
// ****************************************************************************
Miscellaneous::~Miscellaneous()
{
	// default destructor
}