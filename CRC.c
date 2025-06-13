#include<stdio.h>
#include<string.h>
#define MAX 100
void xor_operation(char* data,char* divisor,int l){
    for(int i=0;i<l;i++){
        if(data[i]==divisor[i]){
            data[i] = '0';
        }
        else{
            data[i] = '1';
        }
    }
}
void crc(char* data,char* divisor,char* remainder){
    int l1 = strlen(data);
    int l2 = strlen(divisor);
    char temp[l1+l2-1];
    strcpy(temp,data);
    for(int i=l1;i<l1+l2-1;i++){
        temp[i] = '0';
    }
    temp[l1+l2-1] = '\0';
    for(int i=0;i<l1;i++){
        if(temp[i] == '1'){
            xor_operation(temp+i,divisor,l2);
        }
    }
    strcpy(remainder,temp+l1);
}
void check(char* received,char* divisor){
    int l1 = strlen(received);
    int l2 = strlen(divisor);
    char temp[l1+l2-1];
    crc(received,divisor,temp);
    printf("Remainder at the Receiver Side : %s\n",temp);
    for(int i=0;i<strlen(temp);i++){
        if(temp[i]=='1'){
            printf("Error is FOund in the Received Code\n");
            return;
        }
    }
    printf("No Error Found in the Received Code\n");
    printf("Actual Message without CRC Bits : ");
    for(int i=0;i<=l1-l2;i++){
        printf("%c",received[i]);
    }
    printf("\n");
}
int main(){
    char data[MAX];
    char divisor[MAX];
    char remainder[MAX];
    char received[MAX];
    printf("Enter the Code to be sent : ");
    scanf("%s",data);
    printf("Enter the Divisor : ");
    scanf("%s",divisor);
    crc(data,divisor,remainder);
    printf("CRC Value : %s\n",remainder);
    strcat(data,remainder);
    printf("Code to be sent : %s\n",data);
    printf("Enter the Code Received at the Receiver Side : ");
    scanf("%s",received);
    check(received,divisor);
    return 0;
}