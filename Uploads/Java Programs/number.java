import java.util.Scanner;
class repetation{
    public static void main(String []args){
        int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
        Scanner ss=new Scanner(System.in);
        System.out.println("Enter a number :");
        long num=ss.nextLong();
        long org=num;
        while(num>0){
          int  i=(int)num%10;
            switch(i){
                case 0:
                    c0+=1;break;
                case 1:
                    c1+=1;break;
             case 2:
                    c2+=1;break;
                case 3:
                    c3+=1;break;
                case 4:
                    c4+=1;break;
                case 5:
                    c5+=1;break;
                case 6:
                    c6+=1;break;
                case 7:
                    c7+=1;break;
                case 8:
                    c8+=1;break;
                case 9:
                    c9+=1;
            }
            num/=10;
        }
        System.out.println("repetation in the number "+org);
        System.out.print("\n0="+c0+"\n1="+c1+"\n2="+c2+"\n3="+c3+"\n4="+c4+"\n5="+c5+"\n6="+c6+"\n7="+c7+"\n8="+c8+"\n9="+c9);
    }
}
