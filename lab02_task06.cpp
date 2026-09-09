#include<iostream>
#include<string>
using namespace std;

class Airplane{
	int **airplane;
	int size[3];
	string name[3];
	
	public:
	Airplane(){
	    size[0] = 2;
        size[1] = 4;
        size[2] = 6;

        name[0] = "First Class";
        name[1] = "Business Class";
        name[2] = "Economy Class";
        
        
        
		airplane = new int*[3];
	    for(int i =0; i<3; i++){
		    airplane[i] = new int[size[i]];
	    }
	    //initializing all seats as empty = 0
	    for(int i =0; i<3; i++){
		    for(int j=0; j<size[i]; j++){
			    airplane[i][j] = 0;
		    }
	    }
	}
	
	
void bookASeat(int row, int seat){
	if(row>2){
		cout<<"Invalid row number"<<endl;
		return;
	}
	
    if(seat >= size[row]){
		cout<<"seat number does not exists in "<<name[row]<<endl;
		cout<<name[row]<< " has only "<<size[row]<<" slots!"<<endl;
		return;
	}
	
	if(airplane[row][seat] == 0){ //seat available
	     airplane[row][seat] = 1;    //seat taken = 1
	 }
}

void displaySeats(){
	for(int i =0; i<3; i++){
		cout<<name[i]<<": ";
		for(int j=0; j<size[i] ;j++){
			cout<<airplane[i][j]<<" ";
		}
		cout<<endl;
	}
}

	~Airplane(){
		for(int i =0; i<3; i++){
		    delete [] airplane[i];
	    }
		delete [] airplane;
	}

};

int main(){
	Airplane a1;
			int choice;

	do{
		cout<<"1)BOOK A SEAT\n2)DISPLAY SEATS\n3)EXIT"<<endl;
		cin>>choice;
		if(choice ==1){
			int row, seat;
	        cout<<"Enter row: ";
        	cin>>row;
	        cout<<"Enter seat number: ";
	        cin>>seat;
	
			a1.bookASeat(row, seat);
		}
		else if(choice==2){
			a1.displaySeats();
		}
		else if(choice==3){
			cout<<"goodbye!"<<endl;
		}
		else{
			cout<<"invalid choice"<<endl;
		}
		
	}while(choice != 3);


	return 0;
}
