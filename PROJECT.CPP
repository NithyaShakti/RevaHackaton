#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<iomanip.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
void main();
void first();
void admin();

class customer
{
	public:
	  int cid;
	  char cname[20],cadd[50];
	  long long ph;
	  void cinput();
	  void cdisplay();
	  int retcid();
	  long retcph();
};

void customer::cinput()
{
	cout<<"\n\n\tEnter Customer ID           :";cin>>cid;
	cout<<"\n\n\tEnter Customer Name         :";gets(cname);
	cout<<"\n\n\tEnter Customer Address      :";gets(cadd);
	cout<<"\n\n\tEnter Customer Phone Number :";cin>>ph;
}

void customer::cdisplay()
{
   cout<<cid<<"            "<<cname<<"             "<<cadd<<"             "<<ph<<endl;
}

int customer::retcid()
{  return cid;}

long customer::retcph()
{ return ph;}

void cid_modify()
{  ifstream in;ofstream out;cleardevice(); gotoxy(40,3);
   in.open("customer.dat",ios::binary);
   out.open("t.dat",ios::binary);
   customer c,a;
   int x;
   cout<<"\n\tEnter Customer ID:";
   cin>>x;
   while(in.read((char*)&c,sizeof(c)))
   {
	  if(c.cid==x)
	   {
		cleardevice();
		cout<<"\n\tEnter New Details of Customer :";
		a.cinput();
		out.write((char*)&a,sizeof(a));
	   }
	  else
	  out.write((char*)&c,sizeof(c));
   }
   in.close();
   out.close();
   remove("customer.dat");
   rename("t.dat","customer.dat");
}

void cph_modify()
{
   ifstream in;ofstream out;cleardevice(); gotoxy(40,3);
   in.open("customer.dat",ios::binary);
   out.open("t.dat",ios::binary);
   customer c,a;
   long x;
   cleardevice();
   cout<<"\n\n\tEnter Phone Number Of Customer To Be Modified :";
   cin>>x;
   while(in.read((char*)&c,sizeof(c)))
   {
	  if(c.ph==x)
	  {
		cout<<"\n\n\tEnter New Details of Customer :";
		a.cinput();
		out.write((char*)&a,sizeof(a));
	  }
	  else
	  out.write((char*)&c,sizeof(c));
   }
   in.close();
   out.close();
   remove("customer.dat");
   rename("t.dat","customer.dat");
}
void cust_add()
{
   ofstream out;
   cleardevice();
   gotoxy(40,3);
   out.open("customer.dat",ios::binary|ios::app);
   customer c;
   cout<<"\n\n\n\tEnter Customer Details";
   c.cinput();
   out.write((char*)&c,sizeof(c));
   out.close();
   cout<<"\n\n\t\tYou Are A Member of Jaivika Plants Experts\n\n";
}


void cid_del()
{
   ifstream in;
   cleardevice();
   gotoxy(40,3);
   ofstream out;
   out.open("t.dat",ios::binary);
   in.open("customer.dat",ios::binary);
   int x;
   cout<<"\n\n\tEnter Customer ID:";cin>>x;
   customer c;
   while(in.read((char *)&c,sizeof(c)))
   {
	  if(c.cid!=x)
		   out.write((char*)&c,sizeof(c));
   }
   in.close();
   out.close();
   remove("customer.dat");
   rename("t.dat","customer.dat");
   cout<<"\n\n\t Deleted successfully...";
}

void cph_del()
{  int q=0;
   ifstream in;
   cleardevice();
   gotoxy(40,3);
   ofstream out;
   out.open("t.dat",ios::binary);
   in.open("customer.dat",ios::binary);
   long long x;
   cout<<"\n\n\tEnter Phone Number Of Customer To Be Deleted :";
   cin>>x;
   customer c;
   while(in.read((char *)&c,sizeof(c)))
   {   if(c.ph==x)
		  q=1;
	  if(c.ph!=x)
		   out.write((char*)&c,sizeof(c));
   }
   in.close();
   out.close();
   remove("customer.dat");
   rename("t.dat","customer.dat");
   if(q==1)
		 cout<<"\n\n\tDeleted successfully....";
   else
		 cout<<"\n\n\tRecord not found....";
}

void custdisp()
{
   ifstream in;cleardevice(); gotoxy(40,3);
   in.open("customer.dat",ios::binary);
   customer c;
   int x=0;
   cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   cout<<"\n\nID          NAME              ADDRESS            PHONE NUMBER"<<endl;
   cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   while(in.read((char*)&c,sizeof(c)))
   {
	c.cdisplay();
	if (x%3==0)
	   getch();
   }
   in.close();
}

void cc()
{
   int opt;
   do
   {
	  cleardevice();gotoxy(40,3);
	  cout<<"\n\n\t\t\t\t Customer Details \n\n";
	  cout<<"\n\n\t\t1.Insert\n\n\t\t2.Delete id\n\n\t\t3.Modify\n\n\t\t4.Delete according to phone number\n\n\t\t5.Modify according to phone number\n\n\t\t6.Display all \n\n\t\t7.Return to Menu\n\n\t\tEnter your Choice:";
	  cin>>opt;
	  cleardevice();
	  switch(opt)
	  {
		case 1:cust_add();break;
		case 2:cid_del();break;
		case 3:cid_modify();break;
		case 4:cph_del();break;
		case 5:cph_modify();break;
		case 6:custdisp();break;
		case 7:first(); break;
	  }
	  getch();
   }while(opt<7);
}

class plant
{
   public:
	 int pid,qty;
	 char pname[50],sname[50],type[50],ps;
	 double amount;
	 void plantinput();
	 void plantdisplay();
	 void draw(int n)
	 { qty=qty-n;}
	 void deposit(int n)
	 {qty=qty+n;}
	 void ptype()
	 {
	   cout<<"\n\t\t\t1.Flowering House Plant \n";
	   cout<<"\t\t\t2.Common House Plant\n";
	   cout<<"\t\t\t3.Easy to Grow and Low Light House Plant \n";
	   cout<<"\t\t\t4.Selection of Foliago House Plant\n";
	   cout<<"\t\t\t5.Indoor Palm Plant \n";
	   cout<<"\t\t\t6.Hanging Basket Plant \n";
	   cout<<"\t\t\t7.Climbers and Trailing Plants\n";
	   cout<<"\t\t\t8.Selection of Bulb type House Plant\n";
	   cout<<"\t\t\t9.Christmas Plants\n";
	   cout<<"\t\t\t10.Unusual House Plants\n";
	   cout<<"\t\t\t11.Selection of Office Plant\n";
	   cout<<"\t\t\t12.Succulent House Plant\n";
	   cout<<"\t\t\t13.Easiest of Ferns to grow as House plant\n";
	   cout<<"\t\t\t14.Selection of Living Stones plant\n";
	   cout<<"\t\t\t15.Large House Plant\n";
	 }
	 char *rettype(int a);
};

