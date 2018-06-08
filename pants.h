#ifndef PANTS_H
#define PANTS_H

#include "item.h"

class Pants : public Item {
private:
     string purpose;
     string fit;
     int size;

public:
     // Constructors and destructors
     Pants();
     Pants(string barcode, string color, string purpose, string fit, int size);
     ~Pants();

     // Mutators
     void setPurpose(string purpose);
     void setFit(string fit);
     void setSize(int size);

     // Accessors
     string getPurpose() const;
     string getFit() const;
     int getSize() const;
};

#endif

// ****************************************************************************
// Pants()
// Purpose: default constructor sets data members to the default.
// ****************************************************************************

// ****************************************************************************
// Pants(string barcode, string color, string purpose, string fit, int size)
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Pants()
// Purpose: default destructor
// ****************************************************************************

// ****************************************************************************
// void setPurpose(string purpose)
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************

// ****************************************************************************
// void setFit(string fit)
// Purpose: change the fit based on the parameter provided.
// Pre: f - parameter to change the fit data member.
// ****************************************************************************

// ****************************************************************************
// void setSize(int size)
// Purpose: change the size based on the parameter provided.
// Pre: size - parameter to change the size data member.
// ****************************************************************************

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************

// ****************************************************************************
// string getFit() const
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************

// ****************************************************************************
// int getSize() const
// Purpose: return the size data member
// Post: return the size data member
// ****************************************************************************
