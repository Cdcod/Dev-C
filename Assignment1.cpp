#include<conio.h>
#include<iostream>
using namespace std;

struct sinhvien
{
	int ID;
	float GRADE;
};
void nhap (sinhvien sv[], int &n)
{
	cout<<"Enter Student ID: ";
	cin>>sv[n].ID;
	cout<<"Enter Student Grade: ";
	cin>>sv[n].GRADE;
}
void xuat (sinhvien sv[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout<<"Student ID: "<<sv[i].ID<<endl;
		cout<<"Grade: "<<sv[i].GRADE<<endl;
	}
}
void max (sinhvien sv[], int n)
{
	int i;
	float max = sv[0].GRADE;
	for (i = 0; i<n; i++)
		if (max < sv[i].GRADE)
			max = sv[i].GRADE;
	cout<<"The highest grade is: "<<max<<endl;
}
void min (sinhvien sv[], int n)
{
	int i;
	float min = sv[0].GRADE;
	for (i = 0; i<n; i++)
		if (min > sv[i].GRADE)
			min = sv[i].GRADE;
	cout<<"The lowest grade is: "<<min<<endl;
}
void hoanvi (float x,float y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void tang (sinhvien sv[], int n)
{
	int i,j;
	sinhvien tmp;
	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++ )
			if (sv[j].GRADE < sv[i].GRADE)
			{
				tmp = sv[i];
				sv[i] = sv[j];
				sv[j] = tmp;
			}
}
void giam (sinhvien sv[], int n)
{
	int i,j;
	sinhvien tmp;
	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++ )
			if (sv[j].GRADE > sv[i].GRADE)
			{
				tmp = sv[i];
				sv[i] = sv[j];
				sv[j] = tmp;		
			}	
}
void program (sinhvien sv[], int n, int key)
{
	while (true)
	{
		cout<<"**********************************"<<endl;
		cout<<"* 1. Add student                 *"<<endl;
		cout<<"* 2. Show the student list       *"<<endl;
		cout<<"* 3. Show the highest grade      *"<<endl;
		cout<<"* 4. Show the lowest grade       *"<<endl;
		cout<<"* 5. Sort the list ascending     *"<<endl;
		cout<<"* 6. Sort the list descending    *"<<endl;
		cout<<"* 0. Exit program                *"<<endl;
		cout<<"**********************************"<<endl;
		do
		{
			cout<<"Enter key: ";
			cin>>key;
		}
		while ( key < 0 and key > 6);
		switch(key)
		{
			case 1:
			{
				cout<<"1. Add student"<<endl;
				nhap(sv,n);
				n++;
				cout<<"Add student successfully"<<endl;
				break;
			}
			case 2:
			{
				cout<<"2. Show the student list"<<endl;
				if ( n > 0)
					xuat(sv,n);
				else
					cout<<"\nThe student list is empty";
				break;
			}
			case 3:
			{
				cout<<"3. Show the highest grade"<<endl;
				if ( n > 0)
					max(sv,n);
				else
					cout<<"\nThe student list is empty";
				break;
			}
			case 4:
			{
				cout<<"4. Show the lowest grade"<<endl;
				if ( n > 0)
					min(sv,n);
				else
					cout<<"\nThe student list is empty";
				break;
			}
			case 5:
			{
				cout<<"5. Sort the list ascending"<<endl;
				if ( n > 0)
				{
					tang(sv,n);
					cout<<"Sort successfully"<<endl;
				}
				else
					cout<<"Sort fail, the student list is empty";
				break;
			}
			case 6:
			{
				cout<<"6. Sort the list descending"<<endl;
				if (n > 0)
				{
					giam(sv,n);
					cout<<"Sort successfully"<<endl;
				}
				else
					cout<<"Sort fail, the student list is empty";
				break;
			}
			case 0:
			{
				cout<<"0. Exit program"<<endl;
				exit(0);
				break;
			}
		}
	}
}
int main ()
{
	sinhvien sv[100];
	int key;
	int n = 0;
	program (sv,n,key);
	return 0;
}
