// tp3assembler -- a small assembler for the Logisim
// TinyProc processor.
//
// The processor has four registers r0, r1, r2, r3
// and four opcodes:
//    00 - add
//    01 - subtract
//    10 - multiply
//
//    11 - load immediate
//
// The instruction format is DR SR1 SR2 OP
// Two bits each - destination register DR
// source register SR1 SR2
// op code
//
// For load immediate, the SR bits are used
// as a 2's complement 4-bit value, that
// gets sign extended to 8 bits.
//
// Compile this with
//    gcc tp3assembler.c -o tp3assembler
//
// Run with
//    ./tp3assembler yourfile.s
//
// Some sample assembly code:
//    add r0, r1, r2
//    ldi r3, 4
//    mul r2, r1, r3
//
// The assembler is not very smart.  No error checking.
// No bounds checking.  It's just to show the principle
// of how things like this work.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  FILE *fp2;
  char buffer[1024];
  int sr1, sr2, dr;
  int immediate;
  unsigned int machinecode;


  if (argc != 2)
    {
      printf("Usage: %s filename.s\n", argv[0]);
      exit(1);
    }

  // C has routines to read and write files on your system.
  // fopen will open a file; the "r" indicates that we'll read
  // from the file (versus "w" for writing).
  fp = fopen(argv[1], "r");

  sprintf(buffer, "%s.raw", argv[1]);
  fp2 = fopen(buffer, "w");
  fprintf(fp2, "v2.0 raw\n");

  // fgets will get one line of text from your source code
  // file.  We'll talk about fgets a little more later in the
  // semester
  while (fgets(buffer, 1023, fp) != NULL)
    {
      // We're using sscanf here, to see in the incoming line
      // matches a particular pattern.  If sscanf can match
      // all of the %d spots, it'll return 3.  If it doesn't
      // match everything, it'll return something other than
      // 3.
      if (sscanf(buffer, " add r%d, r%d, r%d", &dr, &sr1, &sr2) == 3)
	{
	  // A little bit of bit shifting to assemble the
	  // whole instruction
	  machinecode = dr << 6 | sr1 << 4 | sr2 << 2 | 0;
	  printf("%02x : %s", machinecode, buffer);
	  fprintf(fp2, "%02x\n", machinecode);
	  continue;
	}
      if (sscanf(buffer, " sub r%d, r%d, r%d", &dr, &sr1, &sr2) == 3)
	{
	  machinecode = dr << 6 | sr1 << 4 | sr2 << 2 | 1;
	  printf("%02x : %s", machinecode, buffer);
	  fprintf(fp2, "%02x\n", machinecode);
	  continue;
	}
      if (sscanf(buffer, " mul r%d, r%d, r%d", &dr, &sr1, &sr2) == 3)
	{
	  machinecode = dr << 6 | sr1 << 4 | sr2 << 2 | 2;
	  printf("%02x : %s", machinecode, buffer);
	  fprintf(fp2, "%02x\n", machinecode);
	  continue;
	}
      if (sscanf(buffer, " ldi r%d, %d", &dr, &immediate) == 2)
	{
	  machinecode = dr << 6 | ((immediate << 2) & 0x3c) | 3;
	  printf("%02x : %s", machinecode, buffer);
	  fprintf(fp2, "%02x\n", machinecode);
	  continue;
	}

      // printf("Unrecognized line.\n");
    }
  fclose(fp);
  fclose(fp2);
}
