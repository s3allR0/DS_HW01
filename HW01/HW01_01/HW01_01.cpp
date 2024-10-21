//阿卡曼函數
#include<iostream>
using namespace std;
//遞迴函式
int Acmf_recursive(int m,int n){
    if(m==0){
        return n+1;
    }
	else if(n==0){
        return Acmf_recursive(m-1,1);
    }
	else{
        return Acmf_recursive(m-1,Acmf_recursive(m,n -1));
    }
}
//非遞迴函式
int Acmf_nonrecursive(int m,int n){
    int stack[1000];//用陣列來看成是遞迴的深度
    int top=0;
    stack[top]=m;

    while(top>=0){//非初始層判斷
        m=stack[top--];//取出之前的值,並且調整top
        
        if(m==0){
            n=n+1;
        }
			else if(n==0){
            	n=1;
            	stack[++top]=m-1;//將m-1的值存入下一層
        	}
		else{
            stack[++top]=m-1;//將m-1的值存入下一層
            stack[++top]=m;//再將m存入下一層
            n=n-1;
            //達到A(m-1,A(m,n-1))的效果;
        }
    }
    return n;
}

int main(){
    unsigned int m,n;
    cout<<"輸入m值:";
    cin>>m;
    cout<<"輸入n值:";
    cin>>n;
    if((m==0)||m<4&&n<4){//判斷m或n是否大於3
    	int ctrl;
    	cout<<"使用遞迴還是非遞迴?(1:遞迴/2:非遞迴):";
    	cin>>ctrl;
    	switch(ctrl){
    		case 1:
    			cout<<"Acmf("<<m<<","<<n<<")="<<Acmf_recursive(m,n)<<"\n";
    			break;
    		case 2:
    			cout<<"Acmf("<<m<<","<<n<<")="<<Acmf_nonrecursive(m,n)<<"\n";
    			break;
    		default:
    			cout<<"沒這個選項";
		}
	}
	else{
		cout<<"m或n的數值超過3了,無法執行";
	}
}
