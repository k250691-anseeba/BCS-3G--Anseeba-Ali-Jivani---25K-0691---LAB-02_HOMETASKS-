#include <iostream>
#include <string>
using namespace std;

class Cart{
	int cap;    // total capacity of cart
	int size;  //elements present in cart
	int *arr; //stores ID of item
	
	public:
		Cart(){
			cap = 3;
			arr = new int [cap]{000,000,000};
			size = 0;
		}
		
		void addItem(int no){
			if(no <= 0){
				cout<<"enter valid no of items"<<endl;
				return;
			}
			if(cap-size >= no){
				//just add item cauz space available
				for(int i = 0; i<no; i++){
					cout<<"Item ID: ";
					cin>>arr[size];
					size++;
				}
			}
			
			else{
				//double the array capacity 
				do{
				cout<<"RESIZING ARRAY: (capacity = "<<cap*2<<")"<<endl;
				int* temp = new int[cap*2];
				for(int i = 0; i<size; i++){
					temp[i] = arr[i];
				}
			
				delete [] arr;
				arr = temp;
				cap = cap*2;
				
				for(int i = size; i<cap; i++){
					arr[i] = 0;
				}

			    }while(cap-size < no);

				for(int i = 0; i<no; i++){
					cout<<"Item ID: ";
					cin>>arr[size];
					size++;
				}
				
			}
			
		}
		
	void displayCart(){
		cout<<" CART:  ";
		for(int i=0; i<cap; i++){
			cout<<"\""<<arr[i]<<"\"";
			if(i<cap-1){
				cout<<" , ";
			}
		}
		cout<<endl;
	}
		
	~Cart(){
		delete [] arr;
	}
};

int main(){
	
	Cart c1;
	c1.displayCart();
	int choice;
	//adding 7 items
	do{
		cout<<"1) Add item to cart"<<endl;
		cout<<"2) Display Cart"<<endl;
		cout<<"3) Exit"<<endl;
		cout<<"choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				int no;
				cout<<"How many items do you want to add: ";
				cin>>no;
				c1.addItem(no);
				break;
		
			case 2:
				c1.displayCart();
				break;
				
			case 3: 
			    cout<<"goodbye!"<<endl;
			    break;
			default:
				cout<<"invalid choice"<<endl;
		}
	}while(choice!= 3);
	

	return 0;
}
	
	


