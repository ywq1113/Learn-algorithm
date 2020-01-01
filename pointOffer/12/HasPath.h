#ifndef HASPATH_H
#define HASPATH_H

bool hasPath(char* matrix, int rows, int cols, char* str);
bool hasPathCore(const char* matrix, int rows, int cols, int row,
                int col, const char* str, int& pathLength, bool* visited);


#endif