class bill
{
   public:
	 int billno,pid,qty,maint,cid,mm,dd,yy;
	 char pname[30],sname[30],type[30],ps,cname[30],cadd[30];
	 double amount,total;
	 long ph;
	 void billcustdisplay()
	 {
		cout<<"Name          : "<<cname<< "                            ID"<<cid<<endl;
		cout<<"Address       : "<<cadd<<endl;
		cout<<"Phone number  : "<<ph<<endl;
	 }
	 void billplantdisplay()
	 {
		cout<<pid<<"  "<<pname<<"  "<<sname<<"  "<<type<<"   "<<amount<<"   "<<qty<<"   "<<ps<<endl;
	 }
};

char* plant:: rettype(int a)
{
   switch(a)
   {
	  case 1:return "Flowering House Plant";
	  case 2:return "Common House Plant";
	  case 3:return "Easy to Grow and Low Light House Plant";
	  case 4:return "Selection of Foliago House Plant";
	  case 5:return "Indoor Palm Plant";
	  case 6:return "Hanging Basket Plant";
	  case 7:return "Climbers and Trailing Plants";
	  case 8:return "Selection of Bulb type House Plant";
	  case 9:return "Christmas Plants";
	  case 10:return "Unusual House Plants";
	  case 11:return "Selection of Office Plant";
	  case 12:return "Succulent House Plant";
	  case 13:return "Easiest of Ferns to grow as House plant";
	  case 14:return "Selection of Living Stones plant";
	  case 15:return "Large House Plant";
   }
}

void plant::plantinput()
{
   int n;
   cout<<"\n\n Enter pid                : ";
   cin>>pid;
   cout<<"\n\n Enter plant name         : ";
   gets(pname);
   cout<<"\n\n Enter scienfitic name    : ";
   gets(sname);
   cout<<"\n\n Enter type               : ";
   ptype();
   cin>>n;
   strcpy(type,rettype(n));
   cout<<"\n\n Enter Quantity           : ";
   cin>>qty;
   cout<<"\n\n Enter Amount             : ";
   cin>>amount;
   cout<<"\n\n Plant or Seed (p/s) : ";
   cin>>ps;
}

int globalx=0;

void plant::plantdisplay()
{
   globalx=globalx+1;
   cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   cout<<"\t\tPlant Type:"<<type<<"\n\n\tPlantID:"<<pid<<"\t\tPlantname:"<<pname<<"\t\tScientificName:"<<sname<<"\n\tQuantity:"<<qty<<"\t\tAmount:"<<amount<<"\t\tP/S:"<<ps<<endl;
   cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"  ;
   if(globalx%3==0)
	  getch();
}

void pcreate()
{
   cleardevice();
   gotoxy(40,3);
   ofstream out;
   out.open("plant.dat",ios::binary|ios::out|ios::app);
   cleardevice();
   plant p;
   cout<<"\n\tEnter Details of the Plant \n";
   p.plantinput();
   out.write((char *)&p,sizeof(p));
   out.close();
}

void pdisplay()
{
   ifstream in; cleardevice(); gotoxy(40,3);
   in.open("plant.dat", ios::binary);
   plant p;
   while(in.read((char*)&p,sizeof(p)))
   {
	   p.plantdisplay();
   }
   in.close();
   getch();
}

void pmodify()
{
   int p;
   cleardevice();
   gotoxy(40,3);
   cout<<"\n\n Enter Plant ID  : ";
   cin>>p;
   ifstream in;
   ofstream out;
   plant pl;
   in.open("plant.dat",ios::binary);
   out.open("temp.dat",ios::binary);
   while(in.read((char*)&pl,sizeof(pl)))
   {
	 if(p==pl.pid)
	 {
	   pl.plantinput();
	   out.write((char *)&pl,sizeof(pl));
	 }
	 else
	   out.write((char *)&pl,sizeof(pl));
   }
   in.close();
   out.close();
   remove("plant.dat");
   rename("temp.dat","plant.dat");
}

void pdelete()
{
   int p;
   cleardevice();
   gotoxy(40,3);
   cout<<"\n\n Enter Plant ID : ";
   cin>>p;
   ifstream in;
   ofstream out;
   plant pl;
   in.open("plant.dat",ios::binary);
   out.open("temp.dat",ios::binary);
   while(in.read((char*)&pl,sizeof(pl)))
   {
	 if(p!=pl.pid)
	 out.write((char *)&pl,sizeof(pl));
   }
   in.close();
   out.close();
   remove("plant.dat");
   rename("temp.dat","plant.dat");
}

void pp()
{
   cleardevice();
   gotoxy(40,3);
   int opt;
   do
   {
	 cleardevice();
	 gotoxy(40,3);
	 cout<<" \n\n\t\t\tP L A N T \n";
	 cout<<"\n\t\t1. New Arrival\n";
	 cout<<"\n\t\t2. Change \n";
	 cout<<"\n\t\t3. Delete\n";
	 cout<<"\n\t\t4. Display\n";
	 cout<<"\n\t\t5. Way to Menu\n";
	 cout<<"\n\t\tEnter your option : ";
	 gotoxy(60,26);
	 cin>>opt;
	 switch(opt)
	 {
	   case 1:pcreate();
			  break;
	   case 2:pmodify();
			  break;
	   case 3:pdelete();
			  break;
	   case 4:pdisplay();
			  break;
	   case 5:first();
	 }
	 getch();
   }while(opt<=4);
}

