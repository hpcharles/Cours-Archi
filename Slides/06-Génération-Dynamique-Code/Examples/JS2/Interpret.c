#define MAX 1024
unsigned char program[MAX];
int stack[MAX];
int PCcounter, STACKcounter;
enum OPCODE {iADD, iSUB};

void functionInterpret ()
{
  int iresult;
  switch (program[PCcounter++])
    {
    case iADD:
      iresult = stack[STACKcounter] + stack[STACKcounter];
      stack[--STACKcounter] = iresult;
      break;
    case iSUB:
      iresult = stack[STACKcounter] - stack[STACKcounter];
      stack[--STACKcounter] = iresult;
      break;
      /* ../.. */
    } 
}
