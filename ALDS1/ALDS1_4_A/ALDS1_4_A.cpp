
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int num_data;
    int num_search_data;
    long cnt_hit_data;
    long search_data;

    cin >> num_data;
    vector<long> in_data(num_data);

    for(int idx = 0; idx < num_data; idx++)
    {
        cin >> in_data[idx];
    }

    cin >> num_search_data;
    vector<long> in_search_data(num_search_data);

    cnt_hit_data = 0;
    for(int idx = 0; idx < num_search_data; idx++)
    {
        cin >> search_data;
        for(int jdx = 0; jdx < num_data; jdx++)
        {
            if (in_data[jdx] == search_data) 
            {
                cnt_hit_data++;
                break;
            }
        }
    }
    
    cout << cnt_hit_data << endl;
    return 0;
}