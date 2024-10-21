//冪集合
#include<iostream>

using namespace std;

//打印子集合
void print_subset(int store[],int sv){
	cout<<"{";
	for(int x=0;x<sv;x+=1){
		cout<<store[x];
		if(x<sv-1){
			cout<<",";
		}
	}
	cout<<"}\n";
}
//找出子集合
void subset(int* s,int n,int* store,int sv,int index){//(S集合,S集合的元素數量,暫存子集合的元素,暫存索引值,索引值)
	if(index==n){//如果瀏覽完所有元素就開始打印
		print_subset(store,sv);
		return;
	}
	//不選擇當前元素,看下一個元素
	subset(s,n,store,sv,index+1);
	
	//選擇當前元素,之後看下一個元素
	store[sv++]=s[index];//將當前元素複製到子集合暫存
	subset(s,n,store,sv,index+1);
	
	//釋放當前元素
	store[sv]=0;
}

int main(){
	int N=0;//元素數量;
	cout<<"集合元素數量設置:";
	cin>>N;//決定集合大小
	int S[N]={0};;
	int store[N];//子集合元素暫存用
	cout<<"S=";
	for(int i=0;i<N;i+=1){
		cin>>S[i];
	}
	cout<<"以下為它的冪集合\n";
	subset(S,N,store,0,0);//(S集合,暫存子集合,索引值)
}