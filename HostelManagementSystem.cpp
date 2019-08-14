//THIS IS A HOSTEL MANAGEMENT SYSTEM
	#include<iostream.h>
	#include<conio.h>
	#include<iomanip.h>
	#include<string.h>
	#include<stdio.h>
	#include<ctype.h>
	#include<fstream.h>
	#include<stdlib.h>
	  struct NAME
	  {
			char firstname[20];
			char lastname[20];
		};
	  struct DATE
	  {
			int day;
			int month;
			int year;
		};
		struct ADDRESS
		{
			char city[20];
			char state[10];
			long zipcode;
		};

	class GUEST
	 {  NAME name;
		ADDRESS address;
		long idno;
		char nationality[10];
		DATE Adate;  //ARRIVAL DATE//
		DATE Ddate;     //DEPARTURE DATE//
		long phone;
		char roomtype[30];
		int roomno;
		int rent;
		float amount; //TOTAL AMOUNT//
		int ndays;
		int status;
		public:  void setamount();
					void readguest();
					void searchguest();
					void showguest();
					float retamount();
					void upamount(float);
					long retid();
					int retroomno();
					long retphone();
					NAME retname();
					int retstatus();
					void start();
					void end();
					void report();
	};
	void pgdesign(char,char);
	void pgdesign(char,char,char);
	void loginbox(int,int,int);
	void border(char,char);
	void smallbox(int,int,int);
	void entrybox(int,int,int,int);
	void mainmenu();
	int assignroom(int);
	void brkfst();
	void lunch();
	void dinefac();
	void spa_fac();
	void pool_fac();
	void gym_fac();
	void search();
	void search_name();     // FUCNTION TO SEARCH BY NAME//
	void search_phoneno();   //FUNCTION TO SEARCH BY PHONE NO://
	void search_idno();      //FUNCTION TO SEARCH BY ID//
	void search_roomno();    //FUNCTION TO SEARCH BY ROOM NO://
	void amenities();
	void checkout();
	void repsearch();
	void developers();
	void logout();
	void page();
	void goback(char x,char ch)
	{
	 if (x==48&& ch=='i')
	 mainmenu();
	 else
	 if(x==48&&ch=='s')
	 search();
	 else
	 if(x==48&&ch=='a')
	 amenities();
	 else
	 if(x==48&&ch=='o')
	 mainmenu();
	 }
	 void goback(int x,char ch)
	 { if (x==0&& ch=='i')
	 mainmenu();
	 else
	 if(x==0&&ch=='s')
	 search();
	 else
	 if(x==0&&ch=='a')
	 amenities();
	 else
	 if(x==0&&ch=='o')
	 mainmenu();
	 }
	 void goback(long x,char ch)
	 { if (x==0&& ch=='i')
	 mainmenu();
	 else
	 if(x==0&&ch=='s')
	 search();
	 else
	 if(x==0&&ch=='a')
	 amenities();
	 else
	 if(x==0&&ch=='o')
	 mainmenu();
	 }
	void GUEST::start()
	{status=1;
	 amount=0.0;
	 }
	void GUEST::end()
	{status=0;
	 }
	NAME GUEST::retname()
	{return name;
	}
	int GUEST::retroomno()
	{return roomno;
	}
	long GUEST::retid()
	{return idno;
	}
	long GUEST::retphone()
	{return phone;
	}
	int GUEST::retstatus()
	{return status;
	}
	void GUEST::readguest()
	{  int r,t;
		char ch='i';
		clrscr(); //guest information //
		char x;
		border('+','+');
		pgdesign('|','-');
		gotoxy(30,4);
		cout<<"GUEST INFORMATION";
		gotoxy(30,5);
		cout<<"~~~~~~~~~~~~~~~~~";
		gotoxy(40,20);
		cout<<"(Enter 0 to exit)";
		gotoxy(5,8);
		cout<<"FIRST NAME:";
		smallbox(16,8,17);
		gotoxy(35,8);
		cout<<"LAST NAME:";
		smallbox(45,8,17);
		gotoxy(5,11);
		cout<<"STATE:";
		smallbox(11,11,15);
		gotoxy(30,11);
		cout<<"CITY:";
		smallbox(35,11,19);
		gotoxy(57,11);
		cout<<"ZIP CODE:";
		smallbox(66,11,8);
		gotoxy(5,14);
		cout<<"NATIONALITY:";
		smallbox(17,14,12);
		gotoxy(5,17);
		cout<<"PHONE NO:";
		smallbox(14,17,13);
		fn:gotoxy(17,8);
			gets(name.firstname);
			if(name.firstname[0]!='\0')
			 {
			  goback(name.firstname[0],ch);
			  name.firstname[0]=toupper(name.firstname[0]);
			  gotoxy(35,15);
			  cout<<"                         ";
			 }
			else
			 {
			  gotoxy(35,15);
			  cout<<"!MUST FILL IN ALL SPACES!";
			  goto fn;
			 }
		ln:gotoxy(46,8);
			gets(name.lastname);
			if(name.lastname[0]!='\0')
			 {
			  goback(name.lastname[0],ch);
			  name.lastname[0]=toupper(name.lastname[0]);
			  gotoxy(35,15);
			  cout<<"                         ";
			 }
			else
			 {
			  gotoxy(35,15);
			  cout<<"MUST FILL IN ALL SPACES";
			  goto ln;
			 }
		as:gotoxy(12,11);
			gets(address.state);
			if(address.state[0]!='\0')
			{
			 goback(address.state[0],ch);
			 address.state[0]=toupper(address.state[0]);
			 gotoxy(35,15);
			 cout<<"                         ";
			}
			else
			 {
			  gotoxy(35,15);
			  cout<<"MUST FILL IN ALL SPACES";
			  goto as;
			 }
		ac:gotoxy(36,11);
			gets(address.city);
			if(address.city[0]!='\0')
			{
			 goback(address.city[0],ch);
			 address.city[0]=toupper(address.city[0]);
			 gotoxy(35,15);
			 cout<<"                         ";
			}
			else
			 {
			  gotoxy(35,15);
			  cout<<"MUST FILL IN ALL SPACES";
			  goto ac;
			 }
		az:gotoxy(67,11);
			cin>>address.zipcode;
			if(address.zipcode==10)
			{
			 gotoxy(35,15);
			 cout<<"MUST FILL IN ALL SPACES";
			 gotoxy(67,11);
			 cout<<"     ";
			 goto az;

			}
			else
			{
			 goback(address.zipcode,ch);
			 gotoxy(35,15);
			 cout<<"                       ";
			}
		na:gotoxy(18,14);
			gets(nationality);
			if(nationality[0]!='\0')
			{
			 goback(nationality[0],ch);
			 nationality[0]=toupper(nationality[0]);
			 gotoxy(35,15);
			 cout<<"                         ";
			}
			else
			 {
			  gotoxy(35,15);
			  cout<<"MUST FILL IN ALL SPACES";
			  goto na;
			 }
		gotoxy(15,17);
		cin>>phone;
		goback(phone,ch);

		//in stay information
		clrscr();
		border('+','+');
		pgdesign('/','-');
		gotoxy(30,3);
		cout<<"STAY INFORMATION";
		gotoxy(30,4);
		cout<<"~~~~~~~~~~~~~~~~";
		gotoxy(48,21);
		cout<<"(Enter 0 to exit)";
		gotoxy(9,8);
		cout<<"ROOM TYPES:";
		gotoxy(21,9);
		cout<<"(a) SINGLE" ;
		gotoxy(21,11);
		cout<<"(b) DOUBLE";
		gotoxy(21,13);
		cout<<"(c) TRIPLE";
		gotoxy(36,9);
		cout<<"(d) DELUX";
		gotoxy(36,11);
		cout<<"(e) STUDIO";
		gotoxy(36,13);
		cout<<"(f) SUITE";
		gotoxy(4,16);
		cout<<" *Enter option(a/b/c/d/e/f)";
		repeat:
		 x=getch();
		 x=tolower(x);
		 goback(x,ch);

				 switch(x)
		{
			case 'a':strcpy(roomtype,"SINGLE");
						rent=50;
						break;
			case 'b':strcpy(roomtype,"DOUBLE");
						rent=60;
						break;
			case 'c':strcpy(roomtype,"TRIPLE");
						rent=75;
						break;
			case 'd':strcpy(roomtype,"DULUX");
						rent=100;
						break;
			case 'e':strcpy(roomtype,"STUDIO");
						rent=125;
						break;
			case 'f':strcpy(roomtype,"SUITE");
						rent=200;
						break;
			default: gotoxy(5,16);
					  cout<<"INVALID CHOICE";
					  goto repeat; }
		clrscr();
		border('+','+');
		pgdesign('|','-');
		gotoxy(30,3);
		amount=0;
		cout<<"STAY INFORMATION";
		gotoxy(30,4);
		cout<<"~~~~ ~~~~~~~~~~~";
		gotoxy(48,21);
		cout<<"(Enter 0 to exit)";
		gotoxy(9,8);
		cout<<"CHECKIN DATE:";
		smallbox(22,8,12);
		gotoxy(25,8);
		cout<<"/";
		gotoxy(28,8);
		cout<<"/";
		gotoxy(29,8);
		cout<<"20-";
		gotoxy(36,8);
		cout<<"(DD/MM/YY)";
		gotoxy(23,8);
		cin>>Adate.day;
		goback(Adate.day,ch);
		gotoxy(26,8);
		cin>>Adate.month;
		goback(Adate.month,ch);
		gotoxy(32,8);
		cin>>Adate.year;
		goback(Adate.year,ch);
		randomize();
		idno=random(1000)+1;
		gotoxy(9,10);
		cout<<"ROOM NUMBER:";
		gotoxy(21,10);
		cin>>r;
		goback(r,ch);
		roomno=assignroom(r);
		gotoxy(48,21);
		cout<<"                 ";
		gotoxy(9,12);
		cout<<"YOUR ID NUMBER:"<<idno;
		gotoxy(26,14);
		start();
		cout<<"#####CHECKIN SUCCESFULL#####";
		gotoxy(28,23);
		cout<<"~~~press any key to continue~~~";
		getch();
		}
		int assignroom(int r)
		{
		 GUEST g;
	rom:fstream filein;
		 filein.open("hotelll.dat",ios::in|ios::binary);
		 while(filein.read((char*)&g,sizeof(g)))
		 {if(g.retstatus()==1)
			if(r==g.retroomno())
			{gotoxy(10,12);
			 cout<<"~ROOM ALREADY IN BOOKING~";
			 gotoxy(21,10);
			 cout<<"   ";
			 gotoxy(21,10);
			 cin>>r;
			 filein.close();
			 goto rom;
			}
		 }
		  gotoxy(10,12);
		  cout<<"                         ";
		  return r;
		}

		void amenities()
		{
			clrscr();
			int x,p=8;
			border('!','!');
			pgdesign('/','+');
			gotoxy(30,3);
			cout<<"AMENITIES OFFERED";
			gotoxy(30,4);
			cout<<"~~~~~~~~~~~~~~~~~";
			gotoxy(11,8);
			cout<<"(A) Breakfast";
			gotoxy(19,10);
			cout<<"~Lunch Is Complementary~";
			gotoxy(11,10);
			cout<<"(B) Lunch Menu";
			gotoxy(11,12);
			cout<<"(C) Dining";
			gotoxy(11,14) ;
			cout<<"(D) Thai Spa";
			gotoxy(11,16);
			cout<<"(E) Swimming Pool";
			gotoxy(11,18);
			cout<<"(F) Gym";
			gotoxy(10,20);
			cout<<"*press backspace to go back";
			gotoxy(56,21);
		cout<<"W- UP";
		gotoxy(56,22);
		cout<<"S- DOWN";
		gotoxy(9,8);
		cout<<"@";
		gotoxy(46,8);
		cout<<"@";
		for(;;)
		{
		x=getch();

		if(x==87 || x==119)
		{
		if(p==8)
		{
		gotoxy(9,p);
		cout<<" ";
		gotoxy(46,p);
		cout<<" ";
		p=18;
		gotoxy(9,p);
		cout<<"@";
		gotoxy(46,p);
		cout<<"@";
		}
		else
		{
		gotoxy(9,p);
		cout<<" ";
		gotoxy(46,p);
		cout<<" ";
		p-=2;
		gotoxy(9,p);
		cout<<"@";
		gotoxy(46,p);
		cout<<"@";
		}
		}
		else
		if(x==83 || x==115)
		{
		if(p==18)
		{
		gotoxy(9,p);
		cout<<" ";
		gotoxy(46,p);
		cout<<" ";
		p=8;
		gotoxy(9,p);
		cout<<"@";
		gotoxy(46,p);
		cout<<"@";
		}
		else
		{
		gotoxy(9,p);
		cout<<" ";
		gotoxy(46,p);
		cout<<" ";
		p+=2;
		gotoxy(9,p);
		cout<<"@";
		gotoxy(46,p);
		cout<<"@";
		}
		}
		else
		if(x==13)
		{
		switch(p)
		{
	  case 8:brkfst();
				 break;
	  case 10:lunch();
				 break;
	  case 12:dinefac();
				 break;
	  case 14:spa_fac();
				 break;
	  case 16:pool_fac();
				 break;
	  case 18:gym_fac();
				 break;
	  }
	}
	else
	if(x==8)
	 mainmenu();
	else
	continue;
		}
		}

		//guest checkin
		void checkin()
		{clrscr();
		GUEST g;
		g.readguest();
		fstream fileout;
		fileout.open("hotelll.dat",ios::app|ios::binary);
		fileout.write((char*)&g,sizeof(g));
		fileout.close();
		mainmenu();
		}

		void GUEST::showguest()
		{
			clrscr();
			border('*','*');
			gotoxy(30,3);
			cout<<"GUEST INFORMATION";
			gotoxy(30,4);
			cout<<"~~~~~~~~~~~~~~~~~";
			gotoxy(5,6);
			cout<<"NAME: "<<name.firstname<<" "<<name.lastname;
			gotoxy(40,6);
			if(status==1)
			cout<<"STATUS:CHECKED-IN ";
			else
			cout<<"STATUS:CHECKED-OUT";
			gotoxy(5,8);
			cout<<"ID NUMBER: "<<idno;
			gotoxy(40,8);
			cout<<"ROOM NUMBER: "<<roomno;
			gotoxy(5,10);
			cout<<"PHONE NUMBER: "<<phone;
			gotoxy(40,10);
			cout<<"ROOM TYPE: "<<roomtype;
			gotoxy(5,12);
			cout<<"ADDRESS: "<<address.city<<","<<address.state<<","<<address.zipcode;
			gotoxy(5,14);
			cout<<"NATIONALITY: "<<nationality;
			gotoxy(5,16);
			cout<<"CHECK-IN DATE: "<<Adate.day<<"/"<<Adate.month<<"/20"<<Adate.year;
			gotoxy(5,18);
			cout<<"AMOUNT: "<<amount;
			if(status==0)
			{gotoxy(40,16);
			cout<<"CHECK-OUT DATE:"<<Ddate.day<<"/"<<Ddate.month<<"/20"<<Ddate.year;
			gotoxy(40,18);
			cout<<"NO: OF DAYS OF STAY:"<<ndays;
			}
		}
		void mainmenu()     //FUNCTION TO REACH MENU//
		{
		int x,p=8;
		clrscr();
		border('#','#');
		pgdesign('!','-','+');
		gotoxy(35,4);
		cout<<"MAIN MENU";
		gotoxy(35,5);
		cout<<"~~~~ ~~~~";
		gotoxy(15,8);
		cout<<"(A): GUEST CHECK-IN" ;
		gotoxy(15,10);
		cout<<"(B): GUEST SEARCH";
		gotoxy(15,12);
		cout<<"(C): AMENITIES";
		gotoxy(15,14);
		cout<<"(D): GUEST CHECK-OUT";
		gotoxy(15,16);
		cout<<"(E): REPORT";
		gotoxy(15,18);
		cout<<"(F): ABOUT DEVELOPERS";
		gotoxy(15,20);
		cout<<"(G): LOG-OUT";
		gotoxy(10,23);
		cout<<"©Created By Sanjay Raju";
		gotoxy(56,20);
		cout<<"W- UP";
		gotoxy(56,21);
		cout<<"S- DOWN";
		gotoxy(13,8);
		cout<<"@";
		gotoxy(40,8);
		cout<<"@";
		for(;;)
		{
		x=getch();

		if(x==87 || x==119)
		{
		if(p==8)
		{
		gotoxy(13,p);
		cout<<" ";
		gotoxy(40,p);
		cout<<" ";
		p=20;
		gotoxy(13,p);
		cout<<"@";
		gotoxy(40,p);
		cout<<"@";
		}
		else
		{
		gotoxy(13,p);
		cout<<" ";
		gotoxy(40,p);
		cout<<" ";
		p-=2;
		gotoxy(13,p);
		cout<<"@";
		gotoxy(40,p);
		cout<<"@";
		}
		}
		else
		if(x==83 || x==115)
		{
		if(p==20)
		{
		gotoxy(13,p);
		cout<<" ";
		gotoxy(40,p);
		cout<<" ";
		p=8;
		gotoxy(13,p);
		cout<<"@";
		gotoxy(40,p);
		cout<<"@";
		}
		else
		{
		gotoxy(13,p);
		cout<<" ";
		gotoxy(40,p);
		cout<<" ";
		p+=2;
		gotoxy(13,p);
		cout<<"@";
		gotoxy(40,p);
		cout<<"@";
		}
		}
		else
		if(x==13)
		{
		switch(p)
		{
	  case 8:checkin();
				  break;
	  case 10:search();
					break;
	  case 12:amenities();
					break;
	  case 14:checkout();
					break;
	  case 16:repsearch();
					break;
	  case 18:developers();
					break;
	  case 20:logout();
					break;
	 }
	}
	else
	continue;
 }
		}


		//functions for availing amenities
		void brkfst()
		{
			clrscr();
			 char b='a';
			 long x;
			 int c=0;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(33,5);
			 cout<<"BREAKFAST MENU";
			 gotoxy(33,6);
			 cout<<"~~~~~~~~~ ~~~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 smallbox(39,12,5);
		 id:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
				fstream filein;
				filein.open("hotelll.dat",ios::in|ios::binary|ios::out);
				while(filein.read((char*)&g,sizeof(g)))

					if((g.retid()==x) && (g.retstatus()==1))
					{ 	c=1;
						clrscr();
						border('+','+');
						int item=1;
						gotoxy(30,3);
						cout<<"BREAKFAST MENU";
						gotoxy(30,4);
						cout<<"~~~~~~~~~~~~~~";
						gotoxy(5,6);
						cout<<"~CONTINENTAL~";
						gotoxy(5,8);
						cout<<"#1.Bread Toast";
						gotoxy(5,9);
						cout<<"#2.Omlete Suffle";
						gotoxy(5,10);
						cout<<"#3.Oatmeal N'Cereal";
						gotoxy(5,11);
						cout<<"#4.Crisp Bacon";
						gotoxy(5,12);
						cout<<"#5.Spring Rolls";
						gotoxy(5,13);
						cout<<"#6.Veg Pasta";
						gotoxy(5,15);
						cout<<"~SWEET TREAT~";
						gotoxy(5,17);
						cout<<"#7.Chocolate Truffle";
						gotoxy(5,18);
						cout<<"#8.Cheese Cake";
						gotoxy(5,19);
						cout<<"#9.Tiramisu";
						gotoxy(5,20);
						cout<<"#10.Lemon Torte";
						gotoxy(5,21);
						cout<<"#11.Ice Cream";
						gotoxy(31,6);
						cout<<"~FRUIT JUICES~";
						gotoxy(31,8);
						cout<<"#12.Apple";
						gotoxy(31,9);
						cout<<"#13.Orange";
						gotoxy(31,10);
						cout<<"#14.Mango";
						gotoxy(31,11);
						cout<<"#15.Grape";
						gotoxy(31,12);
						cout<<"#16.Pineapple";
						gotoxy(31,13);
						cout<<"#17.Watermelon";
						gotoxy(31,14);
						cout<<"#18.Mixed";
						gotoxy(31,16);
						cout<<"~BEVERAGES~";
						gotoxy(31,18);
						cout<<"#19.Cappucino";
						gotoxy(31,19);
						cout<<"#20.Black Coffee";
						gotoxy(31,20);
						cout<<"#21.Green Tea";
						gotoxy(31,21);
						cout<<"#22.Caramel Latte";
						gotoxy(55,6);
						cout<<"~SOFTDRINKS~";
						gotoxy(55,8);
						cout<<"#23.Pepsi";
						gotoxy(55,9);
						cout<<"#24.Coca-Cola";
						gotoxy(55,10);
						cout<<"#25.Seven UP";
						gotoxy(55,11);
						cout<<"#26.Mountain Dew";
						gotoxy(55,12);
						cout<<"#27.Miranda";
						gotoxy(55,13);
						cout<<"#28.Sprite";
						gotoxy(55,14);
						cout<<"#29.Fanta";
						gotoxy(55,15);
						cout<<"#30.Shweppes";
						gotoxy(55,21);
						cout<<"Enter'0'To Finish" ;
						gotoxy(55,17);
						cout<<"Enter The Item code: ";
						int k;
						for(k=55;item!=0;k+=4)
						{smallbox(k,19,3);
				order:gotoxy(k+1,19);
						cin>>item;
						switch(item)
						{
							case 1:g.upamount(1);
									 break;
							case 2:g.upamount(1.5);
									 break;
							case 3:g.upamount(1);
									 break;
							case 4:g.upamount(1.8);
									 break;
							case 5:g.upamount(3.5);
									 break;
							case 6:g.upamount(4);
									 break;
							case 7:g.upamount(2);
									 break;
							case 8:g.upamount(2.5);
									 break;
							case 9:g.upamount(8);
									 break;
							case 10:g.upamount(7);
									 break;
							case 11:g.upamount(8.5);
									 break;
							case 12:g.upamount(6);
									 break;
							case 13:g.upamount(4.5);
									 break;
							case 14:g.upamount(5);
									 break;
							case 15:g.upamount(4.5);
									 break;
							case 16:g.upamount(4);
									 break;
							case 17:g.upamount(4);
									 break;
							case 18:g.upamount(6);
									 break;
							case 19:g.upamount(3.5);
									 break;
							case 20:g.upamount(2);
									 break;
							case 21:g.upamount(2.5);
									 break;
							case 22:g.upamount(4);
									 break;
							case 23:g.upamount(1);
									 break;
							case 24:g.upamount(2);
									 break;
							case 25:g.upamount(1.5);
									 break;
							case 26:g.upamount(2);
									 break;
							case 27:g.upamount(1);
									 break;
							case 28:g.upamount(1.5);
									 break;
							case 29:g.upamount(0.5);
									 break;
							case 30:g.upamount(2);
									 break;
							case  0:break;
							default:gotoxy(k+1,19);
										cout<<"  ";
										goto order;
						}
						}
				 int pos=filein.tellp()-sizeof(g);
				 filein.seekp(pos,ios::beg);
				 filein.write((char*)&g,sizeof(g));
			}
			if(c==0)
			{
			 gotoxy(28,16);
			 cout<<"!GUEST NOT FOUND!";
			 gotoxy(40,12);
			 cout<<"   ";
			 goto id;
			}
			 gotoxy(28,23);
			 cout<<"~~press any key to continue~~";
			 getch();
			 mainmenu();
			 filein.close();
			}
		  void dinefac()
		{
			clrscr();
			 int c=0;
			 char b='a';
			 long x;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(33,5);
			 cout<<"DINNER MENU";
			 gotoxy(33,6);
			 cout<<"~~~~~~ ~~~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 smallbox(39,12,5);
		 id:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
				fstream filen;
				filen.open("hotelll.dat",ios::in|ios::binary|ios::out);
				while(filen.read((char*)&g,sizeof(g)))

					if((g.retid()==x) && (g.retstatus()==1))
					{ c=1;

						int item=1;
						clrscr();
						border('+','+');
						gotoxy(30,3);
						cout<<"DINNER'S MENU";
						gotoxy(30,4);
						cout<<"~~~~~~~~ ~~~~";
						gotoxy(5,6);
						cout<<"~SOUP N SALAD~";
						gotoxy(5,8);
						cout<<"#31.Market Soup";
						gotoxy(5,9);
						cout<<"#32.Razor Clam Chowder";
						gotoxy(5,10);
						cout<<"#33.House Salad";
						gotoxy(5,11);
						cout<<"#34.Caesar Salad";
						gotoxy(5,12);
						cout<<"#35.Chop Salad";
						gotoxy(5,14);
						cout<<"~SHARE N ENTREES~";
						gotoxy(5,15);
						cout<<"#36.Chips/Bread&Dips";
						gotoxy(5,16);
						cout<<"#37.Meat&Cheese Board";
						gotoxy(5,17);
						cout<<"#38.Beef Burger";
						gotoxy(5,18);
						cout<<"#39.Kale Pasta";
						gotoxy(5,19);
						cout<<"#40.Roasted Bay-salmon";
						gotoxy(5,20);
						cout<<"#41.Shrimp Tacos";
						gotoxy(5,21);
						cout<<"#42.Rosemary Chicken";
						gotoxy(5,22);
						cout<<"#43.Steak Frites";
						gotoxy(31,6);
						cout<<"~FLATBREADS~";
						gotoxy(31,7);
						cout<<"#44.Forest Mushrooms";
						gotoxy(31,8);
						cout<<"#45.Roma Tomatoes";
						gotoxy(31,9);
						cout<<"#46.Cheese&Pepperoni";
						gotoxy(31,10);
						cout<<"#47.Garlic Bread";
						gotoxy(31,13);
						cout<<"~ FRUIT JUICES~ ";
						gotoxy(31,14);
						cout<<"#12.Apple ";
						gotoxy(31,15);
						cout<<"#13.Orange";
						gotoxy(31,16);
						cout<<"#14.Mango";
						gotoxy(31,17);
						cout<<"#15.Grape";
						gotoxy(31,18);
						cout<<"#16.Pineapple";
						gotoxy(31,19);
						cout<<"#17.Watermelon";
						gotoxy(31,20);
						cout<<"#18.Mixed";
						gotoxy(55,5);
						cout<<"~SOFTDRINKS~";
						gotoxy(55,6);
						cout<<"#23.Pepsi";
						gotoxy(55,7);
						cout<<"#24.Coca-Cola";
						gotoxy(55,8);
						cout<<"#25.Seven UP";
						gotoxy(55,9);
						cout<<"#26.Mountain Dew";
						gotoxy(55,10);
						cout<<"#27.Miranda";
						gotoxy(55,11);
						cout<<"#28.Sprite";
						gotoxy(55,12);
						cout<<"#29.Fanta";
						gotoxy(55,13);
						cout<<"#30.Schweppes";
						gotoxy(55,23);
						cout<<"Enter 0 to finish";
						gotoxy(55,16);
						cout<<"Item code:";
						int k;
						int d=0,e=1;
						for(k=55;item!=0;k+=4)
						{smallbox(k,18+d,3);
				order:gotoxy(k+1,18+d);
						cin>>item;
						switch(item)
						{
							case 31:g.upamount(5);
										 break;
							case 32:g.upamount(5.5);
									  break;
							case 33:g.upamount(5);
									  break;
							case 34:g.upamount(7.5);
									  break;
							case 35:g.upamount(6.5);
									  break;
							case 36:g.upamount(6);
									  break;
							case 37:g.upamount(9.5);
									  break;
							case 38:g.upamount(6.5);
									  break;
							case 39:g.upamount(7);
									  break;
							case 40:g.upamount(9);
									  break;
							case 41:g.upamount(7.5);
									  break;
							case 42:g.upamount(12);
									  break;
							case 43:g.upamount(10.5);
										break;
							case 44:g.upamount(9);
										break;
							case 45:g.upamount(8);
										break;
							case 46:g.upamount(10);
										break;
							case 47:g.upamount(8.5);
										break;
							case 12:g.upamount(6);
							break;
							case 13:g.upamount(4.5);
							break;
							case 14:g.upamount(5);
									 break;
							case 15:g.upamount(4.5);
							break;
							case 16:g.upamount(4);
								  break;
							case 17:g.upamount(4);
									break;
							case 18:g.upamount(6);
									 break;
							case 23:g.upamount(1);
									 break;
							case 24:g.upamount(2);
									 break;
							case 25:g.upamount(1.5);
									 break;
							case 26:g.upamount(2);
									 break;
							case 27:g.upamount(1);
									 break;
							case 28:g.upamount(1.5);
									 break;
							case 29:g.upamount(0.5);
									 break;
							case 30:g.upamount(2);
									 break;
							case 0:break;
							default:gotoxy(k+1,18+d);
										cout<<"  ";
										goto order;
							}
							e+=1;
							if(e==7)
							{
							 d+=3;
							 e=1;
							 k=51;
							}
							}

							int pos=filen.tellp()-sizeof(g);
							filen.seekp(pos,ios::beg);
							filen.write((char*)&g,sizeof(g));
							if(c==0)
							{
							 gotoxy(28,16);
							 cout<<"!GUEST NOT FOUND!";
							 gotoxy(40,12);
							 cout<<"   ";
							 goto id;
							}
							gotoxy(28,23);
							cout<<"~~press any key to continue~~";
							getch();
							filen.close();
							mainmenu();
							} }
		  void lunch()                     //lunch is complementary w/ service charges
		{
			clrscr();
			 int c=0;
			 char b='a';
			 int x;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(33,5);
			 cout<<"LUNCH MENU";
			 gotoxy(33,6);
			 cout<<"~~~~~ ~~~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 smallbox(39,12,5);
		 id:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
				fstream filein;
				filein.open("hotelll.dat",ios::in|ios::binary|ios::out);
				while(filein.read((char*)&g,sizeof(g)))
				 {	if(g.retid()==x && g.retstatus()==1)
					{   c=1;
						clrscr();
						border('+','+');
						int item=1;
						gotoxy(30,3);
						cout<<"LUNCH MENU";
						gotoxy(30,4);
						cout<<"~~~~~ ~~~~";
						gotoxy(5,6);
						cout<<"~SOUP n SALAD~";
						gotoxy(5,8);
						cout<<"#31.Market Soup";
						gotoxy(5,9);
						cout<<"#32.Razor Clam Chowder";
						gotoxy(5,10);
						cout<<"#33.House Salad";
						gotoxy(5,11);
						cout<<"#34.Caesar Salad";
						gotoxy(5,12);
						cout<<"#35.Chop Salad";
						gotoxy(5,14);
						cout<<"~Share n Entrees~";
						gotoxy(5,16);
						cout<<"#36.Chips/Bread&Dips";
						gotoxy(5,17);
						cout<<"#37.Meat&Cheese Board";
						gotoxy(5,18);
						cout<<"#38.Beef Burger";
						gotoxy(5,19);
						cout<<"#39.Kale Pasta";
						gotoxy(5,20);
						cout<<"#40.Roasted Bay-salmon";
						gotoxy(5,21);
						cout<<"#41.Shrimp Tacos";
						gotoxy(31,6);
						cout<<"~FRUIT JUICES~";
						gotoxy(31,8);
						cout<<"#12.Apple";
						gotoxy(31,9);
						cout<<"#13.Orange";
						gotoxy(31,10);
						cout<<"#14.Mango";
						gotoxy(31,11);
						cout<<"#15.Grape";
						gotoxy(31,12);
						cout<<"#16.Pineapple";
						gotoxy(31,13);
						cout<<"#17.Watermelon";
						gotoxy(31,14);
						cout<<"#18.Mixed";
						gotoxy(31,16);
						cout<<"~SANDWICHES~";
						gotoxy(31,18);
						cout<<"#48.Grilled Chicken";
						gotoxy(31,19);
						cout<<"#49.Beef Burger";
						gotoxy(31,20);
						cout<<"#50.Smoked Pork&Bacon";
						gotoxy(31,21);
						cout<<"#51.Classic Club";
						gotoxy(55,6);
						cout<<"~SOFTDRINKS~";
						gotoxy(55,8);
						cout<<"#23.Pepsi";
						gotoxy(55,9);
						cout<<"#24.Coca-Cola";
						gotoxy(55,10);
						cout<<"#25.Seven UP";
						gotoxy(55,11);
						cout<<"#26.Mountain Dew";
						gotoxy(55,12);
						cout<<"#27.Miranda";
						gotoxy(55,13);
						cout<<"#28.Sprite";
						gotoxy(55,14);
						cout<<"#29.Fanta";
						gotoxy(55,15);
						cout<<"#30.Schweppes";
						gotoxy(55,21);
						cout<<"Enter '0' To EXIT" ;
						gotoxy(55,17);
						cout<<"Enter The Item no: ";
						int k;
						for(k=55;item!=0;k+=4)
						{smallbox(k,19,3);
				 order:gotoxy(k+1,19);
						cin>>item;
						switch(item)
						{
							case 31:break;
							case 32:break;
							case 33:break;
							case 34:break;
							case 35:break;
							case 36:break;
							case 37:break;
							case 38:break;
							case 39:break;
							case 40:break;
							case 41:break;
							case 12:break;
							case 13:break;
							case 14:break;
							case 15:break;
							case 16:break;
							case 17:break;
							case 18:break;
							case 48:break;
							case 49:break;
							case 50:break;
							case 51:break;
							case 23:break;
							case 24:break;
							case 25:break;
							case 26:break;
							case 27:break;
							case 28:break;
							case 29:break;
							case 30:break;
							case 0:break;
							default:gotoxy(k+1,19);
										cout<<"  ";
										goto order;
						}
						}
						g.upamount(3);
				 int pos=filein.tellp()-sizeof(g);
				 filein.seekp(pos,ios::beg);
				 filein.write((char*)&g,sizeof(g));
			  }}if(c==0)
			{gotoxy(28,16);
			 cout<<"!GUEST NOT FOUND!";
			 gotoxy(40,12);
			 cout<<"   ";
			 goto id;
			 }

			 gotoxy(28,23);
			 cout<<"~~press any key to continue~~";
			 getch();
			 filein.close();
	  mainmenu();
			}

		  void spa_fac()
		  {clrscr();
			 int c=0,i;
			 char b='a';
			 long x;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(33,5);
			 cout<<"THAI SPA";
			 gotoxy(33,6);
			 cout<<"~~~~ ~~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 gotoxy(16,14);
			 cout<<"Time expected to use(in hrs):";
			 smallbox(39,12,5);
			 smallbox(45,14,5);
		 id:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
			 gotoxy(46,14);
			 cin>>i;
			fstream filein;
			filein.open("hotelll.dat",ios::in|ios::binary|ios::out);
			while(filein.read((char*)&g,sizeof(g)))
			 {
				if(g.retid()==x && g.retstatus()==1)
				{  g.upamount(i*8);         //cost per hour is 8 bd
					c=1;
					gotoxy(20,15);
					cout<<"!FACILITY SUICESSFULLY AVAILED!";
					int pos=filein.tellp()-sizeof(g);
					filein.seekp(pos,ios::beg);
					filein.write((char*)&g,sizeof(g));
				}
				}
				 if(c==0)
				  {
			 gotoxy(28,16);
					cout<<"!GUEST NOT FOUND!";
					gotoxy(40,12);
					cout<<"   ";
					goto id;
				  }

			 gotoxy(28,23);
			 cout<<"~~~press any key to continue~~~";
			 getch();
			 filein.close();
			 mainmenu();
			}
		void pool_fac()
		{  clrscr();
			 int c=0,i;
			 char b='a';
			 long x;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(33,5);
			 cout<<"SWIMMING POOL";
			 gotoxy(33,6);
			 cout<<"~~~~~~~~ ~~~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 gotoxy(16,14);
			 cout<<"Time expected to use(in hrs):";
			 smallbox(39,12,5);
			 smallbox(45,14,5);
		 id:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
			 gotoxy(46,14);
			 cin>>i;
			 fstream filein;
			 filein.open("hotelll.dat",ios::in|ios::binary|ios::out);
			 while(filein.read((char*)&g,sizeof(g)))
			 {
				if(g.retid()==x && g.retstatus()==1)
				{
					g.upamount(i*15);   //cost per hour is 15bd//
					gotoxy(20,18);
					cout<<"!FACILITY SUCCESSFULLY AVAILED!";
					int pos=filein.tellp()-sizeof(g);
					filein.seekp(pos,ios::beg);
					filein.write((char*)&g,sizeof(g));
					c=1;
				}
			 }
			 if(c==0)
			 {
			  gotoxy(28,16);
			 cout<<"!GUEST NOT FOUND!";
			 gotoxy(40,12);
			 cout<<"   ";
			 gotoxy(46,14);
			 cout<<"   ";
			 goto id;
			 }
			 gotoxy(28,23);
			 cout<<"~~press any key to continue~~";
			 getch();
			 filein.close();
			 mainmenu();
			}
		void gym_fac()
		{  clrscr();
			 int c=0,i;
			 char b='a';
			 long x;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(33,5);
			 cout<<"IRON GYM";
			 gotoxy(33,6);
			 cout<<"~~~~ ~~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 gotoxy(16,14);
			 cout<<"Time expected to use(in hrs):";
			 smallbox(39,12,5);
			 smallbox(45,14,5);
		 id:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
			 gotoxy(46,14);
			 cin>>i;
			fstream filein;
			filein.open("hotelll.dat",ios::in|ios::out|ios::binary);
			 while(filein.read((char*)&g,sizeof(g)))
			 {
				if(g.retid()==x && g.retstatus()==1)
				{  g.upamount(i*20);   //cost per hour is 20bd//
					gotoxy(20,18);
					cout<<"!FACILITY SUCCESSFULLY AVAILED!";
					int pos=filein.tellp()-sizeof(g);
					filein.seekp(pos,ios::beg);
					filein.write((char*)&g,sizeof(g));
					c=1;
				}
			 }
				if(c==0)
				{
				 gotoxy(28,16);
				 cout<<"!GUEST NOT FOUND!";
				 gotoxy(40,12);
				 cout<<"   ";
				 gotoxy(46,14);
				 cout<<"   ";
				 goto id;
				}
			 gotoxy(28,23);
			 cout<<"~~press any key to continue~~";
			 getch();
			 filein.close();
			 mainmenu();
		}


		//functions to search guest

		void search()
		{  clrscr();
			int x,p=8;
			char mos; //METHOD OF SEARCH//
			border('!','!');
			gotoxy(30,4);
			cout<<"GUEST SEARCH";
			gotoxy(30,5);
			cout<<"~~~~~ ~~~~~~";
			gotoxy(5,6);
			cout<<"SEARCH BY:";
			gotoxy(20,8);
			cout<<"(A) NAME";
			gotoxy(20,10);
			cout<<"(B) ROOM NUMBER";
			gotoxy(20,12);
			cout<<"(C) ID NUMBER";
			gotoxy(20,14);
			cout<<"(D) PHONE NUMBER";
			gotoxy(5,16);
			cout<<"*press backspace to go back";
			gotoxy(56,20);
		cout<<"W- UP";
		gotoxy(56,21);
		cout<<"S- DOWN";
			gotoxy(18,8);
		cout<<"@";
		gotoxy(37,8);
		cout<<"@";
		for(;;)
		{
		x=getch();

		if(x==87 || x==119)
		{
		if(p==8)
		{
		gotoxy(18,p);
		cout<<" ";
		gotoxy(37,p);
		cout<<" ";
		p=14;
		gotoxy(18,p);
		cout<<"@";
		gotoxy(37,p);
		cout<<"@";
		}
		else
		{
		gotoxy(18,p);
		cout<<" ";
		gotoxy(37,p);
		cout<<" ";
		p-=2;
		gotoxy(18,p);
		cout<<"@";
		gotoxy(37,p);
		cout<<"@";
		}
		}
		else
		if(x==83 || x==115)
		{
		if(p==14)
		{
		gotoxy(18,p);
		cout<<" ";
		gotoxy(37,p);
		cout<<" ";
		p=8;
		gotoxy(18,p);
		cout<<"@";
		gotoxy(37,p);
		cout<<"@";
		}
		else
		{
		gotoxy(18,p);
		cout<<" ";
		gotoxy(37,p);
		cout<<" ";
		p+=2;
		gotoxy(18,p);
		cout<<"@";
		gotoxy(37,p);
		cout<<"@";
		}
		}
		else
		if(x==13)
		{
		switch(p)
		{
	  case 8:search_name();
				  break;
	  case 10:search_roomno();
					break;
	  case 12:search_idno();
					break;
	  case 14:search_phoneno();
					break;
	  }
	}
	else
	if(x==8)
	 mainmenu();
	else
	continue;
		}
		}
		void search_name()
		{clrscr();
		 GUEST g;
		 char x[30],y[30];  // X is the first name and Y is the second name//
		 NAME ch;
		 int c=0;
		 char b='s';
		 border('!','!');
		 pgdesign('/','-','`');
		 gotoxy(30,5);
		 cout<<"GUEST SEARCH BY NAME";
		 gotoxy(30,6);
		 cout<<"~~~~~ ~~~~~~ ~~ ~~~~";
		 gotoxy(48,21);
		 cout<<"(enter 0 to go back)";
		 entrybox(26,11,25,4);
		 gotoxy(27,12);
		 cout<<"FIRST NAME:";
		 gotoxy(27,14);
		 cout<<"LAST NAME:";
	 nm:gotoxy(38,12);
		 gets(x);
		 goback(x[0],b);
		 gotoxy(37,14);
		 gets(y);
		 goback(y[0],b);
		 fstream filein;
		 filein.open("hotelll.dat",ios::in|ios::binary);
		 while(filein.read((char*)&g,sizeof(g)))
							{  ch=g.retname();
								if(strcmpi(x,ch.firstname)==0 && strcmpi(y,ch.lastname)==0)
								{
								 g.showguest();
								 c=1;
								}
							}
		 if(c==0)
		 {gotoxy(32,16);
		  cout<<"~GUEST NOT FOUND~";
		  gotoxy(38,12);
		  cout<<"           ";
		  gotoxy(37,14);
		  cout<<"           ";
		  goto nm;
		 }
		 filein.close();

		}
		void search_roomno()
		{clrscr();
		 int x;
		 GUEST g;
		 int c=0;
		 char b='s';
		 border('!','!');
		 pgdesign('/','-','`');
		 gotoxy(30,3);
		 cout<<"SEARCH BY ROOM NUMBER";
		 gotoxy(30,4);
		 cout<<"~~~~~~ ~~ ~~~~ ~~~~~~";
		 gotoxy(48,21);
		 cout<<"(enter 0 to go back)";
		 gotoxy(29,12);
		 cout<<"ROOM NUMBER:";
		 smallbox(41,12,5);
	 rm:gotoxy(42,12);
		 cin>>x;
		 goback(x,b);
		 fstream filein;
		 filein.open("hotelll.dat",ios::in|ios::binary);
		 while(filein.read((char*)&g,sizeof(g)))
		 {if(g.retstatus()==1)
		  if(x==g.retroomno())
			{g.showguest();
			c=1;}
		  }
		  if(c==0)
		  {gotoxy(29,15);
			cout<<"~GUEST NOT FOUND~";
			gotoxy(42,12);
			cout<<"   ";
			goto rm;
		  }
		  filein.close();
		  }
		  void search_idno()
		  { clrscr();
			 int c=0;
			 char b='s';
			 long x;
			 GUEST g;
			 border('!','!');
			 pgdesign('/','-','`');
			 gotoxy(30,3);
			 cout<<"SEARCH BY ID";
			 gotoxy(30,4);
			 cout<<"~~~~~~ ~~ ~~";
			 gotoxy(48,21);
			 cout<<"(enter 0 to go back)";
			 gotoxy(29,12);
			 cout<<"ID NUMBER:";
			 smallbox(39,12,5);
		idn:gotoxy(40,12);
			 cin>>x;
			 goback(x,b);
			 fstream filein;
			 filein.open("hotelll.dat",ios::in|ios::binary);
			 while(filein.read((char*)&g,sizeof(g)))
			 {if(x==g.retid())
			 {
			  g.showguest();
			  c=1;
			  }
			  }
			  if(c==0)
			  {gotoxy(29,15);
				cout<<"~GUEST NOT FOUND~";
				gotoxy(40,12);
				cout<<"   ";
				goto idn;
			  }
			  filein.close();
			  }
			  void search_phoneno()
			  {clrscr();
				GUEST g;
				long x;
				int c=0;
				char b='s';
				border('!','!');
				pgdesign('/','-','`');
				gotoxy(30,3);
				cout<<"SEARCH BY PHONE NUMBER";
				gotoxy(30,4);
				cout<<"~~~~~~ ~~ ~~~~~ ~~~~~~";
				gotoxy(48,21);
				cout<<"(enter 0 to go back)";
				gotoxy(29,12);
				cout<<"PHONE NUMBER:";
				smallbox(42,12,13);
			pn:gotoxy(43,12);
				cin>>x;
				goback(x,b);
				fstream filein;
				filein.open("hotelll.dat",ios::in|ios::binary);
				while(filein.read((char*)&g,sizeof(g)))
				{
					if(x==g.retphone())
					{
						c=1;
						g.showguest();
					}
				}
				if(c==0)
				{gotoxy(29,15);
				 cout<<"~GUEST NOT FOUND~";
				 gotoxy(43,12);
				 cout<<"            ";
				 goto pn;
				}
				filein.close();
				}


		  //function to checkout
			  void checkout()
			  {
				 clrscr();
				 int c=0;
				 char b='i';
				 long x;
				 GUEST g;
				 border('!','!');
				 pgdesign('/','-','`');
				 gotoxy(33,5);
				 cout<<"GUEST CHECK-OUT";
				 gotoxy(33,6);
				 cout<<"~~~~~ ~~~~~ ~~~";
				 gotoxy(48,21);
				 cout<<"(enter 0 to go back)";
				 gotoxy(29,12);
				 cout<<"ID NUMBER:";
				 gotoxy(20,15);
				 cout<<"CHECK-OUT DATE:";
				 smallbox(35,15,12);
				 gotoxy(38,15);
				 cout<<"/";
				 gotoxy(41,15);
				 cout<<"/";
				 cout<<"20-";
				 gotoxy(51,15);
				 cout<<"(dd/mm/yy)";
				 smallbox(39,12,5);
			 id:gotoxy(40,12);
				 cin>>x;
				 goback(x,b);
				 fstream filein;
				 filein.open("hotelll.dat",ios::in|ios::binary|ios::out);
			  while(filein.read((char*)&g,sizeof(g)))
				{if(x==g.retid())
				 if(g.retstatus()==1)
				 {
				  gotoxy(15,18);
				  cout<<"               ";
				  c=1;
				  g.end();
				  g.setamount();
				  int pos=filein.tellp()- sizeof(g);
				  filein.seekp(pos,ios::beg);
				  filein.write((char*)&g,sizeof(g));
				  filein.close();
				  g.showguest();
				  gotoxy(28,23);
				  cout<<"**CHECK-OUT SUCCESFULL**";
				  gotoxy(28,23);
				  cout<<"***press any key to continue***";
				  getch();
				  mainmenu();
				 }
				 }
				 if(c==0)
				 {
				  gotoxy(15,18);
				  cout<<"GUEST NOT FOUND";
				  gotoxy(40,12);
				  cout<<"   ";
				  goto id;
				  }
				  }
			  void GUEST::upamount(float x)
			  {
				amount+=x;
			  }
			  void GUEST::setamount()
			  {
				gotoxy(36,15);
				cin>>Ddate.day;
				gotoxy(39,15);
				cin>>Ddate.month;
				gotoxy(45,15);
				cin>>Ddate.year;
				int d1,d2,m1,m2,y1,y2,x,i,n,y;
				int sum=0;
				d1=Adate.day;
				m1=Adate.month;
				y1=Adate.year+2000;
				d2=Ddate.day;
				m2=Ddate.month;
				y2=Ddate.year+2000;
				if(y1==y2)
				if(m1==m2)
				if(d1==d2)
				sum=1;
				else
				sum=d2-d1+1;
				else
	  {      if(m1==2)
				{if(y1%400==0||(y1%100!=0&&y1&&4==0))
				 n=29;
				 else
				 n=28;}
				else
				if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
				n=31;
				else
				n=30;
				sum=d1;
				for(i=1;sum<=n;sum=sum+i)
				{
				}
				sum=sum-d1;
				for(x=m1+1;x!=m2;x++)
			 { if(x==2)
				{if(y1%400==0||y1%100!=0&&y1%4==0)
				 sum=sum+29;
				 else
				 sum=sum+28;
				}
				else
				if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)
				sum=sum+31;
				else
				sum=sum+30;
			 }
			 sum=sum+d2;
	 }
			 else
	 {     if(m1==2)
				{if(y1%400==0||y1%100!=0&&y1%4==0)
				 n=29;
				 else
				 n=28;}
				else
				if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
				n=31;
				else
				n=30;
				sum=d1;
				for(i=1;sum<=n;sum=sum+i)
				{
				}
				sum=sum-d1;
				for(x=m1+1;x!=13;x++)
			 { if(x==2)
				{if(y1%400==0||y1%100!=0&&y1%4==0)
				 sum=sum+29;
				 else
				 sum=sum+28;
				}
				else
				if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)
				sum=sum+31;
				else
				sum=sum+30;
			 }
				for(y=y1+1;y!=y2;y++)
			  {if(y%400==0||y%100!=0&&y%4==0)
				sum=sum+366;
				else
				sum=sum+365;
				}
				sum=sum+d2;
				for(i=1;i<m2;i++)
				{if(i==2)
				{if(y%400==0||y%100!=0&&y%4==0)
				 sum=sum+29;
				 else
				 sum=sum+28;
				}
				else
				if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				sum=sum+31;
				else
				sum=sum+30;
				}

	 }
				ndays=sum;
				amount+=rent*ndays;
				}

		//function for report
		void repsearch()
		{  clrscr();
			border('_','_');
			gotoxy(39,1);
			cout<<"REPORT";
			gotoxy(39,2);
			cout<<"~~~~~~";
			GUEST g;
			g.report();
			getch();
			mainmenu();
		}
		void GUEST::report()
		{
		GUEST g;
		int i=6,j=6,k=1;
		fstream filein;
		filein.open("hotelll.dat",ios::in|ios::binary);
		gotoxy(5,3);
		cout<<"S-No";
		gotoxy(5,4);
		cout<<"----";
		gotoxy(12,3);
		cout<<"NAME";
		gotoxy(12,4);
		cout<<"----";
		gotoxy(26,3);
		cout<<"ID";
		gotoxy(26,4);
		cout<<"--";
		gotoxy(31,3);
		cout<<"ROOM";
		gotoxy(31,4);
		cout<<"----";
		gotoxy(38,3);
		cout<<"TYPE";
		gotoxy(38,4);
		cout<<"----";
		gotoxy(45,3);
		cout<<"PHONE";
		gotoxy(45,4);
		cout<<"-----";
		gotoxy(55,3);
		cout<<"CHECKIN-DATE";
		gotoxy(55,4);
		cout<<"------------";
		gotoxy(70,3);
		cout<<"AMT-DUE";
		gotoxy(70,4);
		cout<<"-------";
		while(filein.read((char*)&g,sizeof(g)))
		{
		if(g.retstatus()==1)
		 {{
		 if(j==6)
		 {
		 for(int z=0;z<22;z++)
		 {
		  gotoxy(i+4,j-3);
		  cout<<"|";
		  gotoxy(i+18,j-3);
		  cout<<"|";
		  gotoxy(i+24,j-3);
		  cout<<"|";
		  gotoxy(i+30,j-3);
		  cout<<"|";
		  gotoxy(i+37,j-3);
		  cout<<"|";
		  gotoxy(i+48,j-3);
		  cout<<"|";
		  gotoxy(i+62,j-3);
		  cout<<"|";
		  j++;
		 }
		 i=6;j=5;
		 }
		 gotoxy(i,j);
		 cout<<k;
		 i+=5;
		 gotoxy(i,j);
		 for(int n=0;g.name.firstname[n]!='\0';n++)
		 cout<<g.name.firstname[n];
		 //we count the no of letters in firstname ie. n
		 cout<<" ";

		 //here we do this to display certain no of letters in the lastname tofit in the column

		 for(int m=0;g.name.firstname[m]!='\0';m++)
		 if(n==1)
		  {
		  if(m!=11)                       //if n=1, then accordingly the letters of lastname appears
		  {
			if(g.name.lastname[m]!='\0')
			 cout<<g.name.lastname[m];
			else
			 break;
		  }
		  else
			break;
		  }
		  else
			if(n==2)
			{
			 if(m!=10)
			 {
			  if(g.name.lastname[m]!='\0')
				cout<<g.name.lastname[m];
			  else
				break;
			 }
			else
			 break;
			}
			else
			 if(n==3)
			 {
			  if(m!=9)
			  {
				if(g.name.lastname[m]!='\0')
				 cout<<g.name.lastname[m];
				else
				 break;
			  }
			  else
				break;
			 }
			 else
			  if(n==4)
			  {
				if(m!=8)
				{
				 if(g.name.lastname[m]!='\0')
				  cout<<g.name.lastname[m];
				 else
				  break;
				}
				else
				 break;
			  }
			  else
				if(n==5)
				{
				 if(m!=7)
				 {
				  if(g.name.lastname[m]!='\0')
					cout<<g.name.lastname[m];
				  else
					break;
				 }
				 else
				  break;
				}
				else
				 if(n==6)
				 {
				  if(m!=6)
				  {
					if(g.name.lastname[m]!='\0')
					 cout<<g.name.lastname[m];
					else
					 break;
				  }
				  else
					break;
				 }
				 else
				  if(n==7)
				  {
					if(m!=5)
					{
					 if(g.name.lastname[m]!='\0')
					  cout<<g.name.lastname[m];
					 else
					  break;
					}
				  else
					break;
				  }
				  else
					if(n==8)
					{
					 if(m!=4)
					 {
					  if(g.name.lastname[m]!='\0')
						cout<<g.name.lastname[m];
					  else
						break;
					 }
					 else
					  break;
					}
					else
					 if(n==9)
					 {
					  if(m!=3)
					  {
						if(g.name.lastname[m]!='\0')
						 cout<<g.name.lastname[m];
						else
						 break;
					  }
					  else
						break;
					 }
					 else
					  if(n==10)
					  {
						if(m!=2)
						{
						 if(g.name.lastname[m]!='\0')
						  cout<<g.name.lastname[m];
						 else
						  break;
						}
						else
						 break;
					  }
					  else
						if(n==11)
						{
						 if(m!=1)
						 {
						  if(g.name.lastname[m]!='\0')
							cout<<g.name.lastname[m];
						  else
							break;
						 }
						 else
						  break;
						}
						else
						 if(n>11)
						  break;
						 else
						  break;
				}
		 i+=15;
		 gotoxy(i,j);
		 cout<<g.idno;
		 i+=6;
		 gotoxy(i,j);
		 cout<<g.roomno;
		 i+=5;
		 gotoxy(i,j);
		 cout<<g.roomtype;
		 i+=8;
		 gotoxy(i,j);
		 cout<<g.phone;
		 i+=12;
		 gotoxy(i,j);
		 cout<<g.Adate.day<<"/"<<g.Adate.month<<"/20"<<g.Adate.year;
		 i+=13;
		 gotoxy(i,j);
		 cout<<"BD "<<g.amount;
		 i=6; j+=2; k++;
		 }}
		if(k==1)
		{
		 gotoxy(24,14);
		 cout<<"~NO GUESTS CURRENTLY CHECKED-IN~";
		}
		}

		//about developers
		void developers()
		{
		 clrscr();
		 border('_','-');
		 pgdesign('+','-','^');
		 gotoxy(30,5);
		 cout<<"----- ----------";
		 gotoxy(30,6);
		 cout<<"ABOUT DEVELOPERS";
		 gotoxy(30,7);
		 cout<<"----- ----------";
		 gotoxy(25,10);
		 cout<<"Team of four:";
		 gotoxy(30,12);
		 cout<<"SANJAY RAJU";
		 gotoxy(30,13);
		 cout<<"NEERAJ T";
		 gotoxy(30,14);
		 cout<<"AKSHIT JYOTHISH";
		 gotoxy(30,15);
		 cout<<"ANJITH PRAKASH";
		 gotoxy(15,17);
		 cout<<"~Developed Under the Supervision of Mr.Pius Mathew~";
		 getch();
		 mainmenu();
		}

		//functions for page design and boxes from here
		void pgdesign(char x,char y,char z)
		{
		 for(int i=0;i<4;i++)
		 {
		  gotoxy(8,3+i);
		  cout<<x;
		  gotoxy(72,3+i);
		  cout<<x;
		  gotoxy(8,20+i);
		  cout<<x;
		  gotoxy(72,20+i);
		  cout<<x;
		  gotoxy(3+i,6);
		  cout<<y;
		  gotoxy(3+i,20);
		  cout<<y;
		  gotoxy(74+i,6);
		  cout<<y;
		  gotoxy(74+i,20);
		  cout<<y;
		 }
		 for(i=0;i<5;i++)
		 {
		  gotoxy(70,11+i);
		  cout<<z;
		  gotoxy(9,11+i);
		  cout<<z;
		 }
		}
		void pgdesign(char x,char y)
		{
		 for(int i=0;i<4;i++)
		 {
		  gotoxy(8,3+i);
		  cout<<x;
		  gotoxy(72,3+i);
		  cout<<x;
		  gotoxy(8,20+i);
		  cout<<x;
		  gotoxy(72,20+i);
		  cout<<x;
		  gotoxy(3+i,6);
		  cout<<y;
		  gotoxy(3+i,20);
		  cout<<y;
		  gotoxy(74+i,6);
		  cout<<y;
		  gotoxy(74+i,20);
		  cout<<y;
		 }
		}
		void border(char x,char y)  // X is the breadth design and Y is the length design//
		{
				gotoxy(1,1);
			 for(int i=1;i<=24;i++)
				{
				 for(int j=1;j<=79;j++)
					if(i==1 || i==24)
						cout<<y;
					else
						if(j==1 || j==79)
							cout<<x;
					else
							cout<<" ";
					cout<<endl;
				}
		}
		void smallbox(int x,int y,int z)    //x and y are the co-ordinates of initial positon,while z is the box length //
		{
			int i;
			gotoxy(x,y);
			cout<<"|";
			gotoxy(x+z,y);
			cout<<"|";
			gotoxy(x,y-1);
			for(i=0;i<z+1;i++)
				cout<<"_";
			gotoxy(x,y+1);
			for(i=0;i<z+1;i++)
				cout<<"-";
		}
		void entrybox(int x,int y,int z,int a) //co-ordinate,length,breadth
		{
		 int i,j;
		 j=y;
		 for(i=0;i<a;i++)
		 {
		 gotoxy(x,y);
		 cout<<"|";
		 gotoxy(x+z,y);
		 cout<<"|";
		 y++;
		 }
		 for(i=0;i<=z;i++)
		 {
		  gotoxy(x+i,j);
		  cout<<"|";
		  gotoxy(x+i,j+a);
		  cout<<"|";
		 }
		}

		//login & logout functions
		void login()
		{   clrscr();
			 int i=3;
			 char username[10],password[25],pw[10]="nasacs";
			 border('_','_');
			 gotoxy(35,5);
			 cout<<"LOGIN";
			 gotoxy(35,6);
			 cout<<"~~~~~";
			 pgdesign('*','+','^');
			 entrybox(24,11,25,4);    //to put box for entering details
			 gotoxy(25,12);
			 cout<<"USERNAME:";
			 gotoxy(25,14);
			 cout<<"PASSWORD:";
			for(i=3;i>=0;i--)
			{
			if(i>0)
			{
		 lu:gotoxy(34,12);
			 gets(username);
			 if(username[0]!='\0')
			{
			 gotoxy(25,23);
			 cout<<"                        ";
			}
			else
			 {
			  gotoxy(25,23);
			  cout<<"!PLEASE ENTER USERNAME!";
			  goto lu;
			 }
			 char ch;
			 gotoxy(34,14);
			 int pi=0,p=0;
			 do
			 {
			  gotoxy(34+p,14);
			  ch=getch();
			  if(ch==13)
			  break;
			  else
			  if(ch==8)             //this is for backspacing without * being displayed
			  {
				gotoxy(33+p,14);       //capable of backspacing password characters upto 10 spaces
				cout<<" ";
				pi--;
				p--;
				continue;
			  }
			  else
			  {password[pi]=ch;
			  cout<<"*";
			  p++;
			  }
			  ++pi;
			 }while(ch!=13);
			 password[pi]=0;
			 if((strcmpi(username,"marriots")==0)&&(strcmpi(password,pw)==0))
			  {
			  mainmenu();
			  break;
			  }
			 else
			 {
			  gotoxy(34,12);
			  cout<<"              ";
			  gotoxy(34,14);
			  cout<<"              ";
			  gotoxy(17,16);
			  cout<<"!Username or password entered is invalid!";
			  gotoxy(20,17);
			  cout<<"Please Re-Enter the details again";
			  gotoxy(30,18);
			  cout<<"TRIES LEFT:"<<(i-1);
			 }
			}
			 else
			 {
			  clrscr();
			  gotoxy(20,12);
			  cout<<"Login Blocked ,Please restart the programme";
			  getch();
			  exit;
			 }
			}
		}
		void logout()
		{
		 clrscr();
		 border('/','/');
		 pgdesign('*','*','`');
		 char ch;
		 gotoxy(20,12);
		 cout<<"Are You Sure You Want To Logout?(Y/N)";
		 gotoxy(22,13);
		 cout<<"(Press n-to go back,y-to exit)";
	 lg:gotoxy(57,12);
		 ch=getch();
		 if(ch=='y' || ch=='Y')
		  {
			clrscr();
			page();
		  }
		 else
		  if(ch=='n' || ch=='N')
			 mainmenu();
		  else
			{gotoxy(20,20);
			cout<<"!INVALID ENTRY!";
			goto lg;
			}
		}

		//main hotel display page
		void page()
		{
		 clrscr();
		 border('|','-');
		 int i=8,j=4;
		 gotoxy(i,j);
		 cout<<"******  ******";
		 for(int k=0;k<5;k++)
		 {
		  gotoxy(i+2,j+k);      //to display 'the'
		  cout<<"*";
		 gotoxy(i+5,j+k);
		 cout<<"*";
		 gotoxy(i+8,j+k);
		 cout<<"*";
		 gotoxy(i+6,j+2);
		 cout<<"******";
		 gotoxy(i+9,j+k);
		 cout<<"*";
		 gotoxy(i+8,j+4);
		 cout<<"******";
		 }
		 i=28;
		 j=9;
		 gotoxy(i+7,j+2);
		 cout<<"**  ****  ***";
		 gotoxy(i+1,j+3);
		 cout<<"*          *    *";
		 gotoxy(i+14,j+1);
		 cout<<"*    *";
		 gotoxy(i+13,j+4);
		 cout<<"*    *";
		 gotoxy(i+14,j+5);
		 cout<<"*    * ***** *****";
		 gotoxy(i-2,j);
		 cout<<"*     * **** **** **** ***** ***** *****";
		 gotoxy(i-2,j+1);
		 cout<<"**   *";
		 gotoxy(i,j+2);
		 cout<<"* *";
		 for(k=0;k<6;k++)
		 {
		  gotoxy(i-2,j+k);                       //to displayt marriot
		  cout<<"*";
		  gotoxy(i+4,j+k);
		  cout<<"*";
		  gotoxy(i+6,j+k);
		  cout<<"*";
		  gotoxy(i+9,j+k);
		  cout<<"*";
		  gotoxy(i+11,j+k);
		  cout<<"*";
		  gotoxy(i+16,j+k);
		  cout<<"*";
		  gotoxy(i+23,j+k);
		  cout<<"*";
		  gotoxy(i+27,j+k);
		  cout<<"*";
		  gotoxy(i+31,j+k);
		  cout<<"*";
		  gotoxy(i+35,j+k);
		  cout<<"*";
		 }
		 gotoxy(16,19);
		 cout<<"-------------~press any key to login~-------------";
		 getch();
		 login();
		}
		void main()
		{
			page();
		}