// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_STACKS
#include "stacks.h"
/******************************************************************************/
/** Stack Functions                                                          **/
/**   Data Stack "stack" - A stack that may be used for passing parameters   **/
/**   between definitions. When there is no possibility of confusion, the    **/
/**   data stack is referred to as “the stack”. Contrast with return stack.  **/
/**                                                                          **/
/**   Return Stack "rStack" - A stack that may be used for program execution **/
/**   nesting, do-loop execution, temporary storage, and other purposes.     **/
/******************************************************************************/

/*********************************************/
/** clear - removes everything from the     **/
/** stack.                                  **/
/*********************************************/
void dStack_clear(void) {
  dStack.top = 0;
  dStack.d[0] = 0;
}

void rStack_clear(void) {
  dStack.top = 0;
  dStack.d[0] = 0;
}

/*********************************************/
/** Push (place) a cell onto the stack      **/
/*********************************************/
void dStack_push(cell_t value) {
  if (dStack.top < dStack.size) {
    dStack.d[++dStack.top] = value;
  } else {
    dStack.d[dStack.top] = -3;
    _throw();
  }
}

void rStack_push(cell_t value) {
  if (rStack.top < rStack.size) {
    rStack.d[++rStack.top] = value;
  } else {
    dStack_push(-5);
    _throw();
  }
}

/*********************************************/
/** Pop (remove) a cell from the stack      **/
/*********************************************/
cell_t dStack_pop(void) {
  if (dStack.top > 0) {
    return (dStack.d[dStack.top--]);
  } else {
    dStack_push(-4);
    _throw();
  }
  return 0;
}

cell_t rStack_pop(void) {
  if (rStack.top > 0) {
    return (rStack.d[rStack.top--]);
  } else {
    dStack_push(-6);
    _throw();
  }
  return 0;
}

/*********************************************/
/** Peek - copy the cell value from the Nth **/
/** position down from the top of the data  **/
/** stack. N = 0 is the top of the stack.   **/
/*********************************************/
cell_t dStack_peek(int n) {
  // Error Check: Make sure the depth doesn't
  // exceed the number of elements
  if (n < dStack.top) {
    return dStack.d[dStack.top - (n)];
  } else {
    Serial.println("Error: Depth too large!");
  }
  return 0;
}

cell_t rStack_peek(int n) {
  // Error Check: Make sure the depth doesn't
  // exceed the number of elements
  if (n < rStack.top) {
    return rStack.d[rStack.top - (n)];
  } else {
    Serial.println("Error: Depth too large!");
  }
  return 0;
}

/*********************************************/
/** isFull - return the true if the stack   **/
/** is full.                                **/
/*********************************************/ 
bool dStack_isFull(void) {
  if (dStack.top == dStack.size) {
    return true;
  } else {
    return false;
  }
}

bool rStack_isFull(void) {
  if (rStack.top == rStack.size) {
    return true;
  } else {
    return false;
  }
}

/*********************************************/
/** isEmpty - return the true if the stack  **/
/** is empty.                               **/
/*********************************************/ 
bool dStack_isEmpty(void) {
  if (dStack.top == 0) {
    return true;
  } else {
    return false;
  }
}

bool rStack_isEmpty(void) {
  if (rStack.top == 0) {
    return true;
  } else {
    return false;
  }
}

/*********************************************/
/** size - return the number items on the   **/
/** stack.                                  **/
/*********************************************/ 
uint8_t dStack_size(void) {
  return dStack.top;
}

uint8_t rStack_size(void) {
  return dStack.top;
}

#endif
