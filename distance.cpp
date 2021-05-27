#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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

double average_distance(double x1, double y1, double x2, double y2, map<pair<double,double>, int>&cluster_pos, vector<vector<vector<double>>>&Cluster, vector<double>&min_pair){
        map<pair<double,double>,int>::iterator it1;
        map<pair<double,double>,int>::iterator it2;
        it1 = cluster_pos.find({x1,y1});        
        it2 = cluster_pos.find({x2,y2});
        double d = 0;
        if(it1 != cluster_pos.end() || it2 != cluster_pos.end()){
                if(it1 != cluster_pos.end() && it2 == cluster_pos.end()){
                        for(int i = 0; i < Cluster[cluster_pos[{x1,y1}]].size(); i++){
                                d += pure_distance(x2,y2, Cluster[cluster_pos[{x1,y1}]][i][0],Cluster[cluster_pos[{x1,y1}]][i][1]);
                                
                        }
                        
                        d = d/Cluster[cluster_pos[{x1,y1}]].size();
                        cout<<"The distance between point("<<x2<<","<<y2<<")"<<"and Cluster that contains("<<x1<<","<<y1<<") is :"<<d<<endl;
                }
                else if(it1 == cluster_pos.end() && it2 != cluster_pos.end()){
                        for(int i = 0; i < Cluster[cluster_pos[{x2,y2}]].size(); i++){
                                d += pure_distance(x1,y1, Cluster[cluster_pos[{x2,y2}]][i][0],Cluster[cluster_pos[{x2,y2}]][i][1]);
                                
                        }
                        
                        d = d/Cluster[cluster_pos[{x2,y2}]].size();
                        cout<<"The distance between point("<<x1<<","<<y1<<")"<<"and Cluster that contains("<<x2<<","<<y2<<") is :"<<d<<endl;
                }
                else {
                     if(cluster_pos[{x1,y1}] == cluster_pos[{x2, y2}]){
                             return 100000;
                     }

                        for(int i = 0; i < Cluster[cluster_pos[{x2,y2}]].size(); i++){
                                for(int j = i+1; j < Cluster[cluster_pos[{x1,y1}]].size(); j++){
                                        d += pure_distance(Cluster[cluster_pos[{x1,y1}]][j][0],Cluster[cluster_pos[{x1,y1}]][j][1],
                                        Cluster[cluster_pos[{x2,y2}]][i][0],Cluster[cluster_pos[{x2,y2}]][i][1]);
                                }
                        }
                        d = d/(Cluster[cluster_pos[{x2,y2}]].size()*Cluster[cluster_pos[{x1,y1}]].size());
                        cout<<"The distance between cluster contains("<<x2<<","<<y2<<")"<<"and Cluster that contains("<<x1<<","<<y1<<") is :"<<d<<endl;
                }
        }
        else {
                d = distance(x1, y1, x2, y2);   
        }       

        return d;
}

