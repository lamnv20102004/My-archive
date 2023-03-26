#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int student_code;
    char student_name[50];
    double subject_a;
    double subject_b;
    double subject_c;
} student;

student students[1000];
int num_students = 0;

void add_new(int num_new_students) {
    int i;
    for (i = 0; i < num_new_students; i++) {
        students[num_students].student_code = num_students + 1;
        scanf("%s %lf %lf %lf", students[num_students].student_name, &students[num_students].subject_a, &students[num_students].subject_b, &students[num_students].subject_c);
        num_students++;
    }
    printf("%d\n", num_new_students);
}

void update_score(int student_code) {
            scanf("%s", students[student_code].student_name);
            scanf("%lf %lf %lf", &students[student_code].subject_a, &students[student_code].subject_b, &students[student_code].subject_c);
    printf("%d\n",student_code);
}

int compare_students(const void *p1, const void *p2) {
    double score1 = (*(student*)p1).subject_a + (*(student*)p1).subject_b + (*(student*)p1).subject_c;
    double score2 = (*(student*)p2).subject_a + (*(student*)p2).subject_b + (*(student*)p2).subject_c;
    if (score1 > score2) return -1;
    else if (score1 < score2) return 1;
    else return 0;
}

void display_list() {
    int i;
    qsort(students, num_students, sizeof(student), compare_students);
    for (i = 0; i < num_students; i++) {
        double total_score = students[i].subject_a + students[i].subject_b + students[i].subject_c;
        printf("%d %s %.1lf %.1lf %.1lf\n", students[i].student_code, students[i].student_name, students[i].subject_a, students[i].subject_b, students[i].subject_c);
    }
}

int main() {
    int choice;
    while (scanf("%d", &choice) == 1) {
        if (choice == 1) {
            int num_new_students;
            scanf("%d", &num_new_students);
            add_new(num_new_students);
        } else if (choice == 2) {
            int student_code;
            scanf("%d", &student_code);
            update_score(student_code);
        } else if (choice == 3) {
            display_list();
            break;
        }
    }
}
