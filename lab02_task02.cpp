#include<iostream>
#include<string>
using namespace std;

int main(){
	int num;
	cout<<"Enter no of passengers"<<endl;
	cin>>num;
	string* arr;
	arr = new string[num];
	
	//input names
	cout<<"CHECK IN:\nEnter passenger names: \n";
	cin.ignore();
	
	for(int i =0; i<num; i++){
		getline(cin, arr[i]);
	}

	//boarding seq
	cout<<endl<<"BOARDING SEQUENCE: "<<endl;
	for(int i =num-1 ; i>=0; i--){
	     cout<<arr[i]<<endl;
	}
	
	////release memory
	
	delete [] arr;
	
	
	return 0;
}
