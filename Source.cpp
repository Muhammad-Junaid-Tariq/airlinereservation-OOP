#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class makeres//class of persons
{
protected:
	int totaln;
	int id;
	char name[40];
	int roomno;
	long contactno;
	char type[40];
	char city[30];
	int fday;
	int fmonth;
	int fyear;
	int tday;
	int tmonth;
	int tyear;
public:
	void enter() //get person’s data
	{
		cout<<endl;
		cout<<"enter id: ";
		cin>>id;
		cout<<"enter name: ";
		cin>>name;
		room();
		cout<<"enter contact no: ";
		cin>>contactno;
		setdate();
		cout<<"enter type: ";
		cin>>type;
		cout<<"enter city: ";
		cin>>city;
	}
	void room()
	{
		cout<<"enter room number: ";
		cin>>roomno;
		if(roomno>200)
		{
			cout<<endl;
			cout<<"out of bound"<<endl;
			cout<<"re-enter room no "<<endl;
			room();
		}
	}
	void setdate()
	{
        cout<<"enter check in date(d/m/y): ";
		cin>>fday>>fmonth>>fyear;
		cout<<"enter check out date(d/m/y):  ";
		cin>>tday>>tmonth>>tyear;
		if(tday<=fday  || tmonth<=fmonth || tyear<fyear)
		{
			if(tday<=fday)
			{
				if(tmonth<=fmonth)
				{
					cout<<endl;
					cout<<"incorrect date"<<endl;cout<<"re-enter date"<<endl<<endl;
					setdate();
				}
			}
			if(tmonth<=fmonth)
			{
				if(tmonth==fmonth)
				{
					if(tday<=fday)
					{
						cout<<endl;
						cout<<"re-enter date"<<endl<<endl;
						setdate();
					}
				}
				if(tmonth<fmonth)
				{
					cout<<endl;
					cout<<"re-enter date"<<endl<<endl;
					setdate();
				}
			}
			if(tyear<fyear)
			{
				cout<<endl;
				cout<<"re-enter date"<<endl<<endl;
				setdate();
			}
		}
		if(tday>fday && tmonth>=fmonth && tyear>=fyear)
		{
		}
	}//end of set date
	void display() //display person’s data
	{
	    cout<<"ID: \t\t"<<id<<endl;
	    cout<<"Name: \t\t"<<name<<endl;
	    cout<<"Room no: \t"<<roomno<<endl;
		cout<<"type: \t\t"<<type<<endl;
		cout<<"checkin date: \t"<<fday<<"-"<<fmonth<<"-"<<fyear<<endl;
		cout<<"checkout date: \t"<<tday<<"-"<<tmonth<<"-"<<tyear<<endl;
		cout<<"contact no: \t"<<contactno<<endl;
		cout<<"city: \t\t"<<city<<endl;
	}
	void read(int pn) //read person number pn
	{ 
		ifstream infile; 
		infile.open("data.txt", ios::binary); 
		infile.seekg( pn*sizeof(makeres) ); 
		infile.read( (char*)this, sizeof(*this) ); 
	}
	void write() //write person to end of file
	{
		ofstream outfile; 
		outfile.open("data.txt", ios::app | ios::binary | ios::out);
		outfile.write( (char*)this, sizeof(*this) ); 
	}
	int count() //return number of persons
	{ 
		ifstream infile;
		infile.open("data.txt", ios::binary);
		infile.seekg(0, ios::end); 
		//cout<<"infile:"<<infile.tellg()<<"\n"<<"makeres"<<sizeof(makeres);
		return (int)infile.tellg() / sizeof(makeres);//calcualate no of person
	}
	void first()
	{
		char ch;
		do {           
			cout<<endl;
			cout << "Enter data for person:"<<endl;
			enter(); //enter data
			write(); //write to disk
			cout<<endl;
			cout << "Do another (y/n)? ";
			cin >> ch;
		} 
		while(ch=='y'); //until user enters ‘n’
		second();
	}
	void second()
	{
		int n = count(); //how many persons in file?
		cout<<endl;
		cout << "There are " << n << " persons in record\n"<<endl;
		for(int j=0; j<n; j++) 
		{
			cout<<"person no: "<<j+1<<endl<<endl;
			read(j);         //read person from file
			display();        //display person
			cout<<endl;
		}
		cout << endl;
	}
	void diskout()
	{
		ofstream out; //make stream
		out.open("data.txt", ios::binary);
		out.write( (char*)this, sizeof(*this) ); //write to it
	}
	virtual void searchid()
	{  /*this is virtual function*/ }
};
class search :public makeres
{
private:
	int ids;
	int status;
public:
	class error
	{
	};
	void func()
	{
	if(status==0)
		{
			throw error();
		
		}
	}
	void searchid()
	{ifstream infile;
		int ids;
infile.open("data.txt", ios::in | ios::binary);
int total=count();
		cout<<"enter id for search: ";
		cin>>ids;
		for(int i=0;i<total;i++)
		{
			makeres::read(i);

	if(ids==makeres::id)
	 {
		 cout<<endl;
		 cout<<"found..."<<endl;
		makeres::display();
		status=1;
		break;
	 }
	 else
	 {
	status=0;	
	 }
}//end of for 
try
{
func();
}
catch(error)
{
	cout<<"No person reserved room with this id"<<endl; 
}
		}	//end of searchid
};//end of class search 
class delete_r:public makeres
{
public:
void temp()
{
	ofstream b;
	b.open("data.txt");
		b.close();
		for(int j=0;j<=makeres::totaln-1;j++)
	{ 
	readtemp(j);
	makeres::write();
	}
}
void readtemp(int n)
{
ifstream b; 
b.open("temp.txt", ios::binary); 
b.seekg( n*sizeof(*this) ); 
b.read( (char*)this, sizeof(makeres) ); 
}
void writetemp()
{
ofstream a; 
a.open("temp.txt", ios::app | ios::binary | ios::out);
a.write( (char*)this, sizeof(makeres) ); 
}

void delr()
	{
	ofstream a;
	a.open("temp.txt");
	a.close();
		int did,status=0;
		
		cout<<"enter id of person you want to delete: ";
		cin>>did;
		del(did);
}
		void del(int did)
		{int status=0;
			int total=makeres::count();
		for(int i=0;i<total;i++)
		{
			if(did!=makeres::id)
			{
			makeres::read(i);
			writetemp();
			status=1;
			temp();
			}
		}//end of for
		if(status==0)
		{
        cout<<"no person exist with this id"<<endl;
		}
		else 
		{
		cout<<"data deleted"<<endl;
		}
		}
	};//end of class delete_r
