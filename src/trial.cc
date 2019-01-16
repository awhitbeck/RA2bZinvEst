#include <fstream>

void trial() {
    std::ifstream in;
    in.open("gJets_signal_TOTAL.dat");
    int v[5];
    int nEC;
    string line;
    while(getline(myfile,line))

    if (in.is_open()) {
        int i = 0;
        while (in >> nEC) {
            v[i++] = nEC;
            
        }
    }
    
    for(int j=0;j<5;j++)
    {
    cout<<v[j]<<"\n";
    }
    in.close();

    return 0;
}
