#include <iostream>
#include<string>
using namespace std;


int main(){
	int arr[6] = {102, 0, 305, 0, 401, 908};

    for(int i =0; i<6; i++){
    	cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	string command;
	cin>>command;
	
	int j=0;
	if(command == "Compact" || command == "compact"){
		for(int i=0; i<6; i++){
			if(arr[i] != 0){
				arr[j] = arr[i];
				j++;
			}
		}
	for(int k=j; k<6; k++){
		arr[k]=0;
	}
	}
	else{
		cout<<"shelf did not compact"<<endl;
	}

    for(int i =0; i<6; i++){
    	cout<<arr[i]<<" ";
	}
	
	
	return 0;
}