void indoor()
{
   cleardevice();
   gotoxy(40,3);
   plant p1;
   bill b1;
   ifstream in;
   in.open("bill.dat",ios::binary);
   in.seekg(0,ios::end);
   int n=in.tellg()/sizeof(b1);
   in.close();
   ofstream out;
   out.open("bill.dat",ios::binary);
   int ccid;
   cleardevice();
   customer c1;
   char mem;
   ifstream in1;
   ifstream in2;
   in1.open("customer.dat",ios::binary|ios::in);
   in2.open("plant.dat",ios::binary|ios::in);
   b1.billno=n+1;
   cout<<"\n\n \t\tAre you be member of Jaivika Plants Experts(y/n)?";
   cin>>mem;
   if (mem=='n')
   {
	 cout<<"\n\n\tAdd yourself as a member...!!";
	 getch();
	 first();
   }
   if (mem=='y')
   {
	  int f=-1;
	  cleardevice();
	  cout<<"\n\n\t\tEnter Customer Id :";
	  cin>>ccid;
	  while(in1.read((char *)&c1,sizeof(c1)))
	  {
		 if(ccid==c1.cid)
		 {
		   f=1;
		   b1.cid=c1.cid;
		   strcpy(b1.cname, c1.cname);
		   strcpy(b1.cadd,c1.cadd);
		   b1.ph=c1.ph;
		   c1.cdisplay();
		  }
	  }
	  if(f==-1)
	  {
		cout<<"\n\n\n\n\t\tInvalid Id Number ... Add yourself as a member...!";
		getch();
		first();
	  }
	  in1.close();
	  loop:
	  cout<<"\n\n Select any one  : ";
	  p1.ptype();
	  int tno;
	  struct date d;
	  getdate(&d);
	  b1.dd=d.da_day;
	  b1.mm=d.da_mon;
	  b1.yy=d.da_year;
	  cout<<"\nEnter type number to purchase   : \n";
	  cin>>tno;
	  int qty;
	  while(in2.read((char *)&p1,sizeof(p1)))
	  {
		if(strcmp(p1.rettype(tno),p1.type)==0 )
		{ p1.plantdisplay();}
	  }
	  in2.close();
	  ifstream i;
	  i.open("plant.dat",ios::binary);
	  int ppp;
	  cout<<"\n\n Enter Plant id : ";
	  cin>>ppp;
	  while(i.read((char *)&p1,sizeof(p1)))
	  {
		 if(ppp==p1.pid)
		 {
		  p1.plantdisplay();
		  cout<<"\n\n Enter Quantity :";
		  cin>>qty;
		  p1.draw(qty);
		  b1.pid=p1.pid;
		  strcpy(b1.pname,p1.pname);
		  strcpy(b1.sname, p1.sname);
		  strcpy(b1.type,p1.type);
		  b1.amount=p1.amount;
		  b1.qty=qty;
		  b1.ps=p1.ps;
		  b1.total=qty*p1.amount;
		  char m;
		  cout<<"\n\n Do you wish to accept maintenance (y/n) : ";
		  cin>>m;
		  if(m=='y')
		  { float t=p1.amount*10/100; b1.total=t;}
		  }
	  }
	  char y;
	  out.write((char *)&b1,sizeof(b1));
	  i.close();
	  ifstream o;
	  ofstream t;
	  t.open("plantqty.dat",ios::binary);
	  o.open("plant.dat",ios::binary|ios::out|ios::in);
	  while(o.read((char *)&p1,sizeof(p1)))
	  {
		if(ppp==p1.pid)
		{
		  p1.draw(qty);
		  t.write((char *)&p1,sizeof(p1));
		}
		else
		   t.write((char *)&p1,sizeof(p1));
	  }
	  o.close();
	  t.close();
	  remove("plant.dat");
	  rename("plantqty.dat","plant.dat");
	  cout<<"\n\n Do you wish to purchase any more (y/n) : ";
	  cin>>y;
	  if (y=='y')
		 goto loop;
	  else
	  {
	   out.close();
	   bill b2,b3;
	   ifstream in4;
	   in4.open("bill.dat",ios::binary);
	   ofstream out1,out2;
	   out2.open("temp.dat",ios::binary);
	   out1.open("billfinal.dat",ios::binary);
	   cout<<"\n\n Items which are purchased :\n";
	   char copt;
	   double amt=0;
	   while(in4.read((char*)&b1,sizeof(b1)))
	   {
		if(n+1==b1.billno)
		 {
		   b2=b1;
		   b1.billplantdisplay();
		   cout<<"\n\t\t\t\t  Wish to confirm  (y/n) :";
		   cin>>copt;
		   if (copt=='y')
		   {
			 out2.write((char *)&b1, sizeof(b1));
			 out1.write((char *)&b1,sizeof(b1));
			 amt=amt+b1.total;
		   }
		   else
			 {cout<<"\n\n\n\t\t\t Item cancelled  ";
			 getch();
			 }

		}
		out1.close();
		out2.close();
		in4.close();
		in1.close();
		remove("bill.dat");
		cleardevice();
		if(copt=='n')
			 { p1.deposit(qty);
			  indoor();
			  }
		cout<<"Preparation of bill\n\n";
		ifstream out3;
		out3.open("temp.dat",ios::binary);
		out3.read((char *)&b1,sizeof(b1));
		b1.billcustdisplay();
		cout<<"\n\t\t\t\t Date : "<<b1.dd<<"/"<<b1.mm<<"/"<<b1.yy<<endl;
		out3.seekg(0,ios::beg);
		while(out3.read((char *)&b1, sizeof(b1)))
		{
		  b1.billplantdisplay();
		}
		cout<<"\n\n\n\t\tTotal Amount ="<<amt;
		out3.close();
	   }
	 }
   }
}

class kit
{
   public:
	 int itemid;
	 char itemname[20];
	 float rate;
	 void insert();
	 int iid()
	 { return itemid; }
	 void display();
};

void kit::insert()
{
   cout<<"\n\n\t\tEnter Item ID   :";
   cin>>itemid;
   cout<<"\n\n\t\tEnter Item Name :";
   gets(itemname);
   cout<<"\n\n\t\tEnter Rate      :";
   cin>>rate;
}

void kit::display()
{
   cout<<"\n\n\t\tItem ID       :"<<itemid;
   cout<<"\n\n\t\tRate          :"<<rate;
   cout<<"\n\n\t\tItem Name     :";
   puts(itemname);
}

void create()
{
   char ch;
   cleardevice();
   gotoxy(40,3);
   ofstream out;
   out.open("kit.dat",ios::binary|ios::app);
   kit k;
   do
   {
	  cleardevice();
	  gotoxy(40,3);
	  k.insert();
	  out.write((char *)&k, sizeof(k));
	  cout<<"\n\nDo you want to enter enter more tools?(y/n): ";
	  cin>>ch;
   }while(ch=='y');
   out.close();
}

void displaykit ()
{
   cleardevice();
   gotoxy(40,3);
   ifstream in;
   in.open("kit.dat",ios::binary|ios::in);
   kit k;
   gotoxy(0,0);
   cout<<"                  K I T   I T E M S \n";
   while(in.read((char*)&k,sizeof (k)))
   {
	k.display();
   }
}

