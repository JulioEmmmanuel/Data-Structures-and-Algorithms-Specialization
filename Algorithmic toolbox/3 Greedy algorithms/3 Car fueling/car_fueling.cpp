#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, int n, vector<int> & stops) {
    // write your code here

    int numRefills = 0;
    int current = 0;
    int i = -1;

    while(current < dist)
    {

        //if we can reach the goal return the number of refills
        if (current + tank >= dist)
        {
            return numRefills;
        }

        if(i < n-1){
            //continue until we find a station that we cannot reach
            if(stops[i+1] > current + tank){
                if (i+1 == 0)
                {
                    return -1;
                }
                //refull at the previous station
                // if i == 0 there is no previous station
                current = stops[i];
                //if the station is still unreachable, the goal cannot be reached
                if (stops[i+1] > current + tank)
                {
                    return -1;
                }
                numRefills++;
            }
            i++;
        }
        else if (i == n-1)
        {
            current = stops[i];
            numRefills++;
            i++;
        }
        else
        {
            return -1;
        }
    }

    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    stops.resize(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, n, stops) << "\n";

    return 0;
}
