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
     Item(string, string, string);
     ~Item();

     // Mutators
     void setStyle(string);
     void setColor(string);

     // Accessors
     string getStyle() const;
     string getBarcode() const;
     string getColor() const;

};

#endif
