#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Item {
private:
     string style;
     string barcode; // barcode is our unique ID
     string color;

     string generateBarcode();

public:
     // Constructors and destructors
     Item();
     Item(string style, string barcode, string color);
     ~Item();

     // Mutators
     void setColor(string color);

     // Accessors
     string getStyle() const;
     string getBarcode() const;
     string getColor() const;

};

#endif

// ****************************************************************************
// Item()
// Purpose: Default constructor that defaults data members.
// ****************************************************************************

// ****************************************************************************
// Item(string style, string barcode, string color)
// Purpose: Constructor that creates an item based on the parameters passed.
// Pre: style - set the style to the parameter passed.
//      barcode - set the barcode to the parameter passsed.
//      color - set the color to the parameter passed.
// Post: tree has been processed
// ****************************************************************************

// ****************************************************************************
// ~Item()
// Purpose: Default destructor.
// ****************************************************************************

// ****************************************************************************
// void setColor(string color)
// Purpose: set the color data member to the parameter passed.
// Pre: c - set the color to the parameter passed.
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
// string generateBarcode()
// Purpose: generate barcode based on specified rules (1st digit is style,
// 2nd digit is color, randomize the last two.
// Post: string that is the generated barcode.
// ****************************************************************************
