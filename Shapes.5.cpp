// Programmer: Erin Lee
// Student id: 1805820
// File: Shapes.5.cpp

// c++ libraries
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "iShapes.h"

// function prototypes
void id();
vector<string> parseString(string);

int main()
{
  // function call for identification information
  id();

  // declare and initialize variables
  ifstream fin;     
  ofstream fout; 
  string line;
  vector<string> tokens;   
  vector<const Shape*> myBag;
  vector<int> myBagType;

  // open files
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  // Check if input file is opened successfully
  if (!fin.good())
  {
    cout << "Input file failed to open." << endl;
    return 1;
  }
 
  // Check if output file is opened successfully
  if (!fout.good())
  {
    cout << "Output file failed to open." << endl;
    return 1;
  }

  // keep looping until end of file is reached
  while (!fin.eof())
  {
    // read each line from input file and call function to get tokens
    getline(fin, line);
    tokens = parseString(line);

    // will skip any empty lines from input file
    if (tokens.size() != 0)
    {
      // check if token is square
      if (tokens[0] == "SQUARE")
      {
        // dynamically allocate memory for a new square object using constructor 
        // store const read-only pointer object in bag
        // store 1 into different bag to represent square shape
        const Square* const s = new Square(tokens);
        myBag.push_back(s);
        myBagType.push_back(1);
      }

      // check if token is rectangle
      else if (tokens[0] == "RECTANGLE")
      {
        // dynamically allocate memory for a new rectangle object using constructor 
        // store const read-only pointer object in bag
        // store 2 into different bag to represent rectangle shape
        const Rectangle* const r = new Rectangle(tokens);
        myBag.push_back(r);
        myBagType.push_back(2);
      }

      // check if token is circle
      else if (tokens[0] == "CIRCLE")
      {
        // dynamically allocate memory for a new circle object using constructor 
        // store const read-only pointer object in bag
        // store 3 into different bag to represent circle shape
        const Circle* const c = new Circle(tokens);
        myBag.push_back(c);
        myBagType.push_back(3);
      }

      // check if token is triangle
      else if (tokens[0] == "TRIANGLE")
      {
        // dynamically allocate memory for a new triangle object using constructor 
        // store const read-only pointer object in bag
        // store 4 into different bag to represent triangle shape
        const Triangle* const t = new Triangle(tokens);
        myBag.push_back(t);
        myBagType.push_back(4);
      }

      // check if token is cube
      else if (tokens[0] == "CUBE")
      {
        // dynamically allocate memory for a new cube object using constructor 
        // store const read-only pointer object in bag
        // store 5 into different bag to represent cube shape
        const Cube* const c = new Cube(tokens);
        myBag.push_back(c);
        myBagType.push_back(5);
      }

      // check if token is box           
      else if (tokens[0] == "BOX")
      {
        // dynamically allocate memory for a new box object using constructor 
        // store const read-only pointer object in bag
        // store 6 into different bag to represent box shape
        const Box* const b = new Box(tokens);
        myBag.push_back(b);
        myBagType.push_back(6);
      }

      // check if token is cylinder      
      else if (tokens[0] == "CYLINDER")
      {
        // dynamically allocate memory for a new cylinder object using constructor 
        // store const read-only pointer object in bag
        // store 7 into different bag to represent cylinder shape
        const Cylinder* const c = new Cylinder(tokens);
        myBag.push_back(c);
        myBagType.push_back(7);
      }

      // check if token is prism
      else if (tokens[0] == "PRISM")
      {
        // dynamically allocate memory for a new prism object using constructor 
        // store const read-only pointer object in bag
        // store 8 into different bag to represent prism shape
        const Prism* const p = new Prism(tokens);
        myBag.push_back(p);
        myBagType.push_back(8);
      }

      // check if token is EOF      
      else if (tokens[0] == "EOF")
        break;

      // token does not match one of eight objects
      else
        cout << tokens[0] << " invalid object" << endl;
    }
  }

  // close input file
  fin.close();

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert const read-only pointer in vector into pointer to square object
        // dereference the read-only pointer to access square object
        // call function to calculate and display info to console output        
        const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
        const Square& rSquare = *pSquare;
        rSquare.output(cout);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert const read-only pointer in vector into pointer to rectangle object
        // dereference the read-only pointer to access rectangle object
        // call function to calculate and display info to console output        
        const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
        const Rectangle& rRectangle = *pRectangle; 
        rRectangle.output(cout);
        break;
      }
      // integer 3 represents circle
      case 3:
      {
        // convert const read-only pointer in vector into pointer to circle object
        // dereference the read-only pointer to access circle object
        // call function to calculate and display info to console output     
        const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
        const Circle& rCircle = *pCircle;
        rCircle.output(cout);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert const read-only pointer in vector into pointer to triangle object
        // dereference the read-only pointer to access triangle object
        // call function to calculate and display info to console output        
        const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
        const Triangle& rTriangle = *pTriangle;
        rTriangle.output(cout);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert const read-only pointer in vector into pointer to cube object
        // dereference the read-only pointer to access cube object
        // call function to calculate and display info to console output         
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        const Cube& rCube = *pCube;
        rCube.output(cout);
        break;
      }
      
      // integer 6 represents box
      case 6:
      {
        // convert const read-only pointer in vector into pointer to box object
        // dereference the read-only pointer to access box object
        // call function to calculate and display info to console output       
        const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
        const Box& rBox = *pBox;
        rBox.output(cout);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert const read-only pointer in vector into pointer to cylinder object
        // dereference the read-only pointer to access cylinder object
        // call function to calculate and display info to console output    
        const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
        const Cylinder& rCylinder = *pCylinder;
        rCylinder.output(cout);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert const read-only pointer in vector into pointer to prism object
        // dereference the read-only pointer to access prism object
        // call function to calculate and display info to console output        
        const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
        const Prism& rPrism = *pPrism;
        rPrism.output(cout);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert const read-only pointer in vector into pointer to square object
        // dereference the read-only pointer to access square object
        // call function to calculate and display info to file output        
        const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
        const Square& rSquare = *pSquare;
        rSquare.output(fout);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert const read-only pointer in vector into pointer to rectangle object
        // dereference the read-only pointer to access rectangle object
        // call function to calculate and display info to file output        
        const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
        const Rectangle& rRectangle = *pRectangle; 
        rRectangle.output(fout);
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert const read-only pointer in vector into pointer to circle object
        // dereference the read-only pointer to access circle object
        // call function to calculate and display info to file output        
        const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
        const Circle& rCircle = *pCircle;
        rCircle.output(fout);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert const read-only pointer in vector into pointer to triangle object
        // dereference the read-only pointer to access triangle object
        // call function to calculate and display info to file output    
        const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
        const Triangle& rTriangle = *pTriangle;
        rTriangle.output(fout);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert const read-only pointer in vector into pointer to cube object
        // dereference the read-only pointer to access cube object
        // call function to calculate and display info to file output       
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        const Cube& rCube = *pCube;
        rCube.output(fout);
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert const read-only pointer in vector into pointer to box object
        // dereference the read-only pointer to access box object
        // call function to calculate and display info to file output      
        const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
        const Box& rBox = *pBox;
        rBox.output(fout);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert const read-only pointer in vector into pointer to cylinder object
        // dereference the read-only pointer to access cylinder object
        // call function to calculate and display info to file output       
        const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
        const Cylinder& rCylinder = *pCylinder;
        rCylinder.output(fout);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert const read-only pointer in vector into pointer to prism object
        // dereference the read-only pointer to access prism object
        // call function to calculate and display info to file output      
        const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
        const Prism& rPrism = *pPrism;
        rPrism.output(fout);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert const read-only pointer in vector into pointer to square object
        // delete dynamically allocated square object      
        const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
        delete pSquare;
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert const read-only pointer in vector into pointer to rectangle object
        // delete dynamically allocated rectangle object   
        const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
        delete pRectangle;
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert const read-only pointer in vector into pointer to circle object
        // delete dynamically allocated circle object   
        const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
        delete pCircle;
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert const read-only pointer in vector into pointer to triangle object
        // delete dynamically allocated triangle object   
        const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
        delete pTriangle;
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert const read-only pointer in vector into pointer to cube object
        // delete dynamically allocated cube object   
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        delete pCube;
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert const read-only pointer in vector into pointer to box object
        // delete dynamically allocated box object   
        const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
        delete pBox;
        break;
      }
     
      // integer 7 represents cylinder
      case 7:
      {
        // convert const read-only pointer in vector into pointer to cylinder object
        // delete dynamically allocated cylinder object   
        const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
        delete pCylinder;
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert const read-only pointer in vector into pointer to prism object
        // delete dynamically allocated prism object   
        const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
        delete pPrism;
        break;
      }

      default:
        break;
    }
  }

  // close output file
  fout.close();
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will take a string and create an array of tokens
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

