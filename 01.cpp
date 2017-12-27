/**
*Problem:A program that show summation of two equations in c++
*Md. Belal Hossain
*Roll No: 160131
*Date:17.05.17
*Sample equation 1 :5x^5+4x^4-10x^3+9x^2-10x+15-10x^-13+100x^-23
*Sample equation 2 :10x^4+5x^3+20x+5+45x^-13-20x^-23
*/
#include<iostream>
#include<cstdio>
#include<ctype.h>
#include<cstring>

using namespace std;

class Coefficient{
    string s;
    int coef[30];
    int pow[30];
    int pod_len;
    public:
    void set_s(string str){
        s=str;
    }
    int get_coef(int i){
        return coef[i];
    }
    int get_pow(int i){
        return pow[i];
    }
    int KeepCoef();
    void sort_eqtn();///sort coef & pow of eqtn according to power
};
///********** main method ****************
int main(){
    string str1,str2;
    int sumE[150][2],ans[150][2];
    int coef[50][2],pod_len1,pod_len2,i,j,maxlen,ind=0,sumlen;
    //str1="5x^5+4x^4-10x^3+9x^2-10x+15-10x^-13+100x^-23";
    //str2="10x^4+5x^3+20x+5+45x^-13-20x^-23";
    cin>>str1;
    cin>>str2;
    Coefficient eqtn1,eqtn2;
    eqtn1.set_s(str1);
    eqtn2.set_s(str2);
    pod_len1=eqtn1.KeepCoef();
    pod_len2=eqtn2.KeepCoef();
    eqtn2.sort_eqtn();
    eqtn1.sort_eqtn();
    cout<<"\nEquation 1 :\n"<<endl;
    cout<<eqtn1.get_coef(0)<<"x^"<<eqtn1.get_pow(0)<<' ';
    for(i=1; i<pod_len1; i++){
        if(eqtn1.get_coef(i)<0)cout<<eqtn1.get_coef(i)<<"x^"<<eqtn1.get_pow(i)<<' ';
        else cout<<'+'<<eqtn1.get_coef(i)<<"x^"<<eqtn1.get_pow(i)<<' ';
    }
    cout<<"\n\nEquation 2 :\n"<<endl;
    cout<<eqtn2.get_coef(0)<<"x^"<<eqtn2.get_pow(0)<<' ';
    for(i=1; i<pod_len2; i++){
        if(eqtn2.get_coef(i)<0)cout<<eqtn2.get_coef(i)<<"x^"<<eqtn2.get_pow(i)<<' ';
        else cout<<'+'<<eqtn2.get_coef(i)<<"x^"<<eqtn2.get_pow(i)<<' ';
    }

    ///********** sum of two eqtn **********
    for(i=0; i<pod_len1; i++){
        sumE[i][0]=eqtn1.get_coef(i);
        sumE[i][1]=eqtn1.get_pow(i);
    }
    for(j=i,i=0; i<pod_len2; i++,j++){
        sumE[j][0]=eqtn2.get_coef(i);
        sumE[j][1]=eqtn2.get_pow(i);
    }
    maxlen=j;
    ///sort(sumE,sumE+maxlen,comp);
    for (i = 0; i < maxlen; i++){
        for (j = i + 1; j <maxlen; j++){
            if (sumE[i][1] < sumE[j][1])
            {
                int po,co;
                po=sumE[i][1];
                co=sumE[i][0];
                sumE[i][1] =sumE[j][1];
                sumE[i][0]=sumE[j][0];
                sumE[j][1] = po;
                sumE[j][0]=co;
            }
        }
    }
    for(i=0; i<maxlen; i++){
        if(sumE[i][1]==sumE[i+1][1]){
            ans[ind][0]=sumE[i][0]+sumE[i+1][0];
            ans[ind][1]=sumE[i][1];
            ind++;
            i++;
        }
        else{
            ans[ind][1]=sumE[i][1];
            ans[ind][0]=sumE[i][0];
            ind++;
        }
    }
    sumlen=ind;
    cout<<"\n\nSum of two equation :\n"<<endl;
    cout<<ans[0][0]<<"x^"<<ans[0][1]<<' ';
    for(i=1; i<sumlen; i++){
        if(ans[i][0]<0)cout<<ans[i][0]<<"x^"<<ans[i][1]<<' ';
        else cout<<'+'<<ans[i][0]<<"x^"<<ans[i][1]<<' ';
    }
    cout<<endl;
    return 0;
}

///************** KeepCoef() definition *************
int Coefficient::KeepCoef(){
    int len,i,ind=0,bac,m,num,j,sign,l,sum;
    bool suru=true;
    len=s.length();
    for(i=0; i<=len; i++){
        ///**********if have no x ,like--> -23 or power of x is 0*********
        if((s[i]=='+'||s[i]=='-'||s[i]=='\0')&&i!=0){
            if(suru==false){
                suru=true;
            }
            else{
                num=0;
                m=1;
                bac=1;
                for(j=i-1; bac==1; j--){
                    if(s[j]=='+'||s[j]=='-'||j==-1){
                        if(s[j]=='-'){sign=-1;}
                        else sign=1;
                        bac=0;
                    }
                    else{
                        num+=((int)s[j]-48)*m;
                        m*=10;
                    }
                }
                if(num==0)num=1;
                coef[ind]=num*sign;
                pow[ind]=0;
                ind++;
            }
            continue;
        }
    ///******if power of x is non 0 integer**********
        if(s[i]=='x'){
            m=1;
            num=0;
            bac=1;
            for(j=i-1; bac==1; j--){

                if(s[j]=='+'||s[j]=='-'||j==-1){
                    if(s[j]=='-'){sign=-1;}
                    else sign=1;
                    bac=0;
                }
                else{
                    num+=((int)s[j]-48)*m;
                    m*=10;
                }
            }
            if(num==0)num=1;
            coef[ind]=num*sign;
            ///*********coefficient end***&***power start******
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='\0'){
                pow[ind]=1;
            }
            else if(s[i+1]=='^'){
                sign=1;
                if(s[i+2]=='-'){
                    i++;
                    sign=-1;
                }
                i+=2;
                l=0;
                j=i;
                while(s[j]!='+'&&s[j]!='-'&&s[j]!='\0'){
                    l++;
                    j++;
                }
                m=1;
                num=0;
                for(j=i+l-1; j>=i; j--){
                        num+=((int)s[j]-48)*m;
                        m*=10;
                }
                pow[ind]=num*sign;
                i=i+l-1;
            }
            ind++;
            suru=false;
        }
    }
    pod_len=ind;
    return pod_len;
}
///***********sort_eqtn() definition **********
void Coefficient::sort_eqtn(){
    int i, j,po,co;
    for (i = 0; i < pod_len; i++){
        for (j = i + 1; j < pod_len; j++){
            if (pow[i] < pow[j])
            {
                po,co;
                po= pow[i];
                co=coef[i];
                pow[i] = pow[j];
                coef[i]=coef[j];
                pow[j] = po;
                coef[j]=co;
            }
        }
    }
}
