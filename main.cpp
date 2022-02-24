#include "matrix.h"
#include<iostream>
#include <ctype.h>
#include <windows.h>
using namespace std;
int main (){
	matrix mymatrix;
	int choice;
	do{
		//Title
		for(int i=0;i<120;i++){
			cout<<(char)95;
		}
		cout<<endl<<endl<<"\t\t\t\t\t\tMATRIC CALCULATOR"<<endl<<endl;
		for(int i=0;i<120;i++){
			cout<<(char)95;
		}
		//options
		cout<<endl<<"Options:\n\n\t1 - For addition\n\t2 - For subtraction\n\t3 - For multiplication\n\t4 - For inverse\n\t5 - To exit\n";
		cout<<"\nEnter (1 or 2 or 3 or 4 or 5) : ";
		while(!(cin>>choice)){
			cout<<"\nEnter (1 or 2 or 3 or 4 or 5) : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		cout<<"\n";
			switch(choice){
				
				case 1:
					mymatrix.read(true);
					mymatrix.addition();
					system("pause");
					break;
				case 2:
					mymatrix.read(true);
					mymatrix.subtraction();
					system("pause");
					break;
				case 3:
					mymatrix.read(true);
					mymatrix.multiplication();
					system("pause");
					break;
				case 4:
					mymatrix.read(false);
					mymatrix.inverse();
					system("pause");
					break;
			}
			system("CLS");
	}while (choice!=5 );
}