void remove()
{
   int q=0;
   cleardevice();
   gotoxy(40,3);
   ifstream in;
   ofstream out;
   in.open("kit.dat",ios::binary||ios::in);
   out.open("temp.dat",ios::binary||ios::out);
   int c;
   kit k;
   cout<<"\n\n\t\tEnter The ItemID To Be Deleted:";
   cin>>c;
   while(in.read((char *)&k,sizeof(k)))
   {
	if(c==k.iid())
		q=1;
	if(c!=k.iid())
	out.write((char*)&k,sizeof(k));
   }
   if(q==1)
	  cout<<"\n\n\tDeleted Successfully...";
   else
	  cout<<"\n\n\tRecord Not Found...";
   out.close();
   in.close();
   remove("kit.dat");
   rename("temp.dat","kit.dat");
}

class kitbill
{
   public:
	  int itemid,cid;
	  float rate;
	  char itemname[20],cname[20],cadd[50];
	  long ph;
	  void display()
	  {
	  cout<<" Item id    "<<itemid<<endl;
	  cout<<" Rate       "<<rate<<endl;
	  cout<<" Itemname   "<<itemname<<endl;
	  cout<<" cname      "<<cname<<endl;
	  cout<<" Address    "<<cadd<<endl;
	  cout<<"Phone number"<<ph<<endl<<endl;
	  }
};

void kititem()
{
   cleardevice();
   gotoxy(40,3);
   int opt;
   do{
   cleardevice();
   cout<<"\n\n\t\t\t1. Add New Items";
   cout<<"\n\n\t\t\t2. Delete";
   cout<<"\n\n\t\t\t3. Display";
   cout<<"\n\n\t\t\t4. Back to Main Menu";
   cout<<"\n\n\tEnter Your option:";
   cin>>opt;
   switch(opt)
   {
	 case 1:create();
			break;
	 case 2:remove();
			break;
	 case 3:displaykit();
			break;
	 case 4:first();
   }
   getch();
  }while(opt<5);

}

void kit1()
{
   cleardevice();
   gotoxy(40,3);
   int opt;
   ofstream ki;
   ki.open("kitbill.dat",ios::binary);
   char ch;
   cout<<"\n\n\t\t\t\tGreen Kit Items";
   cout<<"\n\n\t\t 1. Whole Set Kit ";
   cout<<"\n\n\t\t 2. Purchase Kit Items";
   cout<<"\n\n\t\t 3. Back to Main Menu";
   cout<<"\n\n\t\tEnter Your Option :";
   cin>>opt;
   cout<<"\n\t\t\tAre you a member(y/n) ? ";
   cin>>ch;
   if (ch=='n')
   {
	 cout<<"\n\n\t\t\tAdd yourself as member ...";
	 first();
   }
   else
   {
	 int custid;
	 cout<<"\n\n \t\t\tEnter Customer ID :";
	 cin>>custid;
	 ifstream in;
	 customer c;
	 kitbill k;
	 in.open("customer.dat",ios::binary);
	 int flag=-1;
	 while(in.read((char *)&c,sizeof(c)))
	 {
	   if(custid==c.cid)
	   {
		 flag=1;
		 k.cid=c.cid;
		 strcpy(k.cname,c.cname);
		 strcpy(k.cadd, c.cadd);
		 k.ph=c.ph;
	   }
	}
   if(flag==-1)
   {
	 cout<<"\n\t\tNot found...!!";
	 first();
   }
   in.close();
   char kch;
   float krate=9999;
   if(opt==1)
   {
	  cout<<"\n\n\tKit Rate is "<<krate;
	  k.itemid=10001;
	  strcpy(k.itemname,"Whole Green kit");
	  k.rate=krate;
	  cout<<"\n\n\tWish to confirm (y/n)? ";
	  cin>>kch;
	  if(kch=='y')
		 ki.write((char *)&k, sizeof(k));
	  else
		 cout<<"\n\n\tItem cancelled....";
	  ki.close();
	}
   else if(opt==2)
   {
	  kit k;
	  ifstream in;
	  ofstream out;
	  out.open("kitbill.dat",ios::binary);
	  kitbill ki;
	  loop:
	  in.open("kit.dat",ios::binary|ios::in);
	  while(in.read((char *)&k, sizeof(k)))
	  {
	   k.display();
	  }
   in.close();

	  int id;
	  cout<<"\n\n\tEnter Kit item id   :";
	  cin>>id;
	  in.open("kit.dat",ios::binary|ios::in);
	  int f1=-1;
	  while(in.read((char *)&k, sizeof(k)))
	  {
		if(id==k.itemid)
		{
		  f1=1;
		  ki.itemid=k.itemid;
		  strcpy(ki.itemname, k.itemname);
		  ki.rate=k.rate;
		}
	  }
	  in.close();
	  float t=0;
	  if(f1==1)
	  {
		char mop;
		out.write((char*)&ki,sizeof(ki));
		k.display();
		t=t+ki.rate;
		cout<<"\n\n\t Total Amount   : "<<t;
		cout<<"\n\n \t~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		getch();
		cout<<"\n\n\tWish to purchase any more (y/n):";
		cin>>mop;
		if(mop=='y')
			goto loop;
		out.close();
	   }
	   else
	   cout<<"\n\n\tWrong input..!!";
	  }
   }



}

void construction()
{
   cleardevice();
   gotoxy(40,3);
   ifstream in;
   char ch;
   in.open("customer.dat",ios::binary);
   fstream out;
   out.open("kitbill.dat",ios::binary);
   cout<<"\n\n\t\t Are You A Member(y/n)  :";
   cin>>ch;
   if (ch=='n')
   {
	  cout<<"\n\n\t\tAdd yourself as member";
	  getch();
	  first();
   }
   else
   {
	  int custid;
	  cout<<"\n\n\t Enter customer ID :";
	  cin>>custid;
	  ifstream in;
	  customer c;
	  kitbill k;
	  in.open("customer.dat",ios::binary);
	  int flag=-1;
	  while(in.read((char *)&c,sizeof(c)))
	  {
		if(custid==c.cid)
		{
		  flag=1;
		  k.cid=c.cid;
		  strcpy(k.cname,c.cname);
		  strcpy(k.cadd, c.cadd);
		  k.ph=c.ph;
		 }
	  }
	  if(flag==-1)
	  {
		 cout<<"\n\tNot found..!!";
		 getch();
		 first();
	  }
	  in.close();
	  char kch;
	  float area;
	  float krate=400;
	  cout<<"\n\n\t\t Rate per sqft :" <<krate;
	  k.itemid=10002;
	  strcpy(k.itemname,"Construction for  Green House");
	  cout<<"\n\n\t\t\tEnter Area : ";
	  cin>>area;
	  k.rate=krate*area;
	  cout<<"\n\nAmount                :  "<<k.rate;
	  cout<<"\n\nWish to confirm (y/n) ? ";
	  cin>>kch;
	  if(kch=='y')
		  out.write((char *)&k, sizeof(k));
	  else
		  cout<<"\n\n\t Item cancelled..";
		  out.close();
	  getch();
   }
}

