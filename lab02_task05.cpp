#include<iostream>
#include<string>
using namespace std;

class SafeCommandCenter{
	int* command;
	
	public:
		SafeCommandCenter(){
			command = new int[5];
		}
		
		void SafeWrite(int index, int val){
				if(index<0 || index>=5){
				cout<<"index is out of bounds"<<endl;
				cout<<"Rover Emergency Braking Triggered!"<<endl;
				return;
			}
			
			if(val<0 || val>100){
			    cout<<"Invalid speed (valid range is: 0-100)"<<endl;
			    return;
		    }
		    
		  	command[index] = val;
		  	cout<<"successful"<<endl;
		}
		
    ~SafeCommandCenter(){
        delete [] command;
    }
    
};

int main(){
	
    SafeCommandCenter rover;
    
    cout<<"command[0] = 50"<<endl;
    rover.SafeWrite(0, 50);    
    cout<<"command[1] = 80"<<endl;
    rover.SafeWrite(1, 80);    
    cout<<"command[2] = 100"<<endl;
    rover.SafeWrite(2, 100);   
    cout<<"command[5] = 70"<<endl;
    rover.SafeWrite(5, 70);    
    cout<<"command[3] = -20"<<endl;
    rover.SafeWrite(3, -20);   
    cout<<"command[4] = 120"<<endl;
    rover.SafeWrite(4, 120);   
	
	return 0;
}
