#include <cs-11m.h>
#include <vector>

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(-1);
}

void printList(const vector<int> &list) {
  Serial.print("{ ");
  for (int i = 0; i < list.size(); i++) {
    Serial.print(list[i]);
    Serial.print(" ");
  }
  Serial.println(" }");
}

void bubbleSort(vector<int> &list) {
  int sizeOfArray;
  int temp = 0;

  sizeOfArray = list.size();
  Serial.println(sizeOfArray);

//MAKE SURE TO NOT PASS OVER THE LAST VALUE
//IN ARRAY
  for (int i = 0; i < sizeOfArray-1; i++) {
    for (int j = 0; j < sizeOfArray-1; j++) {
      if (list[j] > list[j + 1]) {
        temp = list[j];
        list.erase(list.begin() + j);
        list.insert(list.begin() + j + 1, temp);
      }
    }
  }


}

void loop() {
  Serial.println("Enter some integers (enter zero when you're done):");
  vector<int> list;
  int num;
  while ((num = Serial.parseInt()) != 0) {
    list.push_back(num);
  }
  Serial.print("Before sort: ");
  printList(list);
  bubbleSort(list);

  Serial.print("After sort: ");
  printList(list);
}
