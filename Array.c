#include<stdio.h>
#include<stdlib.h>   

void main()
{
    int a[50],i,n=0,c,e,p;
    printf("-----Array Operations-----\n");
    while(1)
    {
        printf("Operations\n");
        printf("1.Insert\t");
        printf("2.Delete\t");
        printf("3.Display\t");
        printf("4.Exit\t");
        printf("Select an opertion: ");
        scanf("%d",&c);

        switch(c){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&e);
                printf("Enter postion: ");
                scanf("%d",&p);
                if(p<1 || p>n+1)
                {
                    printf("Invalid Postion");
                }
                else{
                    for(i=n;i>=p;i--)
                    {
                        a[i]=a[i-1];
                    }
                    a[p-1]=e;
                    n++;
                    printf("Element Inserted Sucessfully");
                }
                break;
            case 2:
                if(n == 0)
                {
                    printf("Array empty");
                }
                else
                {
                    printf("Enter the postion to be deleted: ");
                    scanf("%d",&p);
                    if (p<1 || p>n)
                    {
                    printf("Invalid postion");
                    }
                    else
                    {
                        e=a[p-1];
                        for(i=p-1;i<n-1;i++)
                        {
                            a[i]=a[i+1];
                        }
                        n--;
                        printf("Element deleted is %d\n", e);

                    }
                }
                break;
            case 3:
                if(n == 0)
                {
                    printf("Array empty");
                }
                else
                {
                    printf("The elements are: ");
                    for(i=0;i<n;i++)
                    {
                        printf("%d", a[i]);
                    }
                }
                break;

            case 4:
                printf("Program Exited");
                exit(0);
            
            default:
                printf("Invalid opertaion");
        }
    }
}