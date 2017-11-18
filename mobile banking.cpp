
/***********************************************************
*                               	                       *
*      MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY    *
*          	  Computer Science & Engineering               *
*      			AJMOL HOSSAIN APON                         *
*               CE-16012                                   *
***********************************************************/

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Account
{

    string id, pin, balance;

};

char c ;
int member = 0;
Account acc[1000];
map<string, int> mp;

void OpenAccount();
void ChangePin();
void CashIn();
void CashOut();
void CheckBalance();
void Menu();

fstream AccountList("list_of_Account.txt",ios::in | ios::out| ios::app);


int main()
{
    Menu();

    while(c=getch())
    {
        c = tolower(c);

        switch(c)
        {
        case 'a':
            OpenAccount();
            break;
        case 'i':
            CashIn();
            break;
        case 'o':
            CashOut();
            break;
        case 'p':
            ChangePin();
            break;
        case 'b':
            CheckBalance();
            break;
        case 'q':
            system("cls");
            return 0;
        default:
            system("cls");
            break;
        }
        Menu();
    }
}

void Menu()
{
    cout<<"\n    * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"    *        Enter 'A' for Opening a Account    *\n";
    cout<<"    *        Enter 'I' for Cash IN              *\n";
    cout<<"    *        Enter 'O' for Cash OUT             *\n";
    cout<<"    *        Enter 'P' for Change PIN           *\n";
    cout<<"    *        Enter 'B' Check balance            *\n";
    cout<<"    *        Enter 'Q' for Quit                 *\n";
    cout<<"    * * * * * * * * * * * * * * * * * * * * * * *"<<endl;

    cout<<"\n    Please Select Your Choice : ";
}

void OpenAccount()
{
    member++;
    system("cls");
    cout<<"Enter your mobile NO : ";
    getline(cin, acc[member].id);

    ifstream myfilee;
    string k ="information/";
    string z = k+acc[member].id;
    myfilee.open(z);

    if(myfilee.is_open())
    {
        cout<<endl<<"This Account already Exist"<<endl;

        cout<<endl<<endl;

        system("pause");
        system("cls");
        return ;
    }
    AccountList<<acc[member].id<<endl;
    mp[acc[member].id]=member;
    cout<<"enter your 4 digit pin : ";

    while(c=getch())
    {
        if(c==13)
            break;
        else if(c=='\b')
        {
            cout<<"\b \b";
        }

        else
        {
            acc[member].pin+=c;
            cout<<"*";

        }
    }
    acc[member].balance = "10000.00";
    system("cls");

    ofstream myfile;
    //string z,k;
    k = "information/";
    z = k + acc[member].id;

    myfile.open(z);
    myfile<<"Account NO : "<<acc[member].id<<endl;
    myfile<<"Balance : "<<acc[member].balance<<endl;
    myfile<<"PIN : "<<acc[member].pin;

    myfile.close();
}

void ChangePin()
{

    string ID, pass;

    system("cls");

    cout<<"Enter ID: ";


    cin>>ID;

    cout<<"enter pin : ";

    while(c=getch())
    {
        if(c==13)
            break;
        else
        {
            pass +=c;
            printf("*");

        }
    }

    cout<<endl;
    cout<<endl;

    ifstream myfile;

    string k = "information/";
    string z = k+ID;

    myfile.open(z);

    string line, ans;

    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            ans = line;
        }
        myfile.close();
    }

    stringstream ss;

    ss<<ans;

    while(ss>>ans)
    {

    }

    if(pass == ans)
    {
        string lines[3];

        myfile.open(z);

        if(myfile.is_open())
        {
            int i = 0;

            while(getline(myfile,line))
            {
                lines[i] = line;
                i++;
            }
            myfile.close();


        }

        stringstream sss;

        sss << lines[2];

        while(sss>>line);

        cout<<"Enter new pin : ";

        cin>>acc[mp[ID]].pin;

        lines[2] = "PIN : " + acc[mp[ID]].pin;

        string k="information/";
        string z=k+ID;
        remove(z.c_str());

        ofstream myfile;
        k = "information/";
        z = k + ID;
        myfile.open(z);

        myfile<<lines[0]<<endl;
        myfile<<lines[1]<<endl;
        myfile<<lines[2]<<endl;

        myfile.close();


    }
    cout<<endl;
    system("pause");
    system("cls");

}

