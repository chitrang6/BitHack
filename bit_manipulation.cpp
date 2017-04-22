/*


This file contains important bit manipulation problems in C++

*/


#include <iostream>
#include <bitset>

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
}