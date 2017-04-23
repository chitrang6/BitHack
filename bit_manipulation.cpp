/*


This file contains important bit manipulation problems in C++

*/


#include <iostream>
#include <bitset>
#include <math.h>
#include <stdio.h>
\

using namespace std;



// Turn off kth bit in a number


int TurnoffKthBit(int num, int pos)
{
	return (num & (1 << (pos - 1)));
}



// Turn on kth bit in a number

int TurnonKthBit(int num, int pos)
{
	return (num | (1 << (pos - 1)));
}


// Check of the kth bit is set or not.

int IsKthBitSet(int num, int pos)
{
	return (num & (1 << (pos - 1)));
}


// Toggling the Kth bit.

int ToggleKthBit(int num, int pos)
{
	return (num ^ (1 << (pos - 1)));
}



// Problems based on unsetting right most set bit in the number.


int unsetRightMostSetBit(int num)
{
	return (num & (num - 1));
}


// Find the given number is power of 2 or not

int isPowerofTwo(int num)
{
	return (num & (num - 1));
}



// Finding the position the right most set bit

int positionOfRightMostSetBit(int num)
{
	if(num & (num - 1))
		return (log2(num) + 1);

	else
	{
		return (log2(num & -num) + 1);
	}
}



void ToggleCase(char* strPtr, int len)
{
	for(int i = 0 ; i < len ; i++)
	{
		strPtr[i] = strPtr[i] ^ ' ';
	}
}




// Finding the absolute value of the given number.


int my_absolute(int num)
{
	// First we have to figure out the mask. 
	const int mask = num >> ((sizeof(int)*8) - 1);
	return ((num + mask)^mask);

}


// Counting number of sets bit in the number


int numberofSetBits(int num)
{
	int counter = 0;
	while(num)
	{
		num = num & (num - 1);
		counter++;
	}

	return counter;
}




// Num of bits need to flip to convert one integer to other


int BitsNeededtoFlip(int num1, int num2)
{

	int xorNum = num1 ^ num2;
	return numberofSetBits(xorNum);
}



// Find the number's binary representation is palindrom or not


bool isPalindrom(unsigned int num)
{

	int r = 1;
	int l = sizeof(num) * 8;

	while(l > r)
	{
		// We will check here if the bit and left most and right most positions are set or not.

		if(IsKthBitSet(num , l)  != IsKthBitSet(num ,r))
			return false;

		l--;
		r++;

	}

	return true;

}







// Negate the given number

int negateNum(int num)
{
	int flag = 1;
	return (num ^ -flag) + flag;
}







// Find the XOR between two numbers without using the XOR operator ---> ^


int XOR(int a , int b)
{

	return (a | b) - (a & b);

}








int main()
{


	cout<<"Welcome to the Bit Manipulation tutorial."<<endl;
	int var = 12;

	cout << "Bit representation of var: " << bitset<8>(var)<<endl;
	cout<< "Turning off the third bit in number var: "<< bitset<8>(TurnoffKthBit(var, 3)) <<endl;
	var = TurnonKthBit(var, 15);
	cout<< "Turning on the 15th bit in number var: "<< bitset<16>(var) <<endl;


	// Lets check the 15th bit is set or not

	if(IsKthBitSet(var , 15))
		cout<< "15th bit is set"<<endl;
	else
		cout<<"15th Bit is not set"<<endl;

	cout<< "Toggle the ninth bit in number var: "<< bitset<16>(ToggleKthBit(var, 9)) <<endl;


	cout << "Unset the right most set bit: "<<bitset<16>(unsetRightMostSetBit(var))<<endl;
	
	int num = 16;

	if(!isPowerofTwo(num))
		cout << "The number is power of two."<<endl;

	else
		cout<<"Not power of two"<<endl;


	cout<<"Position of the most right set bit is:"<< positionOfRightMostSetBit(num) << endl;



	char myString[50] = "helloWORLD";

	ToggleCase(myString, strlen(myString));
	printf("%s\n" , myString);

	int a = -12;

	cout << "The abs is:" << my_absolute(a) <<endl;

	a = -1;
	cout<<"Number of set bits: " << numberofSetBits(a) << endl;
	cout<<"Negate: " << negateNum(a) << endl;

	cout<< "Bits needed to flip:" << BitsNeededtoFlip(0 , -1) << endl;

	cout << "XOR : " << (10 ^ -10 )<< endl;

	cout<<" XOR without XOR op: " <<  XOR(10 , -10) << endl;




	unsigned int x = 1<<15 + 1<<16;

	cout << "Palindrom result:" << isPalindrom(x) <<endl; 


}