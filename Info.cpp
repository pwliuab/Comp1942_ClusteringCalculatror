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
        map<int, int> m;
        while(matrix.size()!=1){
        int skip_x = min_pair[0];
        int skip_y = min_pair[1];

        cout<<"Merged coordinate ("<<(matrix[min_pair[0]][0])<<","<<matrix[min_pair[0]][1]<<")and ("<<matrix[min_pair[1]][0]<<","<<matrix[min_pair[1]][1]<<")"<<endl;
        
        draw_diagram(matrix, min_pair, m);
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
int main(){
        // input controller, to get distance between two points. 
        // vector<vector<double>> matrix;
        
        // int input[8][2] = {{4,5}, {5,3}, {-7,-2}, {-2,1}, {13,15}, {11,9}, {-5,-3}, {5,4}};
        // initial_matrix(4, 5, matrix);
        // initial_matrix(5, 3, matrix);
        // initial_matrix(-7, -2, matrix);
        // initial_matrix(-2, 1, matrix);
        // initial_matrix(13, 15, matrix);
        // initial_matrix(11, 9, matrix);
        // initial_matrix(-5, -3, matrix);
        // initial_matrix(5, 4, matrix);



        //calculate the distance between each element in the matrix.
        // vector<double> min_pair;
        // visualize_matrix(matrix,min_pair);
        // get the min distance's position in matrix
        // int skip_x = min_pair[0];
        // int skip_y = min_pair[1];
        // control_panel(matrix, min_pair);
        // double x = double(1)/double(5);
        // cout<<"ANS: "<<log_2(x);
        // vector<vector<double>> matrix;
        // initial_matrix(2, 3, matrix);
        // initial_matrix(3, 3, matrix);
        // initial_matrix(6, 3, matrix);
        // initial_matrix(7, 2, matrix);
        // vector<double> min_pair;
        // visualize_matrix(matrix,min_pair);
        // int skip_x = min_pair[0];
        // int skip_y = min_pair[1];
        // control_panel(matrix, min_pair);
        
        vector<double> xxx;
        cout<<"How many T do you have?: ";
        int number_t =0;
        cin>>number_t;
        cout<<"Total parameters:"<<number_t<<endl;
        int i = 1;

        while(number_t--){
                string inp;
                double ans = 0;
                double leftdigit =0;
                cout<<"Please enter your input "<<i<<" : ";
                cin>>inp;
                for(int i = 0 ; i < inp.size() ; i++){
                        if(isdigit(inp[i])){
                               ans = 10*ans + (inp[i] - '0');
                        }
                        else {
                                leftdigit = ans;
                                ans = 0;
                        }
                }
                ans = double(leftdigit) / ans;
                xxx.push_back(ans);
                i++;
        }

        // xxx.push_back(double(1)/double(5));
        // xxx.push_back(double(2)/double(5));
        // xxx.push_back(double(2)/double(5));
        info_T(xxx);
        cin.get();
        
        
                
        
        
}