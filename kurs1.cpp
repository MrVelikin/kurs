#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

char FirstField[12][12];
char SecondField[12][12];
char ThirdField[12][12];
int life1=20;
int life2=20;
int corab=0;
int coordx,coordy;

void PrintFields()
{
    system("cls");
 
    cout<<"   ";
    
    for (int i=1; i<=10; i++)
        cout<<i<<" ";
    
    cout<<"   ";
 
    for(int i=1; i<=10; i++)
        cout<<i<<" ";           
    
    cout<<endl;
    
    for(int i=1; i<=10; i++)
    {
        cout<<setw(2)<<i<<" ";
        
        for(int j=1; j<=10; j++)
            cout<<FirstField[i][j]<<" ";
        
        cout<<" "<<setw(2)<<i<<" ";
        
        for(int k=1; k<=10; k++)
            cout<<SecondField[i][k]<<" ";
        
        cout<<setw(2)<<endl;
    }
    
    cout<<endl;
}

bool Test1(int x1, int y1,int x2,int y2,int z,int k)
{
	int l=0;
    for(int i=x1-1; i<=x2+1; i++)
        for(int j=y1-1; j<=y2+1; j++)
        	{
        		if(k==2)
            		if(ThirdField[i][j]=='.')
            			l++;
            	if(k==1)
            		if(FirstField[i][j]=='.')
            			l++;	
            }		
    if (l==(z*3+6))
    	return false;
	else
    	return true;	
}


bool Test(int x1, int y1,int x2,int y2)
{
	int l=0;
    for(int i=x1-1; i<=x2+1; i++)
        for(int j=y1-1; j<=y2+1; j++)
            if(FirstField[i][j]=='H')
            	l++;
    if ( l!=0)
    	return true;
	else
    	return false;	
}

bool TestShip(int x, int y)
{
	int l=0;
	int kol=0;
	int xl=x;
	int xr=x;
	int yv=y;
	int yn=y;
	while(ThirdField[xl-1][y]=='H' || ThirdField[xl-1][y]=='X')
	{
		l++;
		if (ThirdField[xl-1][y]=='X')
			kol++;
		xl=xl+1;
	}
	while(ThirdField[xr+1][y]=='H' || ThirdField[xr+1][y]=='X')
	{
		l++;
		if (ThirdField[xr+1][y]=='X')
			kol++;
		xr=xr+1;
	}
	while(ThirdField[x][yv+1]=='H' || ThirdField[x][yv+1]=='X')
	{
		l++;
		if (ThirdField[x][yv+1]=='X')
			kol++;
		yv=yv+1;
	}
	while(ThirdField[x][yn-1]=='H' || ThirdField[x][yn-1]=='X')
	{
		l++;
		if (ThirdField[x][yn-1]=='X')
			kol++;
		yn=yn-1;
	}

    
    if (l!=kol)
    	return true;
	else
    	return false;	
}

bool TestShipPl(int x, int y)
{
	int l=0;
	int kol=0;
	int xl=x;
	int xr=x;
	int yv=y;
	int yn=y;
	while(FirstField[xl-1][y]=='H' || FirstField[xl-1][y]=='X')
	{
		l++;
		if (FirstField[xl-1][y]=='X')
			kol++;
		xl=xl+1;
	}
	while(FirstField[xr+1][y]=='H' || FirstField[xr+1][y]=='X')
	{
		l++;
		if (FirstField[xr+1][y]=='X')
			kol++;
		xr=xr+1;
	}
	while(FirstField[x][yv+1]=='H' || FirstField[x][yv+1]=='X')
	{
		l++;
		if (FirstField[x][yv+1]=='X')
			kol++;
		yv=yv+1;
	}
	while(FirstField[x][yn-1]=='H' || FirstField[x][yn-1]=='X')
	{
		l++;
		if (FirstField[x][yn-1]=='X')
			kol++;
		yn=yn-1;
	}

    
    if ( l!=kol)
    	return true;
	else
    	return false;	
}