void maintenance()
{
   int opt;
   cleardevice();
   gotoxy(40,3);
   cout<<"\n\n\n\t\t\tMaintenace \n";
   cout<<"\n\n\t1. Garden \n";
   cout<<"\n\n\t2. Indoor plants \n";
   cout<<"\n\n\t Enter your option : ";
   cin>>opt;
   if(opt<=2)
   {
   ifstream in;
   in.open("customer.dat",ios::binary);

   char ch;
   cout<<"\n\n\tAre you a member (y/n)  : ";
   cin>>ch;

   if (ch=='n')
   {
	 cout<<"\n\n\tAdd yourself as member ...";
	 first();
   }
   else
   {
	 int custid;
	 cout<<"\n\n\t Enter customer ID  : ";
	 cin>>custid;
	 ifstream in;
	 customer c;
	 kitbill k;
	 ofstream ki;
	 ki.open("kitbill.dat",ios::binary);
	 in.open("customer.dat",ios::binary);
	 int flag=-1;
	 while(in.read((char *)&c,sizeof(c)))
	 {
	   if(custid==c.cid)
	   {
		 flag=1;
		 k.cid=c.cid;
		 strcpy(k.cname,c.cname);
		 strcpy(k.cadd, c.cadd);
		 k.ph=c.ph;
	   }
	 }
	 if(flag==-1)
	 {
	   cout<<"\n\n\t Not found...!!";
	   first();
	 }
	 in.close();
	 if(opt==1)
	 {
		char kch;
		float area;
		float krate=200;
		cout<<" Rate per sqft  : " <<krate;
		k.itemid=10003;
		strcpy(k.itemname,"Garden Maintenance");
		cout<<"\n\n\t\t\tEnter Area :";
		cin>>area;
		k.rate=krate*area;
		cout<<"\n\t\tWish to confirm (y/n) ?";
		cin>>kch;
		if(kch=='y')
		{
		   ki.write((char *)&k, sizeof(k));
		   cout<<"\n\n\n\t\t Amount    :"<<k.rate;
		   getch();
		}
		else
		   cout<<"\n\t\tItem cancelled..!!";
		   ki.close();
	 }
	 else if(opt==2)
	 {
		char kch;
		float area,krate=300;
		cout<<"\n\t\t\t Rate per sqft : " <<krate;
		k.itemid=10004;
		strcpy(k.itemname,"Indoor Plant Maintenance");
		cout<<"\n\n\tEnter Area :";
		cin>>area;
		k.rate=krate*area;
		cout<<"\n\nWish to confirm (y/n) ? ";
		cin>>kch;
		if(kch=='y')
		{
			ki.write((char *)&k, sizeof(k));
			cout<<"\n\n\t\t Amount :"<<k.rate;
		}
	   else
			cout<<"\n\n\t\tItem cancelled..";
	   ki.close();
  } }
  }
}

void Greenkit()
{
   int opt;
   cleardevice();
   do
   {
	  gotoxy(40,3);
	  cout<<"\n\n\t\t\t\tMENU";
	  cout<<"\n\n\t1.Construction";
	  cout<<"\n\n\t2.Kit";
	  cout<<"\n\n\t3.House Plants";
	  cout<<"\n\n\t4.Maintenance";
	  cout<<"\n\n\t5.Back to Main menu\n";
	  cout<<"\n\nEnter your choice :";
	  cin>>opt;
	  switch(opt)
	  {
		 case 1:construction();    getch();  cleardevice();
				break;
		 case 2:kit1();            getch();  cleardevice();
				break;
		 case 3:indoor();          getch();  cleardevice();
				break;
		 case 4:maintenance();     getch();  cleardevice();
				break;
		 case 5:first();           getch();  cleardevice();
	  }
	}while(opt<=5);
	getch();
}

void searchby_pid()
{
   plant p;
   ifstream in;
   in.open("plant.dat",ios::binary);
   int x;int flag=-1;
   cout<<"\n\tEnter The Plant ID :";cin>>x;
   while(in.read((char*)&p,sizeof(p)))
   { if(x==p.pid)
	  { p.plantdisplay();flag=1;}
   }
   if(flag==-1)
	  cout<<"\n\tPlant Doesn't Exist..!!";
   in.close();
}

void searchby_sname()
{
   plant p;
   ifstream in;
   in.open("plant.dat",ios::binary);
   char x[50] ;int flag=-1;
   cout<<"\nEnter The Scientific Plant Name :";gets(x);
   while(in.read((char*)&p,sizeof(p)))
   { if(strcmp(x,p.sname)==0)
		{ p.plantdisplay();flag=1;}
   }
   if(flag==-1)
	  cout<<"\n\tPLant Doesn't Exist..!!";
   in.close();
}

void searchby_pname()
{
   plant p;
   ifstream in;
   in.open("plant.dat",ios::binary);
   char x[50];int flag=-1;
   cout<<"\n\tEnter The Plant Name :";gets(x);
   while(in.read((char*)&p,sizeof(p)))
   { if(strcmp(x,p.pname)==0)
		{ p.plantdisplay();flag=1;}
   }
   if(flag==-1)
	  cout<<"\n\tPLant Doesn't Exist..!!";
   in.close();
}

void searchtype()
{
   int opt;
   do
   {
	  cleardevice();gotoxy(40,3);
	  cout<<"\n\n\t\tSearch By\n~~~~~~~~~~\n\n\t1.Plant ID";
	  cout<<"\n\n\t2.Plant Name\n\n\t3.Scientific Plant Name";
	  cout<<"\n\n\t4.Way to Menu";
	  cout<<"\n\n\n\t\tEnter Your Choice :";
	  cin>>opt;
	  switch(opt)
	  {
		 case 1:searchby_pid();
				break;
		 case 2:searchby_pname();
				break;
		 case 3:searchby_sname();
				break;
		 case 4:first();
	  }
	  getch();
   }while(opt<4);
}

class helpcare
{
   public:
   helpcare()
   {
	 strcpy(type,"\0");
	 strcpy(reason,"\0");
	 strcpy(serviceadd,"nill");
   }
   int cid,noofdays;
   char cname[30],cadd[30];
   long ph;
   float servicecharge;
   char type[30],reason[20],serviceadd[25];
   void helpinput();
   void helpdisplay();
};
void helpcare::helpinput()
{
   cout<<"\n\n\tEnter number of days of service : ";
   cin>>noofdays;
}
void helpcare::helpdisplay()
{
   for(int i=0;i<80;i++)
	  cout<<"_";
   cout<<"ID"<<"      "<<"No of days"<<"     "<<"Service charge"<<"     "<<"Type"<<"     "<<"Reason"<<"     "<<"Address";     cout<<"\n";
   cout<<cid<<"      "<<noofdays   <<"           "<<servicecharge   <<"          "<<type  <<"          "<<reason  <<"         "<<serviceadd<<"\n";
   for( i=0;i<80;i++)
   cout<<"_";
}

