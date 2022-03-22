
typedef struct {
  /*
   * Data structure what contain
   * m = slope of the line
   * b = intersection point
   * This values is in the chart of the datasheet
   *
  */
  float m;
  float b;

  }ChartValues;


typedef struct  {

  float VRL;
  float Rs;
  float Ro;

}SensorValues;

typedef struct {

  float x;
  float y;
  }Point;
