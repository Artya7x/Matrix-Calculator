#include<iostream>
#include<iomanip>
#include "matrix.h"
using namespace std;

/*This function reads the matrices depending on the user's operation. 
The first (if) statement reads two matrices, and the second reads one matrix 
to calculate the inverse.*/

void matrix::read(bool check1){
	//
	if(check1==true){
		cout<<"\nFirst Matrix";
		cout<<"\n\nEnter number of rows : ";
		//validation for character input
		while(!(cin>>row)){ 
			cout<<"Enter number of rows : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		cout<<"Enter number of Columns : "; 
		//validation for character input
		while(!(cin>>col)){
			cout<<"Enter number of Columns : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		cout<<endl;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<"Enter data in ["<<i<<"]"<<"["<<j<<"] : ";
				while(!(cin>>array[i][j])){
					cout<<"Enter data in ["<<i<<"]"<<"["<<j<<"] : ";
					cin.clear();
					cin.ignore(123,'\n');
				}
			}
			cout<<endl;
		}
		cout<<"\nSecond Matrix";
		cout<<"\n\nEnter number of rows : ";
		//validation for character input
		while(!(cin>>row1)){
			cout<<"Enter number of rows : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		cout<<"Enter number of Columns : ";
		//validation for character input
		while(!(cin>>col1)){
			cout<<"Enter number of Columns : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		cout<<endl;
		for(int i=0;i<row1;i++){
			for(int j=0;j<col1;j++){
				cout<<"Enter data in ["<<i<<"]"<<"["<<j<<"] : ";
				while(!(cin>>array2[i][j])){
					cout<<"Enter data in ["<<i<<"]"<<"["<<j<<"] : ";
					cin.clear();
					cin.ignore(123,'\n');
				}
			}
			cout<<endl;
		
		}
	}
	else{
		cout<<"\nMatrix";
		cout<<"\n\nEnter number of rows : ";
		//validation for character input
		while(!(cin>>row)){
			cout<<"\n\nEnter number of rows : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		cout<<"Enter number of Columns : ";
		//validation for character input
		while(!(cin>>col)){
			cout<<"Enter number of Columns:";
			cin.clear();
			cin.ignore(123,'\n');
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<"Enter data in ["<<i<<"]"<<"["<<j<<"] : ";
				while(!(cin>>array[i][j])){
					cout<<"Enter data in ["<<i<<"]"<<"["<<j<<"] : ";
					cin.clear();
					cin.ignore(123,'\n');
				}
			}
			cout<<endl;
		}
	}
}

//This function calculates the sum of two matrices
void matrix::addition(){
	if(col==col1 && row==row1){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				array3[i][j]=array[i][j]+array2[i][j];	
			}
		}
		print(true);
	}
	else{
		//vadilation
		cout<<"WARNING!"<<endl;
		cout<<"A matrix can only be added to another matrix if the two matrices have the same dimensions"<<endl;
	}
}

//This function calculates the difference between two matrices
void matrix::subtraction(){
	if(col==col1 && row==row1){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				array3[i][j]=array[i][j]-array2[i][j];	
			}
		}
		print(true);
	}
	else{
		//vadilation
		cout<<"WARNING!"<<endl;
		cout<<"A matrix can only be subtracted from another matrix if the two matrices have the same dimensions\n\n";
	}
}
//This function calculates the multiplication of two matrices
void matrix::multiplication(){
	if(col==row1){
		for(int i=0;i<row;i++){  
			for(int j=0;j<col1;j++){ 
					array3[i][j]=0;
				for(int k=0;k<col;k++){
					array3[i][j]+=array[i][k]*array2[k][j];	 
				}
			}
		}
		print(true); 
	}
	else{
		//vadilation
		cout<<"WARNING!"<<endl;
		cout<<"For matrix maltiplication, the number of columns in the first matrix must be equal to the number of rows in the second matrix"<<endl;
	}
	
}
//This function calculates the inverse of a matrix
void matrix::inverse(){
	if(row==2 && col==2){
		//determinant
		det=(array[0][0]*array[1][1])-(array[0][1]*array[1][0]);
		if(det!=0){
			array3[0][0]=array[1][1];
			array3[1][1]=array[0][0];
			array3[0][1]=-array[0][1];
			array3[1][0]=-array[1][0];
		
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					array3[i][j]=(1/det)*array3[i][j];
				}
			}
			print(false);
		}
		else{
			//validation
			cout<<"The inverse of the matrix does not exist"<<endl;
		}
	}
	else if(row==3 && col==3){
		//determinant
		det=array[0][0]*((array[1][1]*array[2][2])-(array[1][2]*array[2][1]));
		det-=array[0][1]*((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
		det+=array[0][2]*((array[1][0]*array[2][1])-(array[1][1]*array[2][0]));
		//inverted matrix
		if(det!=0){	
			array3[0][0]=(array[1][1]*array[2][2])-(array[1][2]*array[2][1]);
			array3[1][0]=-((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
			array3[2][0]=(array[1][0]*array[2][1])-(array[1][1]*array[2][0]);
			
			array3[0][1]=-((array[0][1]*array[2][2])-(array[0][2]*array[2][1]));
			array3[1][1]=(array[0][0]*array[2][2])-(array[0][2]*array[2][0]);
			array3[2][1]=-((array[0][0]*array[2][1])-(array[0][1]*array[2][0]));
			
			array3[0][2]=(array[0][1]*array[1][2])-(array[0][2]*array[1][1]);
			array3[1][2]=-((array[0][0]*array[1][2])-(array[0][2]*array[1][0]));
			array3[2][2]=(array[0][0]*array[1][1])-(array[1][0]*array[0][1]);
			
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					array3[i][j]=(1/det)*array3[i][j];
				}
			}
			print(false);
			
		}
		else{
			//validation
			cout<<"The inverse of the matrix does not exist"<<endl;
		}
	}
	
	else{
		//validation
		cout<<"WARNING!"<<endl;
		cout<<"Only inverse of square matrix can be determined"<<endl;
	}
}
//This function prints the calculated Matrix
void matrix::print(bool check2){
	cout<<"MATRIX\n\n";
	//Matrix for 1||2||3 option
	if(check2==true){
		for(int i=0;i<row;i++){
			cout<<"[   ";
			for(int j=0;j<col1;j++){
				cout<<fixed<<setprecision(2)<<array3[i][j]<<"\t";
			}
			cout<<"   ]"<<endl;
		}
	}
	//Matrix for number 5 option
	else{
		for(int i=0;i<row;i++){
			cout<<"[   ";
			for(int j=0;j<col;j++){
				cout<<fixed<<setprecision(2)<<array3[i][j]<<"\t";
			}
			cout<<"   ]"<<endl;
		}
	}
}