void CashIn()
{
    system("cls");
    string Agent, Custom;

    string pass;


    cout<<"Enter your account NO : ";
    cin>>Agent;

    string k = "information/";
    string z = k+Agent;

    int amount;

    ifstream agentfile;

    agentfile.open(z);
    if(agentfile.is_open())
    {

        string alines[3];
        string line;

        int p = 0;

        while(getline(agentfile,line))
        {
            alines[p]  = line;
            p++;
        }

        stringstream sso1;

        sso1 <<alines[1];

        string taka;

        while(sso1>>taka);

        stringstream sso2;

        sso2<<taka;

        float mymoney;

        sso2>>mymoney;

        string PIN;

        stringstream sso3;

        sso3<<alines[2];
        while(sso3>>PIN);

        cout<<"Enter customer phone number";
        cin>>Custom;

        ifstream customfile;

        string i = "information/";
        string j = i+Custom;

        customfile.open(j);

        if(customfile.is_open())
        {
            string cline[3];
            string get;

            int q = 0;

            while(getline(customfile,get))
            {
                cline[q]= get;
                q++;
            }

            stringstream sso5;
            sso5<<cline[1];

            string newmoney;

            while(sso5>>newmoney);

            stringstream sso6;
            sso6<<newmoney;
            float nowmoney;
            sso6>>nowmoney;

            cout<<"Enter amount : ";
            float amount;
            cin>> amount;

            cout<<"enter pin number : ";
            while(c=getch())
            {
                if(c==13)
                    break;
                else if(c=='\b')
                {
                    cout<<"\b \b";
                }

                else
                {
                    pass +=c;
                    printf("*");

                }
            }

            if(PIN == pass)
            {
                if(mymoney>=amount)
                {
                    float now, now1;
                    now = (mymoney - amount)+(amount*.005);
                    stringstream sso4;
                    sso4<<now;
                    string pp;
                    sso4>>pp;
                    acc[mp[Agent]].balance = pp;
                    alines[1] = "Balance : "+acc[mp[Agent]].balance;

                    ///cusomer amount change///
                    now1 = (nowmoney+amount);
                    stringstream sso7;
                    sso7<<now1;
                    string pp1;
                    sso7>>pp1;
                    acc[mp[Custom]].balance = pp1;
                    cline[1]=  "Balance : "+acc[mp[Custom]].balance;

                    remove(j.c_str());
                    remove(z.c_str());

                    ofstream customfile;
                    customfile.open(j);

                    customfile<<cline[0]<<endl;
                    customfile<<cline[1]<<endl;
                    customfile<<cline[2];


                    ofstream agentfile;
                    agentfile.open(z);
                    agentfile<<alines[0]<<endl;
                    agentfile<<alines[1]<<endl;
                    agentfile<<alines[2]<<endl;

                    system("cls");
                    cout<<"Transaction succefull!! your balance is "<<pp<<"."<<endl<<endl;
                    system("pause");


                }
                else
                {
                    system("cls");
                    cout<<"insufficient fund!!"<<endl;
                    system("pause");
                }

            }

            else
            {
                system("cls");
                cout<<"Invalid PIN"<<endl;
                system("pause");
            }



        }

        else
        {
            system("cls");
            cout<<"This account does not exists"<<endl;
            system("pause");
        }
        customfile.close();
    }
    else
    {
        system("cls");
        cout<<"sorry this account does not exists !!";
        system("pause");
    }
    agentfile.close();

    system("cls");

}