void Potop(int x, int y)
{
	int xl=x;
	int xr=x;
	int yv=y;
	int yn=y;
	while(ThirdField[xr+1][y]=='X')
	{
		xr=xr+1;
	}
	while(ThirdField[xl-1][y]=='X')
	{
		xl=xl-1;
	}
	while(ThirdField[x][yv+1]=='X')
	{
		yv=yv+1;
	}
	while(ThirdField[x][yn-1]=='X')
	{
		yn=yn-1;
	}
	if(yv==yn)
    {
        for(int i=xl-1; i<=xr+1; i++)
            for(int j=yn-1; j<=yv+1; j+=2)
                {
                	SecondField[i][j]='o';
                	ThirdField[i][j]='o';
                }
        SecondField[xr+1][yn]='o';
        SecondField[xl-1][yn]='o';
        ThirdField[xr+1][yn]='o';
        ThirdField[xl-1][yn]='o';
    }
    else
    {
        for(int i=xl-1; i<=xr+1; i+=2)
            for(int j=yn-1; j<=yv+1; j++)
            	{
            		ThirdField[i][j]='o';	
            	    SecondField[i][j]='o';
            	}
        SecondField[xr][yn-1]='o';
        SecondField[xr][yv+1]='o';
        ThirdField[xr][yn-1]='o';
        ThirdField[xr][yv+1]='o';
    }
}

void PotopPlayer(int x, int y)
{
	int xl=x;
	int xr=x;
	int yv=y;
	int yn=y;
	while(FirstField[xr+1][y]=='X')
	{
		xr=xr+1;
	}
	while(FirstField[xl-1][y]=='X')
	{
		xl=xl-1;
	}
	while(FirstField[x][yv+1]=='X')
	{
		yv=yv+1;
	}
	while(FirstField[x][yn-1]=='X')
	{
		yn=yn-1;
	}
	if(xl==xr && yn==yv)
	{
		for(int i=x-1;i<=x+1;i++)
			for(int j=y-1;j<=y+1;j++)
				FirstField[i][j]='o';
		FirstField[x][y]='X';	
		goto m;		
	}			
	if(yv==yn)
    {
        for(int i=xl-1; i<=xr+1; i++)
            for(int j=yn-1; j<=yv+1; j+=2)
                {
                	FirstField[i][j]='o';
                }
        FirstField[xr+1][yn]='o';
        FirstField[xl-1][yn]='o';
    }
    else
    {
        for(int i=xl-1; i<=xr+1; i+=2)
            for(int j=yn-1; j<=yv+1; j++)
            	{
            		FirstField[i][j]='o';	
            	}
        FirstField[xr][yn-1]='o';
        FirstField[xr][yv+1]='o';
    }
	m:;
}

void Locate(int x1, int y1,int x2,int y2,int z)
{ 
	char py1[256],px1[256],px2[256],py2[256];
	int k=0;
	if (z==1)
	{
		while(k==0)
		{
			cout<<"Write x,y for ship with 1 life"<< endl;
			cin>>py1>>px1;
			y1=atoi(py1);
			x1=atoi(px1);
			if ((x1<1) || x1>10 || y1<1 || y1>10 || Test(x1,y1,x1,y1) )
 				cout<<"Bad coordinate"<< endl;
 			else
 			{	k=1;
				FirstField[x1][y1]='H';
				PrintFields();	
 			}
 		}                                       
	}
	else
		while(k==0)
		{
			cout<<"Write x1,y1,x2,y2 for ship with "<<z<< " life"<< endl;
			cin>>py1>>px1>>py2>>px2;
			y1=atoi(py1);
			x1=atoi(px1);
			y2=atoi(py2);
			x2=atoi(px2);
 			if( (x1<1) || (x2>10) || (y1<1) || (y2>10) || (x1!=x2 && y1!=y2) || ((x2-x1!=z-1) && (y2==y1)) || ((x2==x1) && (y2-y1!=z-1)) || Test(x1,y1,x2,y2) )
 			{
 				cout<<"Bad coordinate"<< endl;
 			}
			else
				{ 	
					for(int i=x1;i<=x2;i++)
						for(int j=y1;j<=y2;j++)
							FirstField[i][j]='H';
					PrintFields();	
					k=1;	
				}
		}
}

