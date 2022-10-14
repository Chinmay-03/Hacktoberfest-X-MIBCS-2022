 void swap(int * x,int* y)
    {
        int temp=*x;
        *x=*y;
        *y= temp;
    }
    void selectionSort(int arr[], int n)
    {
      int mn;
       for(int i=0;i<n-1;i++)
       {
           mn=i;
           for(int j=i+1;j<n;j++)
           {
              if(arr[j]<arr[mn])
                 mn=j;
           }
           swap(&arr[mn],&arr[i]);
       }
    }
