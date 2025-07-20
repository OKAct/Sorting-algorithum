#include <stdio.h>
#include <cs50.h>

void sort(int inputs,int b[inputs]);
void merge(int half,int inputs,int left[half],int right[inputs-half],int b[half*2]);
int main(void)
{

    int inputs=get_int("Enter number of inputs:");

    int Entries[inputs];

    for(int a =0;a<inputs;a++)
    {
        Entries[a]=get_int("No. %d:",a+1);
        
    }

    sort(inputs,Entries);
    printf("\n");
    printf("Sorted list:-\n");
    for(int a =0;a<inputs;a++)
    {
        printf("%d\n",Entries[a]);
        
    }
    
}



void sort(int inputs,int b[inputs])
{

    if(inputs<=1)
    {
        return;

    }
    int half=inputs/2;

    int left[half];
    int right[inputs-half];

    for(int d=0;d<inputs;d++)
    {
        if(d<half)
        {
            left[d]=b[d];

        }
        else
        {
            right[d-half]=b[d];
        }
    }

    sort(half,left);
    sort(inputs-half,right);
    
    
    merge(half,inputs,left,right,b);

   
}

void merge(int half,int inputs,int left[half],int right[inputs-half],int b[inputs])
{

    int i=0;
    int j=0;

    for(int a=0;a<inputs;a++)

    {
        if(left[i]>right[j] && j<inputs-half)
        {
            b[a]=right[j];
            j++;
        }
        else if(left[i]<right[j] && i<half)
        {
            b[a]=left[i];
            i++;
        }
        else if(i==half)
        {
            b[a]=right[j];
            j++;
        }
        else if(j==inputs-half)
        {
            b[a]=left[i];
            i++;
        }
    }

    
}