#include "item.h"

// ****************************************************************************
// Purpose: generate barcode based on specified rules (1st digit is style,
// 2nd digit is color, randomize the last two.
// Post: string that is the generated barcode.
// ****************************************************************************
string Item::generateBarcode() {
     // create a temp string to assign the first two numbers according to
     // specifications.
     // then randomize the next two numbers.
     string temp = "";

     // set the first digit according to style.
     if (style == "Socks")
     {
          temp += "1";
     }
     else if (style == "Shirt")
     {
          temp += "2";
     }
     else if (style == "Shoes")
     {
          temp += "3";
     }
     else if (style == "Pants")
     {
          temp += "4";
     }
     else if (style == "Outerwear")
     {
          temp += "5";
     }
     else if (style == "Miscellaneous")
     {
          temp += "6";
     }
     else
     {
          cout << "Not sure how you got here"
               << "Proper precautions should have taken place to avoid this.."
               << endl;
          return "0";
     }

     // set the second digit according to color.
     if (color == "Black")
     {
          temp += "0";
     }
     else if (color == "Brown")
     {
          temp += "1";
     }
     else if (color == "Red")
     {
          temp += "2";
     }
     else if (color == "Orange")
     {
          temp += "3";
     }
     else if (color == "Yellow")
     {
          temp += "4";
     }
     else if (color == "Green")
     {
          temp += "5";
     }
     else if (color == "Blue")
     {
          temp += "6";
     }
     else if (color == "Violet")
     {
          temp += "7";
     }
     else if (color == "Grey")
     {
          temp += "8";
     }
     else if (color == "White")
     {
          temp += "9";
     }
     else
     {
          cout << "Not sure how you got here"
               << "Proper precautions should have taken place to avoid this.."
               << endl;
          return "0";
     }

     // randomize the last two digits. (Convert to string to concat)
     srand(time(NULL));
     // first digit to randomize
     int randomInt = rand() % 10;
     temp += to_string(randomInt);

     srand(time(NULL));
     // second digit to randomize
     randomInt = rand() % 10;
     temp += to_string(randomInt);

     // Convert full barcode from string to int before returning.
     return temp;
}

// ****************************************************************************
// Purpose: Default constructor that defaults data members.

// ****************************************************************************
Item::Item()
{
     style = "";
     barcode = "";
     color = "";
}

// ****************************************************************************
// Purpose: Constructor that creates an item based on the parameters passed.
// Pre: style - set the style to the parameter passed.
//      barcode - set the barcode to the parameter passsed.
//      color - set the color to the parameter passed.
// Post: tree has been processed
// ****************************************************************************
Item::Item(string style, string barcode, string color)
{
     this -> style = style;
     if (barcode == "0")
     {
          this -> barcode = generateBarcode();
     }
     else
     {
          this -> barcode = barcode;
     }
     this -> color = color;
}

// ****************************************************************************
// Purpose: Default destructor.
// ****************************************************************************
Item::~Item()
{
     // This is the default destructor.
}

// ****************************************************************************
// Purpose: set the color data member to the parameter passed.
// Pre: color - set the color to the parameter passed.
// ****************************************************************************
void Item::setColor(string color)
{
     this -> color = color;
}

// ****************************************************************************
// Purpose: return the style data member.
// Post: return the style data member.
// ****************************************************************************
string Item::getStyle() const
{
     return style;
}

// ****************************************************************************
// Purpose: return the barcode data member.
// Post: return the barcode data member.
// ****************************************************************************
string Item::getBarcode() const
{
     return barcode;
}

// ****************************************************************************
// Purpose: return the color data member.
// Post: return the color data member.
// ****************************************************************************
string Item::getColor() const
{
     return color;
}
