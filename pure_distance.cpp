#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
using namespace std;
vector<int> draw_map(8,1);
vector<vector<vector<double>>> cluster;
vector<vector<double>> temp;
double distance(double x1, double y1, double x2, double y2){
        double dis = (x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2);
        cout<<"Distance between two point (" <<x1<<","<<y1<<"), ("<<x2<<","<<y2<< ") is: "<<dis<<endl;
        return dis;
}

void mid_point(double x1, double y1, double x2, double y2, vector<double>& min_pair){

        double x = double((x1 + x2)) /2;
        double y = double((y1 + y2)) / 2;
        min_pair.pop_back();
        min_pair.pop_back();
        min_pair.push_back(x);
        min_pair.push_back(y);
        cout<<"The midpoint:( "<<x<<","<<y<<")"<<endl;
        
        
}
void initial_matrix(double x, double y, vector<vector<double>>& copy){
        vector<double> input;
        input.push_back(x);
        input.push_back(y);
        copy.push_back(input);
}       
void find_min_d(vector<vector<double>>& matrix, vector<double>& min_pair, int i, int j, int d){
        int min_n = 10000;
        if(min_n > d){

        if(min_pair.size()){
                min_pair.pop_back();
                min_pair.pop_back();
        }
        min_pair.push_back(i);
        min_pair.push_back(j);
        min_n = d;
                        }
}
int visualize_matrix(vector<vector<double>>& matrix, vector<double>& min_pair){
        double min_n = 100000;

        for(int i = 0; i < matrix.size(); i++){
                for(int j = i+1; j < matrix.size(); j++){
                        if((matrix[i][0] == matrix[j][0])&& (matrix[j][1] ==  matrix[i][1]))
                                continue;

                        double d = distance(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1]);
                        
                        if(min_n > d){

                                if(min_pair.size()){
                                        min_pair.pop_back();
                                        min_pair.pop_back();
                                }
                        min_pair.push_back(i);
                        min_pair.push_back(j);
                        min_n = d;
                        }
                }
                cout<<endl;
                
        }
        cout<<"The minimun distance: "<<min_n<<endl;
        return min_n;
}

int draw_diagram(vector<vector<double>>& matrix, vector<double>& min_pair, map<int, int>& m){
        double dis = (matrix[min_pair[0]][0] - matrix[min_pair[0]][1]) * (matrix[min_pair[0]][0] - matrix[min_pair[0]][1])
                     + (matrix[min_pair[1]][1] - matrix[min_pair[1]][0])*(matrix[min_pair[1]][1] - matrix[min_pair[1]][0]);
        
        return 0;
}

void control_panel(vector<vector<double>>& matrix, vector<double>& min_pair){
        int x = 6;
        visualize_matrix(matrix,min_pair);
        while(matrix.size()!=1){
        int skip_x = min_pair[0];
        int skip_y = min_pair[1];

        cout<<"Merged coordinate ("<<(matrix[min_pair[0]][0])<<","<<matrix[min_pair[0]][1]<<")and ("<<matrix[min_pair[1]][0]<<","<<matrix[min_pair[1]][1]<<")"<<endl;
        
        mid_point(matrix[min_pair[0]][0], matrix[min_pair[0]][1], matrix[min_pair[1]][0],matrix[min_pair[1]][1],min_pair);

        for(int i = 0; i < matrix.size(); i++){
                if( i != skip_x &&  i != skip_y){
                //distance(min_pair[0],min_pair[1], matrix[i][0], matrix[i][1]);
                
                }
                else if(i == skip_x) {

                        matrix[i][0] = min_pair[0];
                        matrix[i][1] = min_pair[1];
                }

        }
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        matrix.erase(matrix.begin()+skip_y);

        visualize_matrix(matrix,min_pair);
        }
}

double log_2(double x){
        double ans = double(log(x))/double(log(2));
        return ans;
}

double info_T(vector<double> input){
        int x = input.size();
        double ans = 0;
        int i = 0;
        while(x--){
                double temp = -1 * double(input[i]) * double(log(input[i])) / double(log(2));
                ans += temp;
                i++;
        }
        cout<<"The info_T : "<<ans;
        return ans;
}

double Cart_info(vector<double> value){
        int x = value.size();
        double ans = 0;
        int i = 0;
        while(x--){
                double temp = value[i]*value[i];
                ans += temp;
                i++;
        }
        ans = 1 - ans;
        cout<<"The info_T : "<<ans;
        return ans;        
}

double pure_distance(double x1, double y1, double x2, double y2){
        double dis = (x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2);
        dis = sqrt(dis);
        return dis;
}

void average_distance(vector<vector<double>>& matrix){
    int max_n = 0;
    int coordinate = 0;
    for(int i = 0; i< matrix.size(); i++){
        double ans =0;
        for(int j = 0; j < matrix.size(); j++){
            if(j != i){
            double announce = pure_distance(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1]); 
            ans += pure_distance(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1]);
            cout<<"distance between x"<<i+1<<" and x"<<j+1<<" is:"<<announce<<endl;
            }
        }
       if(ans > max_n){
           max_n = ans;
           coordinate = i;
       }
        cout<<"the x"<<i+1<<"average distance is: "<<ans/double(matrix.size()-1)<<endl;
    }
    cout<<"The suggested cluster A and cluster B is : "<<endl;
    
    cout<<"cluster A: "<<coordinate+1<<endl;

    cout<<"cluster B:{ ";
    for(int i = 0; i < matrix.size() ; i++){
        if(i != coordinate) cout<<i+1<<" ,";
    }
    cout<<" }"<<endl;
    
    for(int i = 0; i < matrix.size(); i++){
        if (i != coordinate)
        cout<<"d(x"<<i+1<<" ,A):"<<pure_distance(matrix[i][0], matrix[i][1], matrix[coordinate][0], matrix[coordinate][1])<<endl;
    }
        for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j< matrix.size(); j++){
            if (j != coordinate && i != coordinate && i!=j)
            cout<<"d(x"<<i+1<<" ,B):"<<pure_distance(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1])<<endl;
        }
    }
}

int main(){

        vector<vector<double>> matrix;
        double x = 0;// x coordinate
        double y = 0;// y coordinate
        int n = 2;// number of inputs
        int count = n;
        int i = 1;
        while(n--){
            cout<<"please enter x"<<i<<":";
            cin>>x;
            cout<<"please enter y"<<i<<":";
            cin>>y;
            initial_matrix(x, y, matrix);
            i++;
        }

            cout<<"distance between those two points :"<<pure_distance(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
        
        
        
        
}