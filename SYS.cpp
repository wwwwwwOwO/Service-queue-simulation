#include <iostream>
#include <queue>
#include "RANDOM.H"
//#include "RANDOM.CPP"
#define N 300
#define T 60
using namespace std;
int main(){
    pair<int, int> win[5];
    queue<int> q;
    int order_num = 0;
    int waiting_time[N+1] = {0};
    int num_of_guest;
    Random rand;

    for (int i = 0; i < 5;i++){
        win[i] = pair(0, 0);
    }

        for (int time = 1; time <= T; time++)
        {

            for (int i = 0; i < 5; i++)
            {
                if (win[i].second == 0&&!q.empty())
                {
                    win[i].first = q.front();
                    win[i].second = rand.random_integer(1, 5);
                    waiting_time[q.front()] += time;
                    q.pop();
                }
            }

            for (int i = 0; i < 5; i++)
            {
                cout << " Windouw " << i + 1 << endl;
                
                cout << " NO. " << win[i].first << " called. " << endl;
            }

            cout << endl;
            cout << " There is/are " << q.size() << " guest(s) waiting. " << endl;
            cout << endl;

            num_of_guest = rand.poisson(N/T);

            cout << "Time : " << time << endl;
            for (int i = 0; i < num_of_guest; i++)
            {
                if(order_num<N)
                    q.push(++order_num);
                waiting_time[order_num] = -time;
            }
            cout << endl;
            cout << "There is/are " << num_of_guest << " new guest(s). " << endl;
            cout << "Their order numbers range from " << order_num - num_of_guest << " to " << order_num << endl;
            cout << endl;

            for (int i = 0; i < 5; i++)
            {
                if(win[i].second>0)
                win[i].second--;
            }
        }

            system("pause");

        return 0;
}