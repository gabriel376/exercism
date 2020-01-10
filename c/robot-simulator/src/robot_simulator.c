#include "robot_simulator.h"

robot_grid_status_t robot_init(void) {
    return (robot_grid_status_t) {
        DEFAULT_BEARING,
        {
            DEFAULT_X_COORDINATE,
            DEFAULT_Y_COORDINATE
        }
    };
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y) {
    return (robot_grid_status_t) {
        bearing < HEADING_MAX ? bearing : DEFAULT_BEARING,
        {
            x,
            y
        }
    };
}

void robot_turn_right(robot_grid_status_t * robot) {
    switch (robot->bearing) {
    case HEADING_NORTH:
        robot->bearing = HEADING_EAST;
        break;
    case HEADING_EAST:
        robot->bearing = HEADING_SOUTH;
        break;
    case HEADING_SOUTH:
        robot->bearing = HEADING_WEST;
        break;
    case HEADING_WEST:
        robot->bearing = HEADING_NORTH;
        break;
    case HEADING_MAX:
        break;
    }
}

void robot_turn_left(robot_grid_status_t * robot) {
    switch (robot->bearing) {
    case HEADING_NORTH:
        robot->bearing = HEADING_WEST;
        break;
    case HEADING_WEST:
        robot->bearing = HEADING_SOUTH;
        break;
    case HEADING_SOUTH:
        robot->bearing = HEADING_EAST;
        break;
    case HEADING_EAST:
        robot->bearing = HEADING_NORTH;
        break;
    case HEADING_MAX:
        break;
    }
}

void robot_advance(robot_grid_status_t * robot) {
    switch (robot->bearing) {
    case HEADING_NORTH:
        robot->grid.y_position++;
        break;
    case HEADING_SOUTH:
        robot->grid.y_position--;
        break;
    case HEADING_EAST:
        robot->grid.x_position++;
        break;
    case HEADING_WEST:
        robot->grid.x_position--;
        break;
    case HEADING_MAX:
        break;
    }
}

void robot_simulator(robot_grid_status_t * robot, const char *commands) {
    for (int i = 0; commands[i] != '\0'; i++) {
        switch (commands[i]) {
        case COMMAND_LEFT:
            robot_turn_left(robot);
            break;
        case COMMAND_RIGHT:
            robot_turn_right(robot);
            break;
        case COMMAND_ADVANCE:
            robot_advance(robot);
            break;
        }
    }
}
