#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
void Merge(int Arr[],int x, int y,int z)
{

	int n1=y-x+1,i,j,k;

	int n2=r-y;

	int left[n1],right[n2];

	for(i=0;i<n1;i++)

	{
		left[i]=A[x+i];
	}

	for(j=0;j<n2;j++)
	{
		right[j]=A[y+j+1];
	}

	i=0,j=0;

	for(k=x;i<n1&&j<n2;k++)
	{
		if(left[i]<right[j])
		{
			A[k]=left[i++];
		}
		else
		{
			A[k]=right[j++];
		}
	}

	while(i<n1)
	{
		A[k++]=left[i++];
	}

	while(j<n2)
	{
		A[k++]=right[j++];
	}
}

void mergesort(int Arr[],int x,int z)
{
	int y;

	if(x<z)
	{
		y=(x+z)/2;
		mergesort(A,x,y);
		mergesort(A,y+1,z);
		merge(A,x,y,z);
	}

}
clock_t startTime=clock();
int main()
{


    ofstream fileinput;
    srand(time(NULL));
    fileinput.open("100k.txt");
    int n=100000;

   int Arr[n];

    for(int i=0;i<n;i++)
    {
         Arr[i]=rand()%5000;
        fileinput<<rand()<<endl;

    }
    fileinput.close();

      mergesort(A,0,n-1);

    ofstream fileoutput;
    fileoutput.open("100koutput.txt");
 clock_t endTime=clock();
    for(int i=0;i<100000;i++)
    {

        fileoutput<<Arr[i]<<endl;
    }
    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<timelapse<<endl;

    fileoutput.close();
    delete[] Arr;
}
