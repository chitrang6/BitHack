/*


This file contains important bit manipulation problems in C++

*/


#include <iostream>
#include <bitset>
#include <math.h>

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
}