int z;

void cust_helpcare()
{
   cleardevice();
   ofstream out;
   out.open("help.dat",ios::binary|ios::app);
   helpcare h;
   gotoxy(0,0);
   outtextxy(40,40,"Are you a member : ");
   char x;
   cin>>x;
   int id;
   if(x=='y')
	  {
		cout<<"\n\n\tEnter ID";
		cin>>id;
		ifstream in;
		in.open("customer.dat",ios::binary);
		customer c;
		int fl2=-1;
		while(in.read((char *)&c, sizeof(c)))
		{
		  if (id==c.cid)
			{
			  fl2=1;
			  h.cid=c.cid;
			  strcpy(h.cname,c.cname);
			  strcpy(h.cadd,c.cadd);
			  h.ph=c.ph;
			}
		}
	   in.close();
	   if(fl2==-1) { cout<<"\n\tInalid ID..!!"; first(); }
	   h.helpinput();
	   cout<<"\n\n\t\tType of service required   ";
	   cout<<"\n\n\t1.Garden\n\n\t2.Indoor";
	   cout<<"\n\n\tEnter your choice :";
	  int y;
	  cin>>y;
	  if(y==1)
	  {
		 strcpy(h.type,"Garden service");
		 h.servicecharge=100*h.noofdays;
	  }
	  else if(y==2)
	  {
		 strcpy(h.type,"Indoor service");
		 cout<<"\n\n\t\t Mode of service  \n\n\t1.Home service\n\n\t2.Manual service";
		 cout<<"\n\n\tEnter your choice:";
		 int q;
		 cin>>q;
		 if(q==1)
		 {
			 cout<<"\n\tEnter address where the service is to be provided : ";
			 gets(h.serviceadd);
			 h.servicecharge=500*h.noofdays;
		 }
		 else if(q==2)
		 h.servicecharge=200*h.noofdays;
	  }
	  cout<<"\n\t\tReason for seeking service : ";
	  cout<<"\n\n\t1.Demonstration\n\n\t2.Vacation\n\n\t3.Emergency\n\n\t4.Other reason ";
	  cout<<"\n\n\tEnter your choice :";
	  cin>>z;
	  switch(z)
	  {
		 case 1:strcpy(h.reason,"Demonstration");break;
		 case 2:strcpy(h.reason,"Vacation");break;
		 case 3:strcpy(h.reason,"Emergency");break;
		 case 4:strcpy(h.reason,"Other reason");break;
	   }
   }
   else
   {
	 int r;
	 cout<<"\n\tEnter customer ID          : ";
	 cin>>r;
	 h.cid=r;
	 cout<<"\n\tEnter number of days       : ";
	 cin>>h.noofdays;
	 cout<<"\n\n\t\tType of service required  ";
	 cout<<"\n\n\t1.Garden\n\n\t2.Indoor \n\n\tEnter your choice :";
	 int y,z;
	 cin>>y;
	 if(y==1)
	 {
	   strcpy(h.type,"Garden service");
	   h.servicecharge=100*h.noofdays;
	 }
	 else if(y==2)
	 {
		strcpy(h.type,"Indoor service");
		cout<<"\n\n\t\t\tMode of service  \n\n\t1.Home service\n\n\t2.Manual service";
		cout<<"\n\n\tEnter your choice :";
		int q;
		cin>>q;
		if(q==1)
		{
		  cout<<"\n\tEnter address where the service is to be provided : ";
		  gets(h.serviceadd);
		  h.servicecharge=500*h.noofdays;
		}
		else if(q==2)
		h.servicecharge=200*h.noofdays;
	 }
	 cout<<"\n\n\n\t\tReason for seeking service  ";
	 cout<<"\n\n\t1.Demonstration\n\n\t2.Vacation\n\n\t3.Emergency\n\n\t4.Other reason\n\n\tEnter your choice :  ";
	 cin>>z;
	 switch(z)
	 {
		case 1:strcpy(h.reason,"Demonstration");break;
		case 2:strcpy(h.reason,"Vacation");break;
		case 3:strcpy(h.reason,"Emergency");break;
		case 4:strcpy(h.reason,"Other reason");break;
	 }
   }
   out.write((char*)&h,sizeof(h));
   getch();
   out.close();
   int g;
   do
   {
	 cleardevice();
	 gotoxy(4,4);
	 cout<<"\n\n\t\t1. Display\n\n\t\t2. Modify\n\n\t\t3. Summary\n\n\t\t4. Back to main menu\n\n\t\t Enter your choice : ";
	 ifstream dis;
	 cin>>g;
	 helpcare hn,tem;
	 int eleid;
	 ofstream mout;
	 switch(g)
	 {
	   case 1:
		  dis.open("help.dat",ios::binary);
		  while(dis.read((char*)&tem,sizeof(tem)))
		  {
			tem.helpdisplay();
			cout<<"\n";
		  }
		  dis.close();
		  break;
	   case 2:
		 dis.open("help.dat",ios::binary);
		 mout.open("temp.dat",ios::binary);
		 cout<<"\nEnter customer ID to be modified :";
		 cin>>eleid;
		 while(dis.read((char*)&tem,sizeof(tem)))
		 {
		   if(eleid==tem.cid)
		   {
			 int r;
			 cout<<"\n\tEnter customer ID         : ";
			 cin>>r;
			 hn.cid=r;
			 cout<<"\n\tEnter number of days      : ";
			 cin>>hn.noofdays;
			 cout<<"\n\tType of service required  ";
			 cout<<"\n\t\t1.Garden\n\t\t2.Indoor";
			 cout<<"\n\t\tEnter your choice :";
			 int  y,z;
			 cin>>y;
			 if(y==1)
			   strcpy(hn.type,"Garden service");
			 else if(y==2)
			 {
			   strcpy(hn.type,"Indoor service");
			   cout<<"\n\t\tMode of service \n\t1.Home service\n\t2.Manual service";
			   cout<<"\n\n\tEnter your choice :";
			   int q;
			   cin>>q;
			   if(q==1)
			   {
				 cout<<"\n\tEnter address where the service is to be provided : ";
				 gets(hn.serviceadd);
				 hn.servicecharge=500*hn.noofdays;
			   }
			   else if(q==2)
			   hn.servicecharge=200*hn.noofdays;
			}
		 cout<<"\n\n\t\t\t Reason for seeking service  ";
		 cout<<"\n\n\t1.Demonstration\n\t2.Vacation\n\t3.Emergency\n\t4.Other reason ";
		 cout<<"\n\tEnter your choice :";
		 cin>>z;
		 switch(z)
		 {
			case 1:strcpy(hn.reason,"Demonstration");break;
			case 2:strcpy(hn.reason,"Vacation");break;
			case 3:strcpy(hn.reason,"Emergency");break;
			case 4:strcpy(hn.reason,"Other reason");break;
		 }
		 mout.write((char*)&hn,sizeof(hn));
		 }
		 else
		  mout.write((char*)&tem,sizeof(tem));
		 }
		 dis.close();
		 mout.close();
		 remove("help.dat");
		 rename("temp.dat","help.dat");
		 break;
	   case 3:
		 dis.open("help.dat",ios::binary);
		 cout<<"\n\tEnter ID : ";
		 cin>>eleid;
		 helpcare ty;
		 while(dis.read((char*)&ty,sizeof(ty)))
		 {
		   if(eleid==ty.cid)
		   {  ty.helpdisplay();
			  cout<<"\n";
		   }
		 }
		 dis.close();
		 break;
	   case 4:
		 first();
	 }
	 getch();
   }while(g<5);
}
void Help()
{
   char ch;
   cleardevice();
   do
   {
	 gotoxy(5,5);
	 cust_helpcare();
	 cout<<"\nDo you wish to continue(y/n) : ";
	 cin>>ch;
   }while(ch=='y');
}

