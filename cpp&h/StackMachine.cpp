// David Ang
// 10-29-2018
// CSC2431
// Lab 3
#include "StackMachine.h"


template<class T>
stackMachine<T>::stackMachine()
{

	T elements[100] = {0}; //initalize the arrays to be all zero
}

template <class T>
T stackMachine<T>::smPush(const T& newItem) //pushes the element to the stack
{
	operands->push(newItem);
}

template <class T>
T stackMachine<T>::smPop() //pops an element from the stack
{
	operands->Pop();
}

template <class T>
T stackMachine<T>::smPeek(T index) //looks at X location in the stack
{
	if (size > index && index >= 0)
	{
		return element[index] //finds the element in the postion
	}
}

template <class T>
T stackMachine<T>::smAdd()
{
	while (size >= 2 && count < 100) //needs two elements to add also checks bounds
	{
		T topOne = operands->peek(); //Taking the top element
		operands->Pop();		   //removing the top element
		T topTwo = operands->peek(); //taking the "second" element
		operands->Pop();		   //removing the "second" element
		T total = topTwo + topOne;
		operands->push(total); //pushing the sum of the two elements
	}
}

template <class T>
T stackMachine<T>::smSubtract()
{
	while(size >= 2 && count < 100) //checking bounds
	{
		T topOne = operands->peek();
		operands->pop();
		T topTwo = operands->peek();
		operands->pop();
		T total = topTwo - topOne;
		operands->push(total);
	}
}

template <class T>
T stackMachine<T>::smMultiply()
{
	while (size >= 2 && count < 100) //checking bounds
	{
		T topOne = operands->peek();
		operands->pop();
		T topTwo = operands->peek();
		operands->pop();
		T total = topTwo * topOne;
		operands->push(total);
	}
}

template <class T>
T stackMachine<T>::smDivide()
{
	while (size >= 2 && count < 100) //checking bounds
	{
		T topOne = operands->peek();
		pop();
		T topTwo = operands->peek();
		operands->pop();
		T total = topTwo / topOne;
		operands->push(total);
	}
}

template <class T>
void stackMachine<T>::readFile(std::string file)
{
	std::ifstream infile(file); //checks to see if file can be read
	if (!infile) {
		cout << "Cannot open input file.\n";
		return 1;
	}

	std::string data; //checks the first line in the txt file (should be .data)
	std::getline(infile, data);

	std::string arrayNumbers; //checks the second line in the txt file
	std::string token;
	std::getline(infile, arrayNumbers); //checks the line and puts it in arrayNumbers
	int i = 0;
	while (getline(arrayNumbers, token, ' ')) //tokens through each word in the line
	{
		if (i <= 99)
		{
			elements[i] = std::stoi(token);
			i++;
		}
	}

	std::string text; //checks the third line in the txt file (should be .text)
	std::getline(infile, text);

	std::string line;
	while (std::getline(infile, line))
	{

		if (line == "add")	//checks for the add function
		{
			smAdd();
		}
		else if (line.find("push") != string::npos) //checks to see if the push function is called
		{
			std::string tkn;
			int i = 0;
			int pushValue;
			while (getline(line, tkn, ' ')) //tokens through the line
			{
				if (i == 1)
				{
					pushValue = std::stoi(tkn); //get the index value
					
				}
				i++;
			}
			smPush(elements[pushValue]); //calls the msPush function and pushes it to the stack
		}
		else if (line.find("peek") != string::npos) //checks if the peek function is called
		{
			std::string tkn;
			int i = 0;
			int pushValue;
			while (getline(line, tkn, ' ')) //tokens through the line
			{
				if (i == 1)
				{
					pushValue = std::stoi(tkn); //get the index value

				}
				i++;
			}
			smPeek(pushValue); //calls the msPeek function and returns the number

		else if (line == "subtract") //checks if it calls the subtract function
		{
			smSubtract();
		}
		else if (line == "multiply") //checks if it calls the multiply function
		{
			smMultiply();
		}
		else if (line == "divide") //checks if it calls the divide function
		{
			smDivide();
		}
		else if (line == "pop") // //checks if it calls the pop function
		{
			smPop();
		}
	}

}

