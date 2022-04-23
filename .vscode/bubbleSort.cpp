#include<iostream>
#include <string>
using namespace std;

void mySwap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

bool myCompare(int a, int b){
    if (a > b) return true;
    else return false;
}

int correct_input()
{
  int value = 0;
  string input;
  cin >> input;
  for (int i = 0; i < input.length(); i++) {
    if ((isdigit(input[i]) == false) && (input[0]!='-')) {
      cout << "Wrong input. Please retry >> " << endl;
      cin >> input;
      i = 0;
      continue;
    }
  }
  value = stoi(input);
  return value;
}

void BubbleSort(int answer, int size, int a[]){

    int temp, i, j;

    if (answer == 0){
        for(i = 0; i < (size - 1); i++){
            for(j = 0; j < (size - i - 1); j++)
            {
                if(myCompare(a[j], a[j+1]))
                {
                    mySwap(a[j], a[j+1]);
                }
            }
        }
    } else if (answer == 1){
        for(i = 0; i < (size - 1); i++){
            for(j = 0; j < (size - i - 1); j++)
            {
                if(!myCompare(a[j], a[j+1]))
                {
                    mySwap(a[j], a[j+1]);
                }
            }
        }

    } else {
        cout << "Wrong input. Terminating process.";
        exit(1);
    }
}

int main()
{
    const int size = 10;
    int answer, i, a[size], j, temp;
    string inputValue;
    
    cout << "Enter Numbers: \n";
    for (i = 0; i < size; i++){
        a[i] = correct_input();
    }

    cout << "\nSelect sorting order: 0 - ascending, 1 - descending >> ";
    cin >> answer;
    BubbleSort(answer, size, a);
    
    cout << "\nSuccess!\n";
    cout << "\nSorted array: \n";
    for(i = 0; i < size; i++)
        cout << a[i] <<" ";
    cout << endl;
}