class compost
{
   public:
   int cid,comid,qty;
   char cname[30],cadd[50];
   long int ph;
   float amt;
};

void compost_home()
{
   cleardevice();gotoxy(40,3);
   int opt,x,choice,qty=0;float total=0;
   ifstream in;
   ofstream out;
   customer c;
   compost a;
   in.open("customer.dat",ios::binary);
   out.open("compost.dat",ios::binary|ios::app);
   cleardevice();
   cout<<"\n\n\t\t\t* * * * * C O M P O S T * * * * * ";
   cout<<"\n\n\t1.Buy a Ready-to-use Compost Kit.";
   cout<<"\n\n\t2.Buy Compost Bin for Your Home.";
   cout<<"\n\n\tEnter Your Choice :";
   cin>>opt;
   switch(opt)
   {
	  case 1:
		  cleardevice();
		  gotoxy(40,3);
		  cout<<"\n\n\t1.Ready-to-go Bin (01 Litre Capacity)    @  Rs.500";
		  cout<<"\n\n\t2.Ready-to-go Bin (05 Litre Capacity)    @  Rs.2200";
		  cout<<"\n\n\t3.Ready-to-go Bin (15 Litre Capacity)    @  Rs.6000";
		  cout<<"\n\nEnter Your Choice:";cin>>choice;
		  cout<<"\n\n\tEnter Quantity:";cin>>qty;
		  cout<<"\n\nEnter Customer ID:";cin>>x;
		  if(choice==1)
			total=qty*500;
		  else if(choice==2)
			total=qty*2200;
		  else if(choice==3)
			total=qty*6000;
			   int f=-1;
		  while(in.read((char*)&c,sizeof(c)))
		  {
			if(x==c.cid)
			{
			  f=1;
			  cout<<"\n\n\t\tCustomer Found In Database.";
			  strcpy(a.cadd,c.cadd);
			  strcpy(a.cname,c.cname);
			  a.cid=c.cid;
			  a.ph=c.ph;
			  a.amt=total;
			  a.qty=qty;
			  out.write((char *)&a, sizeof(a));
			  cout<<"\n\n***********THANK  YOU***********\n";
			  getch();
			}
		  }
		  if(f==-1)
		  {
			cout<<"\n\nCustomer Not found in Database.";
			getch();
			first();
			getch();
		  }
		  break;
	  case 2:
		  cleardevice();gotoxy(40,3);
		  customer c;compost a;
		  cout<<"\n\n\t1.Smart Bin (01L Capacity)   @  Rs.700";
		  cout<<"\n\n\t2.Smart Bin (05L Capacity)   @  Rs.3000";
		  cout<<"\n\n\t3.Smart Bin (15L Capacity)   @  Rs.8000";
		  cout<<"\n\n\tEnter Your Choice:";cin>>choice;
		  cout<<"\n\nEnter Quantity   :";cin>>qty;
		  cout<<"\n\nEnter Customer ID:";cin>>x;
		  if(choice==1)
			 total=qty*700;
		  else if(choice==2)
			 total=qty*3000;
		  else if(choice==3)
			 total=qty*8000;
		  int f1=-1;
		  while(in.read((char*)&c,sizeof(c)))
		  {
			if(x==c.cid)
			{
			  f1=1;
			  cout<<"\n\n\tCustomer Found in Database";
			  strcpy(a.cadd,c.cadd);
			  strcpy(a.cname,c.cname);
			  a.cid=c.cid;
			  a.ph=c.ph;
			  a.amt=total;
			  a.qty=qty;
			  out.write((char*)&a, sizeof(a));
			}
		  }
		  if(f1==1)
		  cout<<"\n\n\t\tDelivered with bill";
		  cout<<"\n\n\t\t***********THANK  YOU***********\n";
		  getch();
		  if(f1==-1)
		  {
			 cout<<"\n\n\t\tCustomer Not found in Database.";
			 getch();
			 first();
			 getch();
		  }
		  }
		  out.close();
		  in.close();
		  cout<<"Total Amount ="<<total<<endl;
		  getch();
}

