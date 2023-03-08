#include <bits/stdc++.h>
using namespace std;

class App {

public:
    App(int d) { download = d; }
    ~App() {};

    int getDownload() { return download; }
    void increaseDownload() { ++download; }

private:
    int download;

};

class JJBox : public App{
public:
    JJBox(int download) : App(download) {
        song = download * 5;
    };
    void update_song(){
        song = getDownload() * 5;
    };
    int get_song(){
        return song;
    }
private:
    int song;
};

class Nosebook : public App{
public:
    Nosebook(int download) : App(download) {
        myfriend = download * 3 + 5;
    };
    void update_friend(){
        myfriend = getDownload() * 3 + 5;
    };
    int get_friend(){
        return myfriend;
    }
private:
    int myfriend;
};

int main(){
    int download1, download2;
    cin >> download1 >> download2;
    JJBox jjbox(download1);
    Nosebook nosebook(download2);

    int command;
    while(cin >> command){
        if(command == -1) break;
        
        switch(command){
            case 1:
                jjbox.increaseDownload();
                break;
            case 2:
                nosebook.increaseDownload();
                break;
            case 3:
                jjbox.increaseDownload();
                nosebook.increaseDownload();
                break;
            case 4:
                jjbox.update_song();
                break;
            case 5:
                nosebook.update_friend();
                break;
        }

        cout << "JJBox now has " << jjbox.get_song() << " songs." << endl;
        cout << "NoseBook now has " << nosebook.get_friend() << " friends." << endl;
        cout << "==========" << endl;
    }
}