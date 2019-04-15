#include<stdio.h>
#include<conio.h>
int main()
 {
   int n,p[10],bt[10];
   int w[10],t[10],Awt,Atat,i,at[10],timeQ,pr[10];

   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("Enter time quantum : ");
   scanf("%d",&timeQ);
   printf("\n\t Enter Burst_Time : Priority : Arrival_Time  \n");
 
   for(i=0;i<n;i++)
    {
      printf("\n Process %d ",i+1);
      scanf("%d %d %d",&bt[i],&pr[i],&at[i]);
      p[i]=i+1;
    }
 
  int j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
       if(pr[i]<pr[j])
       {
            temp=pr[i];
            pr[i]=pr[j];
            pr[j]=temp;
     
            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
     
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
       }
   }
 }
w[0]=0;
Awt=0;
t[0]=bt[0];
Atat=t[0];
for(i=1;i<n;i++)
 {
    if(timeQ<n||timeQ>n)
	{
        w[i]=t[i-1];
        Awt+=w[i];
        t[i]=w[i]+bt[i];
        Atat+=t[i];
    }
 }
    printf("\n");
    printf("Gantt chart\n");
    for(i=0;i<n;i++)
    {
    printf("P %d ",p[i]);
    }
    printf("\n\nProcess \tArrival time \tBurst Time \tTurn Around Time \tWait Time \tPriority\n");
    for(i=0;i<n;i++)
	{
        printf("\n  %d",p[i]);
	    printf("\t\t %d",at[i]);
	    printf("\t\t %d",bt[i]); 
    	printf("\t\t %d",t[i]); 
    	printf("\t\t\t %d",w[i]); 
    	printf("\t\t %d",pr[i]);
    }
    
Atat/=n;
printf("\n Avg. Waiting Time : %d ",Awt);
printf("\n Avg. Turn Around Time : %d",Atat);
getch();
}








