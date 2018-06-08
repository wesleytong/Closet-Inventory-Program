#ifndef SOCKS_H
#define SOCKS_H

#include "item.h"

class Socks : public Item {
private:
     string material;
     string fit;
     string size; //string instead of char because need to account for XS, XL, etc.
public:
     // Constructors and destructors
     Socks();
     Socks(string barcode, string color, string material, string fit, string size);
     ~Socks();

     // Mutators
     void setMaterial(string material);
     void setFit(string fit);
     void setSize(string size);

     // Accessors
     string getMaterial() const;
     string getFit() const;
     string getSize() const;

};

#endif

// ****************************************************************************
// Socks()
// Purpose: Constructor that sets materials, fit and size to default.
// ****************************************************************************

// ****************************************************************************
// Socks(string barcode, string color, string material, string fit, string size)
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor.
// Create an object using the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Socks()
// Purpose: default destructor to delete sock object.
// ****************************************************************************

// ****************************************************************************
// void setMaterial(string material)
// Purpose: change the material based on the parameter provided.
// Pre: m - parameter to change the material data member.
// ****************************************************************************

// ****************************************************************************
// void setFit(string fit)
// Purpose: change the fit based on the parameter provided.
// Pre: f - parameter to change the fit data member.
// ****************************************************************************

// ****************************************************************************
// void setSize(string size)
// Purpose: change the size based on the parameter provided.
// Pre: s - parameter to change the size data member.
// ****************************************************************************

// ****************************************************************************
// string getMaterial() const
// Purpose: return the material data member
// Post: return the material data member
// ****************************************************************************

// ****************************************************************************
// string getFit() const
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************

// ****************************************************************************
// string getSize() const
// Purpose: return the size data member
// Post: return the size data member
// ****************************************************************************
