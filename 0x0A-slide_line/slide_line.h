#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 'L'
#define SLIDE_RIGHT 'R'

int slide_line(int *line, size_t size, int direction);

#endif
