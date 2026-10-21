#define MAXN 100000
int a[MAXN]; //A对每个石子的评价
int count[201];//记录每种价值和的石子数量

int main(void) {
    int n;
    scanf("%d", &n);
    //记录A得分减去B得分
    long long diff = 0;
    //输入A对石子的评价
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //输入B的评价，并统计每个石子的价值和
    for(int i = 0; i < n; i++){
        int b;
        scanf("%d", &b);
        count[a[i] + b]++; //先假设所有石子都被B拿走
        diff -= b;
    }

    //turn为0表示A的回合，1表示B的回合
    int turn = 0;
    //按照a[i]+b[i]从大到小选择石子
    for (int sum = 200; sum >= 2; sum--) {
        while (count[sum] > 0) {
            if (turn == 0){
                //石子由A拿走，得分差增加a[i]+b[i]
                diff += sum;
            }
            //切换玩家
            turn = 1 - turn;
            //当前价值和的石子减少一个
            count[sum]--;
        }
    }

    if (diff > 0){
        printf("1\n");
    } else if (diff < 0){
        printf("-1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
