/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "linkheader.h"

int func_prime(int);
int print_array(int*,int );
void bubble_sort(int*,int );
void string_cpy(char*,char*);
void string_rev(char*);
int string_com(char*s,char*p);
void sentence_rev(char*);
void sentence_word_rev(char *);
float cominterest(int ,int , int );
int bin_to_decimal(int);
void rec_printstr(char*);
int strlen_rec(char*);
void pyramid_print(int );
void rev_array(int *,int);
int check_num(int*,int , int );
void mx_mn_array(int *,int );
void bubb_srt_arry(int*,int);
int set_bit(int ,int );
int clear_bit(int ,int );
int lexicographic_sort(const char* , const char* );
int lexicographic_sort_reverse(const char* , const char* );
int sort_by_number_of_distinct_characters(const char* , const char* );
int sort_by_length(const char* , const char* );
void string_sort(char** ,const int ,int (*cmp_func)(const char* , const char* ));
int main()
{
   int num[6]={11,20,4,4,50,4};
   int len,i,j,ele;
   len=sizeof(num)/sizeof(num[0]);
   char s[17]="aman dubey abcd";
   char d[15]="aman";
   
   char g[5][10];
   ele=sizeof(g)/sizeof(g[0]);
   
   
   printf("number after clearing the bit=%d\n",clear_bit(9,3));
   
}
/*String sort with advanced application*/
int lexicographic_sort(const char* a, const char* b) {
    for(int i=0,j=0;a[i]&&a[j];i++,j++){
        if(a[i]<b[j]){
            return -1;
        }else if(a[i]>b[j]){
            return 1;
        }
    }
    if(strlen(a)> strlen(b)){
        return 1;
    }
    else if(strlen(a)<strlen(b)){
        return -1;
    }else{
        return 0;
    }
    
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    for(int i=0,j=0;a[i]&&a[j];i++,j++){
        if(a[i]<b[j]){
            return 1;
        }else if(a[i]>b[j]){
            return -1;
        }
    }
    if(strlen(a)> strlen(b)){
        return -1;
    }
    else if(strlen(a)<strlen(b)){
        return 1;
    }else{
        return 0;
    }

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count[256] ={0},count_1[256]={0};
    int counta=0,countb=0;
    for(int i=0;i<strlen(a);i++){
        count[a[i]]++;
    }
    for(int i=0;i<256;i++){
        if(count[i]!=0){
            counta++;
        }
    }
    for(int i=0;i<strlen(b);i++){
        count_1[b[i]]++;
    }
    for(int i=0;i<256;i++){
        if(count_1[i]!=0){
            countb++;
        }
    }
    
    if(counta>countb){
        return 1;
    }else if(counta<countb){
        return -1;
    }else{
        return lexicographic_sort(a, b);
    }
    
    
}

int sort_by_length(const char* a, const char* b) {
    int l=0;
    if(strlen(a)>strlen(b)){
        return 1;
    }else if(strlen(a)<strlen(b)){
        return -1;
    }else{
        l=lexicographic_sort(a, b);
        return l;
    }

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(cmp_func(arr[i],arr[j])>0){
                char *temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    

}


/*Write a function to set a particular bit in a number*/
int set_bit(int n,int pos){
    n=n|1<<pos;
    return n;
}
int clear_bit(int n,int pos){
    n=n&(~(1<<pos));
    return n;
}

int toggle_bit(int n,int pos){
    
}
/*Write a program to bubble sort the array*/
void bubb_srt_arry(int *a,int n){
    int i=0,j,temp;
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    }
    
}
/*Write aprogram to check the max and min number in an array*/
void mx_mn_array(int *a,int n){
    int l=0,s=0,i;
    for(i=0;i<n;i++){
        if(a[i]>l){
        l=a[i];
    }
    }
    for(i=0;i<n;i++){
        if(a[i]<s){
            s=a[i];
        }
    }
    printf("largest=%d,smallest=%d\n",l,s);
}
/*write aprogram to check  repeating element in a array*/
int check_num(int*p,int l, int n){
    int i,c=0;
    
    for(i=0;i<l-1;i++){
        if(p[i]==n){
            c++;
        }
    }
    return c;
}

