#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char *name;
    int points;
    float grade;
} Course;


void printCourses(Course *courses, int size);

Course* addCourse(Course *courses, int size, Course toAdd);

Course *findPrevCourse(Course *courses, int size, char *name);

int main(){
    Course courses[4];
    Course *c;
    int i;
    Course toAdd = {
            "hello", 5, 100
    };
    srand(time(NULL));

    for (i=0; i<4; i++){
        courses[i].name = (char*) malloc (5* sizeof(char));
        strcpy(courses[i].name, "abcd");
        courses[i].points = rand()%5;
        courses[i].grade = rand()%100;
    }

    printCourses(courses, 4);


    c = addCourse(courses, 4, toAdd);

    printCourses(c,5);
    return 0;
}

Course* addCourse(Course *courses, int size, Course toAdd){
    Course* newCourseList = (Course*) malloc ((size+1) * sizeof(Course));
    int distance;
    int i;
    distance = (int) (findPrevCourse(courses, size, toAdd.name) - courses);

    for (i=0; i<distance; i++){
        newCourseList[i] = courses[i];
    }

    newCourseList[i] = toAdd;

    for (; i<size; i++){
        newCourseList[i] = courses[i-1];
    }

    return newCourseList;
}

Course *findPrevCourse(Course *courses, int size, char *name) {
    int i;

    for (i=0; i<size; i++){
        if (strcmp(name,courses[i].name) < 0){
            return &courses[i-1];
        }
    }

    return NULL;
}

void printCourses(Course *courses, int size) {
    int i;

    for (i=0; i<size; i++){
        printf("******************************");
        printf("\nname %s\npoints %d\ngrade %d\n", courses[i].name, courses[i].points, courses[i].grade);
        printf("******************************");
    }
}