#include "grade_school.h"

#include <stdlib.h>
#include <string.h>

static roster_t roster = { 0 };

bool add_student(char *name, uint8_t grade) {
  if (roster.count >= MAX_STUDENTS || strlen(name) > MAX_NAME_LENGTH) {
    return false;
  }

  size_t index = roster.count;
  for (size_t i = 0; i < roster.count; i++) {
    if (grade < roster.students[i].grade || (grade == roster.students[i].grade && strncmp(name, roster.students[i].name, MAX_NAME_LENGTH) <= 0)) {
      index = i;
      memmove(&roster.students[index+1], &roster.students[index], (roster.count - index) * sizeof(student_t));
      break;
    }
  }

  roster.students[index].grade = grade;
  roster.students[index].name = malloc((1 + strlen(name)) * sizeof(char));
  strcpy(roster.students[index].name, name);
  roster.count++;

  return true;
}

roster_t get_roster() {
  return roster;
}

roster_t get_grade(uint8_t grade) {
  roster_t roster_by_grade = {0};

  for (size_t i = 0; i < roster.count; i++) {
    if (roster.students[i].grade == grade) {
      roster_by_grade.students[roster_by_grade.count++] = roster.students[i];
    }
  }

  return roster_by_grade;
}

void clear_roster(void) {
  for (size_t i = 0; i < roster.count; i++) {
    free(roster.students[i].name);
  }
  roster.count = 0;
}
