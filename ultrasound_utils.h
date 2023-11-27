struct Ultrasound
{
  int trig;
  int echo;
  int distance;
  int duration;
};
// const int trig = 4; //ประกาศขา trig
// const int echo = 5; //ประกาศขา echo



void initUltrasound(struct Ultrasound *us, int trig, int echo)
{
  us->trig = trig;
  us->echo = echo;
  pinMode(us->echo, INPUT);
  pinMode(us->trig, OUTPUT);
}