void CompShip(int k)
{
    int x1,y1,x2,y2;
    srand(time(0));
    int pos;
    int size=4;
    int j=10;
    while(j>0)
    {
        pos=1+rand() % 2;
        if(pos==1)
        {
            x1=x2=1+rand() % 10;
            y1=1+rand() % 10;
            if(y1+size-1>10)
                continue;
            else
                y2=y1+size-1;
        }
        else
            {
                y1=y2=1+rand() % 10;
                x1=1+rand() % 10;
                if(x1+size-1>10)
                    continue;
                else
                    x2=x1+size-1;
            }    
        if(Test1(x1,y1,x2,y2,size,k))
            continue;
        else
        {
        	j--;
        	if (j==8 || j==9) size=3;
        		else if ( j<8 && j>4) size=2;
        			else size =1;
            for(int i=x1; i<=x2; i++)
                for(int j=y1; j<=y2; j++)
                	if(k==1)
                		FirstField[i][j]='H';
                	else
                    	ThirdField[i][j]='H';
        }
    }
}

void SetShip()
{ 
	int x1,y1,x2,y2;
	int shet=10;
	while(shet>0)
	{
		if (shet==10)
		{
			Locate(x1,y1,x2,y2,4);
			shet--;
		}
		else 
			if (shet>7)
			{
				Locate(x1,y1,x2,y2,3);
				shet--;
			}
			else 
				if (shet>4)
					{
						Locate(x1,y1,x2,y2,2);
						shet--;
					}
				else
					{
						Locate(x1,y1,x1,y1,1);
						shet--;
					}
	}
}

void PlayerAt()
{	
	if (life2==0)
	goto h;
	PrintFields();
	char py[256],px[256];
	int x,y;
	cout << "Write x,y coordinate to attack"<< endl;
	cin>>py>>px;
	y=atoi(py);
	x=atoi(px);
	if ((x<1) || x>10 || y<1 || y>10 || ThirdField[x][y]=='o'|| ThirdField[x][y]=='X')
	{	
 		cout<<"Bad coordinate to attack"<< endl;
 		Sleep(2000);
 		PlayerAt();
 	}
	else
	{
		if (ThirdField[x][y]=='H' )
		{
			SecondField[x][y]='X';
			ThirdField[x][y]='X';
			life2--;
			if (TestShip(x,y))
				PlayerAt();
			else
			{
				Potop(x,y);
				PlayerAt();
			}
		}
		else 
		{
			SecondField[x][y]='o';
			ThirdField[x][y]='o';
		}
	}
	h: ;
	PrintFields();
}

