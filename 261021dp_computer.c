#include<stdio.h>
#define MAX 5000
typedef struct{
    int l,r,d;
}task;

void quickSort(task arr[],int left,int right){
    int i=left,j=right;
    int pivot=arr[left+(right-left)/2].r;
    while(i<=j){
        while(arr[i].r<pivot)i++;
        while(arr[j].r>pivot)j--;
        if(i<=j){
            task temp=arr[i];
            arr[i]=arr[j];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    if(left<j)quickSort(arr,left,j);
    if(i<right)quickSort(arr,i,right);
}
int main(){
    int arr[10000];
    int n=0;
    int x;
    while(scanf("%d",&x)==1){
        arr[n++]=x;
    }
    int taskcnt=n/3;
    task tasks[1005];
    for(int i=0;i<taskcnt;i++){
        tasks[i].l=arr[i*3];
        tasks[i].r=arr[i*3+1];
        tasks[i].d=arr[i*3+2];
    }
    if(taskcnt>1)quickSort(tasks,0,taskcnt-1);
    int used[MAX]={0};
    for(int i=0;i<taskcnt;i++){
        int l=tasks[i].l;
        int r=tasks[i].r;
        int d=tasks[i].d;
        int cnt=0;
        for(int j=l;j<=r;j++){
            if(used[j]==1) cnt++;
        }
        int need=d-cnt;
        if(need<=0)continue;
        for(int t=r;t>=l && need>0;t--){
            if(!used[t]){
                used[t]=1;
                need--;
            }
        }
    }
    int ans=0;
    for(int i=0;i<MAX;i++){
        if(used[i])ans++;
    }
    printf("%d\n",ans);
    return 0;
}
