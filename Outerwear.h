#ifndef OUTERWEAR_H
#define OUTERWEAR_H

#include "item.h"

class Outerwear : public Item {
private:
public:
	// Constructors and destructors
	Outerwear();
	Outerwear(string barcode, string color, string material, string size, string description);
	~Outerwear();

};

#endif

// ****************************************************************************
// Outerwear()
// Purpose: default constructor sets data members to the default.
// ****************************************************************************

// ****************************************************************************
// Outerwear(string barcode, string color, string material, string size, string description)
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Outerwear()
// Purpose: default destructor
// ****************************************************************************