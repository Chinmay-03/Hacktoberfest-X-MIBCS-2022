 void merge(int *arr, int l,int r)
    {
        int mid=(l+r)/2;
        int l1=mid-l+1;
        int l2=r-mid;
        
        int *first =new int[l1];
        int *second=new int[l2];
        
        int k=l;
        for(int i=0;i<l1;i++)
        {
            first[i]=arr[k++];
        }
        k=mid+1;
        for(int i=0;i<l2;i++)
        {
            second[i]=arr[k++];
        }
        
        //merge 2 array
        int i1 = 0;
        int i2 = 0;
        k = l;
        while(i1<l1 and i2<l2)
        {
            if(first[i1]<second[i2])
            {
                arr[k++]=first[i1++];
            }
            else
            {
                 arr[k++]=second[i2++];
            }
        }
        
        while(i1<l1)
        {
            arr[k++]=first[i1++];
        }
        while(i2<l2)
        {
            arr[k++]=second[i2++];
        }
        delete []first;
        delete []second;
    }
   
    void mergeSort(int arr[], int l, int r)
    {   
        int mid=(r+l)/2;
        if(l>=r)
           return;
           
      
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,r);
    }
