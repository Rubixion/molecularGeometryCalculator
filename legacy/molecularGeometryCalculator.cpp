#include <iostream>
#include <map>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace std;

int main() {   
    string molecule;
    int i, j, wants=0, got=0, valence=0, bonds=0, numatom=0, lonepairs, domains=0, midwant=0, midgot=0, height=1000, width=1000;
    char charge=0;
    string start;
    string atom;
    string midatom;
    map<string, int> s_mapStringValues = {    
            {"H", 1}, {"He", 2}, {"Li", 1}, {"Be", 2}, {"B", 3}, {"C", 4}, {"N", 5}, {"O", 6},
            {"F", 7}, {"Ne", 8}, {"Na", 1}, {"Mg", 2}, {"Al", 3}, {"Si", 4}, {"P", 5}, {"S", 6},
            {"Cl", 7}, {"Ar", 8}, {"K", 1}, {"Ca", 2}, {"Sc", 3}, {"Ti", 4}, {"V", 5}, {"Cr", 6},
            {"Mn", 7}, {"Fe", 8}, {"Co", 9}, {"Ni", 10}, {"Cu", 11}, {"Zn", 12}, {"Ga", 13}, {"Ge", 14},
            {"As", 15}, {"Se", 16}, {"Br", 17}, {"Kr", 18}, {"Rb", 1}, {"Sr", 2}, {"Y", 3}, {"Zr", 4}, {"Nb", 5}, {"Mo", 6},
            {"Tc", 7}, {"Ru", 8}, {"Rh", 9}, {"Pd", 10}, {"Ag", 11}, {"Cd", 12}, {"In", 13}, {"Sn", 14},
            {"Sb", 15}, {"Te", 16}, {"I", 17}, {"Xe", 18}
        };
        map<string, int> s_mapStringValues2 = {    
            {"H", 2}, {"He", 2}, {"Li", 8}, {"Be", 8}, {"B", 6}, {"C", 8}, {"N", 8}, {"O", 8},
            {"F", 8}, {"Ne", 8}, {"Na", 8}, {"Mg", 8}, {"Al", 8}, {"Si", 8}, {"P", 8}, {"S", 8},
            {"Cl", 8}, {"Ar", 8}, {"K", 18}, {"Ca", 18}, {"Sc", 18}, {"Ti", 18}, {"V", 18}, {"Cr", 18},
            {"Mn", 18}, {"Fe", 18}, {"Co", 18}, {"Ni", 18}, {"Cu", 18}, {"Zn", 18}, {"Ga", 18}, {"Ge", 18},
            {"As", 18}, {"Se", 18}, {"Br", 18}, {"Kr", 18}, {"Rb", 18}, {"Sr", 18}, {"Y", 18}, {"Zr", 18}, {"Nb", 18}, {"Mo", 18},
            {"Tc", 18}, {"Ru", 18}, {"Rh", 18}, {"Pd", 18}, {"Ag", 18}, {"Cd", 18}, {"In", 18}, {"Sn", 18},
            {"Sb", 18}, {"Te", 18}, {"I", 18}, {"Xe", 18}
        };
        cout << "What is the molecule: ";
        cin >> molecule;
        cout << "Is the charge +, -, or 0: ";
        cin >> charge;
        if(charge=='-'){
            cout << "What is the negative charge: ";
            cin >> got;
        }
        else if(charge=='+'){
            cout << "What is the positive charge: ";
            cin >> got;
            got*=-1;
        }
        int length = molecule.length();
        for (i=0; i<=length-1; i++)
            {
                atom=molecule[i];
                if(isdigit(molecule[i+1])){
                    numatom = molecule[i + 1] - '0';
                    i+=1;
                }
                else if(islower(molecule[i+1])){
                    numatom=1;
                    i+=1;
                    atom = molecule.substr(i-1, 2);
                    if(isdigit(molecule[i+1])){
                        numatom = molecule[i + 1] - '0';
                        i+=1;
                    }   
                }
                else{
                    numatom=1;
                }
                if(numatom==1)
                    {
                        midatom=atom;
                    }
                domains+=numatom;


                for (j=1; j<=numatom; j++){
                    wants += s_mapStringValues2[atom];
                    got += s_mapStringValues[atom];
                    
                }
                
            }

        midwant += s_mapStringValues2[midatom];
        midgot += s_mapStringValues[midatom];
        domains-=1;
        bonds=(wants-got) / 2;
        lonepairs=((midwant)-(bonds*2))/2;

        if(domains==1)
        {
            lonepairs=0;
        }
    
    cout << "What would you like to do? \n A) Find a compounds geometry \n B) Display a compound \n C) Both \n";
    cin >> start;
    
    if(start=="A" || start=="C"){
        cout << "Bonds: " << bonds << "\n";
        cout << "Lone pairs: " << lonepairs << "\n";
        domains+=lonepairs;
        if(domains==1){
            cout <<"Electron domain geometry: linear\n";
            cout <<"Molecular geometry: linear\n";
            cout <<"Bond angle: 180\n";
        }
        if(domains==2){
            cout <<"Electron domain geometry: linear\n";
            cout <<"Molecular geometry: linear\n";
            cout <<"Bond angle: 180\n";
        }
        if(domains==3){
            cout <<"Electron domain geometry: trigonal planar\n";
            if(lonepairs==0){
            cout <<"Molecular geometry: trigonal planar\n";
            cout <<"Bond angle: 120\n";
            }
            else if(lonepairs==1){
                cout <<"Molecular geometry: bent\n";
                cout <<"Bond angle: 115\n";
            }
        }
        if(domains==4){
            cout <<"Electron domain geometry: tetrahedral\n";
            if(lonepairs==0){
                cout <<"Molecular geometry: tetrahedral\n";
                cout <<"Bond angle: 109.5\n";
            }
            else if(lonepairs==1){
                cout <<"Molecular geometry: trigonal pyrimidal\n";
                cout <<"Bond angle: 107\n";
            } 
            else if(lonepairs==2){
                cout <<"Molecular geometry: bent\n";
                cout <<"Bond angle: 104.5\n";
            } 
        }
    }
    if(start=="B" || start=="C"){
        if(domains==1){
            // linear
        }
        if(domains==2){
            // linear
        }
        
        if(domains==3){
            // trigonal planar
        }
        else if(lonepairs==1){
            // bent
        }
        if(domains==4){
            if(lonepairs==0){
                cv::Mat img = cv::imread("tetrahedral.png");
                if (img.empty()) {
                    cout << "Error: Image not found or unable to open the image file!" << endl;
                    return -1;
                }
                cout << "it got here at least";
                cv::putText(img, "H", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
                cv::putText(img, "O", cv::Point(100, 100), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                cv::imshow("Molecule", img);
                cv::waitKey(0);
                cv::imwrite("output_image.png", img);
            }
            else if(lonepairs==1){
                // trigonal pyrimidal
            } 
            else if(lonepairs==2){
                // bent
            } 
            
        }
    }
}
