#include "wordy.h"

typedef enum {
  STATE_STR_WHAT,
  STATE_STR_IS,
  STATE_NUM_A,
  STATE_OPER,
  STATE_STR_BY,
  STATE_NUM_B,
} state_t;

typedef enum {
  OPER_ADD,
  OPER_SUB,
  OPER_MUL,
  OPER_DIV,
} operation_t;

static int get_token_at(const char * const text, int start, char * const token) {
  int pos = 0;

  if (text[start] == ' ') {
    start++;
  }

  for (int i = start; text[i] != ' ' && text[i] != '?' && text[i] != '\0'; i++) {
      token[pos++] = text[i];
      token[pos] = '\0';
  }

  if (pos == 0) {
    return 0;
  }

  return start + pos;
}

static int power(const int base, const int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

static int str_len(const char * const str) {
  int len = 0;

  for (len = 0; str[len] != '\0'; len++) {

  }

  return len;
}

static bool str_to_int(const char * const str, int * const out) {
  int factor = 1;
  const int len = str_len(str);

  *out = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (i == 0 && str[i] == '-') {
      factor = -1;

    } else if (str[i] >= '0' && str[i] <= '9'){
      *out += (str[i] - '0') * power(10, len - i - 1);

    } else {
      return false;
    }
  }

  *out *= factor;

  return true;
}

static bool str_equals(const char * const a, const char * const b) {
  int i = 0;

  for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  if (a[i] != '\0' || b[i] != '\0') {
    return false;
  }

  return true;
}

bool answer(const char * const question, int * const result) {
  char token[128];
  int pos = 0;

  state_t state = 0;
  operation_t oper = 0;

  int a = 0;
  int b = 0;

  while ((pos = get_token_at(question, pos, token)) != 0) {
    switch (state) {
    case STATE_STR_WHAT:
      if (!str_equals(token, "What")) {
        return false;
      }
      state = STATE_STR_IS;
      break;

    case STATE_STR_IS:
      if (!str_equals(token, "is")) {
        return false;
      }
      state = STATE_NUM_A;
      break;

    case STATE_NUM_A:
      if (!str_to_int(token, &a)) {
        return false;
      }
      state = STATE_OPER;
      break;

    case STATE_OPER:
      if (str_equals(token, "plus")) {
        oper = OPER_ADD;
        state = STATE_NUM_B;
      } else if (str_equals(token, "minus")) {
        oper = OPER_SUB;
        state = STATE_NUM_B;
      } else if (str_equals(token, "multiplied")) {
        oper = OPER_MUL;
        state = STATE_STR_BY;
      } else if (str_equals(token, "divided")) {
        oper = OPER_DIV;
        state = STATE_STR_BY;
      } else {
        return false;
      }
      break;

    case STATE_STR_BY:
      if (!str_equals(token, "by")) {
        return false;
      }
      state = STATE_NUM_B;
      break;

    case STATE_NUM_B:
      if (!str_to_int(token, &b)) {
        return false;
      }
      switch (oper) {
      case OPER_ADD:
        *result = a + b;
        break;
      case OPER_SUB:
        *result = a - b;
        break;
      case OPER_MUL:
        *result = a * b;
        break;
      case OPER_DIV:
        *result = a / b;
        break;
      }
      a = *result;
      state = STATE_OPER;
      break;
    }
  }

  return true;
}
