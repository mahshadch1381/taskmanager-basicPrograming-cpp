#include <iostream>
#include <string.h>
#include "clui.h"
using namespace std;
 struct deadline{
   	     int year;
   	     int month;
   	     int day;
   	 };
struct task{
    char* onvan;
    char* tozih;
    int importance;
   deadline time;
   	    
}; 

 void Sort(task *array, int size) {
   int  j;
   task key;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1].importance<key.importance) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key; } }

	   
void didan_yek_task(task m[],int &i, int &n){
	  clear_screen();   
	  cout<<"onvan task :"<<" "<<m[i].onvan<<endl;
	   cout<<"tozihat task :"<<" "<<m[i].tozih<<endl;
	   cout<<"ahamiat task :"<<" "<<m[i].importance<<endl;
       cout<<"deadline task :"<<" "<<m[i].time.year<<"/"<<m[i].time.month<<"/"<<m[i].time.day<<endl;
	   cout<<endl;
	   cout<<"if you want to delete this task enter'40'"<<endl; 
	   cout<<"if you want to back enter '20'"<<endl; 
	   cout<<"if you whant to exit enter '0'"<<endl;
	   cout<<"if you want to edit enter '50'"<<endl;
	   
			 flush(); 
	 }
			
 void delete_task(task m[],int i, int &n){
 	n=n-1;
   int j;
    delete m[i].onvan;
    delete m[i].tozih;
    for(j=i;j<n;j++)
       m[j]=m[j+1];
       
	 
       }    
	     
void new_task(task m[],int &i,int &n,char* onvan,char* tozih,int importance,int deadline1,int deadline2,int deadline3){
 n=n+1;
 m[i].onvan=onvan;
 m[i].tozih=tozih;
 m[i].importance=importance;
 m[i].time.year=deadline1;
 m[i].time.month=deadline2;
 m[i].time.day=deadline3;
  cout<<"you made a new task"<<endl;
  cout<<"if you want to exit enter '0'"<<endl;
  cout<<"if you want to make a new '10'"<<endl;
  cout<<"if you want to see table enter '20'"<<endl;
  cout<<"if you want to choose a task to see enter '30'"<<endl;
}	     
int main()
{
	init_clui();
   task m[1000];
   int j;
   for(j=0;j<100;j++){
   	
 m[j].importance=0;
 m[j].time.year=0;
 m[j].time.month=0;
 m[j].time.day=0;
   	
   }
   
   int a,i=-1,num=1,y,ma,d,n=0,x; 
   change_color_rgb(0,102,255);
    cout<<endl;
    printf("please enter a number to Continue\n");
     printf("10=>make a new task\n");
    printf("20=>namayesh hame\n");
    printf("30 => didan yek task\n");
    printf("0=>exit\n");
    cout<<endl;
    reset_color();
  
  while(num!=0){
        cin>>num;
        char* onv=new char[100];
        char* toz=new char[100];
       if(num==10){ 
           //new task:
           clear_screen(); 
           delay(3000);
           change_color_rgb(0,204,0);
            i++;
            printf("write title\n");
            cin.ignore();
            cin.getline(onv,100);
           printf("write tozih\n");
            cin.ignore();
            cin.getline(toz,100);
            printf("write ahamiat\n");
             cin>>a;
            printf("write 3 number for deadline\n");
             cin>>y>>ma>>d;
             reset_color();
            change_color_rgb(255,102,0);
            new_task(m,i,n,onv,toz,a,y,ma,d);
			}
	        reset_color();
    if(num==20){
       	//moshahede task haye mojood
       	 change_color_rgb(255,0,102);
		   Sort(m,n); 
		   delay(3000);
          cout<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" ";
	      cout<<"onvan";
	      cout<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" ";
	      cout<<"ahamiat";
	      cout<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" ";
	      cout<<"deadline"<<endl;
	      for(i=0;i<n;i++){
  	      cout<<endl;
  	      cout<<"task"<<i+1;
	      cout<<" "<<" "<<" "<<" "<<" "<<" "<<" ";
          cout<<m[i].onvan;
          cout<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" ";
	      cout<<m[i].importance;
	      cout<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" ";
	      cout<<m[i].time.year<<"/"<<m[i].time.month<<"/"<<m[i].time.day<<endl;}
	      flush(); 
	      reset_color();
	}
    
	       
    if(num==30){
    	change_color_rgb(150,10,15);
           //moshahede yek task khas
            clear_screen(); 
            cout<<"shomare andis task"<<endl;
	        cin>>i;
            didan_yek_task(m,i,n);
           cout<<endl;
            reset_color();
            
             change_color_rgb(153,102,0);
            printf("please enter a number to Continue\n");
            printf("10=>make a new task\n");
            printf("20=>namayesh hame\n");
            printf("30 => didan yek task\n");
             printf("0=>exit\n");
            cout<<endl;
            reset_color();
             flush(); 
			}
    if(num==40){
    	     change_color_rgb(153,51,255);
       		clear_screen(); 
       		cout<<"andis task i ke hazv beshe"<<endl;
    	    cin>>x;
    	    delete_task(m,x,n);
    	    cout<<"you deleted a task ";
    	    cout<<"if you want to exit enter '0'"<<endl;
            cout<<"if you want to make a new '10'"<<endl;
            cout<<"if you want to see table enter '20'"<<endl;
            cout<<"if you want to choose a task to see enter '30'"<<endl; 
			flush(); 
			reset_color();
	          }

	if(num==50){
	     	clear_screen(); 
	     	change_color_rgb(0,255,255);
	        int number,i,tedad,im,y,ma,d,z=0,andis;
	    	cout<<"enter tedad task baraye virayesh"<<endl;
	    	cin>>tedad;
	    	for(i=0;i<tedad;i++){
	    	char*jadid=new char[100];
	    	cout<<"andis task i ke avaz beshe"<<endl;
	    	 cin>>andis;
	    	cout<<"write parts number(1:(onvan)|2:(tozih)|3:(ahamiat)|4:(deadline))"<<endl;
	    	cin>>number;
	       if(number==1){
	    		 cout<<"title jadid"<<endl;
	    		 cin.ignore();
                 cin.getline(jadid,100);
                 delete m[andis].onvan;
	    		  m[andis].onvan=jadid;
	    		  
	    		}
	         if(number==2){
		        cout<<"tozih jadid"<<endl;
		      	cin.ignore();
                cin.getline(jadid,100);
                delete m[andis].tozih;
	    		m[andis].tozih=jadid;
	    		
	    	}
	         if(number==3){
	         	cout<<"new ahamiat"<<endl;
	        	cin>>im;
	        	 m[andis].importance=im;
			}
		    if(number==4){
				cin>>y>>ma>>d;
				m[andis].time.year=y;
                m[andis].time.month=ma;
                m[andis].time.day=d;
					}
                    }
                    cout<<"you edit the task"<<endl;
              cout<<"if you want to exit enter '0'"<<endl;
              cout<<"if you want to make a new '10'"<<endl;
              cout<<"if you want to see table enter '20'"<<endl;
              cout<<"if you want to choose a task to see enter '30'"<<endl;
               flush();
			   reset_color();       
             }
         }
         for(i=0;i<n;i++){
         	delete m[i].onvan;
         	delete m[i].tozih;
		         }
		      
    quit();  
    
   return 0;
   }
