#include "grade_school.h"

#include <stdlib.h>
#include <string.h>

static bool contains_student(const roster_t * const roster,
                             const char * const name) {
  for (size_t i = 0; i < roster->count; i++) {
    if (strcmp(roster->students[i].name, name) == 0) {
      return true;
    }
  }

  return false;
}

static int compare_students(const void * const a,
                            const void * const b) {
  const student_t * const student1 = (student_t *) a;
  const student_t * const student2 = (student_t *) b;

  if (student1->grade > student2->grade) {
    return 1;
  }

  if (student1->grade < student2->grade) {
    return -1;
  }

  return strcmp(student1->name, student2->name);
}

static void append_student(roster_t * const roster,
                           const char * const name,
                           const uint8_t grade) {
  roster->students[roster->count].grade = grade;
  strcpy(roster->students[roster->count].name, name);
  roster->count++;
}

void init_roster(roster_t * const roster) {
  memset(roster, 0, sizeof(* roster));
}

bool add_student(roster_t * const roster,
                 const char * const name,
                 const uint8_t grade) {
  if (roster->count >= MAX_STUDENTS
      || strlen(name) > MAX_NAME_LENGTH
      || contains_student(roster, name)) {
    return false;
  }

  append_student(roster, name, grade);

  qsort(roster->students, roster->count, sizeof(student_t), compare_students);

  return true;
}

roster_t get_grade(const roster_t * const roster,
                   const uint8_t grade) {
  roster_t grade_roster;
  init_roster(&grade_roster);

  for (size_t i = 0; i < roster->count; i++) {
    if (roster->students[i].grade == grade) {
      append_student(&grade_roster, roster->students[i].name, roster->students[i].grade);
    }
  }

  return grade_roster;
}
