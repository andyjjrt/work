#include <bits/stdc++.h>
#include "IDFT.h"
#include "IFFT.h"
#include "Utilities.h"
using namespace std;

int main() {
    Timer timer;
    int IDFT_count = 0;
    double IDFT_time = 0;
    int heartbeat = 0;

    while(1) {
        if(IDFT_time + timer.get_time() > 60) {
            IDFT_count--;
            break;
        }
        // if(IDFT_time > heartbeat) cout << heartbeat++ << " sec" << endl;
        IDFT_time += timer.get_time();
        IDFT idft(1024);
        timer.start();
        idft.process();
        timer.stop();
        IDFT_count++;
    }

    cout << IDFT_count << " " << IDFT_time << endl;

    int IFFT_count = 0;
    double IFFT_time = 0;
    heartbeat = 0;

    while(1) {
        if(IFFT_time + timer.get_time() > 60) {
            IFFT_count--;
            break;
        }
        // if(IFFT_time > heartbeat) cout << heartbeat++ << " sec" << endl;
        IFFT_time += timer.get_time();
        IFFT ifft(1024);
        timer.start();
        ifft.process();
        timer.stop();
        IFFT_count++;
    }

    cout << IFFT_count << " " << IFFT_time << endl;
}