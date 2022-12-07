/*Program to make a class for printing job*/
#include <iostream>
using namespace std;

class printJobs
{
    int nPages;             // # of pages in current job
    static int nTrayPages;  // # of pages remaining in the tray
    static int nJobs;       // # of print jobs exceuting
public:
    printJobs(int np) : nPages(np)
    {
        ++nJobs;
        cout << "Printing " << np << " pages" << endl;
        nTrayPages = nTrayPages - np;
    }
    ~printJobs()
    {
        --nJobs;
    }
    static int getJobs()
    {
        return nJobs;
    }
    static int checkPages()
    {
        return nTrayPages;
    }
    static void loadPages(int nP)
    {
        nTrayPages += nP;
    }
};

int printJobs::nTrayPages = 500; // Definition and initialization -- load paper
int printJobs::nJobs = 0;        // Definition and initialization -- no. of jobs to start with

int main()
{
    cout << "Jobs = " << printJobs::getJobs() << endl;
    cout << "Pages = " << printJobs::checkPages() << endl;
    printJobs j1(10);
    cout << "Jobs = " << printJobs::getJobs() << endl;
    cout << "Pages = " << printJobs::checkPages() << endl;
    {
        printJobs j1(30), j2(20);
        cout << "Jobs = " << printJobs::getJobs() << endl;
        cout << "Pages = " << printJobs::checkPages() << endl;
        printJobs::loadPages(100);
    }
    cout << "Jobs = " << printJobs::getJobs() << endl;
    cout << "Pages = " << printJobs::checkPages() << endl;

    return 0;
}
