// #include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
// #include<iostream.h>
// #include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <conio.h>
#include <dos.h>
     // void punit (void);
      void intro();
      void deposit(void);
      void addrecord();
      void delrecord();
      void modrecord();
      void disprecord();
      void dispall();
      void withdraw();
      void interest();
      void pin();
      void atm_exit();
      float w,z;
      class account
      {
	    public:

	     int accountno,cls;
	     char name[30],type;
	     float deposit,withdraw;

	    public:

		  account()
		  {
		    deposit=withdraw=0;
		  }
		  int giveaccountno()
		  {
		     return accountno;
		  }
		  void getdata(int mrno)
		  {
		     accountno=mrno+1;
		     cout<<"  ACCOUNT NUMBER        ::  ";
		     cout<<accountno<<" "<<endl;
		     cout<<"  ENTER YOUR NAME       ::  ";
		     gets(name);
		     cout<<" "<<endl;
		     cout<<"  ENTER TYPE OF ACCOUNT SAVING(s)/CURRENT(c)  ::  ";
		     cin>>type;
		     cout<<" "<<endl;
		     cout<<"ENTER INITIAL AMOUNT  :: Rs  ";
		     cin>>deposit;
		     cout<<" "<<endl;
		  }
		 void withdrawal(int m)
		 {
		    cout<<"AMOUNT BEFORE WITHDRAWING::Rs  "<<deposit<<" "<<endl;
		    deposit=deposit-m;
		    cout<<"AMOUNT AFTER WITHDRAWING::Rs  "<<deposit<<endl;
		 }
		void deposital(int m)
		 {
		   cout<<"AMOUNT BEFORE DEPOSIT::Rs  "<<deposit<<" "<<endl;
		   deposit=deposit+m;
		   cout<<"AMOUNT AFTER DEPOSIT ::Rs  "<<deposit<<endl;
		 }
				    void interestal()
				    {
		      float in_amt=0.0,total =0.0;
		      in_amt = in_amt + (deposit * 0.02);
					 cout<<"====================================================="<<endl;
				cout<<" THE INTEREST ON THE PRESENT AMOUNT IN EVERY  MONTH= "<<in_amt<<endl;
		      cout<<endl;
					  total = total +(deposit + in_amt);
					 cout<<"THE ESTIMATED AMOUNT AT THE END OF TH IS MONTH = "<<total<<endl;
		     cout<<" THIS HAS BEEN CALCULATED ON THE BASIS OF PRESENT ACCOUNT BALANCE."<<endl;
		     cout<<endl;
		     cout<<"INTEREST MAY CHANGE DEPENDING UPON DEPOSIT AND WITHDRAW."<<endl;
					cout<<"=========================================================="<<endl;
				     }
		void dispdata()
		 {
			 int scrnt=0;
			 if(scrnt==1)
			 {
			    clrscr();
			    cout<<"DISPLAY ALL MENU . "<<endl;
			    scrnt=0;
			 }
			cout<<"ACCOUNT NUMBER              :: ";
			cout<<accountno<<endl;
			cout<<"NAME OF DEPOSITER             :: ";
			cout<<name<<endl;
			cout<<"TYPE OF ACCOUNT SAVING(s)/CURRENT(c)  ::  ";
			cout<<type<<endl;
			cout<<"BALANCE  :: Rs  ";
			cout<<deposit<<endl;
			scrnt++;
		  }
	    /* void denomination(int m)
		{
			int amt,i,j;
			amt = m;
			while(amt > 0)
			{
				if(i == amt || j== amt)
				break;
			}
			if( amt < v[i])
			{
			   i++;
			   j++;
			}
			else
			{

			}
		}*/
			  void denomination(int amount)
			   {
				 int i;
				 int notes[9] = { 2000, 500, 200, 100, 50, 20, 10, 5, 1 };
				 int noteCounter[9] = { 0 };
				 for (i = 0; i < 9; i++)
		 {
				 if (amount >= notes[i])
			 {
				 noteCounter[i] = amount / notes[i];
				amount = amount - noteCounter[i] * notes[i];
					     }
				    }

				 // Print notes
			       cout<<"DENOMINATION OF NOTES :"<<endl;
			       cout << "Currency Count ->" << endl;
			       cout<<"===================="<<endl;
				for (i = 0; i < 9; i++)
				 {
					if (noteCounter[i] != 0)
					 {
				cout <<"Rs. "<<notes[i] << " : " << noteCounter[i] << endl;
					  }
				 }
			   }
  };

		void main()
		{
		    clrscr();
		    int menuch;
		    time_t my_time = time(NULL);
		    cout<< "    "<<ctime(&my_time)<<"   " ;
		    intro();
			 do
			 {
				clrscr();
			      //	textcolor(14);
			       //	textbackground(1);
				cout<<"           MAIN MENU         "<<endl;
				cout<<"============================="<<endl;
				cout<<"    1. NEW ACCOUNT   "<<endl;
				cout<<endl;
				cout<<"    2. CLOSE AN ACCOUNT "<<endl;
				cout<<endl;
				cout<<"    3. MODIFY AN ACCOUNT  "<<endl;
				cout<<endl;
				cout<<"    4. DISPLAY AN ACCOUNT "<<endl;
				cout<<endl;
				cout<<"    5. DISPLAY ALL RECORDS "<<endl;
				cout<<endl;
				cout<<"    6. WITHDRAW AMOUNT"<<endl;
				cout<<endl;
				cout<<"    7. DEPOSIT AMOUNT"<<endl;
				cout<<endl;
				cout<<"    8. ESTIMATED INTEREST CALCULATION     "<<endl;
				cout<<endl;
				cout<<"    9. CHANGE  PIN"<<endl;
				cout<<endl;
				cout<<"   10. EXIT "<<endl;
				cout<<endl;
				cout<<"    ENTER YOUR CHOICE :: ";
				cin>>menuch;

				switch(menuch)
				 {

				 case 1:
					addrecord();
					break;
				 case 2:
					delrecord();
					break;
				 case 3:
					modrecord();
					break;
				 case 4:
					disprecord();
					break;
				 case 5:
					dispall();
					break;
				 case 6:
					withdraw();
					break;
				 case 7:
					deposit();
					break;
				 case 8:
					interest();
					break;
				 case 9:
					pin();
					break;
				 case 10:
					atm_exit();
					break;
				 }
			 }
			while(menuch!=11);
			getch();
		}

		  //to add a new customer to the bank through atm
		     void addrecord()
			{
			     account obj_1,obj_2;
			     fstream fout;
			     int mrno;
			     fout.open("banking.txt",ios::in|ios::binary);
			     if(!fout)
			     {
				 cout<<"  FILE OPEN ERROR  "<<endl;
				 getch();
				 return;
			     }
			    // cout<<"Enter the account number."<<endl;
			    // cin>>mrno;
			     int recsize=sizeof(account);
			     fout.seekg(0,ios::end);
			     fout.seekg(-1*recsize,ios::cur);
			     fout.read((char*)&obj_1,recsize);
			     mrno=obj_1.giveaccountno();
			     fout.close();
			     clrscr();
			     cout<<"    ADD MENU    "<<endl;
			     cout<<"================"<<endl;
			     obj_2.getdata(mrno);
			     fout.open("banking.txt",ios::app|ios::binary);
			     if(!fout)
			     {
				cout<<"  FILE OPEN ERROR    ";
				getch();
				return;
			     }
			     fout.write((char*)&obj_2,recsize);
			    cout<<"================================"<<endl;
			    cout<<"  ACCOUNT CREATED SUCCESSFULLY  "<<endl;
			    cout<<"   RECORD ADDED TO DATABASE    "<<endl;
			    cout<<endl;
			    cout<<"  Press any key to continue... "<<endl;
			    getch();
			    fout.close();
			 }

			 // basically for bank's purpose ,displays all the records stored in the bank account
			void dispall()
			{
				account obj_3;
				fstream fout;
				int recsize=sizeof(account);
				int countrec=0;
				clrscr();
				cout<<"DISPLAY ALL MENU ";
				fout.open("banking.txt",ios::in);
				if(!fout)
				{
				 cout<<"================================================"<<endl;
				 cout<<"              FILE OPEN ERROR         "<<endl;
				 cout<<" You have created an error while opening the file . "<<endl;
				 cout<<".............Please try again........."<<endl;
				 getch();
				 return;
				}
				while(fout.read((char*)&obj_3,recsize))
			       {
				 obj_3.dispdata();
				 countrec++;
				 cout<<"======================================="<<endl;
				 cout<<"      PRESS ANY KEY FOR NEXT....";
				 getch();
			       }
				clrscr();
				cout<<"         END OF FILE.    "<<endl;
				cout<<" TOTAL  NUMBER  OF  RECORDS..."<<countrec;
				cout<<"======================================="<<endl;
				cout<<"........ Press any key..........";
				getch();
				fout.close();
			       }

			// display's the record of any customer
			void disprecord()
			{
			   account obj_4;
			   fstream fout;
			   int mrno,flag=0;
			   int recsize=sizeof(account);
			   clrscr();
			   cout<<"-------------DISPLAY A RECORD MENU----------"<<endl;
			   cout<<"============================================"<<endl;
			   fout.open("banking.txt",ios::in);
			   if(!fout)
			   {
				cout<<"          FILE OPEN ERROR         "<<endl;
				cout<<".........Please try again........"<<endl;
				getch();
				return;
			   }
			   cout<<"        ENTER  THE ACCOUNT NUMBER   :    "<<endl;
			   cin>>mrno;
			 while(fout.read((char*)&obj_4,recsize))
			{
			  if (obj_4.giveaccountno()==mrno)
			  {
				obj_4.dispdata();
				cout<<" ........Press any key...........";
				flag=1;
				break;
			  }
			}
			 if(flag==0)
			{
				cout<<"     NO SUCH ACCOUNT EXIST      "<<endl;
				cout<<"........Press any key..........";
			}
			getch();
			fout.close();
		 }

	      // for  deleting a certain account of any customer from the respective bank
		void delrecord()
		{
			account obj_5;
			fstream fout,temp;
			int mrno,flag;
			int recsize=sizeof(account);
			clrscr();
			cout<<"-------------CLOSE ACCOUNT MENU------------ "<<endl;
			cout<<"==========================================="<<endl;
			fout.open("banking.txt",ios::in);
			if(!fout)
			 {
				cout<<"       FILE OPEN ERROR        "<<endl;
				 getch();
				return;
			 }
			temp.open("temp.txt",ios::app|ios::binary);
			if(!temp)
			 {
				cout<<"       FILE OPEN ERROR        "<<endl;
				getch();
				 return;
			  }
			cout<<"      ENTER THE ACCOUNT NUMBER : ";
			cin>>mrno;
		  while(fout.read((char*)&obj_5,recsize))
		   {
			 if(obj_5.giveaccountno()==mrno)
			{
				obj_5.dispdata();
				char confirm;
				cout<<"   ARE YOU SURE TO DELETE IT (Y/N).... : ";
				cin>>confirm;
				 if(confirm=='Y'||confirm=='y')
				 {
					fout.read((char*)&obj_5,recsize);
					cout<<"    RECORD DELETED FROM DATABASE    "<<endl;
					cout<<"===================================="<<endl;
					cout<<"............Press any key............";
					flag=1;
					if(!fout)
					 break;
				 }
			flag=1;
			 }
		 temp.write((char*)&obj_5,recsize);
		 }
		 fout.close();
		 temp.close();
		 remove("banking.txt");
		  rename("temp.txt","banking.txt");
		   if(flag==0)
		   {
		     cout<<"      NO SUCH ACCOUNT EXIST     "<<endl;
		     cout<<".........Press any key..........."<<endl;
		   }
		 getch();
	       }
	      void modrecord()
	      {
	       account obj_6;
	       fstream fout;
	       int mrno,flag=0;
	       int recsize=sizeof(account);
	       clrscr();
	       cout<<"             MODIFY RECORD MENU            "<<endl;
	       cout<<"==========================================="<<endl;
	       cout<<endl;
	       fout.open("banking.txt",ios::in|ios::out|ios::binary);
	       if(!fout)
	       {
		   cout<<"      SORRY!!! FILE OPEN ERROR     "<<endl;
		   getch();
		    return;
	       }
		  fout.seekg(ios::beg);
		   cout<<"  ENTER RECORD NUMBER : ";
		    cin>>mrno;
		    cout<<endl;
		 while(fout.read((char*)&obj_6,recsize))
		 {
		   if(obj_6.giveaccountno()==mrno)
		   {
		     clrscr();
		     cout<<"                   MODIFY MENU               "<<endl;
		     cout<<endl;
		     cout<<"=================================="<<endl;
		      cout<<endl;
		      obj_6.dispdata();
		      int tmprno=obj_6.giveaccountno()-1;
		      account obj_7;
		      cout<<"------------ENTER NEW DATA-------------"<<endl;
		      cout<<"========================================"<<endl;
		      obj_7.getdata(tmprno);
		      char confirm;
		      cout<<".......... ARE YOU SURE(Y/N)....."<<endl;
		      cin>>confirm;
		      cout<<endl;
		      cout<<endl;
		      if(confirm=='Y'||confirm=='y')
		      {
			  fout.seekg(-1*recsize,ios::cur);
			  fout.write((char*)&obj_7,recsize);
			  cout<<"================================="<<endl;
			  cout<<"............GREETINGS..............."<<endl;
			  cout<<endl;
			  cout<<"     CHANGES  ARE  SUCCESSFUL    "<<endl;
			  cout<<"         RECORD MODIFIED       "<<endl;
			  cout<<".........Press any key....."<<endl;
			  flag=1;
			  getch();
		      }
		  }
		  if(flag==0)
		  {
		    cout<<"      NO SUCH RECORD EXIST     "<<endl;
		    cout<<".......Press any key..........."<<endl;
		   }
	 }
	fout.close();
      }

      //for withdrawing an amount of money from the account
	void withdraw()
	{
	      account obj_9;
	      fstream fout;
	      int mrno=0;
	      int recsize=sizeof(account);
	      clrscr();
	      cout<<"-----------------WITHDRAWAL MENU--------------"<<endl;
	      cout<<"==============================================="<<endl;
	      fout.open("banking.txt",ios::in|ios::out|ios::binary);
	      if(!fout)
	      {
		cout<<" ......SORRY!!!! FILE OPEN ERROR.......  "<<endl;
		cout<<"=========================================="<<endl;
		getch();
		return;
	      }
		fout.seekg(ios::beg);
	     cout<<endl;
	     cout<<"  ENTER ACCOUNT NUMBER : ";
	     cin>>mrno;
	     while(fout.read((char*)&obj_9,recsize))
	     {
	       if(obj_9.giveaccountno()==mrno)
	       {
		 clrscr();
		 cout<<"  ENTER THE AMOUNT TO BE WITHDRAWED : Rs ";
		 cin>>w;
		 obj_9.withdrawal(w);
		 obj_9.denomination(w);
		 fout.seekg(-1*recsize,ios::cur);
		 fout.write((char*)&obj_9,recsize);
	       }
	     }
	     getch();
	 fout.close();
  }
	void interest()
	{
	      account obj_10;
	      fstream fout;
	      int mrno=0;
	      int recsize=sizeof(account);
	      clrscr();
	      cout<<"-----------------FINDING INTEREST (ESTIMATED )--------------"<<endl;
			cout<<endl;
	      cout<<"==============================================="<<endl;
	      fout.open("banking.txt",ios::in|ios::out|ios::binary);
	      if(!fout)
	      {
		cout<<" ......SORRY!!!! FILE OPEN ERROR.......  "<<endl;
		cout<<"=========================================="<<endl;
		getch();
		return;
	      }
	     fout.seekg(ios::beg);
	     cout<<endl;
	     cout<<"  ENTER ACCOUNT NUMBER : ";
	     cin>>mrno;
	     while(fout.read((char*)&obj_10,recsize))
	     {
	       if(obj_10.giveaccountno()==mrno)
	       {
		 clrscr();

		 obj_10.interestal();
		 fout.seekg(-1*recsize,ios::cur);
		 fout.write((char*)&obj_10,recsize);
	       }
	     }
	     getch();
	 fout.close();
  }
 /* void punit(void)
    {
    int gd=5, gm, errorcode;
    int col,i=0,j;
    initgraph(&gd, &gm, "c:\tc\bgi");
      while(5*i<=700)
      {
		 setbkcolor(1);
		 setcolor(3);
		 rectangle(0+5*i,0+5*i,getmaxx()-5*i,getmaxy()-5*i);
		 i++;
      }
      i=0;
      setcolor(4);
      settextstyle(1,0,6);

      sleep(5);
      cleardevice();
		  while(5*i<=700)
		 {
		   setbkcolor(1);
		   setcolor(3);
		   circle(getmaxx()/2,getmaxy()/2,i*5);
		   i++;
		 }
		 setcolor(4);
		 settextstyle(0,0,6);
		 outtextxy(190 ,getmaxy()/2-85,"PROJECT");
		 outtextxy(300,getmaxy()/2-25,"ON");

		 outtextxy(190,getmaxy()/2+25,"BANKING");
		 sleep(3);
		 i=0;
		while(i<=130)
		{
		     setbkcolor(1);
		     setcolor(3);
		     line(i*3,0,i*3,getmaxy());
		     line(getmaxx()-i*3,0,getmaxx()-i*3,getmaxy());
		     i++;
		}
		sleep(1);
		i=getmaxy();
		while(i>0)
		{
			line(getmaxx()/2,getmaxy(),getmaxx(),i-=10);
			delay(10);
		}
		i=getmaxx();
		while(i>0)
		{
		   line(getmaxx()/2,getmaxy(),i-=10,0);
		   delay(10);
		}
	       i=0;
	       while(i<getmaxy())
	       {
		   line(getmaxx()/2,getmaxy(),0,i+=10);
		   delay(10);
	       }
	   getch();
	   closegraph();
	   flushall();
   }*/

   // for giving the introduction to the main screen
	void intro(void)
	{
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<<"==============================================="<<endl;
		cout<<endl;
		cout<<".............WELCOME TO THE NINE'S ATM .............."<<endl;
		cout<<endl;
		cout<<"==============================================="<<endl;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<<endl;
		getch();
	}

	void deposit(void)
	{
	account obj_10;
	fstream fout;
	int mrno=0;
	int recsize=sizeof(account);
	clrscr();
	cout<<"------------------DEPOSITAL MENU-------------------"<<endl;
	cout<<"====================================================="<<endl;
	fout.open("banking.txt",ios::in|ios::out|ios::binary);
	if(!fout)
	{
	cout<<"             Sorry !!! FILE OPEN ERROR        "<<endl;
	cout<<".................Please try again............."<<endl;
	 getch();
	 return;
	}
	fout.seekg(ios::beg);
	cout<<"   ENTER ACCOUNT NUMBER  : ";
	cin>>mrno;
	while(fout.read((char*)&obj_10,recsize))
	{
	   if(obj_10.giveaccountno()==mrno)
	   {
	     clrscr();
	     cout<<"  ENTER THE AMOUNT TO BE DEPOSITED ::Rs ";
	     cin>>w;
	     obj_10.deposital(w);
	     fout.seekg(-1*recsize,ios::cur);
	     fout.write((char*)&obj_10,recsize);
	   }
	}
	getch();
	fout.close();
   }

   // for changing the pin of the account of the customer
   void pin()
   {
	clrscr();
	int p1,p2;
	cout<<"Enter your new pin number ."<<endl;
	cin>>p1;
	cout<<"Confirm your new pin . "<<endl;
	cin>>p2;
	if(p1 == p2)
	{
	   cout<<"       GREETINGS       ."<<endl;
	   cout<<"PIN CHANGED SUCCESSFULLY."<<endl;
	}
	else
	{
	   cout<<"  FILE  ERROR  OCCURRED.   "<<endl;
	   cout<<"   PLEASE  TRY  AGAIN.        "<<endl;
	}
	getch();
   }

   //for exiting from the atm finally
   void atm_exit()
   {
	clrscr();
	int k;
	cout<<"==============================================="<<endl;
	cout<<"........THANK YOU FOR BANKING WITH US.........."<<endl;
	cout<<endl;
	cout<<"..........BROUGHT TO YOU BY GROUP 3............." <<endl;
	cout<<"================================================"<<endl;
	cout<<endl;
	cout<<"..........Press 0 to exit..........."<<endl;
	cin>>k;
	if(k == 0)
	 exit(1);
	getch();
   }