/*Write aprogram to reverse an array */
void rev_array(int *p,int n){
    int i,j,l,temp;
    
    for(i=0,j=n-1;i<j;i++,j--){
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
    }
}

/*write a program to print pyramid */
void pyramid_print(int n){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            printf(" ");
        }
        for(j=0;j<=2*i;j++){
            printf("*");
        }
        printf("\n");
    }
    
}
/*Find the length of given string usig recursion*/
int strlen_rec(char*s){
    static int i=0;
    if(s[i]){
        i++;
        strlen_rec(s);
    }else{
        return i;
    }
    
}

/*recursive function to print given string character by character*/
void rec_printstr(char *s){
    static int i=0;
    if(s[i]){
        printf("%c",s[i]);
        i++;
        rec_printstr(s);
    }
}

/*function to convert binary to decimal*/
int bin_to_decimal(int num){
    int dec,i=0;
    
    while(num){
        if(num%10!=0){
            dec=dec+pow(2,i);
        }
        num=num/10;
        i++;
    }
    return dec;
    
}

/*Function for calculating compound Interest*/
float cominterest(int amt,int interest, int year){
    float num;
    float temp;
    temp=1.0+(interest*0.01);
    printf("temp=%f\n",temp);
    num = amt*pow(temp,year);
    return num;
}
/*function to reverse the string word by word*/
void sentence_word_rev(char *s){
    string_rev(s);
    sentence_rev(s);
}

/*function to reverse the words in a given sentence*/
/*whole program is based on putting the i and j at correct spot for each word*/
void sentence_rev(char*s){
    int l=0,j=0,i=0;
    char temp;
    while(s[l]!='\0'){ /*run the loop till it reaches \0 */
        for(;s[j]!=' '&& s[j]!='\0';j++); //we need to put j to end of the sentence
        l=j;
        //printf("l=%d\n",l);
        j--;
        for(;j>i;j--,i++){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
        j=l+1;
        i=l+1;
        //printf("i =%d,j=%d\n",i,j);
    }
}

/*function to reverse the string*/
void string_rev(char*s){
    int i,j;
    char temp;
    for(i=0;s[i];i++);
    i--;
    
    for(j=0;j<i;j++,i--){
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;
        //printf("i=%d,j=%d\n",i,j);
    }
}
/*function to compare two string*/
int string_com(char*s,char*p){
    int i,j,l1,l2,c=0;
    for(i=0;s[i];i++);
    l1=i;
    for(j=0;p[j];j++);
    l2=j;
    if(l1!=l2){
        return 0;
    }else{
        for(i=0;s[i];i++){
            if(s[i]==p[i]){
                c++;
            }
        }
        if(c==l1){
            return 1;
        }else{
            return 0;
        }
    }
    
}
/*function to copy source string to destination*/
void string_cpy(char*s,char*p){
    int i,j,len;
    for(i=0;s[i];i++);
    len=i;
    for(i=0;s[i];i++){
        p[i]=s[i];
    }
    p[i]='\0';
}


/*function to bubble sort the array*/
void bubble_sort(int*n,int l){
    int i,j,temp;
    
    for(i=0;i<l-1;i++){
        for(j=0;j<l-1-i;j++){
            if(n[j]>n[j+1]){
                temp=n[j];
                n[j]=n[j+1];
                n[j+1]=temp;
            }
            
        }
    }
    
}
/*function to print an integer array*/
int print_array(int *n,int l){
    int i;
    for(i=0;i<=l;i++){
        printf("%d, ",n[i]);
    }
}

int func_prime(int n){
    int l=0,i;
    
    for(i=n;i>0;i--){
        if(n%i==0){
            l++;
        }
    }
    if(l>2){
        return 0;
    }else{
        return 1;
    }
    
}
