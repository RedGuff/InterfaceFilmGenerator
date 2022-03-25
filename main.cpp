#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>    // std::sort
using namespace std;

bool compareFunction (std::string a, std::string b) {
    return a<b;
} //compare any way you like, here I am using the default string comparison

int main() {
    int choice = 0;
    int time_min = 0;
    int ips = 0;
    int size_Pixels = 0;
    int x = 0;
    int y = 0;
    string cmd = "";
    cout << "Interface Film Generator." << endl; // Later in GUI, of course!
    cout << "" << endl;
    vector<string> genres;
    genres = {""};
    genres.push_back("Disaster");
    genres.push_back("Science-Fiction");
    genres.push_back("Western");
    genres.push_back("Romance");
    genres.push_back("Sexy");
    genres.push_back("Pornografic");
    genres.push_back("Slasher");
    genres.push_back("Zombies");
    genres.push_back("Sport");
    genres.push_back("Crime");
    genres.push_back("Action");
    genres.push_back("Man Hunting");
    genres.push_back("Monster");
    genres.push_back("Comedy");
    genres.push_back("Fantasy");
    genres.push_back("Historical");
    genres.push_back("War");
    genres.push_back("Noir");
    genres.push_back("Opera");
    genres.push_back("Bollywood");
    genres.push_back("Thriller");
    genres.push_back("Melodrama");
    sort(genres.begin(),genres.end(),compareFunction);
    cout << "What kind of film do You want?" << endl;
    cout << "(If your number is out (0 for example): random choice!)" << endl;
    for (int item=1; item<genres.size(); ++item) {
        cout << item << ") " << genres[item] << endl;
    }
    cin >> choice ;
    if ((choice <1) || (choice >genres.size()-1)) {
        std::random_device device;
        std::mt19937 generator(device());
        std::uniform_int_distribution<int> distribution(1,genres.size()-1);
        choice = distribution(generator);
        clog << "My random choice: " << choice << ") " << genres[choice] << endl;
    }
    cout << "How long dou you want your film, in minuts?" << endl;
    cout << "(10 is good for tests.)" << endl;
    cout << "(90 is good for standard films, but it's VERY LONG to calculate!)" << endl;
    cout << "(240 seems good for bollywood and operas, but it's HORRIBLY LONG to calculate!)" << endl;
    cin >> time_min;
    if (time_min<1) {
        time_min=1 ;
        cerr << "Too small! I correct time." << endl;
    }
    if (time_min>420) {
        time_min=420 ;
        cerr << "Too long! I correct time." << endl;
    }
    cout << "Quality:" << endl;
    cout << "Number of images in each second:" << endl;
    cout << "10 is good for tests." << endl;
    cout << "30 is generally sufficient, but it's VERY LONG to calculate!" << endl;
    cout << "60 is needed for speed films, but it's HORRIBLY LONG to calculate!" << endl;
    cin >> ips;
    if (ips<1) {
        ips=1;
        cerr << "Not enough! I correct ips." << endl;
    }
    if (ips>120) {
        ips=120 ;
        cerr << "Too much! I correct ips." << endl;
    }
    cout << "Size, in pîxels:" << endl;
    cout << "1) For tests: 160 * 90." << endl;
    cout << "2) Full HD: 1920 * 1080 (VERY LONG to calculate!)." << endl;
    cout << "3) Ultra HD (\"4K\"): 3840 * 2160 (HORRIBLY LONG to calculate!)." << endl;
    cin >> size_Pixels;
    switch (size_Pixels) { // int or char only;
    case '1':
        x = 160;
        y = 90;
        break;
    case '2':
        x = 1920;
        y = 1080;
        break;
    case '3':
        x = 3840;
        y = 2160;
        break;
    default:
        cerr << "I correct the size, in pixels." << endl;
        x = 1920;
        y = 1080;
        break;
    }
    cout << "Conclusion:" << endl;
    cout << choice << ") " << genres[choice] << endl;
    cout << "Time: " << time_min << " minuts."<< endl;
    cout << "Quality: x = "<< x << " * " << y << ", " << ips << " i/s, "<< endl;
    cmd = "FilmGenerator "+ genres[choice] + " " + to_string(time_min) + " " + to_string(x) + " " + to_string(y) + " " + to_string(ips);
    const char *command = cmd.c_str();
    system(command);
    return 0;
}
