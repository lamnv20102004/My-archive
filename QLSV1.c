#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  int id;
  char name[50];
  float scores[3];
  float total_score;
} Student;

int num_students = 0;
int max_students = 100;
Student* students;

void addNewStudents() {
  int num;
  scanf("%d", &num);

  if(num_students + num >= max_students) {
    max_students += num;
    students = realloc(students, max_students * sizeof(Student));
  }

  for (int i = 0; i < num; i++) {
    scanf("%s", students[num_students].name);
    scanf("%f", &students[num_students].scores[0]);
    scanf("%f", &students[num_students].scores[1]);
    scanf("%f", &students[num_students].scores[2]);

    students[num_students].id = num_students + 1;
    num_students++;
  }
}

void updateScore() {
  int code;
  scanf("%d", &code);

  for (int i = 0; i < num_students; i++) {
    if (students[i].id == code) {
      scanf("%f", &students[i].scores[0]);
      scanf("%f", &students[i].scores[1]);
      scanf("%f", &students[i].scores[2]);
      return;
    }
  }
}

void merge(Student arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].total_score <= R[j].total_score) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void displayList() {
  Student temp;
  float total_score[num_students];
  for (int i = 0; i < num_students; i++) {
    total_score[i] = students[i].scores[0] + students[i].scores[1] + students[i].scores[2];
  }

  for (int i = 0; i < num_students - 1; i++) {
    for (int j = i + 1; j < num_students; j++) {
      if (total_score[i] > total_score[j]) {
        temp = students[i];
        students[i] = students[j];
        students[j] = temp;
        float tmp = total_score[i];
        total_score[i] = total_score[j];
        total_score[j] = tmp;
      }
    }
  }

  for (int i = 0; i < num_students; i++) {
    printf("%d %s %0.1f %0.1f %0.1f %0.1f\n", i + 1, students[i].name, students[i].scores[0], students[i].scores[1], students[i].scores[2], total_score[i]);
  }
}

int main() {
  students = malloc(max_students * sizeof(Student));

  int choice;

  do {
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addNewStudents();
        break;
      case 2:
        updateScore();
        break;
      case 3:
        displayList();
        break;
      default:
        break;
    }
  } while (choice != 0);

  return 0;
}