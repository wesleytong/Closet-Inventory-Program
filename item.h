#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Item{
private:
     string style;
     string barcode; // barcode is our unique ID
     string color;
     string description;
     string material;
     string size;

     string generateBarcode();

public:
     // Constructors and destructors
     Item();

     Item(string style, string barcode, string color, string description, string material, string size);
     ~Item();

     // Mutators
     void setMaterial(string material);
     void setColor(string color);
     void setDescription(string description);
     void setSize(string size);

     // Accessors
     string getMaterial() const;
     string getStyle() const;
     string getBarcode() const;
     string getColor() const;
     string getDescription() const;
     string getSize() const;

};

#endif

// ****************************************************************************
// Item()
// Purpose: Default constructor that defaults data members.
// ****************************************************************************

// ****************************************************************************
// Item(string style, string barcode, string color, string description, string material, string size)
// Purpose: Constructor that creates an item based on the parameters passed.
// Pre: style - set the style to the parameter passed.
//      barcode - set the barcode to the parameter passsed.
//      color - set the color to the parameter passed.
//      description - set the description to the parameter passed.
//      material - set the material to the parameter passed.
//      size - set the size to the parameter passed.
// Post: tree has been processed
// ****************************************************************************

// ****************************************************************************
// ~Item()
// Purpose: Default destructor.
// ****************************************************************************

// ****************************************************************************
// void setMaterial(string material)
// Purpose: set the material data member to the parameter passed.
// Pre: material - set the color to the parameter passed.
// ****************************************************************************

// ****************************************************************************
// void setDescription(string description)
// Purpose: set the description data member to the parameter passed.
// Pre: description - set the description to the parameter passed.
// ****************************************************************************

// ****************************************************************************
// void setColor(string color)
// Purpose: set the color data member to the parameter passed.
// Pre: color - set the color to the parameter passed.
// ****************************************************************************

// ****************************************************************************
// void setSize(string size)
// Purpose: set the size data member to the parameter passed.
// Pre: size - set the size to the parameter passed.
// ****************************************************************************

// ****************************************************************************
// string getStyle() const
// Purpose: return the style data member.
// Post: return the style data member.
// ****************************************************************************

// ****************************************************************************
// string getBarcode() const
// Purpose: return the barcode data member.
// Post: return the barcode data member.
// ****************************************************************************

// ****************************************************************************
// string getColor() const
// Purpose: return the color data member.
// Post: return the color data member.
// ****************************************************************************

// ****************************************************************************
// string getMaterial() const
// Purpose: return the material data member.
// Post: return the material data member.
// ****************************************************************************

// ****************************************************************************
// string getDescription() const
// Purpose: return the descrption data member.
// Post: return the description data member.
// ****************************************************************************

// ****************************************************************************
// string getSize() const
// Purpose: return the size data member.
// Post: return the size data member.
// ****************************************************************************

// ****************************************************************************
// string generateBarcode()
// Purpose: generate barcode based on specified rules (1st digit is style,
// 2nd digit is color, randomize the last two.
// Post: string that is the generated barcode.
// ****************************************************************************