class change:public delete_r
{
private:
	int nroomno;
	int nfday;
	int nfmonth;
	int nfyear;
	int ntday;
	int ntmonth;
	int ntyear;
public:
	void writetemp2()
{
ofstream a; 
a.open("temp2.txt", ios::app | ios::binary);
a.write( (char*)this, sizeof(makeres) ); 
}
	void ch()
	{ifstream infile;
	ofstream a;
	a.open("temp2.txt");
	a.close();
	int status;
		int idc,rnc;
		infile.open("data.txt", ios::in | ios::binary);
		int total=count();
		cout<<"enter id of person: ";
		cin>>idc;
		cout<<"enter room number: ";
		cin>>rnc;
        for(int i=0;i<total;i++)
		{
			makeres::read(i);
			if(idc==makeres::id   &&  rnc==makeres::roomno)
			{cout<<endl;
			makeres::read(i);
			makeres::roomno;
		writetemp2();
		makeres::fday;
			writetemp2();
			makeres::fmonth;
			writetemp2();
		makeres::fyear;
		writetemp2();
		makeres::tday;
		writetemp2();
		makeres::tmonth;
		writetemp2();
		makeres::tyear;
		writetemp2();
	
		cout<<"enter new data"<<endl<<endl;
			cout<<"enter room no";
			cin>>nroomno;
			cout<<"enter checkin date";
			cin>>nfday>>nfmonth>>nfyear;
			cout<<"enter checkout date";
			cin>>ntday>>ntmonth>>ntyear;
			makeres::read(i);
			makeres::roomno=nroomno;
		makeres::fday=nfday;
			makeres::fmonth=nfmonth;
		makeres::fyear=nfyear;
		makeres::tday=nfday;
		makeres::tmonth=ntmonth;
		makeres::tyear=ntyear;
		delete_r::del(idc);
		makeres::write();
		
		makeres::read(i);
cout<<"changed";
			 status=1;
			 break;
			}
			else 
			{
           status=0;
			}
		}//end of for
		if(status=0)
		{
		cout<<"not found...";
		}
		}//end of ch
};//end of class change
class check:public makeres
{
public:
	void checkavail()
	{ifstream infile;
		int rnc;
			int total=count();
		infile.open("data.txt", ios::in | ios::binary);    //open file 
		cout<<"enter room number: ";
		cin>>rnc;        //enter room no for check
		int status;
      for(int i=0;i<total;i++)
	  {
		  makeres::read(i);
		  if(rnc==makeres::roomno)
		  {
          cout<<"room reserved"<<endl;
		  status=1;
		  break;
		  }
		  else
		  {
       status=0;;
		  }
	  } //end of for
	  if(status==0)
	  {
cout<<"room available"<<endl;
	  }
	}//end of checkavail
};//end of class check
void pas();
void wrng();
void start();
void main()
{
int choice;
makeres mr;
	cout<<endl<<endl;
	cout<<"\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"\t\t\t %  WELCOME TO HOTEL RESERVATION SYSTEM  %"<<endl;
	cout<<"\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl<<endl;
	cout<<"\t\t\t\t    \xdb MAIN MENU \xdb"<<endl;
	cout<<"\t\t\t\t      ========="<<endl<<endl;
    cout<<"\t\t\t\t1.Take view project"<<endl;
	cout<<"\t\t\t\t2.Enter as administror mode"<<endl;
	cout<<"\t\t\t\t3.Enter as guest mode"<<endl;
	cout<<"\t\t\t\t4.Exit:";
	cin>>choice;
	switch(choice)
	{
	case 1:
	{
		cout<<endl<<endl;
    cout<<"\t The project Hotel reservation system contains "<<endl;
		cout<<"\t different modules "<<endl<<endl;
		cout<<"\t There are Two user mode in this project "<<endl;
		cout<<"\t 1.administrator mode requires password "<<endl;
		cout<<"\t 2.guest only see list of  reservations "<<endl<<endl;
		cout<<"\t We can make reservation,check room availbility, "<<endl;
		cout<<"\t see list of reservations ,search information "<<endl;
		cout<<"\t about any person,change reservation "<<endl<<endl;
		cout<<"press any key for back";
		_getch();
    main();
	break;
	}//end of case 1
	case 2:
		{
			pas();//ask password
			start();//then goto menu
			break;
		}
		case 3:
		{
		mr.second();
		cout<<"press any key for back";
		_getch();
    main();
		break;
        }
	case 4:
		{
			exit(0);
		}
	default:
		{
			cout<<"unknown command";
			cout<<endl<<endl;
		cout<<"press key for back";
		_getch();
		main();
		}
	}
	_getch();
}
void start()
{
	makeres mr; //object of derived class display
	search s;
	delete_r dr;
	change c;
	check ch1;
	int ch;
cout<<endl<<endl;
cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<"\t\t\t$                                         $"<<endl;
cout<<"\t\t\t$          1.Make reservation             $"<<endl;
cout<<"\t\t\t$          2.Check room availability      $"<<endl;
cout<<"\t\t\t$          3.Delete reservation           $"<<endl;
cout<<"\t\t\t$          4.Change reservation           $"<<endl;
cout<<"\t\t\t$          5.Display list                 $"<<endl;
cout<<"\t\t\t$          6.Search                       $"<<endl;
cout<<"\t\t\t$          7.Back to main menu            $"<<endl;
cout<<"\t\t\t$                                         $"<<endl;
cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
cout<<"\t\t\t\tHit your choice: ";
cin>>ch;
switch(ch)
{

case 1:
	{
		cout<<endl;
		mr.first();
		cout<<endl<<endl;
		cout<<"press any key for back";
		_getch();
		start();
		break;
	}//end of case 1
case 2:
	{
    ch1.checkavail();
      cout<<endl<<endl;
          cout<<"press any key for back";
		_getch();
      start();
	  break;
	}//end of case 2
case 3:
	{
		dr.delr();
		cout<<endl<<endl;
          cout<<"press any key for back";
		_getch();
      start();
	  break;
	}//end of case 3
case 4:
	{
		c.ch();
		cout<<endl<<endl;
	cout<<"press any key for back";
	_getch();
      start();
	}//end of case 4
case 5:
	{
	mr.second();
	cout<<endl<<endl;
	cout<<"press any key for back"; 
     _getch();
	start();
	break;
	}//end of case 5
case 6:
	{
		cout<<endl<<endl;
		s.searchid();
		cout<<endl<<endl;
		cout<<"press any key for back";
		_getch();
		start();
		break;
	}//end of case 6
case 7:
	{
		main();
		break;
	}//end of case 7
default:
	{
	cout<<"invalid input"<<endl;	
	cout<<"press any key for back";
		_getch();
		start();
}//end of default
}  //end of switch
}//end of function start
void pas()
{
const int str1=1234;//my password
int pas;
cout<<endl;		
	cout<<"enter password: ";
	cin>>pas;
	if(pas==str1)
	{
	start();
	}
	else
	{ 
	wrng();//call function wrng
	}
			}//end of function pas
void wrng()
{
	cout<<"wrong password\ntry again"<<endl;
	pas();
}

	
