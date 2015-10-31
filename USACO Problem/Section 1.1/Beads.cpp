#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("beads_in.txt");
    ofstream output("beads_out.txt");
    string necklace;
    input >> necklace;
    char bead[] = "rb";
    int i=0, k=0, length=0, temp, maxlength=0;
    while(i < necklace.size())
    {
        while(necklace.at((i-1)%necklace.size()) == 'w')
        {
            i--;
            if(i < (0-necklace.size()))
            {
                temp = necklace.size() + 1;
                length = necklace.size();
                break;
            }
        }
        while(true)
        {
            if(bead[k%2] == necklace.at(i%necklace.size()))
            {
                temp = i;
                break;
            }
            length++;
            i++;
            if(length > necklace.size())
            {
                temp = necklace.size() + 1;
                length = necklace.size();
                break;
            }
        }
        while(true)
        {
            if(bead[(k+1)%2] == necklace.at(i%necklace.size()))
            {
                break;
            }
            length++;
            i++;
            if(length > necklace.size())
            {
                temp = necklace.size() + 1;
                length = necklace.size();
                break;
            }
        }
        if(length > maxlength)
        {   maxlength = length; }
        length = 0;
        k++;
        i = temp;

    }
    output << maxlength << endl;
    return 0;
}