void report()
{
   ifstream in1, in2, in3;
   in1.open("billfinal.dat",ios::binary);
   bill b;
   gotoxy(0,0);
   outtextxy(10,40," Plant Details ");
   cout<<"\n\n";
   gotoxy(3,10);
   while(in1.read((char *)&b, sizeof(b)))
   {
	 b.billplantdisplay();
   }
   in1.close();
   getch();
   cleardevice();
   in2.open("kitbill.dat",ios::binary);
   kitbill k;
   outtextxy(10,40," Kit Details ");
   gotoxy(3,10);
   while(in2.read((char *)&k, sizeof(k)))
   {
	 k.display();
   }
   in2.close();
   getch();
}
void exe()
{

   setcolor(YELLOW);
   setfillstyle(1,CYAN);

   settextstyle(10,0,6);
   floodfill(75,180,YELLOW);

   delay(500);
   ellipse(300,225,0,360,295,80);
   int x=70;
   outtextxy(x,150,"T");
   delay(300);
   x=x+50;
   outtextxy(x,150,"H");
   delay(250);
   x=x+50;
   outtextxy(x,150,"A");
	   delay(200);
   x=x+50;
   outtextxy(x,150,"N");
	   delay(150);
   x=x+50;
   outtextxy(x,150,"K");
	   delay(100);
   x=x+50;
   outtextxy(x,150," ");
	   delay(90);
   x=x+50;
   outtextxy(x,150,"Y");
   delay(80);
   x=x+50;
   outtextxy(x,150,"O");
   delay(50);
   x=x+50;
   outtextxy(x,150,"U");
   delay(30);
   x=x+50;
   outtextxy(x,150,"!");
 delay(10);
 settextstyle(4,0,4);
 outtextxy(240,250," ");
	 int xa=295;
	 int ya=80;
   for(int i=0;i<10;i++)
   {
	delay(200);
	setcolor(i);
	ellipse(300,225,0,360,295,ya);
	ya=ya+10;
	}
	settextstyle(2,0,2);
	setcolor(BLUE);
  outtextxy(50,400,"Project by  NITHYA PRATHIK  NAZNEEN PAVAN");

getch();

}








void homescreen()
{setbkcolor(WHITE);
	 int xa=295;
	 int ls=98;
	 int le=550;
	 int lr=65;
	 int ya=20;

   for(int i=0;i<26;i++)
   {if(i<=19)
   {
	delay(50);
	setcolor(i);
	circle(2,4,ya);
	circle(650,4,ya);
	ya=ya+5;
	}
	else
	{
	 int q=0;
	 lr=lr+5+q;
	 q+= 2;
	 ls-=5;
	 le+=5;
	 line(ls,lr,le,lr);
	setcolor(i);
settextstyle(6,0,6);
outtextxy(400,240,"Planted by :");
settextstyle(7,0,3);
outtextxy(410,300,"Nithya ");
outtextxy(410,330,"Prathik ");
outtextxy(410,380,"Nazneen  ");
outtextxy(410,430,"Pavan ");

	 }

settextstyle(7,0,7);
setcolor(i);
delay(20);
outtextxy(120,2 ,"J");
delay(20);
outtextxy(180,2 ,"A");
delay(20);
outtextxy(240,2 ,"I");
delay(20);
outtextxy(300,2 ,"V");
delay(20);
outtextxy(360,2 ,"I");
delay(20);
outtextxy(420,2 ,"K");
delay(20);
outtextxy(480,2 ,"A");
delay(20);

}
setcolor(BROWN);
setfillstyle(SOLID_FILL,BROWN);
rectangle(90,250,110,445);
floodfill(97,260,BROWN);
setcolor(WHITE);
setfillstyle(SOLID_FILL,GREEN);
line(20,250,190,250);
line(20,250,100,100);
line(100,100,190,250);
floodfill(55,200,WHITE);
setcolor(RED);
setcolor(GREEN);

for(int e=0;e<20;e++)
{
 int x=0,z=0,y=0;
	if(e%2==0)
	{
	 y=y+40+random(5);
	 x=x+45+random(100);
	 z=z+420+random(50);
arc(x,z,0,70,y);
arc(x+80,z,110,180,y);}
else{  y=y+40-random(5);
	 x=x+45-random(70);
	 z=z+420-random(50);
	arc(x,z,0,70,y);
	arc(x+80,z,110,180,y);
	  }
 }
arc(35,455,0,70,40);
arc(115,455,110,180,40);

arc(45,455,0,70,40);
arc(125,455,110,180,40);

arc(55,455,0,70,40);
arc(135,455,110,180,40);

arc(65,455,0,70,40);
arc(145,455,110,180,40);

arc(85,455,0,70,40);
arc(165,455,110,180,40);

arc(85,405,0,70,40);
arc(165,405,110,180,40);

arc(75,435,0,70,40);
arc(155,435,110,180,40);

for(i=0;i<21;i++)
{delay(100);

setbkcolor(i);
}setcolor(BROWN);
for(i=0;i<12;i++)
{delay(80);
setfillstyle(1,12);
fillellipse(280,235,40,40);
}
setfillstyle(CLOSE_DOT_FILL,YELLOW);
fillellipse(280,235,20,20);


getch();

}

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   homescreen();
   first();
}

void first()
{
   cleardevice();
   setcolor(WHITE);
   rectangle(10,10,630,470);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(65,65,WHITE);
   int opt;
   do
   {
	setbkcolor(BLACK);
	cleardevice();
	settextstyle(10,0,3);
	setcolor(RED);
	outtextxy(100,30,"Jaivika Planters");
	outtextxy(100,70,"~~~~~~~~~~~~~");
	settextstyle(7,0,3);
	setcolor(YELLOW);
	outtextxy(50,90 ,"1. ADMIN");
	outtextxy(50,120,"2. A-Z PLANTS");
	outtextxy(50,150,"3. INDOOR PLANTS");
	outtextxy(50,180,"4. GREEN HOUSE");
	outtextxy(50,210,"5. SEARCH TYPE");
	outtextxy(50,240,"6. GARDEN MAINTENANCE");
	outtextxy(50,270,"7. HELP CARE");
	outtextxy(50,300,"8. COMPOST");
	outtextxy(50,330,"9. REPORT");
	outtextxy(50,360,"10. EXIT");
	outtextxy(50,390," ENTER YOUR OPTION :");
	gotoxy(60,25);
	cin>>opt;
	cleardevice();
	switch(opt)
	{
	   int ch;
	   case 1:
		  cleardevice();gotoxy(40,3);
		  cout<<"\n\n\t\t Entry Option\n\n";
		  cout<<"\n\t1. Plant\n\n";
		  cout<<"\n\t2. Customer\n\n";
		  cout<<"\n\t3. Green House Kit items\n\n";
		  cout<<"\n\t4. Back to main menu\n";
		  cout<<"\n\n\tEnter your option : ";
		  cin>>ch;
		  if(ch==1)
			pp();
		  else if(ch==2)
			cc();
		  else if(ch==3)
			kititem();
		  else if(ch==4)
			first();
		  break;
	   case 2:
		  cout<<" \n\n\t\tPlants in our Organization\n\n ";
		  pdisplay();
		  break;
	   case 3:
		  indoor();
		  break;
	   case 4:
		  Greenkit();
		  break;
	   case 5:
		  searchtype();
		  break;
	   case 6:
		  maintenance();
		  break;
	   case 7:
		  Help();
		  break;
	   case 8:
		  compost_home();
		  break;
	   case 9:
		  report();
		  break;
	   case 10:
		  exe();
		  exit(0);
	}
	getch();
	} while(opt<=10);
}

