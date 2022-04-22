#include <iostream>
#include <string>
using namespace std;
bool compare(int first, int second) 
{
  if (first > second) return true;
  else return false;
}
void sub(int& first, int& second) {
  int temp;
  temp = first;
  first = second;
  second = temp;
}
void sort(int arr[], int size, int choice) 
{
  bool flag = false;
  for (int i = 0; i < size-1; i++)
  {
    flag = false;
    if (choice == 1) {
      for (int j = 0; j < size - i - 1; j++)
      {
        if (!compare(arr[j], arr[j + 1])) {
          sub(arr[j], arr[j + 1]);
          flag = true;
        }
      }
      if (flag == false) break;
    }
    if (choice == 2) {
      for (int j = 0; j < size - i - 1; j++)
      {
        if (compare(arr[j], arr[j + 1])) {
          sub(arr[j], arr[j + 1]);
          flag = true;
        }
      }
      if (flag == false) break;
    }
  }
}
void print(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int correct_input()
{
  int value = 0;
  string input;
  cin >> input;
  for (int i = 0; i < input.length(); i++) {
    if ((isdigit(input[i]) == false)&&(input[0]!='-')) {
      cout << "Incorrect input.Try again >> " << endl;
      cin >> input;
      i=0;
      continue;
    }
  }
  value = stoi(input);
  return value;
}
int main()
{
  const int size = 10;
  int arr[size];
  for (int i = 0; i < size; ++i)
  {
    cout << i + 1 << " element >>  ";
    arr[i] = correct_input();
  }
  cout << "Source array >>  ";
  print(arr, size);

  int choice;
  cout << "Enter |1| to sort from max to min \nEnter |2| to sort from min to max " << endl;
  choice = correct_input();
  if ((choice != 1) && (choice != 2)) {
    cout << "1 or 2 wasn`t entered!!!";
    exit(1);
  }

  sort(arr, size, choice);
  cout << "Sorted array >>  ";
  print(arr, size);
  return 0;
}