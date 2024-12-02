/*Task 2: Iterating Through Containers and Finding Elements
Goal: Practice iterating through containers and retrieving specific elements.

Scenario:
You are tasked with highlighting all active widgets on the HMI screen. The HMI has two main containers:
std::vector for dynamic widgets.
std::set for static widgets.

Steps:
Populate Containers:
Initialize a std::vector<std::string> with dynamic widgets ("Speedometer", "Tachometer", etc.).
Initialize a std::set<std::string> with static widgets ("Logo", "WarningLights").

Use Iterators:
Print all dynamic widgets using an iterator.
Check if a specific widget (e.g., "WarningLights") is in the std::set using std::set::find.

Advanced Iteration:
Combine both containers into a std::vector<std::string> using std::copy.
Use std::find to locate a specific widget in the combined container.

Output Results:
Print the widget list dynamically and show results of widget searches.*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator> //for the 'distance()'

using namespace std;
int main(){
    vector<string>dynamic_widgets;
    int nd_widgets;
    string d_widgets;
    vector<string>::iterator it1;

    set<string>static_widgets;
    int ns_widgets;
    string s_widgets;
    set<string>::iterator it2;

    vector<string>Widgets; //new container to hold the combined values of both 'dynamic_widgets' and 'static_widgets'
    vector<string>::iterator it3;

    //initiating the dynamic nature for the dynamic widgets with d_widgets by giving size
    cout<<"Enter the size of d_widgets: "<<endl;
    cin>>nd_widgets;
    cout<<"The size is: "<<nd_widgets<<endl;

    //initializing the values into the vector
    cout<<"Enter the dynamic widgets: "<<endl;
    for(int i = 0; i<nd_widgets; i++){
        cin>>d_widgets;
        
        //if we use spaces for the string comparisions the condition doesn't work as intended and may poentially fail
        if(d_widgets == "Fuel_guage" || d_widgets == "Ambient_temperature" || d_widgets == "engine_temperature_guage" || d_widgets == "Speedometer" || d_widgets == "Tachometer"){
            dynamic_widgets.push_back(d_widgets);
            cout<<"The valid widget - "<<i+1<<" : "<<d_widgets<<endl;
        }
        else{
            cout<<"Invalid widgets"<<endl;
            break;
        }
    }
    

    //displaying the dynamic widgets using iterators
    cout<<"THESE ARE THE DYNAMIC WIDGETS AS A WHOLE: "<<endl;

    for(it1 = dynamic_widgets.begin(); it1 != dynamic_widgets.end(); ++it1){
        cout<<*it1<<endl;
    }

    cout<<"----------------------------------------------------------------------------------------------"<<endl;


    //initializing the dynamic nature of static widgets with s_widgets by giving size
    cout<<"Enter the size of the s_widgets: "<<endl;
    cin>>ns_widgets;
    cout<<"The size is: "<<ns_widgets<<endl;

    //initializing values into the set of static_widgets
    cout<<"Enter the static widgets: "<<endl;

    for(int j = 0; j<ns_widgets; j++){
        cin>>s_widgets;
        if(s_widgets == "Labels" || s_widgets == "Icons" || s_widgets == "Warning_display" || s_widgets == "Seperators"){
            static_widgets.insert(s_widgets);
            cout<<"The valid widget - "<<j+1<<" : "<<s_widgets<<endl;
        }
        else{
            cout<<"Invalid widget"<<endl;
        }
    }

    //displaying the values in the static widgets using iterators
    cout<<"THESE ARE THE STATIC WIDGETS AS A WHOLE: "<<endl;
    for(it2 = static_widgets.begin(); it2 != static_widgets.end(); ++it2){
        cout<<*it2<<endl;
    }

    //finding existence of specific element in the set of static_widgets using 'find()'
    if(static_widgets.find("Labels") != static_widgets.end()){
        cout<<"Search operation : Done"<<endl;
    }
    else{
        cout<<"Search operation : Failed<<endl";
    }

    //combining two containers into a new 'vector' container using 'std::copy()'
    cout<<"COPY OPERATION UNDER PROGRESSION........................."<<endl;
    Widgets.resize(dynamic_widgets.size() + static_widgets.size());
    copy(dynamic_widgets.begin(), dynamic_widgets.end(), Widgets.begin());
    copy(static_widgets.begin(), static_widgets.end(), Widgets.begin() + dynamic_widgets.size());


    //using 'std::find()' to find a widget's location in the 'combined container - Widget'
    cout<<"FINDING OPERATION UNDER PROGRESSION.............................."<<endl;
    auto it4 = find(Widgets.begin(), Widgets.end(), "Labels");
    cout<<"The location of element: "<<endl;
    cout<<distance(Widgets.begin(), it4)<<endl;

    //using iterators to display the elements in the 'Widgets'
    cout<<"FINALLY PRINTING ALL THE ELEMENTS IN THE NEW COMBINED CONTAINER..........................."<<endl;
    cout<<"New container is 'Widgets', a combination of 'dynamic_widgets' and 'static_widgets', it consists of:  "<<endl;
    for(it3 = Widgets.begin(); it3 != Widgets.end(); ++it3){
        cout<<*it3<<endl;
    }

    //[OR]

    // cout<<"New container is 'Widgets', a combination of 'dynamic_widgets' and 'static_widgets', it consists of:  "<<endl;
    // for(string w : Widgets){
    //     cout<<w<<endl;
    // }

return 0;}