void CompAt1(int x,int y)
{		
	int z=1+rand() % 2;
	int xl=x;
	int xr=x;
	int yv=y;
	int yn=y;
	if (life1==0)
		goto z3;	
	while(FirstField[xr+1][y]=='X')
	{
		xr=xr+1;
	}
	while(FirstField[xl-1][y]=='X')
	{
		xl=xl-1;
	}
	while(FirstField[x][yv+1]=='X')
	{
		yv=yv+1;
	}
	while(FirstField[x][yn-1]=='X')
	{
		yn=yn-1;
	}
	if (xl==xr && FirstField[x][yv+1]!='o' && (yn-1)>=0 && (yv+1)<=10 && FirstField[x][yn-1]!='o')
	{
		if(z==1)
		{
			if(FirstField[x][yv+1]=='H')
			{
				FirstField[x][yv+1]='X';
				life1--;
				if(TestShipPl(x,y))
					CompAt1(x,y);
				else
				{
					corab=0;
					PotopPlayer(x,y);
				}
			}
			else
				if(FirstField[x][yv+1]=='o')
					CompAt1(x,y);
				else 
					if (yv+1<=10)  
						FirstField[x][yv+1]='o';
					else
						CompAt1(x,y);
		}
		else
		{
			if(FirstField[x][yn-1]=='H')
			{
				FirstField[x][yn-1]='X';
				life1--;
				if(TestShipPl(x,y))
					CompAt1(x,y);
				else
				{
					corab=0;
					PotopPlayer(x,y);
				}
			}
			else
				if(FirstField[x][yn-1]=='o')
					CompAt1(x,y);
				else 
					if (yn-1>=0)  
						FirstField[x][yn-1]='o';
					else
						CompAt1(x,y);
		}	
	}
	else if (yv==yn && FirstField[xr+1][y]!='o' && (xl-1)>=0 && (xr+1)<=10 && FirstField[xl-1][y]!='o')
	{
		if(z==1)
		{
			if(FirstField[xr+1][y]=='H')
			{
				FirstField[xr+1][y]='X';
				life1--;
				if(TestShipPl(x,y))
					CompAt1(x,y);
				else
				{
					corab=0;
					PotopPlayer(x,y);
				}
			}
		else
			if(FirstField[xr+1][y]=='o')
				CompAt1(x,y);
			else 	
				if (xr+1<=10)  
					FirstField[xr+1][y]='o';
				else
					CompAt1(x,y);
		}
		else
		{
			if(FirstField[xl-1][y]=='H')
			{
				FirstField[xl-1][y]='X';
				life1--;
				if(TestShipPl(x,y))
					CompAt1(x,y);
				else
				{
					corab=0;
					PotopPlayer(x,y);
				}
			}
			else
				if(FirstField[xl-1][y]=='o')
					CompAt1(x,y);
				else 
					if (xl-1>=0)  
						FirstField[xl-1][y]='o';
					else
						CompAt1(x,y);	
		}	
	}
	z3:;
}

void CompAt()
{
	if (life1==0)
		goto z1;	
	if (corab==0)
	{
		int x=1+rand() % 10;
		int y=1+rand() % 10;	
		while(FirstField[x][y]=='o' || FirstField[x][y]=='X')
		{
			x=1+rand() % 10;
			y=1+rand() % 10;
		}
		if (FirstField[x][y]=='H')
		{
			FirstField[x][y]='X';
			life1--;
			if(TestShipPl(x,y))
			{
				corab=1;
				coordx=x;
				coordy=y;
				CompAt1(x,y);
			}
			else
			{
				corab=0;
				PotopPlayer(x,y);
			}
		}
		else 	
			FirstField[x][y]='o';
	}
	else
	{
		CompAt1(coordx,coordy);
	}
	z1:;
	PrintFields();
}

 int main()
{   
	string prov; 
	srand ( time(NULL) );
	for(int i=0; i<12; i++)
    	for(int j=0; j<12; j++)
    	{
       		FirstField[i][j]='.';
        	SecondField[i][j]='.';
        	ThirdField[i][j]='.';
    	}
	PrintFields();
	CompShip(2);
	cout << "Do you like select autamatic position to your ships?" << endl;
	while( prov!= "yes" &&  prov!= "no")
	{
    	cout << "Select the answer (yes/no):" << endl;
        cin >> prov;
    }
	if (prov=="yes")
		CompShip(1);
	else
	SetShip();
	while(life1>0 && life2>0)
	{
		PrintFields();	
		PlayerAt();
		CompAt();
	}
	Sleep(1000);
	system("cls");
	Sleep(1000);
	if( life2==0)
	{
		cout << "You WIN !!!" << endl;	
		Sleep(2000);
		cout << "Congratulations " << endl;	
	}
	else
		cout << "You lose =(" << endl;	
	Sleep(5000);
	return -1;
}
