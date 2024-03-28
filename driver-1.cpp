#include "Shape.h" 
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands
	float x = 0, y = 0, e = 0, r = 0, h = 0, w = 0;
	char* next;
	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s
		parameters.push_back(strtok_s(cstr, " ", &next));
		while (next && next[0] != '\0')
		{
			parameters.push_back(strtok_s(NULL, " ", &next));
		}

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 

		string command = parameters[0];


		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			// The following four lines have a type mismatch error
			// note that the the parameters vector contains ascii values
			// HINT: stoi function converts from string to int

			if (parameters.size() < 5)
			{
				cout << "Invalid parametre\nTry again ";
				continue;
			}
			x = stof(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
			y = stof(parameters[2].c_str());
			h = stof(parameters[3].c_str());
			w = stof(parameters[4].c_str());


			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			cout << r->toString(); /* instead of this, you may implement operator overloadig and
									use cout << r which will give you additional points */
		}
		else if (command.compare("addS") == 0) {
			// get parameters
			// ...
			if (parameters.size() < 4)
			{
				cout << "Invalid parametre\nTry again ";
				continue;
			}
			x = stof(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
			y = stof(parameters[2].c_str());
			e = stof(parameters[3].c_str());
			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s->toString();
		}

		if (command.compare("addC") == 0) {
			// get parameters
			// ...
			x = stof(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
			y = stof(parameters[2].c_str());
			r = stof(parameters[3].c_str());
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c->toString();

		}
		else if (command.compare("scale") == 0) {
			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!

			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!
			if (parameters.size() < 4)
			{
				cout << "Invalid parametre\nTry again ";
				continue;
			}
			int shapeNo = 0;
			shapeNo = stoi(parameters[1].c_str());
			if (shapeNo < 1 || shapeNo>shapes.size())
			{
				cout << "Invalid index\nTry again ";
				continue;
			}
			x=stof(parameters[2].c_str());
			y=stof(parameters[3].c_str());
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);
			// scale should work similarly...

			// note that here you should see the corresponding toString output for the derived classes...
			// if toString is not a virtual function, you may see the base class functionality :(
			cout << shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("move") == 0) {
			// move object at index 
			int shapeNo=0; // read from parameters
			// you may want to check if the index exists or not!
			
			if (parameters.size() < 4)
			{
				cout << "Invalid parametre\nTry again ";
				continue;
			}
			// Study the following code. A Shape object is not Movable, but all derived classes are...
			// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
			shapeNo = stoi(parameters[1].c_str());
			if (shapeNo < 1 || shapeNo>shapes.size())
			{
				cout << "Invalid index\nTry again ";
				continue;
			}
			x = stof(parameters[2].c_str());
			y = stof(parameters[3].c_str());
			Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);
			// scale should work similarly...

			// note that here you should see the corresponding toString output for the derived classes...
			// if toString is not a virtual function, you may see the base class functionality :(
			cout << shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("display") == 0) 
		{
			// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
			for (int a = 0;a < shapes.size();a++)
			{
				cout << "Shape no. " << a + 1 << ":\n";
				cout<<shapes[a]->toString();
			}
		}

		parameters.clear();
		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...
		cout << endl << endl;
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}