#include <stdio.h>

int len_digits(long int n){
    int l=0;
    while(n>0){
        n=n/10;
        l++;
    }
    return l;
}

bool AreAll9s(int num[], int len ) {
    for(int i=0;i<len;i++){
        if(num[i]!=9){
            return false;
        }
    }
    return true;
}
void generateNextPalindrome(int num[],int len){
    
     if( AreAll9s( num, len ) )
    {
        printf( "1 ");
        for(int i = 1; i < len; i++ )
            printf( "0 " );
        printf( "1" );
    }
    else {
        int middle=(len%2)? len/2 +1 : len/2;
        middle=middle-1;
        if(len%2){
            if(num[middle-1] < num[middle] && num[middle] > num[middle+1]){
                printf("i am here1\n");
                int middletemp=middle;
                for(int i=middle;i>=0;i--){
                    num[middletemp++]=num[i];
                }
                for(int i=0;i<len;i++){
                    printf("%d ",num[i]);
                }
            }else if(num[middle-1] < num[middle] && num[middle] <= num[middle+1]){
                printf("i am here2\n");
                int middletemp=middle+1;
                for(int i=middle-1;i>=0;i--){
                    num[middletemp++]=num[i];
                }
                num[middle+1]=num[middle];
                num[middle-1]=num[middle];
                for(int i=0;i<len;i++){
                    printf("%d ",num[i]);
                }
            }
        }else{
            if(num[middle] > num[middle+1] ){
                printf("i am here3\n");
                int middletemp=middle+1;
                for(int i=middle;i>=0;i--){
                    num[middletemp++]=num[i];
                }
                for(int i=0;i<len;i++){
                    printf("%d ",num[i]);
                }
                
            }else if(num[middle] == num[middle+1]){
                 printf("i am here5\n");
                 int middletemp=middle+1;
                 int temp=num[middletemp];
                 while((num[middle] != num[middletemp]) && middle>=0 && middletemp<=len-1){
                     middle--;
                     middletemp++;
                 }
                
                for(int i=middle;i>=0;i--){
                        num[middletemp++]=num[i];
                    }
                    
                num[middle]=temp+1;
                num[middle+1]=temp+1;
                for(int i=0;i<len;i++){
                    printf("%d ",num[i]);
                }
                 
            }else{
                printf("i am here4\n");
                int middletemp=middle+1;
                
                int temp=num[middletemp];
                for(int i=middle;i>=0;i--){
                    num[middletemp++]=num[i];
                }
                num[middle]=temp;
                num[middle+1]=temp;
                for(int i=0;i<len;i++){
                    printf("%d ",num[i]);
                }
            }
        }
        
    }    
}

int main(){
	long int i,n,ntemp;
	scanf("%ld",&n);
	ntemp=n;
	int len;
	len=len_digits(n);
    printf("%d",len);
    
    //make the number as  array
    int num[len];
    for(i=0;i<len;i++){
        num[i]= ntemp%10;
        ntemp=ntemp/10;
    }
   
    //reverese the array
    int be=0,en=len-1;
    while(be<en){
        int temp=num[be];
        num[be]=num[en];
        num[en]=temp;
        be++;
        en--;
    }
    
    
	generateNextPalindrome( num, len);

	return 0;
}
