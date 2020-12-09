#include <stdio.h>  
#include <stdlib.h>  

/* 函式申明 */  
int long_n(int n);  
int shuru(char *arr, int k, char *wei, int is_first);  
void jiami(char *arr, int k, int e, int n);  

/* 輸入函式，記錄從鍵盤輸入的明文*/  
int shuru(char *arr, int k, char *wei, int is_first)  
{  
    int i;  
    char ch;  
    /*判斷是否為第一分組的輸入，如果是則獲取輸入的字元，否則就將上一分組最後獲取的字元作為這一分組的第一個字元*/  
    if (is_first == 1)      
        ch = getchar();  
    else  
        ch = *wei;  
    for (i = 0; (i < k) && (ch != '\n');i++)  //獲取字元直到獲取到回車符為止  
    {  
        arr[i] = ch;  
        ch = getchar();  
    }  
    *wei = ch;  //最後獲取到的字元準備作為下一分組的第一個字元  
    for (i = i; i < k; i++)  
        arr[i] = 'a';  //輸入不夠一組個數的整數倍則補'a'(即為補零)  
    if (ch == '\n')  //接收到回車符返回0，否則為1  
        return 0;  
    else  
        return 1;  
}   

/*加密函式*/  
void jiami(char *arr, int k, int e, int n)  
{   
    int m = 0,c=1, i, j,t=0, shu,temp,num=0;  
    int *array;  
    /*Mi賦值過程*/  
    for (i = 0; i < k; i++)  
    {  
        temp = 1;  
        for (j = 0; j < (k-i-1)*2; j++)  
            temp = temp * 10;  
        shu = (int)arr[i] - 97;  
        m = m + temp * shu;  
    }  
    temp = e;  
    /*獲取e的二進位制表達形式的位數*/  
    do{  
        temp = temp / 2;  
        num++;  
    } while (temp != 0);  
    array = (int *)malloc(sizeof(int)*k);   //申請動態陣列  
    temp = e;  
    /*動態陣列儲存e的二進位制表達形式*/  
    for (i = 0; i < num; i++)  
    {  
        array[i] = temp % 2;  
        temp = temp / 2;  
    }  
    /*避免出現天文數字的演算法，詳情見上文文字說明*/  
    for (i = num - 1; i >= 0; i--)  
    {  
        t = t * 2;  
        temp = c*c;  
        if (temp > n)  
        {  
            for (j = 0; temp - n*j >= 0; j++);  
            j--;  
            c = temp - n*j;  
        }  
        else  
            c = temp;  
        if (array[i] == 1)  
        {  
            t = t + 1;  
            temp = c*m;  
            if (temp > n)  
            {  
                for (j = 0; temp - n*j >= 0; j++);  
                j--;  
                c = temp - n*j;  
            }  
            else  
                c = temp;         
        }  

        e = e / 2;  
    }  
    temp = c;  
    i = 0;  
    /*c的位數小於分組長度則在前補零*/  
    do{  
        temp = temp / 10;  
        i++;  
    } while (temp != 0);  
    for (i; i < num; i++)  
        printf("0");  
    printf("%d", c);  
}   

/*獲取分組的長度*/  
int long_n(int n)  
{   
    int temp,i,j,k,shi,comp=0;  
    temp = n;  
    /*獲取n的位數*/  
    for (i = 1; temp / 10 != 0; i++)  
    {  
        temp = temp / 10;  
    }  
    temp = i;  
    /*若n的位數為基數*/  
    if (i % 2 != 0)  
    {  
        i = i - 1;  
        return i;  
    }  
    /*若位數為偶數*/  
    else  
    {  
        for (j = 0; j < i/2; j++)  
        {  
            shi = 1;  
            for (k = 0; k < temp - 2; k++)  
                shi = shi * 10;  
            comp = comp + shi * 25;  
            temp = temp - 2;  
        }  
        if (comp <= n)  
            return i;  
        else  
        {  
            i = i - 2;  
            return i;  
        }  
    }  
}   

/*主函式*/  
int main(void)  
{  
    int p, q, e, d, n, fai_n, k, i,is_first=1;  
    char ch,*arr,wei='a';  
    printf("請輸入p、q、e值，用空格間隔開\n");  
    scanf("%d%d%d", &p, &q, &e);  //從鍵盤獲取p、q、e值  
    n = p*q;    
    fai_n = (p-1)*(q-1);   //Φ(n)  
    for (k = 0; (k*n + 1) % e != 0; k++);  
    if ((k*n + 1) % e == 0)  
        d = (k*n + 1) / e;  //d * e ≡ 1 (mod Φ(n))  
    k = long_n(n);  
    k = k / 2;  //分組的長度  
    ch = getchar(); //緩衝回車符  
    arr = (char *)malloc(sizeof(char)*k);  //申請動態陣列  
    printf("請輸入明文\n");  
    while (1)  
    {  
        i=shuru(arr,k,&wei,is_first);  //呼叫輸入字元的函式，接收到回車符返回0，否則為1  
        is_first = 0;  //第一分組錄入結束設為0  
        jiami(arr,k,e,n);  //呼叫加密函式  
        if (i == 0)  //接收到返回值為0跳出迴圈  
            break;  
    }  
    printf("\n");  
    return 0;  
} 