void CheckBalance()
{
    system("cls");
    string id, PIN,pass;



    cout<<"Enter your Number : ";
    cin>>id;

    cout<<"enter your pin : ";
    while(c=getch())
    {
        if(c==13)
            break;
        if(c=='\b')
            cout<<"\b \b";
        else
        {
            pass +=c;
            printf("*");

        }
    }


    string k = "information/";
    string z = k+id;

    ifstream myfile;

    myfile.open(z);

    if(myfile.is_open())
    {
        string lines[3];
        string line,money,PIN;
        int i = 0;
        while(getline(myfile,line))
        {
            lines[i] = line;
            i++;
        }
        myfile.close();

        stringstream ss;

        ss<<lines[1];

        while(ss>>money);
        stringstream sss;

        sss<<lines[2];

        while(sss>>PIN);

        if(PIN==pass)
        {
            system("cls");
            cout<<"your current Account balance is TK "<<money<<"."<<endl;
            cout<<"your available balance is Tk "<<money<<".";


            cout<<endl<<endl;
            system("pause");
            system("cls");
        }
        else
        {
            system("cls");
            cout<<"Invalid Pin"<<endl<<endl;
            system("pause");
            system("cls");

        }
    }

    else
    {
        system("cls");
        cout<<"Account does not exists"<<endl<<endl;
        system("pause");
        system("cls");

    }

}

void CashOut()
{
    system("cls");
    string Agent, Custom;

    string pass;


    cout<<"Enter your account NO : ";
    cin>>Agent;

    string k = "information/";
    string z = k+Agent;

    int amount;

    ifstream agentfile;

    agentfile.open(z);
    if(agentfile.is_open())
    {

        string alines[3];
        string line;

        int p = 0;

        while(getline(agentfile,line))
        {
            alines[p]  = line;
            p++;
        }

        stringstream sso1;

        sso1 <<alines[1];

        string taka;

        while(sso1>>taka);

        stringstream sso2;

        sso2<<taka;

        float mymoney;

        sso2>>mymoney;

        string PIN;

        stringstream sso3;

        sso3<<alines[2];
        while(sso3>>PIN);

        cout<<"Enter Agent phone number";
        cin>>Custom;

        ifstream customfile;

        string i = "information/";
        string j = i+Custom;

        customfile.open(j);

        if(customfile.is_open())
        {
            string cline[3];
            string get;

            int q = 0;

            while(getline(customfile,get))
            {
                cline[q]= get;
                q++;
            }

            stringstream sso5;
            sso5<<cline[1];

            string newmoney;

            while(sso5>>newmoney);

            stringstream sso6;
            sso6<<newmoney;
            float nowmoney;
            sso6>>nowmoney;

            cout<<"Enter amount : ";
            float amount;
            cin>> amount;

            cout<<"enter pin number : ";
            while(c=getch())
            {
                if(c==13)
                    break;
                else if(c=='\b')
                {
                    cout<<"\b \b";
                }

                else
                {
                    pass +=c;
                    printf("*");

                }
            }

            if(PIN == pass)
            {
                if(mymoney-(amount*.0185)>=amount)
                {
                    float now, now1;
                    now = (mymoney - amount)-(amount*.0185);
                    stringstream sso4;
                    sso4<<now;
                    string pp;
                    sso4>>pp;
                    acc[mp[Agent]].balance = pp;
                    alines[1] = "Balance : "+acc[mp[Agent]].balance;

                    ///cusomer amount change///
                    now1 = (nowmoney+amount)+(amount*0.005);
                    stringstream sso7;
                    sso7<<now1;
                    string pp1;
                    sso7>>pp1;
                    acc[mp[Custom]].balance = pp1;
                    cline[1]=  "Balance : "+acc[mp[Custom]].balance;

                    remove(j.c_str());
                    remove(z.c_str());

                    ofstream customfile;
                    customfile.open(j);

                    customfile<<cline[0]<<endl;
                    customfile<<cline[1]<<endl;
                    customfile<<cline[2];


                    ofstream agentfile;
                    agentfile.open(z);
                    agentfile<<alines[0]<<endl;
                    agentfile<<alines[1]<<endl;
                    agentfile<<alines[2]<<endl;

                    system("cls");

                    cout<<"Transaction succefull!! your Balance is "<<pp<<"."<<endl<<endl;
                    system("pause");


                }
                else
                {
                    system("cls");
                    cout<<"insufficient fund!!"<<endl;
                    system("pause");
                }

            }

            else
            {
                cout<<"Invalid PIN"<<endl;
                system("pause");
            }



        }

        else
        {
            cout<<"This account does not exists"<<endl;
            system("pause");
        }
        customfile.close();
    }
    else
    {
        cout<<"sorry this account does not exists !!";
        system("pause");
    }
    agentfile.close();

    system("cls");

}
