#include "data_types_gases.h"


ChartValues find_m_b_MG811(float x1, float y1, float x2, float y2){

  ChartValues chartValues;
  chartValues.m = float ( (y2 - y1) / (x2 - x1));
  chartValues.b = float(y1 - (chartValues.m * x1));
  return chartValues;

}
