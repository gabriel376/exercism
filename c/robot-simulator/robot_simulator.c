#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
  return (robot_status_t) { direction, { x, y } };
}

static void robot_turn_left(robot_status_t *robot) {
  switch (robot->direction) {
  case DIRECTION_NORTH:
    robot->direction = DIRECTION_WEST;
    break;
  case DIRECTION_WEST:
    robot->direction = DIRECTION_SOUTH;
    break;
  case DIRECTION_SOUTH:
    robot->direction = DIRECTION_EAST;
    break;
  case DIRECTION_EAST:
    robot->direction = DIRECTION_NORTH;
    break;
  }
}

static void robot_turn_right(robot_status_t *robot) {
  switch (robot->direction) {
  case DIRECTION_NORTH:
    robot->direction = DIRECTION_EAST;
    break;
  case DIRECTION_EAST:
    robot->direction = DIRECTION_SOUTH;
    break;
  case DIRECTION_SOUTH:
    robot->direction = DIRECTION_WEST;
    break;
  case DIRECTION_WEST:
    robot->direction = DIRECTION_NORTH;
    break;
  }
}

static void robot_advance(robot_status_t *robot) {
  switch (robot->direction) {
  case DIRECTION_NORTH:
    robot->position.y++;
    break;
  case DIRECTION_SOUTH:
    robot->position.y--;
    break;
  case DIRECTION_EAST:
    robot->position.x++;
    break;
  case DIRECTION_WEST:
    robot->position.x--;
    break;
  }
}

void robot_move(robot_status_t *robot, const char *commands) {
  char c;
  while((c = *commands++) != '\0') {
    switch (c) {
    case 'L':
      robot_turn_left(robot);
      break;
    case 'R':
      robot_turn_right(robot);
      break;
    case 'A':
      robot_advance(robot);
      break;
    }
  }
}
