#include<iostream>
#include<string>
using namespace std;

void addNewStudent(int**& currentGrades, int& currentN){
    int** temp = new int* [currentN+1];
    currentN++;
	for(int i = 0; i<currentN; i++){
		temp[i] = new int[3];
	}	
	
	//copy elements
	for(int i =0; i<currentN-1; i++){
		for(int j=0; j<3; j++){
	        temp[i][j] = currentGrades[i][j];
	    }
    }
    delete currentGrades;
    currentGrades = temp;
    
    //add new student marks
    cout<<"Enter marks for transfer student: \n";
	    cout<<"Enter marks for subject 1: ";
	    cin>>currentGrades[currentN-1][0];
	    cout<<"Enter marks for subject 2: ";
	    cin>>currentGrades[currentN-1][1];
	    cout<<"Enter marks for subject 3: ";
	    cin>>currentGrades[currentN-1][2];
	    
}

void enterStudentData(int** arr, int no){
	for(int i= 0; i<no; i++){
		cout<<"\nStudent "<<i+1<<endl;
	    cout<<"Enter marks for subject 1: ";
	    cin>>arr[i][0];
	    cout<<"Enter marks for subject 2: ";
	    cin>>arr[i][1];
	    cout<<"Enter marks for subject 3: ";
	    cin>>arr[i][2];
	}
}

void displayStudents(int** arr, int no){
	cout<<"\nStudents Marks: "<<endl;
	for(int i=0; i<no; i++){
		cout<<"Student "<<i+1<<": ";
		for(int j=0; j<3; j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
}

int main(){
	int n;
	cout<<"Number of students: "<<endl;
	cin>>n;
	
	int** arr;
	arr = new int*[n];
	for(int i= 0 ; i<n ; i++){
		arr[i] = new int[3];
	}
	
	enterStudentData(arr, n);
	displayStudents(arr,n);
	
	addNewStudent(arr, n);
	displayStudents(arr,n);
	
	
	for(int i= 0 ; i<n ; i++){
        delete [] arr[i];
	}
	delete [] arr;
	
	return 0;
}
