#ifndef MOVCOU_H
#define MOVCOU_H

int movingCountCore(int threshold, int rows, int cols,
                     int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row,
           int col, bool* visited);
int getDigitSum(int i);

#endif
