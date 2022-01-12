#include <algorithm>
#include <queue>
#include <vector>
#define MAX_SIZE 200000
using namespace std;


////
int numQuery;
int mNumber, mStock, mQuantity, mPrice;
int userAns, ans;
bool isCorrect = false;
////


typedef pair<int, int> pii;

int hBuy[MAX_SIZE][4];
int hSell[MAX_SIZE][4];
const int INF =1e9;
vector< vector<pii>> edge;


struct stock{
    int num,sname,quan,cost;
};
typedef struct stock stock;

class compair {

//연산자 오버로딩부분
public:    bool operator() (const pair<int, int> a, const pair<int, int> b) {
    return a.second > b.second;
}

};
priority_queue<stock, vector<stock>, compare> pq;

void dijkstra(int n){
   vector <int> dist(n+1,INF);
    dist[1]=0;
    priority_queue <pii> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = -pq.top().second;
        pq.pop();
        
        if(dist[here] <cost)continue;
        for(int i=0; i<edge[here].size(); i++){
            int next = edge[here][i].first;
            int nextcost = edge[here][i].second;
            
            if(dist[next] > dist[here]+nextcost){
                dist[next] = dist[here]+nextcost;
                pq.push({-dist[next], next});
            }

        }
    }
}

void init()
{
    mNumber =1;
    int hBuy[MAX_SIZE][4]={0,};
    int hSell[MAX_SIZE][4]={0,};
    //[i][0] ==주문번호, [i][1] ==주식종목, [i][2] ==주문수량, [i][3] ==단가
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
//주문 번호가 mNumber인 매도 주문, 주식 종목은 mStock, 주문 수량은 mQuantity, 매도 희망 가격은 mPrice이다.
{
    int left; //남은 수량
    prior
    
    
    
    //
    
    return 0;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    return 0;
}

void cancel(int mNumber)
{
}

int bestProfit(int mStock)
{
    return 0;
}

using namespace std;
int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }    return 0;
}
