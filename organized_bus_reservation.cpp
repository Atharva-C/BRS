#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
class bus
{
    char arrival_time[5]; 
    char depart_time[5]; 
    char from[10]; 
    char to[10]; 
    
    public:
    	int seatn;
    	char seat[3][8][10];
    
    void detail()
    {
    	ofstream file;
    	file.open("PBL-proj.txt",ios::out|ios::app);
        file<<"\t\t\t**********BOOK-MY-BUS SERVICE**********\t\t\t\n\n";
        file<<"\n\n\t\t\t***TRAVEL DETAILS***\t\t\t\n\n"
            <<"\n";
    	Color(3);
        cout<<"\nArrival Time: ";
        file<<"\nArrival Time: ";
        cin>>arrival_time;
        file<<arrival_time;
        cout<<"\nDeparture Time: ";
        file<<"\nDeparture Time: ";
        cin>>depart_time;
        file<<depart_time;
        Color(7);
        cout<<"\nFrom(enter Place): ";
        cin>>from;
        file<<"\nFrom: \t\t"<<from;
        cout<<"\nTo(enter place): ";
        cin>>to;
        file<<"\nTo: \t\t"<<to;
        file.close();
    }
};

class volvo: public bus
{
    public:
    char bus_no[5];
    char driver_name[10];
    void volreserve();
    void volempty();
    void volshow();
    void volvo_input()
    {
    	fstream file;
    	file.open("PBL-proj.txt",ios::out|ios::app);
        cout<<"\nEnter bus no: ";
		cin>>bus_no;
		file<<"\nBus No: "<<bus_no;
        cout<<"Enter Driver's name: ";
        cin>>driver_name;
        file<<"\nDriver Name: "<<driver_name;
        file.close();
    }
};
void volvo::volempty()
{
	for(int i=0;i<3;i++)
    	{
    		for(int j=0;j<8;j++)
    		{
                strcpy(seat[i][j],"EMPTY");
            }
		}
}
void volvo::volreserve()
{
	fstream file;
   	file.open("PBL-proj.txt",ios::out|ios::app);
	int x;
	zzz:cout<<"Enter seat number: ";
        cin>>seatn;
        if(seatn>24)
		{
			cout<<"There are only 24 seats available"<<endl;
			goto zzz;
		}
		else
		{
			if(strcmp(seat[seatn/4][(seatn%4)-1],"EMPTY")==0)
			{
				cout<<"Enter Passanger Name: ";
				cin>>seat[seatn/4][(seatn%4)-1];
				Color(6);
				cout<<endl<<"SEAT is BOOKED!"<<endl;
				Color(7);
            }
			else
			{
				try
				{
					throw x;
				}
				catch(int x)
				{
					cout<<"SEAT is RESERVED!!"<<endl;
					goto zzz;
				}
			}
		}
		file<<"\nSEAT NUMBER "<<seatn<<" is booked for "<<seat[seatn/4][(seatn%4)-1]<<endl;
        file.close();
}
void volvo::volshow()
{
	ofstream file;
   	file.open("PBL-proj.txt",ios::out|ios::app);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<seat[i][j]<<"\t";
		}
		cout<<endl;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			file<<seat[i][j]<<"\t";
		}
		file<<endl;
	}
    file.close();
}
class vrl: public bus
{
    public:
    char bus_no[5];
    char driver_name[10];
	void vrlempty();
	void vrlreserve();
	void vrlshow();
    void vrl_input()
    {
        ofstream file;
    	file.open("PBL-proj.txt",ios::out|ios::app);
        cout<<"Enter bus no: ";
		cin>>bus_no;
		file<<"\nBUS NUMBER: "<<bus_no;
        cout<<"Enter Driver's name: ";
        cin>>driver_name;
        file<<"\nDRIVER NAME: "<<driver_name;
        file.close();
    }   
};
void vrl::vrlempty()
{
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    		strcpy(seat[i][j],"EMPTY");
		}
	}
}
void vrl::vrlreserve()
{
	ofstream file;
   	file.open("PBL-proj.txt",ios::out|ios::app);
	int x;
	yyy:cout<<"Enter seat number: ";
        cin>>seatn;
        if(seatn>24)
		{
			cout<<"There are only 12 SEATS available!!"<<endl;
			goto yyy;
		}
		else
		{
			if(strcmp(seat[seatn/4][(seatn%4)-1],"EMPTY")==0)
			{
				cout<<"Enter Passanger name: ";
				cin>>seat[seatn/4][(seatn%4)-1];
				Color(6);
				cout<<endl<<"SEAT IS BOOKED!"<<endl;
				Color(7);
			}
			else
			{
				try
				{
					throw x;
				}
				catch(int x)
				{
					cout<<"SEAT is RESERVED"<<endl;
					goto yyy;
				}
			}
		}
		file<<"\n SEAT NUMBER "<<seatn<<" is booked for "<<seat[seatn/4][(seatn%4)-1]<<endl;
        file.close();
}
void vrl::vrlshow()
{
	ofstream file;
   	file.open("PBL-proj.txt",ios::out|ios::app);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<seat[i][j]<<"\t";
		}
		cout<<endl;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			file<<seat[i][j]<<"\t";
		}
		file<<endl;
	}
    file.close();
}
int main()
{
	ofstream file;
    bus b1;
    volvo v1;
    vrl v2;
    v1.volempty();
    v2.vrlempty();
    system("cls");
    int a=1,choice;
    char ch,x;
    do
    {
    	Color(14);
    	cout<<"WELCOME TO BOOK-MY-BUS!!!"<<endl;
        cout<<"\n\n";
        Color(7);
        cout<<"Enter travel details:\n";
        b1.detail();
        cout<<"\t\t\t\nEnter the bus facility you want to avail:\n\t\t\t";
        Color(5);
        cout<<"1.Volvo bus\n\t\t\t"
        <<"2.VRL bus\n\t\t\t";
        Color(7);
		cout<<"3.Exit";
        xxx:cout<<"\n\t\t\tEnter your choice:- ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"***VOLVO TRAVELS***\n\n";
            v1.volvo_input();
            aaa:v1.volreserve();
            cout<<"If you want to continue booking?"<<endl;
            cout<<"y-->YES"<<endl
                <<"n-->NO";
            cin>>x;
            if(x=='y')
            {
            	goto aaa;
			}
            break;
            cout<<endl<<endl;
            v1.volshow();
            
            case 2:
            cout<<"***VRL TRAVELS***\n\n";
            v2.vrl_input();  
            aac:
            v2.vrlreserve();
            cout<<"If you want to continue booking?"<<endl;
            cout<<"y--YES"<<endl
                <<"n--NO";
            cin>>x;
            if(x=='y')
            {
            	goto aac;
			}
            cout<<"Press 1 to view the reservations: ";
            cin>>a;
            cout<<endl<<endl;
            v2.vrlshow();
            break;
            
            case 3:  
            cout<<"Good bye...";
            exit(0);
            break;
            
            default:
            cout<<"INVALID input!!";
            goto xxx;
            break; 
        }
        cout<<"If you want to continue booking?"<<endl;
        cout<<"y---YES"<<endl;
        cout<<"n---NO";
        cout<<endl;
        cin>>ch;
    }
    while(ch=='y');
}
