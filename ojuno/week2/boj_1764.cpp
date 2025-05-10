#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m;               // 명 수
    vector<string> result;          // 듣도 보도 못한 사람 

    // n = 듣도 못한 사람
    // m = 보도 못한 사람
    cin >> n >> m;
    
    vector<string> n_v;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        n_v.push_back(name);
    }
    sort(n_v.begin(), n_v.end());

    
    for (int i = 0; i < m; i++)
    {
        string m_v;
        cin >> m_v;
        if(binary_search(n_v.begin(), n_v.end(), m_v)){          // 이진 탐색으로 듣도 보도 못한 사람을 result에 저장
            result.push_back(m_v);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    
    return 0;


}