void group_distance(vector<vector<double>>& matrix){
    vector<vector<vector<double>>> Cluster;
    map<pair<double,double>, int> cluster_pos;// if there exist a coordinate that already added to the 3D cluster, it will return the group number.
    vector<vector<double>> group;// temp group
    vector<double> coordinate;// temp coordinate.
    vector<double> min_pair;
    map<pair<double,double>,int>::iterator it1;
    map<pair<double,double>,int>::iterator it2;

    
    while(matrix.size()!=1){
    double min_d = 10000;
    for(int i = 0; i < matrix.size(); i++ ){
            for(int j = i+1; j < matrix.size(); j++){
                    double d = average_distance(matrix[i][0],matrix[i][1], matrix[j][0], matrix[j][1],cluster_pos, Cluster, min_pair);
                    if(min_d > d){
                            if(min_pair.size()){
                            min_pair.pop_back();
                            min_pair.pop_back();
                            }
                            min_pair.push_back(i);
                            min_pair.push_back(j);
                            min_d = d;
                    }
            }
    }
    it1 = cluster_pos.find({matrix[min_pair[0]][0],matrix[min_pair[0]][1]});        
    it2 = cluster_pos.find({matrix[min_pair[1]][0],matrix[min_pair[1]][1]}); 
    // see whether those two coordinates merged before
    cout<<"the min distance is: "<<min_d<<endl;
    if(it1 == cluster_pos.end() && it2 == cluster_pos.end()){
        cluster_pos[{matrix[min_pair[0]][0],matrix[min_pair[0]][1]}] = Cluster.size();
        cluster_pos[{matrix[min_pair[1]][0],matrix[min_pair[1]][1]}] = Cluster.size();
        group.push_back(matrix[min_pair[0]]);
        group.push_back(matrix[min_pair[1]]);
        Cluster.push_back(group);
        group.clear();
    }
    else if(it1 == cluster_pos.end() && it2 != cluster_pos.end()){
            cluster_pos[{matrix[min_pair[0]][0], matrix[min_pair[0]][1]}] = cluster_pos[{matrix[min_pair[1]][0],matrix[min_pair[1]][1]}];
            Cluster[cluster_pos[{matrix[min_pair[1]][0],matrix[min_pair[1]][1]}]].push_back(matrix[min_pair[0]]);
            
    }
    else if (it1 != cluster_pos.end() && it2 == cluster_pos.end()){
             cluster_pos[{matrix[min_pair[1]][0], matrix[min_pair[1]][1]}] = cluster_pos[{matrix[min_pair[0]][0],matrix[min_pair[0]][1]}];
            Cluster[cluster_pos[{matrix[min_pair[0]][0],matrix[min_pair[0]][1]}]].push_back(matrix[min_pair[1]]);           
    }
    else {
            int s1 = Cluster[cluster_pos[{matrix[min_pair[0]][0],matrix[min_pair[0]][1]}]].size();
            int s2 =Cluster[cluster_pos[{matrix[min_pair[1]][0],matrix[min_pair[1]][1]}]].size();
            int group1 = cluster_pos[{matrix[min_pair[0]][0],matrix[min_pair[0]][1]}];
            int group2 = cluster_pos[{matrix[min_pair[1]][0],matrix[min_pair[1]][1]}];
            
            
            for(int i = 0; i < s1; i++){
                    cluster_pos[{Cluster[group1][i][0], Cluster[group1][i][1]}] = (group1 > group2)? group2 : group2-1;
                    Cluster[group2].push_back(Cluster[group1][i]);
                    
            }
            for(int i = 0; i < s2; i++){
                     cluster_pos[{Cluster[group1][i][0], Cluster[group1][i][1]}] = (group1 > group2)? group2 : group2-1;
            }

            Cluster.erase(Cluster.begin()+group1);
            
        }
        matrix.erase(matrix.begin()+min_pair[1]);
        cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
                for(int i = 0; i < Cluster.size(); i++){
                cout<<"The Cluster "<<i<<" contains points: ";
                for(int j = 0; j < Cluster[i].size(); j++){
                        cout<<"("<<Cluster[i][j][0]<<","<<Cluster[i][j][1]<<")";
                        if(j!=Cluster[i].size()-1){
                                cout<<", ";
                        }
                }
                cout<<endl;
        }
        cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
        }// end while loop


}
vector<int> mean(int x1, int y1, int x2, int y2, int previous_n){
        float new_x = float(x1*previous_n + x2) / (float(previous_n + 1));
        float new_y = float(y1*previous_n + y2) / (float(previous_n + 1));
        vector<int> temp;
        temp.push_back(new_x);
        temp.push_back(new_y);
        return temp;
}
float tan_func(float net){
        return ((exp(net*2) - 1) / (exp(net*2) + 1));
}
float sigmoid_func(float net){
        return (1 / (exp(-1*net) + 1));
}
float rectifier_func(float net){
        if(net >= 0){
                return net;
        }
        return 0;
}
float threshold_func(float net){
        if(net >= 0){
                return 1;
        }
        return 0;
}
void neural_network(vector<vector<double>> matrix, char ActFunc, double ini_w1, double ini_w2, double ini_b, double learning_rate){
        int iteration = matrix.size();
        int i = 0;
        vector<double> y;
        while(iteration--){
        double yy;
        cout<<"please input y values :"<<endl;
        cin>>yy;
        y.push_back(yy);
        }
        iteration = matrix.size();
        while(iteration--){
                double net = ini_w1*matrix[i][0] + ini_w2*matrix[i][1] + ini_b;
                cout<<"net = "<<ini_w1<<" * "<<matrix[i][0]<<" + "<<ini_w2<<" * "<<matrix[i][1]<<" + "<<ini_b<< " = "<<net<<endl;
                float d = (exp(net*2) - 1) / (exp(net*2) + 1);
                if(ActFunc == 't'){
                        d = tan_func(net);
                }
                else if(ActFunc == 's'){
                        d = sigmoid_func(net);
                }
                else if(ActFunc == 'r'){
                        d = rectifier_func(net);
                }
                else if(ActFunc == 'h'){
                        d = threshold_func(net);
                }
                float a = ini_w1 +  learning_rate * (y[i] - d) * matrix[i][0];
                float b = ini_w2 +  learning_rate * (y[i] - d) * matrix[i][1];
                float c = ini_b +  learning_rate * (y[i] - d);
                cout<<"w1 = "<<ini_w1<<" + "<<learning_rate<<" * "<<"("<<y[i]<<" - "<<d<<") * "<<matrix[i][0]<<" = "<<a<<endl;
                cout<<"w2 = "<<ini_w2<<" + "<<learning_rate<<" * "<<"("<<y[i]<<" - "<<d<<") * "<<matrix[i][1]<<" = "<<b<<endl;
                cout<<"b = "<<ini_b<<" + "<<learning_rate<<" * "<<"("<<y[i]<<" - "<<d<<") = "<<c<<endl;
                ini_w1 = ini_w1 +  learning_rate * (y[i] - d) * matrix[i][0];
                ini_w2 = ini_w2 +  learning_rate * (y[i] - d) * matrix[i][1];
                ini_b = ini_b +  learning_rate * (y[i] - d);
                cout<<"So in iteration "<<i+1<< " w1 = "<<ini_w1<<", w2 = "<<ini_w2<<", b = "<<ini_b<<endl;
                i++;
        }
}
void FP_tree(int threshold){
        map<char, int> count_char;
        vector<vector<char>> items;
        int n = 0;

        while(n != 27){
                char x = 'a' + n;
                count_char[x] = 0;
                n++;
        }       

        char x = 'a';
        n = 0;

        while(x != '/'){
                cout<<"please enter "<< n+1<<"th charater"<<endl;
                cin>>x;
                count_char[x] += 1 ;
                n++;
        }
        n = 0;

        while(n != 27){
        char x = 'a' + n;
        if(count_char[x] >= threshold){
                cout<<"The number of "<<x<<" "<<count_char[x]<<endl;
        }
        n++;
        }

        cout<<"Please enter Tid"<<endl;
        int Tid;
        int i = 0;
        cin>>Tid;

        while(Tid){
                char x = 'a';
                vector<char> temp;
                while(x != '/'){
                        cout<<"Please enter items for Tid "<<i+1<<endl;
                        cin>>x;
                        if( x!='/' && count_char[x] >= threshold){
                                temp.push_back(x);
                        }
                }
                for(int i = 0; i < temp.size(); i++){
                        for(int j =0; j< temp.size();j++){
                                if(count_char[temp[i]]> count_char[temp[j]]){
                                      char y =  temp[i];
                                      temp[i] = temp[j];
                                      temp[j] = y;
                                }
                        }
                }
                
                items.push_back(temp);
                i++;
        Tid--;
        }
        for(int i = 0; i < items.size(); i++){
                cout<<"For transaction ID "<<i+1<<" ";
                for(int j = 0; j < items[i].size(); j++){
                       cout<<items[i][j]<<" ";
        }
        cout<<endl;
        }
}
int main(){

        vector<vector<double>> matrix;
        double x = 0;// x coordinate
        double y = 0;// y coordinate
        int n = 0;// number of inputs

        cout<<"how many coordinate do you have: ";
        cin>>n;
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

        cout<<"which mode do you want : median enter'm', complete enter 'c', single enter 's', average enter 'a', distance only 'd' :";
        char choice;
        cin >> choice;
        vector<double> min_pair;
        if(choice == 'm'){
        control_panel(matrix, min_pair);
        }

        if(choice == 'a'){
           // group_average distance , which will show the distance between each cluster.
           group_distance(matrix);
        }
        if(choice == 'd'){
                int i = 0;
                int j = 0;
                for(int i = 0; i < matrix.size(); i++){
                        for(int j = i+1; j < matrix.size(); j++){
                                cout<<"distance between(x"<<i+1<<", y" <<i+1 <<"), (x"<<j+1<<","<<"y"<<j+1<<")"
                                << ":"<<pure_distance(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1])<<endl;
                        }
                }
        }
        if(choice == 'e'){
                int i = 0;
                int j = 0;
                int n = 1;
                vector<int> temp;
                for(int i = 0; i < matrix.size(); i++){
                        for(int j = i+1; j < matrix.size(); j++){
                                cout<<"mean coordinate (x"<<i+1<<", y" <<i+1 <<"), (x"<<j+1<<","<<"y"<<j+1<<")"
                                << ":"<<mean(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1], n)[0]<<","<<mean(matrix[i][0], matrix[i][1], matrix[j][0], matrix[j][1], n)[1]
                                <<endl;
                        }
                }
        }
        if(choice == 'n'){
                // activation function, w1, w2, b, learning rate
                // tan_func = t sigmoid = s , threshold = h 
                neural_network(matrix,'s',0.1,0.1,0.1,0.5);
   
        }
        if (choice == 'p'){
                double mean_y = 0;
                double mean_x = 0;
                for(int i = 0; i < matrix.size(); i++){
                                mean_y += matrix[i][1];
                                mean_x += matrix[i][0];
                }
                 mean_y = double(mean_y) / double(matrix.size());
                 mean_x = double(mean_x) / double(matrix.size());
                 cout<<"mean coordinate :("<<mean_x<<", "<<mean_y<<")"<<endl;
                for(int i = 0; i < matrix.size(); i++){
                        double ty = matrix[i][1] - mean_y;
                        double tx = matrix[i][0] - mean_x;
                        cout<<"difference between mean and x"<<i+1<< " coordinate = ("<<tx<<", "<<ty<<")"<<endl;
                }
        }

        if(choice == 'f'){
                int x;
                cout<<"please input threshold : "<<endl;
                cin>>x;
                FP_tree(x);
        }
}
