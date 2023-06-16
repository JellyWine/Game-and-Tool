#include <cstdlib> //rand()
#include <ctime> //time()
#include <iostream>
#include <string> //getline()

using namespace std;

int main()
{
    srand(time(NULL));
    int n = (rand() % 9000) + 1000; //1000~9999
    int c[4], k[4], x;
    c[0] = n % 10;
    c[1] = (n % 100 - n % 10) / 10;
    c[2] = (n % 1000 - n % 100) / 100;
    c[3] = (n - n % 1000) / 1000;
    cout << "這是1A2B遊戲~" << endl;
    cout << "規則說明：" << endl;
    cout << "有一個隨機生成的四位數(範圍為1000~9999)，請輸入一個四位數字後按下enter" << endl;
    cout << "如果這個四位數字有1個數字位置對且位置也對=>A，2個數字對但位置不對=>B，那麼將會顯示1A2B" << endl;
    cout<<"是否開始遊戲? (Yes/NO)"<<endl;
    string choice="no";
    cin>>choice;
    while (choice == "Yes" || choice == "yes" || choice == "YES")
    {
        cout << "請輸入一個四位數字: ";
        cin >> x;
        int A = 0, B = 0;
        k[0] = x % 10;
        k[1] = (x % 100 - x % 10) / 10;
        k[2] = (x % 1000 - x % 100) / 100;
        k[3] = (x - x % 1000) / 1000;

        bool marked[4] = {false}; // 紀錄已判定為B的位置

        for (int t = 0; t < 4; t++)
        {
            if (k[t] == c[t])
            {
                A = A + 1;
                marked[t] = true; // 將已判定為A的位置標記為true
            }
        }

        for (int m = 0; m < 4; m++)
        {
            if (!marked[m]) // 只處理未被標記的位置
            {
                for (int t = 0; t < 4; t++)
                {
                    if (k[m] == c[t] && m != t)
                    {
                        B = B + 1;
                        marked[m] = true; // 將已判定為B的位置標記為true
                        break; // 找到符合條件的位置後，跳出迴圈
                    }
                }
            }
        }

        cout << k[3] << k[2] << k[1] << k[0] << " ===> " << A << "A" << B << "B  ";

        if (A == 4 && B == 0)
        {
            cout << "恭喜答對了！" << endl;
            cout << "是否繼續遊戲？(YES/NO): ";
            choice="no";
            cin>>choice;
            if (choice == "Yes" || choice == "yes" || choice == "YES")
            {
                n = (rand() % 9000) + 1000;
                c[0] = n % 10;
                c[1] = (n % 100 - n % 10) / 10;
                c[2] = (n % 1000 - n % 100) / 100;
                c[3] = (n - n % 1000) / 1000;
            }
            else
            {
               cout<<"感謝遊玩!"<<endl;
               break;
            }
        }
    }

    cout << "遊戲結束！" << endl;

    return 0;
}
